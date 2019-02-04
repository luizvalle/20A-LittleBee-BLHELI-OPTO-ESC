#include <Servo.h>

Servo myservo;
int vrx= A0;
int vry = A1;
int btn = 7;
int var = 0;

void setup() {

  myservo.attach (9);
  pinMode (btn, INPUT);
  
  Serial.begin (9600);

  delay (3000);

  Serial.println ("Do you wish to configure the throttle? (y or n)");

  while(!Serial.available()){}
  
  if (Serial.readString().equals ("y")){

   Serial.println ("Beginning throttle configuration...");
    
   Serial.read();
  
   myservo.writeMicroseconds (1500);

   delay (1000);

   Serial.println ("Full Throttle (enter anything to go to next step).");
 
   myservo.writeMicroseconds (2000);
  
   while (!Serial.available()){}
  
   Serial.println ("Low throttle configuration (enter anything to conclude throttle configuration).");
  
   Serial.read();
  
   myservo.writeMicroseconds (1500);
  
   while (!Serial.available()){}
  
   Serial.println ("Arming Complete");
  }
}


void loop() {

  var = analogRead (vry);

  if (var >= 750){

    Serial.println (var);
    myservo.writeMicroseconds (1500);
    
  } else {

    var = (-(var^2) * 250/(377^2)) + 2000;

    myservo.writeMicroseconds (var);
  }
}
