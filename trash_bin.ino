/// include library

#include <Servo.h> ///servo motor library


// Pin Definitions


//plastic bin pin definitions
#define redpin 5
#define bluepin 6
#define greenpin 7
#define plasticsensor A0
#define plasticsensor2 A1
// #define metalsensor A1
//#define IR_plastic A3

//metal bin pin definitions
#define redpin_M 8
#define bluepin_M 9
#define greenpin_M 10
// #define metalsensor_M A2
// #define IR_metal A3


Servo myservo; // create servo object to control a servo on plastic bin
Servo myservo_M; // create servo object to control a servo on metal bin



int pos = 165; // deafult servo position of plastic bin
int pos_M = 158; // deafult servo position of metal bin


void setup() {

    myservo.attach(11); // attaches the plastic bin servo on pin 11 to the servo object
    myservo_M.attach(12); // attaches the metal bin servo on pin 12 to the servo object
    //RGB LED on plastic bin
    pinMode(redpin,OUTPUT);
    pinMode(bluepin,OUTPUT);
    pinMode(greenpin,OUTPUT);
    //RGB LED on metal bin
    pinMode(redpin_M,OUTPUT);
    pinMode(bluepin_M,OUTPUT);
    pinMode(greenpin_M,OUTPUT);
    //Create sensor values in pull up condition
    pinMode(plasticsensor,INPUT_PULLUP);
    pinMode(plasticsensor2,INPUT_PULLUP);
    // pinMode(metalsensor,INPUT_PULLUP);
    // pinMode(metalsensor_M,INPUT_PULLUP);
    //Activate IR sensor
    //pinMode(IR_plastic,INPUT);
    // pinMode(IR_metal,INPUT);
    //start serial monitor
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    Serial.begin(9600);
    //Set RGB LED on deafult vaues (white)
    analogWrite(redpin,255);
    analogWrite(bluepin,255);
    analogWrite(greenpin,255);
    analogWrite(redpin_M,255);
    analogWrite(bluepin_M,255);
    analogWrite(greenpin_M,255);


}
// bool biodegradable_detected = false; // Flag to track whether biodegradable trash has been detected previously
    // unsigned long binOpenTime = 0; // Variable to store the time when the bin was opened
