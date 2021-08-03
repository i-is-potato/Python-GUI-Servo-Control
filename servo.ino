#include <Servo.h>
Servo myservo;


String InByte;
int pos = 90;

void setup() {
  Serial.begin(9600);
  myservo.attach(9); 

}

void loop() {
  
if (pos < 180){
    if (Serial.available()>0){
    InByte=Serial.readStringUntil('\n');
    if (InByte == "r"){
      
      pos -=30;
      myservo.write(pos);
     
       if (pos <=0){
      
      pos=0;
      myservo.write(pos);
      Serial.print(pos);
      Serial.print("\n");

      }

      
      
    }
      else if (InByte == "l"){
      
      pos +=30;
      myservo.write(pos);
    
       if (pos >=180){
      
      pos=180;
      myservo.write(pos);
      Serial.print(pos);
      Serial.print("\n");

    }

      
      
    }
       else if (InByte == "R"){
   
      pos =90;
      myservo.write(pos);

       if (pos >=180){
      
      pos=180;
      myservo.write(pos);
      Serial.print(pos);
      Serial.print("\n");
    }

}
}
}
}

        
        

      
