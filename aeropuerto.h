#ifndef AEROPUERTP_H
#define AEROPUERTP_H
#include "QString"
#include "conexion.h"

class Conexion;
class Aeropuerto
{
public:
    QString codigo;
    QString ciudad;
    int x,y;
    Aeropuerto *sgte;
    Conexion *ady;
    Aeropuerto();
    Aeropuerto(QString codigo, QString ciudad);
};

#endif // AEROPUERTP_H
