//This is a simple door alarm project where if the distance between the ultrasonic and an object is less than 100 the buzzer goes off
//Distance can be changed as desired
//If there is no object within the distance range a blue LED is on else a red LED turns on 
  
//variables declaration and pin initialization
const int buzzer = 11;
const int echopin = 10;
const int trigpin = 9;
const int led = 7;
const int led1 = 6;
long duration;
int distance;

//setup
void setup(){
  //Pin mode setting 
  pinMode (trigpin, OUTPUT);
  pinMode (echopin, INPUT);
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  }

//Program control loop
 void loop(){
  //clear the trigpin
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  //settrippin high for 10ms
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  
  //taking readings from ultrasonic sensor
  duration = pulseIn(echopin, HIGH);
  //distance caluculation
  distance = duration*0.34/2;
  
  //buzzer loop
  if (distance<100){
    //red LED high
    digitalWrite(led, HIGH);
    //blue LED low 
    digitalWrite(led1, LOW);
    //Buzzer tone
    tone(buzzer, 100);
    delay(10);
  }
  else{
    //blue LED high
    digitalWrite(led1, HIGH);
    }
  
 //printing readings to the serial monitor
 Serial.print("Distance :");
 Serial.println(distance);
  }
