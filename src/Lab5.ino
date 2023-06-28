
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

//internal variables
int current_min = 5000;
int current_max = 0; 
int potentiometer_voltage;

void setup() {

  //initialize pins
  pinMode(A5, INPUT);
  pinMode(D5, OUTPUT);

}

void loop() {

  //maps output to (0,255) then lights up the light with the power
  int lux_sensor_voltage = analogRead(A5);
  current_min = min(current_min, lux_sensor_voltage);
  current_max = max(current_max, lux_sensor_voltage);

  int light_brightness = map(lux_sensor_voltage, current_min, current_max, 0, 255);
  analogWrite(D5, light_brightness);
  
}

