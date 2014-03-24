#include "grafo.h"

Grafo::Grafo()
{
    this->p=NULL;
    this->cont = 0;
    //ctor
}

bool Grafo::insertar_aeropuerto(QString codigo,QString ciudad,int x,int y)
{
        Aeropuerto *t,*nuevo = new Aeropuerto();

        nuevo->ciudad = ciudad;
        nuevo->codigo =codigo;
        nuevo->x = x;
        nuevo->y = y;
        nuevo->sgte = NULL;
        nuevo->ady=NULL;

        if(p==NULL)
         {
            p = nuevo;
            cont++;
            return true;
         }
        else
         {
            t = p;
            while(t->sgte!=NULL)
             {
                t = t->sgte;
              }
            t->sgte = nuevo;
            cont++;
            return true;
        }
         return false;
}

void Grafo::agrega_conexion(Aeropuerto *aux, Aeropuerto *aux2, Conexion *nuevo)
{
      Conexion *q;
      if(aux->ady==NULL)
      {   aux->ady=nuevo;
          nuevo->destino=aux2;
      }
      else
      {   q=aux->ady;
          while(q->sgte!=NULL)
              q=q->sgte;
          nuevo->destino=aux2;
          q->sgte=nuevo;
      }
}

void Grafo::insertar_conexion(QString ini, QString fin, double costo)
{
        Conexion *nuevo=new Conexion();
        nuevo->costo = costo;

        Aeropuerto *aux, *aux2;

        if(p==NULL)
         {
             //"GRAFO VACIO...!!!!";
             return;
         }
        nuevo->sgte=NULL;

        aux=p;
        aux2=p;
        while(aux2!=NULL)
        {
            if(aux2->ciudad==fin)
            {
                break;
            }

            aux2=aux2->sgte;
        }
        while(aux!=NULL)
        {
            if(aux->ciudad==ini)
            {
                agrega_conexion(aux,aux2, nuevo);
                return;
            }
            aux = aux->sgte;
        }
}

void Grafo::vaciar_conexiones(Aeropuerto *aux)
{
   Conexion *q,*r;
        q=aux->ady;
        while(q->sgte!=NULL)
        {
            r=q;
            q=q->sgte;
            delete(r);
        }
}

void Grafo::eliminar_aeropuerto()
{

}

void Grafo::eliminar_conexion()
{

}

void Grafo::mostrar_grafo()
{
        Aeropuerto *ptr;
        Conexion *ar;
        ptr=p;
        cout<<"AEROPUERTO|LISTA DE ADYACENCIA\n";
        while(ptr!=NULL)
        {
            cout<<"   "<<ptr->ciudad.toStdString()<<"|";
            if(ptr->ady!=NULL)
            {
                ar=ptr->ady;

                while(ar!=NULL)
                {
                  //  cout<<" "<<ar->destino->ciudad.toStdString();
                    cout<<" "<<ar->costo;
                    ar=ar->sgte;

                }

            }
            ptr=ptr->sgte;
            cout<<endl;
        }
}

void Grafo::mostrar_conexiones(QString ciudad)
{
        Aeropuerto *aux;
        Conexion *ar;      
        cout<<"MOSTRAR CONEXIONES DE AEROPUERTO\n";
        aux=p;
        while(aux!=NULL)
        {
            if(aux->ciudad==ciudad)
            {
                if(aux->ady==NULL)
                {   cout<<"EL AEROPUERTO NO TIENE CONEXIONESS...!!!!";
                    return;
                }
                else
                {
                    cout<<"AEROPUERTO|LISTA DE ADYACENCIA\n";
                    cout<<"   "<<aux->ciudad.toStdString()<<"|";
                    ar=aux->ady;

                    while(ar!=NULL)
                    {
                       // cout<<ar->destino->ciudad.toStdString()<<" "<<ar->costo<<" ";
                        cout<<ar->costo<<" ";
                        ar=ar->sgte;
                    }
                    cout<<endl;
                    return;
                }
            }
            else
            aux=aux->sgte;
        }
}

