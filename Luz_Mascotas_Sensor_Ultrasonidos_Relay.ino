/* Luz para mascotas en el comedor/bebedero
 * Sensor Ultrasonidos de proximidad (HC-SR04)
 * Francisco Javier Luengo Gutiérrez
 * Sevilla 17.11.2019
 * 
 * Al acercarse el animal a menos de 40 cm se encenderá ristra led conectada a corriente
 * y activada con un relay.

  Más info en: https://github.com/fraluegut
 
 HC-SR04 conexión:
  VCC al arduino 5v 
  GND al arduino GND
  Echo al Arduino pin 6 
  Trig al Arduino pin 7

 KY019 5V relay module
 */

#define Echo 6
#define Trig 7
long duracion, distancia;   
int relay = 10;

void setup() {                
  Serial.begin (9600);     // inicializa el puerto seria a 9600 baudios
  pinMode(Echo, INPUT);    // define el pin 6 como entrada (echo)
  pinMode(Trig, OUTPUT);   // define el pin 7 como salida  (trig)
  pinMode (relay, OUTPUT); // define relay (pin 10) como salida
}
  
void loop() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);   // genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  
  duracion = pulseIn(Echo, HIGH);
  distancia = (duracion/2) / 29;            // calcula la distancia en cm
  
  if (distancia >= 500 || distancia <= 0){  
    Serial.println("---");                  // Vacío
  }
  else {
    Serial.print(distancia);           // Indica distancia
    Serial.println("cm");              // texto "cm"
  }
  
   if (distancia <= 40){
    Serial.println("Mascota cerca.......");
    digitalWrite (relay, HIGH); // relay conduction;
    delay (1000);
  }
  else {
        digitalWrite (relay, LOW); // relay conduction;
  }
}
