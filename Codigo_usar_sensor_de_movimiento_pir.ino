byte sensorpir = 7;
byte led = 13;


void setup()
{
  pinMode(sensorpir,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}


void loop()
{
  
  if(digitalRead(sensorpir) == HIGH)
  {
    Serial.println("Detectado movimiento por el sensor PIR");
    digitalWrite(led,HIGH);
    delay(1000);
    digitalWrite(led,LOW);
    delay(500);
  }else{
    Serial.println("NO pir");
    digitalWrite(led,LOW);
    delay(1000);
    }
}
