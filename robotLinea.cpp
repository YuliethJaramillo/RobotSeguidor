#include "robotLinea.h"
#include "Arduino.h"



int Valor_Izquierdo = 0;
int Valor_Derecho = 0;
int Valor_Centro = 0;
int contVueltas = 0;

robotLinea::robotLinea(uint8_t velocidadMotorIZQ, uint8_t velocidadMotorDER, uint8_t si, uint8_t sd,uint8_t cen, uint8_t INI2, uint8_t INI3, uint8_t INI4, uint8_t INI5, uint8_t velocidadIzq, uint8_t velocidadDer) {

  this->velocidadMotorIZQ = velocidadMotorIZQ;
  this->velocidadMotorDER = velocidadMotorDER;
  this->si = si;
  this->sd = sd;
  this->cen = cen;
  this->INI2=INI2;
  this->INI3=INI3;
  this->INI4=INI4;
  this->INI5=INI5;
  this->velocidadIzq = velocidadIzq; 
  this->velocidadDer = velocidadDer;
  
  }
  
void robotLinea::ini(){ 
  pinMode(si, INPUT);
  pinMode(sd, INPUT);
  pinMode(cen, INPUT);
  pinMode(INI2, OUTPUT);
  pinMode(INI3, OUTPUT);
  pinMode(INI4, OUTPUT);
  pinMode(INI5, OUTPUT);
  pinMode(velocidadMotorIZQ, OUTPUT);
  pinMode(velocidadMotorDER, OUTPUT);
  analogWrite(velocidadMotorIZQ, velocidadIzq);
  analogWrite(velocidadMotorDER, velocidadDer);



}



void robotLinea::correr() {
  digitalWrite(INI2, LOW);
  digitalWrite(INI3, HIGH);
  digitalWrite(INI4, LOW);
  digitalWrite(INI5, HIGH);
}

void robotLinea::giro_izquierda() {
  digitalWrite(INI2, LOW);
  digitalWrite(INI3, HIGH);
  digitalWrite(INI4, LOW);
  digitalWrite(INI5, LOW);
}

void robotLinea::giro_derecha() {
  digitalWrite(INI2, LOW);
  digitalWrite(INI3, LOW);
  digitalWrite(INI4, LOW);
  digitalWrite(INI5, HIGH);
}

void robotLinea::parar() {
  digitalWrite(INI2, LOW);
  digitalWrite(INI3, LOW);
  digitalWrite(INI4, LOW);
  digitalWrite(INI5, LOW);
}

void robotLinea::estado() {

   Valor_Izquierdo = digitalRead(si);
   Valor_Derecho = digitalRead(sd);
   Valor_Centro = digitalRead(cen);
  
if (Valor_Izquierdo == 1 && Valor_Derecho == 1 && Valor_Centro == 1){
  parar();
  contVueltas = 0;
}


if (Valor_Izquierdo ==1 && Valor_Centro == 1 && Valor_Derecho == 0){
  giro_izquierda();
  contVueltas = 0;
  
  }

if (Valor_Izquierdo ==0 && Valor_Centro == 0 && Valor_Derecho == 1){
  giro_derecha();
  contVueltas = 0;
  
  }
if (Valor_Izquierdo ==1 && Valor_Centro == 0 && Valor_Derecho == 0){
  giro_izquierda();
  contVueltas = 0;
  
  }
if (Valor_Derecho == 1 && Valor_Centro == 1 && Valor_Izquierdo == 0){

  giro_derecha();

  contVueltas = 0;
  }

if (Valor_Izquierdo ==0 && Valor_Centro == 0 && Valor_Derecho == 0){
      
     if  (contVueltas  <= 100){
          giro_derecha();
          contVueltas = contVueltas + 1;
          Serial.println(contVueltas);
          
         }      
        else {giro_izquierda();}
 } 


if (Valor_Izquierdo ==0 && Valor_Centro == 1 && Valor_Derecho == 0){
  correr();

  contVueltas = 0;
  
  }
}
