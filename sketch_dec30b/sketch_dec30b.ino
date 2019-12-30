// SIMPLE PROXIMITY SENSOR
// by Chris and Kamil
// initial project 2019.12.30
// version 2019.12.30_11:45

#define trig 4
#define echo 3

#define led_red 8 
#define led_yellow 9
#define led_green 10

void setup() {
  Serial.begin(9600);
  
  pinMode(led_red, OUTPUT); // red
  pinMode(led_yellow, OUTPUT); // yellow
  pinMode(led_green, OUTPUT); // green
  disableAllLeds();

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);  
}

void loop() {

  int proximitySensorTime = 0;
  int proximitySensorDistance = 0;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  proximitySensorTime = pulseIn(echo, HIGH);
  proximitySensorDistance = proximitySensorTime / 58;
  Serial.print(proximitySensorDistance);
  Serial.print("cm\n");
  delay(100);

  if(proximitySensorDistance<=8) {
    enableOneLed('r');
  } else if(proximitySensorDistance<=18) {
    enableOneLed('y');
  } else {
    enableOneLed('g');
  }
}

void enableOneLed(char color) {
  disableAllLeds();
  enableLed(color);
}

void enableLed(char color) {
  switch (color) {
    case 'r':
      digitalWrite(led_red, HIGH);  
      break;
    case 'y':
      digitalWrite(led_yellow, HIGH);  
      break;
    case 'g':
      digitalWrite(led_green, HIGH);  
      break;
  }
}

void disableAllLeds() {
  digitalWrite(led_red, LOW);  
  digitalWrite(led_yellow, LOW);  
  digitalWrite(led_green, LOW);  
}
