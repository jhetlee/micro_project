#include <SoftwareSerial.h>
#define RX 3
#define TX 4

int ledPin = 1;
int buttonPin = 0;
int buttonState = 0;
// the setup function runs once when you press reset or power the board

SoftwareSerial Serial(RX, TX);
String msg;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
 pinMode(buttonPin, INPUT);
 pinMode(ledPin, OUTPUT); 
 Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
 buttonState = digitalRead(buttonPin);
 while (Serial.available())
  { 
    delay(10); 
    char c = Serial.read(); 
    msg += c; 
  } 
  
 if(buttonState == HIGH){
  //send ng data
  
  digitalWrite(ledPin, HIGH);
  Serial.write("HIGH");
  delay(1000);
 }
 else{
  //wag mag transmit ng data
  digitalWrite(ledPin, LOW);
 }
}
