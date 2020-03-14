//Defining the pins

#define pir 12

//The relay is connected to a light

#define relay 4

void setup() {
  pinMode(pir,INPUT);
  pinMode(relay,OUTPUT);
  Serial.begin(115200);
  digitalWrite(relay,HIGH);
}

void loop() {
  //Initializing variables to detect motion
  int zeros = 0;
  int ones = 0;
  //Taking reading from the sensor 10 times for accuracy
  for(int i=0;i<=10;i++)
  {
    int val = digitalRead(pir);
    delay(500);
    //If no detection, increment variable "zeros"
    if(val==0)
      zeros+=1;
    //If motion is detected, increment variable "ones"
    else
      ones+=1;
  }
  Serial.print(zeros);
  Serial.print("\t");
  Serial.print(ones);
  Serial.print("\n");
  //If motion has been detected more than once by the sensor, then turn on the light.
  if(ones>=1)
  {
    digitalWrite(relay,LOW);
  }
  else
  {
    digitalWrite(relay,HIGH);
  }
  delay(2000);
}
