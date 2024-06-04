#ifndef robotLinea_h
#define robotLinea_h
#include "Arduino.h"



class robotLinea {
  private:

    int velocidadIzq;
    int velocidadDer;
    int velocidadMotorIZQ;
    int velocidadMotorDER;
    int si;
    int sd;
    int cen;
    int INI2;
    int INI3;
    int INI4;
    int INI5;
    
  public:
    robotLinea(uint8_t velocidadMotorIZQ,uint8_t velocidadMotorDER,uint8_t si,uint8_t sd,uint8_t cen,uint8_t INI2,uint8_t INI3,uint8_t INI4,uint8_t INI5, int velocidadIzq,int velocidadDer);
    void estado();
    void correr();
    void giro_izquierda();
    void giro_derecha();
    void parar();
    void ini();
};

#endif
