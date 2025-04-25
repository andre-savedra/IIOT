//https://www.tinkercad.com/things/4niSDr0USVO-projeto1-ta

#define BUTTON_PIN 2
#define LED_PIN 1

bool button = 0, led = 0;

//configurações:
void setup(){
    pinMode(BUTTON_PIN,INPUT_PULLUP);
    pinMode(LED_PIN,OUTPUT);
}

//lógica:
void loop(){
    /*if(button){
        led = 1;
    }
    else{
        led = 0;
    }*/
    led = button;

    //I-O's:
    button = !digitalRead(BUTTON_PIN);
    digitalWrite(LED_PIN,led);
}