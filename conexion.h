#ifndef CONEXION_H
#define CONEXION_H
#include "QString"
#include "aeropuerto.h"

class Aeropuerto;
class Conexion
{
public:
    Aeropuerto *destino;//puntero al nodo de llegada
    Conexion *sgte;
    double costo;
    Conexion();
};

#endif // CONEXION_H
