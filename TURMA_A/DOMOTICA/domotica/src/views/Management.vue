<script setup lang="ts">
import DeviceComponent from '@/components/DeviceComponent.vue';
import EnvironmentComponent from '@/components/EnvironmentComponent.vue';
import { ApiResponse, Device, Environment, EnvironmentResponse, mapApiResponseToEnvironments } from '@/models/devices';
import { ref, reactive, onMounted, onBeforeMount, type Ref } from 'vue';
import { useDeviceRepository } from '@/stores/deviceRepository';
import { getEnvironments } from '@/services/cdnService';
import { publish, saveEnvironment } from '@/services/apiService';

const selectedEnvironment = ref(new Environment());
const newEnv = reactive(new Environment());
const showNewEnvForm = ref(false);

const saveNewEnv = async ()=> {
    try{
        const savedEnv = await saveEnvironment(newEnv.name);
        showNewEnvForm.value = false;
        if(savedEnv?.sys){
            await publish(savedEnv.sys.id, savedEnv.sys.version);
            newEnv.devices = [];
            newEnv.id = '';
            newEnv.name = '';
            await getAllEnvironments();
        }   

    } catch(error){
        console.error("Error when saving new envi", error);
    }

}


const allEnvironments: Ref<Array<Environment>> = ref([]);
const teste = ref<Number>(0);

    

const getAllEnvironments = async() =>{

    try{
        console.log("start request");
        const response = await getEnvironments();
        allEnvironments.value.length = 0;
        // teste.value = (await getEnvironments()).items.length;
        getEnvironments().then(r=>teste.value = r.items.length);
        // teste.length = 0;

        // response.items.forEach(i=>teste.push(JSON.parse(JSON.stringify(i.fields?.name)) ?? "-"));
        
        // teste.includes = response.includes;
        // teste.items = response.items;
        // teste.sys = response.sys;
        mapApiResponseToEnvironments(response).forEach(item=> 
            {
                allEnvironments.value.push(item);
                // teste.push(item.name);
                // teste.push(JSON.parse(JSON.stringify(item)));
            }
        );          
        // setTimeout(()=>{teste.length=0},2000);
    } catch(error){
        console.error("Error when getting environments", error);
    }
}

onBeforeMount(()=>{
    getAllEnvironments();
})

</script>

<template>
    <main class="flex flex-column text-center justify-content-center align-items-center">
        <h1>Gerencie seus Dispositivos! ⚡</h1>        
        <section class="environments flex flex-column border-round-sm">
            <div class="flex flex-row m-3">
                <label for="selectedEnv" class="mr-3">Ambiente:</label>
                <select id="selectedEnv" v-model="selectedEnvironment">
                    <option v-for="(currentEnv, envId) in allEnvironments" :key="envId" 
                      :value="currentEnv">
                        {{ currentEnv.name }}
                    </option>
                    <option value="" v-if="allEnvironments.length == 0">
                        Sem Ambientes!
                    </option>                      
                </select>
                <button @click="()=> showNewEnvForm = true">
                    <span class="icons material-icons-round">add</span>
                </button>
                <div v-if="showNewEnvForm">
                    <label for="">Nome:</label>
                    <input type="text" v-model="newEnv.name">
                </div>
                <button @click="saveNewEnv" v-if="showNewEnvForm">
                    <span class="icons material-icons-round">save</span>
                </button>
            </div>
            <div>
                <EnvironmentComponent :showDeviceButtons="false" :environment="selectedEnvironment" />
            </div>      
            <!-- {{ teste.map(i=>`<> ${i.name} <>`) }}       -->
              <!-- {{ teste.items.map(i=>`<> ${i.sys.id} <>`) }} -->
                {{ teste }}
            
        </section>
    </main>
</template>

<style scoped lang="scss">
    main{
        width: 100vw;
        min-height: 100vh;
        .environments{
            width: 90vw;
            min-height: 95vh;
            background-color: var(--background-envs-color);
            box-shadow: rgba(0, 0, 0, 0.25) 0px 54px 55px, rgba(0, 0, 0, 0.12) 0px -12px 30px, rgba(0, 0, 0, 0.12) 0px 4px 6px, rgba(0, 0, 0, 0.17) 0px 12px 13px, rgba(0, 0, 0, 0.09) 0px -3px 5px;
        }
    }
</style>