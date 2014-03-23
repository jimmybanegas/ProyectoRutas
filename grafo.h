#ifndef GRAFO_H
#define GRAFO_H
#include "aeropuerto.h"
#include "conexion.h"
#include <iostream>
using namespace  std;

class Grafo
{
public:
    Aeropuerto *p;
    int cont;
    bool insertar_aeropuerto(QString codigo, QString ciudad, int x, int y);
    void agrega_conexion(Aeropuerto *aux, Aeropuerto *aux2, Conexion *nuevo);
    void insertar_conexion(QString ini, QString fin, double costo);
    void vaciar_conexiones(Aeropuerto *aux);
    void eliminar_aeropuerto();
    void eliminar_conexion();
    void mostrar_grafo();
    void mostrar_conexiones(QString ciudad);
    void llenarMatriz();
   // int matri[][];
    Aeropuerto *recuperar(int x, int y);
    Grafo();
};

#endif // GRAFO_H