void Grafo::llenarMatriz()
{
    Aeropuerto *ptr;
    Conexion *ar;
    double matriz[cont][cont];
    for(int x=0;x<cont;x++)
    {
        for(int y=0;y<cont;y++)
        {
            if(x!=y)
             matriz[x][y]=1;
            else
              matriz[x][y]=0;
        }
    }

    for(int fila=0; fila<cont; fila++)
    {
        cout<<" "<<endl;
        for(int columna=0; columna<cont; columna++)
        {
         cout<<matriz[fila][columna]<<" ";
        }
    }

    int x = 0;

    ptr=p;
    while(ptr!=NULL)
    {
        int y = 0;
        if(ptr->ady!=NULL)
        {
            ar=ptr->ady;
            while(ar!=NULL)
            {
                matriz[x][y] = ar->costo;
                y++;
                ar=ar->sgte;

            }

        }
        ptr=ptr->sgte;

        x++;
    }

    for(int fila=0; fila<cont; fila++)
    {
        cout<<" "<<endl;
        for(int columna=0; columna<cont; columna++)
        {
                  cout<<matriz[fila][columna]<<" ";

        }
    }

}


Aeropuerto * Grafo::recuperar(int x, int y)
{
    Aeropuerto *ptr;
    ptr=p;

    if(p==NULL)
    cout<<"NULO"<<endl;

    while(ptr!=NULL)
    {
        if((((x>= ptr->x)&& (x<= ptr->x+20)) || ((x+20 >= ptr->x)&& (x+20 <= ptr->x+20))) &&
               (((y >= ptr->y) && (y <= ptr->y+20)) || ((y+20 >= ptr->y) && (y+20 <= ptr->y+20))))
            return ptr;

        ptr=ptr->sgte;
    }
    return ptr;
}

int * Grafo::recuperar2(QString ciudad)
{
    Aeropuerto *aux;
    aux=p;
    int cont = 0;
    while(aux!=NULL)
    {
        if(aux->ciudad==ciudad)
        {
            return cont;
        }
        else
        {
            aux=aux->sgte;
            cont++;
        }

    }
    return cont;
}

void Grafo::dtra(int Origen)
{

    int Aux[cont], VertInc[cont], Ver1, Ver2, Ind1, Ind2, Menor, Band,
    Origen;
    /* El arreglo VertInc se utiliza para guardar los vértices elegidos
    ➥por ser los de la distancia mínima. El arreglo Aux es un arreglo
    ➥lógico que indica si el nodo de la posición i ya fue incluido en
    ➥VertInc y de esta manera evitar ciclos. */
    for (Ind1= 0; Ind1 < cont; Ind1++)
    {
     Aux[Ind1]= 0;
     VertInc[Ind1]= 0;
    }
    cout<<"\n\n Ingrese vértice origen: ";
    cin>>Origen;
    Aux[Origen – 1]= 1;
    /* El arreglo donde se guardan las distancias mínimas del Origen a
    ➥los demás vértices se inicializa con los valores de la matriz de
    ➥adyacencia. */
    for (Ind1= 0; Ind1 < cont; Ind1++)
    DistMin[Ind1]= MatAdy[Origen][Ind1];
    for (Ind1= 0; Ind1<cont; Ind1++)
    {
    /* Se busca el vértice Ver1 en (Vertices - VertInc) tal que
    ➥DistMin[Ver1] sea el mínimo valor. Se usa el 999 como valor
    ➥inicial ya que es el elegido para indicar que no existe camino
    ➥entre dos vértices. */
    Menor= 999;
    for (Ind2= 1; Ind2 < cont; Ind2++)
    if (DistMin[Ind2] < Menor && !Aux[Ind2])
    {
    Ver1= Ind2;
    Menor= DistMin[Ind2];
    }
    /* Se incluye Ver1 a VertInc y se actualiza el arreglo Aux. */
    VertInc[Ind1]= Ver1;
    Aux[Ver1]= 1;
    /* Se busca la distancia mínima para cada vértice Ver2 en(Vertices - VertInc). */
    Ver2= 1;
    while (Ver2 < cont)
    {
    Band=0;
    Ind2= 1;
    while (Ind2 < cont && !Band)
    if (VertInc[Ind2] == Ver2)
    Band= 1;
    else
    Ind2++;
    if (!Band)
    DistMin[Ver2]=  Minimo (DistMin[Ver2],DistMin[Ver1] + MatAdy[Ver1][Ver2]);
    Ver2++;
    }
    }

}
