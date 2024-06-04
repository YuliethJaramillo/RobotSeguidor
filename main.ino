#include "robotLinea.h"
#include "Arduino.h"

robotLinea robotVelocista(10,9,7,6,11,2,3,4,5,150,150); //Se instancia un nuevo objeto


void setup(){

  robotVelocista.ini();
  Serial.begin(9600);

  
  Serial.println("Programa iniciado");
  
}

void loop(){
    
    robotVelocista.estado();
}
