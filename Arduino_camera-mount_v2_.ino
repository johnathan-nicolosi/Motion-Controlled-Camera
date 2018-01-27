
/* Motion detection and servo control
 * using Arduino Servo Shield
 * and three passive infrared receivers
 * written by Johnathan Nicolosi
 */

#include <Servo.h> // a maximum of 8 servos can be created
Servo servo1; // this motor pans up and down
Servo servo2; // this motor turns left and right

//int moistureSensor = A0;        // Moisture sensor output to Arduino analog A0 pin
//int lightSensor = A1;           // Light sensor output to Arduino analog A1 pin
int passiveIR1 = 2;              // (Center) PassiveIR sensor on Raspberry sends a digital high to Digital Pin 2 
int passiveIR2 = 3;              // (Right) PassiveIR sensor on Raspberry sends a digital high to Digital Pin 3
int passiveIR3 = 4;              // (Left) PassiveIR sensor on Raspberry sends a digital high to Digital Pin 4
int piezoPin = 8;               // for the alarm buzzer
int pir1State = LOW;             // start by assuming no motion detected at center
int pir2State = LOW;             // start by assuming no motion detected on right
int pir3State = LOW;             // start by assuming no motion detected on left
float val1 = 0;                    // variable for reading center PIR pin status
float val2 = 0;                    // variable for reading right PIR pin status
float val3 = 0;                    // variable for reading left PIR pin status
void setup() {
  // initialize the serial communications:
  Serial.begin(9600);
  // turn on servo1
  servo1.attach(9);
  // turn on servo2
  servo2.attach(10);
}



void loop() {
   int i;
  Serial.print("Motion (Center): ");
  Serial.print(digitalRead(passiveIR1));
  // print a tab between values
  Serial.print("\t");
   // print the sensor values:
  Serial.print("Motion (Right): ");
  Serial.print(digitalRead(passiveIR2));
  // print a tab between values
  Serial.print("\t");
   // print the sensor values:
  Serial.print("Motion (Left): ");
  Serial.print(digitalRead(passiveIR3));
  // print a tab between values
  Serial.print("\t");
  // print the sensor values:

for (i = 0; i < 1; i++) {
  val1 = digitalRead(passiveIR1);  // read input value  
  if (val1 == HIGH) {            // check if the input is HIGH
    //digitalWrite(piezoPin, HIGH);  // turn buzzerON
    if (digitalRead(passiveIR1) > 0) {
      // we have just turned on
      Serial.println("Alert: Motion detected at Center!");
      // We only want to print on the output change, not state
      while(pir1State == LOW){
             servo1.write(60);
             delay(500);
             servo2.write(75);
             delay(500);
             break;
             }
      pir1State = HIGH;    
    }
  } else {
    //digitalWrite(piezoPin, LOW); // turn buzzer OFF
    if (pir1State == HIGH){
      // we have just turned of
      Serial.println("Alert: Motion ended!");
      // We only want to print on the output change, not state
      pir1State = LOW;
    }
  } 
  val2 = digitalRead(passiveIR2);  // read input value
  if (val2 == HIGH) {            // check if the input is HIGH
      //digitalWrite(piezoPin, HIGH);  // turn buzzerON
      if (digitalRead(passiveIR2) > 0) {
      // we have just turned on
      Serial.println("Alert: Motion detected on my right!");
      // We only want to print on the output change, not state
      while(pir2State == LOW){
             servo1.write(60);
             delay(500);
             servo2.write(1);
             delay(500);
             break;
             }
      pir2State = HIGH;  
    }
  } else {
    //digitalWrite(piezoPin, LOW); // turn buzzer OFF
    if (pir2State == HIGH){
      // we have just turned of
      Serial.println("Alert: Motion on my right has ended!");
      // We only want to print on the output change, not state
      pir2State = LOW;
    }
  }
  val3 = digitalRead(passiveIR3);  // read input value
  if (val3 == HIGH) {            // check if the input is HIGH
      //digitalWrite(piezoPin, HIGH);  // turn buzzerON
      if (digitalRead(passiveIR3) > 0) {
      // we have just turned on
      Serial.println("Alert: Motion on my left detected!");
      // We only want to print on the output change, not state
      while(pir3State == LOW){
         servo1.write(60);
         delay(500);
         servo2.write(180);
         delay(500);
         break;
      }
    pir3State = HIGH;  
    }
  } else {
    //digitalWrite(piezoPin, LOW); // turn buzzer OFF
    if (pir3State == HIGH){
      // we have just turned of
      Serial.println("Alert: Motion on my left has ended!");
      // We only want to print on the output change, not state
      pir3State = LOW;
    }
  }
}
delay(1000);
}

