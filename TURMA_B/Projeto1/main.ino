//https://www.tinkercad.com/things/aojy9Up9uzz-ads-b-1

// I/O's  Inputs (Entradas)
// Outputs (Saídas)

#define BUTTON_PIN 2
#define LED_PIN 1

//bool/digital: 0/1, false/true, LOW/HIGH
bool button = 0, led = 0;

//configurações
void setup()
{
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(LED_PIN,OUTPUT);
}
//lógica
void loop()
{
    //I/O's:
    button = !digitalRead(BUTTON_PIN);
    digitalWrite(LED_PIN, led);

    led = button;
    //led = button? 1 : 0; 

    /* if(button){
       led = 1;
    }
    else{
        led = 0;
    } */
}