#define ON_BUTTON_PIN 9
#define BAR_SENSOR_PIN 1
#define WINDOW_SENSOR1_PIN 2
#define WINDOW_SENSOR2_PIN 3
#define ROOM_SENSOR_PIN 4
#define KITCHEN_SENSOR_PIN 5
#define GARAGE_SENSOR_PIN 6|
#define HALL_SENSOR_PIN 7
#define ALARM_PIN 8

bool onButton = 0, barSensor = 0, windowSensor1 = 0;
bool roomSensor = 0, kitchenSensor = 0, windowSensor2 = 0;
bool garageSensor = 0, hallSensor = 0, alarm = 0;

void void setup()
{
    pinMode(ON_BUTTON_PIN, INPUT_PULLUP);
    pinMode(BAR_SENSOR_PIN, INPUT_PULLUP);
    pinMode(WINDOW_SENSOR1_PIN, INPUT_PULLUP);
    pinMode(WINDOW_SENSOR2_PIN, INPUT_PULLUP);
    pinMode(ROOM_SENSOR_PIN, INPUT_PULLUP);
    pinMode(KITCHEN_SENSOR_PIN, INPUT_PULLUP);
    pinMode(GARAGE_SENSOR_PIN, INPUT_PULLUP);
    pinMode(HALL_SENSOR_PIN, INPUT_PULLUP);
    pinMode(ALARM_PIN, OUTPUT);
}

void void loop()
{
    

//I-O's



}
