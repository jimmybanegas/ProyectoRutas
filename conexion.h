#ifndef CONEXION_H
#define CONEXION_H
#include "QString"

class Conexion
{
public:
    QString procede;
    QString destino;
    double costo;
    void agregarDestino(QString procede, QString destino, double costo);
    Conexion(QString procede, QString destino, double costo);
};

#endif // CONEXION_H
