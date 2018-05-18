#ifndef PARTICULA_H
#define PARTICULA_H
#include <math.h>

class particula
{
private:
    float x,y,vx,vy,ax,ay,masa,t;
public:
    particula(float, float, float, float, float);
    void setx(float);
    void sety(float);
    void setvx(float);
    void setvy(float);
    void setax(float);
    void setay(float);
    float getx();
    float gety();
    float getmasa();
    float posicionx();
    float velocidadx();
    float posiciony();
    float velocidady();
};

#endif // PARTICULA_H
