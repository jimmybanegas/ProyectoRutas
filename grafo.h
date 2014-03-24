#ifndef GRAFO_H
#define GRAFO_H
#include "aeropuerto.h"
#include "conexion.h"
#include <iostream>    
#include <algorithm>
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
    int recuperar2(QString ciudad);
    void dtra(int origen);
    void mat2(Aeropuerto *origen, Aeropuerto *destino);
   // int matri[][];
    Aeropuerto *recuperar(int x, int y);
    Grafo();
};

#endif // GRAFO_H
