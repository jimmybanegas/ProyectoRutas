#include "grafo.h"

Grafo::Grafo()
{
    this->p=NULL;
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
          cout<<"PRIMERA Conexion....!"<<endl;
      }
      else
      {   q=aux->ady;
          while(q->sgte!=NULL)
              q=q->sgte;
          nuevo->destino=aux2;
          cout<<"Conexion AGREGADA...!!!!"<<endl;
      }
}

void Grafo::insertar_conexion(QString ini, QString fin, double costo)
{
       // char ini, fin;
        Conexion *nuevo=new Conexion();
        nuevo->costo = costo;

        Aeropuerto *aux, *aux2;

        if(p==NULL)
         {
             cout<<"GRAFO VACIO...!!!!";
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
      /* char var;
        Aeropuerto *aux,*ant;
        aux=p;
        cout<<"ELIMINAR UN Aeropuerto\n";
        if(p==NULL)
         {
             cout<<"GRAFO VACIO...!!!!";
             return;
         }
        cout<<"INGRESE NOMBRE DE VARIABLE:";
        cin>>var;

        while(aux!=NULL)
        {
            if(aux->nombre==var)
            {
                if(aux->ady!=NULL)
                    vaciar_conexions(aux);

                if(aux==p)
                {

                        p=p->sgte;
                        delete(aux);
                        cout<<"Aeropuerto ELIMINADO...!!!!";
                        return;
                }
                else
                {
                    ant->sgte = aux->sgte;
                    delete(aux);
                    cout<<"Aeropuerto ELIMINADO...!!!!";
                    return;
                }
            }
            else
            {
                ant=aux;
                aux=aux->sgte;
             }
        }*/
}

void Grafo::eliminar_conexion()
{
       /* char ini, fin;
        Aeropuerto *aux, *aux2;
        Conexion *q,*r;
        cout<<"\n ELIMINAR Conexion\n";
        cout<<"INGRESE Aeropuerto DE INICIO:";
        cin>>ini;
        cout<<"INGRESE Aeropuerto FINAL:";
        cin>>fin;
        aux=p;
        aux2=p;
        while(aux2!=NULL)
        {
            if(aux2->nombre==fin)
            {
                break;
            }
            else
            aux2=aux2->sgte;
        }
         while(aux!=NULL)
        {
            if(aux->nombre==ini)
            {
                q=aux->ady;
                while(q!=NULL)
                {
                    if(q->destino==aux2)
                    {
                        if(q==aux->ady)
                            aux->ady=aux->ady->sgte;
                        else
                            r->sgte=q->sgte;
                        delete(q);
                        cout<<"Conexion  "<<aux->nombre<<"----->"<<aux2->nombre<<" ELIMINADA.....!!!!";
                        return;
                    }
                }
                r=q;
                q=q->sgte;
            }
            aux = aux->sgte;
         }*/
}

void Grafo::mostrar_grafo()
{
        Aeropuerto *ptr;
        Conexion *ar;
        ptr=p;
        cout<<"AEROPUERTO|LISTA DE ADYACENCIA\n";

        while(ptr!=NULL)
        {   cout<<"   "<<ptr->ciudad.toStdString()<<"|";
            if(ptr->ady!=NULL)
            {
                ar=ptr->ady;
                while(ar!=NULL)
                {   cout<<" "<<ar->destino->ciudad.toStdString();
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
       // QString var;
       /* cout<<"MOSTRAR CONEXIONES DE AEROPUERTO\n";
        cout<<"INGRESE AEROPUERTO:";
        cin>>var;*/
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
                        cout<<ar->destino->ciudad.toStdString()<<" ";
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

Aeropuerto * Grafo::recuperar(int x, int y)
{
    Aeropuerto *ptr;
    ptr=p;

    while(ptr!=NULL)
    {
        cout<<x<<" "<<ptr->x<<endl;
        cout<<x<<" "<<ptr->x<<endl;
        if((((x>= ptr->x)&& (x<= ptr->x+20)) || ((x+20 >= ptr->x)&& (x+20 <= ptr->x+20))) &&
               (((y >= ptr->y) && (y <= ptr->y+20)) || ((y+20 >= ptr->y) && (y+20 <= ptr->y+20))))
            return ptr;

        ptr=ptr->sgte;
    }
    return ptr;
}
