#include <Servo.h>        //servo library
Servo servo;
//konstanter
const int TRIG_PIN = 9; // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN = 8; // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int servoPin = 13;
const int LED_PIN  = 2; // Arduino pin connected to LED's pin


const int maxAvstand = 50; // centimeters

// variabler:
float duration_us;
float distance_cm;

void setup() {
  	Serial.begin (9600);       // initialize serial port
	servo.attach(servoPin);
  	pinMode(TRIG_PIN, OUTPUT); // set arduino pin to output mode
  	pinMode(ECHO_PIN, INPUT);  // set arduino pin to input mode
  	pinMode(LED_PIN, OUTPUT);  // set arduino pin to output mode

	servo.write(0);         //servoen skal lukke lokket ved power on
	delay(100);
  	servo.detach();
   
}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);
  // calculate the distance
  distance_cm = 0.017 * duration_us;

  if(distance_cm < maxAvstand){
    digitalWrite(LED_PIN, HIGH); // turn on LED
     servo.attach(servoPin);
     delay(1);
     servo.write(0);  
     delay(3000);
     servo.write(150);    
     delay(1000);
     servo.detach();
  }
  else{
      digitalWrite(LED_PIN, LOW); // turn off LED
  }

  delay(500);
}