void loop(){
int sensor_read_plastic = digitalRead(plasticsensor);
    int sensor_read_plastic2 = digitalRead(plasticsensor2);

    // Check if either of the plastic sensors detects biodegradable trash
    if (sensor_read_plastic == 0 || sensor_read_plastic2 == 0) {
        // Biodegradable trash detected
        Serial.println("Biodegradable trash detected");

        // Open plastic bin door for biodegradable trash
        for (pos_M = 160; pos_M >= 90; pos_M -= 1) {
            myservo_M.write(pos_M);
            delay(10); // Small delay for smooth movement
        }
        // Indicate biodegradable trash
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        analogWrite(redpin_M, 255);
        analogWrite(bluepin_M, 0);
        analogWrite(greenpin_M, 255);
        delay(5000);
        // Close plastic bin door for biodegradable trash
        for (pos_M = 90; pos_M <= 160; pos_M += 1) {
            myservo_M.write(pos_M);
            delay(50); // Small delay for smooth movement
        }
        // Turn off LED indication
        analogWrite(redpin_M, 0);
        analogWrite(bluepin_M, 0);
        analogWrite(greenpin_M, 0);
    } 
    else {
        // No biodegradable trash detected by either sensor
        // Check if non-biodegradable trash is detected
        if (sensor_read_plastic != 0 || sensor_read_plastic2 != 0) {
            // Non-biodegradable trash detected
            Serial.println("Non-biodegradable trash detected");

            // Open plastic bin door for non-biodegradable trash
            for (pos = 160; pos >= 90; pos -= 1) {
                myservo.write(pos);
                delay(10); // Small delay for smooth movement
            }
            // Indicate non-biodegradable trash
            digitalWrite(5, HIGH);
            digitalWrite(6, HIGH);
            digitalWrite(7, HIGH);
            analogWrite(redpin, 255);
            analogWrite(bluepin, 0);
            analogWrite(greenpin, 255);
            delay(5000);
            // Close plastic bin door for non-biodegradable trash
            for (pos = 90; pos <= 160; pos += 1) {
                myservo.write(pos);
                delay(50); // Small delay for smooth movement
            }
            // Turn off LED indication
            analogWrite(redpin, 0);
            analogWrite(bluepin, 0);
            analogWrite(greenpin, 0);
        }
    }

}

    
    
  //   int sensor_read_plastic=digitalRead(plasticsensor);
  //   int sensor_read_plastic2=digitalRead(plasticsensor2);
  //   // int sensor_read_metal=digitalRead(metalsensor);
  //   // int sensor_read_metaletal2=digitalRead(metalsensor_M);
  //   // int sensor_read_IR_plastic=digitalRead(IR_plastic);
  //   // int sensor_read_IR_metal=digitalRead(IR_metal);
  //   // Serial.println("plastic sensor");
  //   // Serial.println(sensor_read_plastic);
  //   // Serial.println("metal sensor");
  //   // Serial.println(sensor_read_metal);
  //   // Serial.println(sensor_read_metaletal2);
    
  //   ///Check if the trash bin is full

  // //   //plastic bin
  // //   if(sensor_read_IR_plastic==1){
  // //       analogWrite(redpin,255);
  // //       analogWrite(bluepin,0);
  // //       analogWrite(greenpin,0);
  // //       Serial.println("BASTA PLASTIC");
  // //   }
  // //  //metal bin
  // //  if(sensor_read_IR_metal==1){
  // //       analogWrite(redpin_M,255);
  // //       analogWrite(bluepin_M,0);
  // //       analogWrite(greenpin_M,0);
  // //       Serial.println("BASTA METAL");
  // //   }

  //   // Serial.println(sensor_read_plastic);
  //   // Serial.println(sensor_read_metal);
  //   // Serial.println(sensor_read_metaletal2);
  //   // Serial.println();

  //   // Serial.println(sensor_read_metal);
  //   //&&(sensor_read_metal!=1)
  //   //Plastic bin
  //   // Serial.println(sensor_read_metal);
  //   if((sensor_read_plastic!=0)){
  //       Serial.println("NON BIO");
  //       for (pos = 160; pos >= 90; pos -= 1) { // goes from 160 degrees to 0 degrees
  //           // in steps of 1 degree
  //           myservo.write(pos); // tell servo to go to position in variable 'pos'
  //           delay(1); // waits 1ms for the servo to reach the position
  //       }
  //       digitalWrite(5, HIGH);
  //       digitalWrite(6, HIGH);
  //       digitalWrite(7, HIGH);
  //       analogWrite(redpin,255);
  //       analogWrite(bluepin,0);
  //       analogWrite(greenpin,255);
  //       delay(2500);
  //       for (pos = 90; pos <= 160; pos += 1) { // goes from 90 degrees to 160 degrees
  //           myservo.write(pos); // tell servo to go to position in variable 'pos'
  //           delay(1); // waits 1ms for the servo to reach the position
    
  //       }
  //       analogWrite(redpin,0);
  //       analogWrite(bluepin,0);
  //       analogWrite(greenpin,0);
    
  //       myservo_M.write(pos_M); 
    
    
  //         analogWrite(redpin_M,255);
  //         analogWrite(bluepin_M,255);
  //         analogWrite(greenpin_M,255);
  //   }

  //   if ((sensor_read_plastic==0)) {
      
  //       Serial.println("BIO");

  //       for (pos_M = 160; pos_M >= 90; pos_M -= 1) { // goes from 160 degrees to 90 degrees
  //           // in steps of 1 degree
  //           myservo_M.write(pos_M); // tell servo to go to position in variable 'pos'
  //           delay(1); // waits 1ms for the servo to reach the position
  //       }
  //       digitalWrite(5, HIGH);
  //       digitalWrite(6, HIGH);
  //       digitalWrite(7, HIGH);
  //       analogWrite(redpin_M,255);
  //       analogWrite(bluepin_M,0);
  //       analogWrite(greenpin_M,255);
  //       delay(2500);
  //       for (pos_M = 90; pos_M <= 160; pos_M += 1) { // goes from 90 degrees to 160 degrees
  //           myservo_M.write(pos_M); // tell servo to go to position in variable 'pos'
  //           delay(1); // waits 1ms for the servo to reach the position
  //       }
  //       analogWrite(redpin_M,0);
  //       analogWrite(bluepin_M,0);
  //       analogWrite(greenpin_M,0);
    
  //       // keep the door close
  //       myservo.write(pos); 
    
  //       analogWrite(redpin,255);
  //       analogWrite(bluepin,255);
  //       analogWrite(greenpin,255);
  //   }
    
    
  //   // //metal bin
    
    
  //   // if(sensor_read_metaletal2==1){
  //   //     for (pos_M = 160; pos_M >= 90; pos_M -= 1) { // goes from 160 degrees to 90 degrees
  //   //         // in steps of 1 degree
  //   //         myservo_M.write(pos_M); // tell servo to go to position in variable 'pos'
  //   //         delay(1); // waits 1ms for the servo to reach the position
  //   //     }
  //   //     analogWrite(redpin_M,255);
  //   //     analogWrite(bluepin_M,0);
  //   //     analogWrite(greenpin_M,255);
  //   //     delay(2500);
  //   //     for (pos_M = 90; pos_M <= 160; pos_M += 1) { // goes from 90 degrees to 160 degrees
  //   //         myservo_M.write(pos_M); // tell servo to go to position in variable 'pos'
  //   //         delay(1); // waits 1ms for the servo to reach the position
  //   //     }
  //   //     analogWrite(redpin_M,0);
  //   //     analogWrite(bluepin_M,0);
  //   //     analogWrite(greenpin_M,0);
    
    
    
  //   // }
    
  //   // else{
  //   //     // keep the door close
  //   //     myservo_M.write(pos_M); 
    
    
  //   //     analogWrite(redpin_M,255);
  //   //     analogWrite(bluepin_M,255);
  //   //     analogWrite(greenpin_M,255);
    
  //   // }
    

