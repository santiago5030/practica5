#include <iostream>
#include <fstream>
#include <math.h>
#include "particula.h"

using namespace std;
float aceleracionx(particula*, particula*,float);
float aceleraciony(particula*,particula*,float);
void agregar(string,float,float);
void agregar2(string,float,float);
float g=1;
int main()
{
    particula *p1,*p2;
    float px,py,vx,vy,masa;
    string nombre;
    for(int i=1; i<=2; i++){
        cout<<"\nIngrese la posicion inicial en x del cuerpo "<<i<<": ";cin>>px;
        cout<<"\nIngrese la posicion inicial en y del cuerpo "<<i<<": ";cin>>py;
        cout<<"\nIngrese la velocidad inicial en x del cuerpo "<<i<<": ";cin>>vx;
        cout<<"\nIngrese la velocidad inicial en y del cuerpo "<<i<<": ";cin>>vy;
        cout<<"\nIngrese la masa del cuerpo "<<i<<": ";cin>>masa;
        if(i==1){
            p1=new particula(px,py,vx,vy,masa);
        }
        if(i==2){
            p2= new particula(px,py,vx,vy,masa);
        }
    }
    cin.ignore();
    cout<<"\nIngrese el nombre del archivo donde desea almacenar los resultados: "; getline(cin,nombre);
    for(int i=0; i<1000; i++){
        p1->setax(aceleracionx(p1,p2,p2->getmasa()));
        p1->setay(aceleraciony(p1,p2,p2->getmasa()));
        p2->setax(aceleracionx(p2,p1,p1->getmasa()));
        p2->setay(aceleraciony(p2,p1,p1->getmasa()));

        p1->setx(p1->posicionx());
        p1->sety(p1->posiciony());
        p2->setx(p2->posicionx());
        p2->sety(p2->posiciony());

        p1->setvx(p1->velocidadx());
        p1->setvy(p1->velocidady());
        p2->setvx(p2->velocidadx());
        p2->setvy(p2->velocidady());

        cout<<"cuerpo 1: "<<p1->getx()<<" "<<p1->gety()<<endl;
        cout<<"cuerpo 2: "<<p2->getx()<<" "<<p2->gety()<<endl;
        agregar(nombre,p1->getx(),p1->gety());
        agregar2(nombre,p2->getx(),p2->gety());
    }

    return 0;
}
float aceleracionx(particula *part1,particula *part2,float masa){
    float a,d,angulo;
    d=sqrt(pow(part2->getx()-part1->getx(),2)+ pow(part2->gety()-part1->gety(),2));
    angulo=atan2(part2->gety()-part1->gety(),part2->getx()-part1->getx());
    a=(g*masa/pow(d,2))*cos(angulo);
    return a;
}
float aceleraciony(particula *part1,particula *part2,float masa){
    float a,d,angulo;
    d=sqrt(pow(part2->getx()-part1->getx(),2)+ pow(part2->gety()-part1->gety(),2));
    angulo=atan2(part2->gety()-part1->gety(),part2->getx()-part1->getx());
    a=(g*masa/pow(d,2))*sin(angulo);
    return a;
}
void agregar(string nombre,float x,float y){
    ofstream archivo;
    archivo.open(nombre.c_str(), ios::app);
    if(archivo.fail()){
        cout<<"\nEl archivo no se abrio correctamente"<<endl;
        exit(1);
    }
    archivo<< x<<"  "<<y<<"  ";
    archivo.close();
}
void agregar2(string nombre,float x,float y){
    ofstream archivo;
    archivo.open(nombre.c_str(), ios::app);
    if(archivo.fail()){
        cout<<"\nEl archivo no se abrio correctamente"<<endl;
        exit(1);
    }
    archivo<< x<<"  "<<y<<'\n';
    archivo.close();
}
