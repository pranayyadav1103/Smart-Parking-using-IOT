#include <Servo.h>
Servo s1;  
int val = 0 ;  
int IRPin1= 3;
int IRPin2= 4;
int IRPin3= 5;
void setup() {
  Serial.begin(9600);
   pinMode(2,INPUT);
   s1.attach(9); 
   s1.write(0);
  pinMode(IRPin1, INPUT);
  pinMode(IRPin2, INPUT);
  pinMode(IRPin3, INPUT);
  Serial.print("\t\t\tSMART PARKING SYSTEM USING IOT\n");
}
void loop() {
  int totalslots=3 ,filledslots=0,S1=0,S2=0,S3=0;  
  val = digitalRead(2);
  int IR1Value= digitalRead(IRPin1);
  int IR2Value= digitalRead(IRPin2);  
  int IR3Value= digitalRead(IRPin3);
  delay(10);
  if (IR1Value==LOW){ 
    filledslots+=1;
    S1=1;
  }
  if (IR2Value==LOW){
    filledslots+=1;   
    S2=1;   
  }
  if (IR3Value==LOW){ 
    filledslots+=1;
    S3=1;
  }
  if(val == 1 || filledslots == totalslots)  
   {  
   s1.write(0);
   }  
  else 
   {
    s1.write(90); 
    Serial.print("\n\t\t\tA Vehicle has Entered\n");
    delay(2000);
   }  
  Serial.print("\nTotal Empty Slots are:\t");
  Serial.print(totalslots-filledslots);  
  delay(1000);  
  Serial.print("\t\t\tEmpty Slots are:\t");
  if (S1==0){
    Serial.print("A\t");
  }
  if (S2==0){
    Serial.print("B\t");
  }
  if (S3==0){
    Serial.print("C\t");
  }
  if (filledslots == totalslots){
    Serial.print("Sorry No Slots\t");
  }
  delay(3000);
}
