#include "particula.h"

particula::particula(float x, float y, float vx, float vy, float masa)
{
    this->x=x;
    this->y=y;
    this->vx=vx;
    this->vy=vy;
    this->masa=masa;
    ax=0;
    ay=0;
    t=1;
}

void particula::setx(float x)
{
    this->x=x;
}

void particula::sety(float y)
{
    this->y=y;
}

void particula::setvx(float vx)
{
    this->vx=vx;
}

void particula::setvy(float vy)
{
    this->vy=vy;
}

void particula::setax(float ax)
{
    this->ax=ax;
}

void particula::setay(float ay)
{
    this->ay=ay;
}

float particula::getx()
{
    return x;
}

float particula::gety()
{
    return y;
}

float particula::getmasa()
{
    return masa;
}

float particula::posicionx()
{
    float px;
    px=x+(vx*t)+((ax*pow(t,2))/2);
    return px;
}

float particula::velocidadx()
{
    float velx;
    velx=vx+ax*t;
    return velx;
}

float particula::posiciony()
{
    float py;
    py=y+(vy*t)+((ay*pow(t,2))/2);
    return py;
}

float particula::velocidady()
{
    float vely;
    vely=vy+ay*t;
    return vely;
}
