#include<iostream>
/*
UNANSE!!!!!!!!!!!!!!!!!
https://meet.google.com/zzt-qufo-zba?authuser=1
*/
using namespace std;

template<typename T>
class Nodo
{
    public:
        T m_dato;
        Nodo<T> * m_sig;
        Nodo<T> * m_ant;
    public:
        Nodo(T d){
            m_dato = d; 
            m_sig = 0;
            m_ant = 0;
        } 
};

template<typename T>
class ListaCircularDoble{
    private:
        Nodo<T> * m_head;
        Nodo<T> * m_actual;
    public:
        ListaCircularDoble(){
            m_head=0;
            m_actual=0;
        }
        void push_back(T d){
            if(!m_head){
                m_head=new Nodo<T>(d);
                m_head->m_sig=m_head;
                m_head->m_ant=m_head;
                m_actual=m_head;
            }
            else{
                Nodo<T>*tmp=m_head;
                while(tmp->m_sig!=m_head){
                    tmp=tmp->m_sig;
                }
                tmp->m_sig=new Nodo<T>(d);
                tmp->m_sig->m_sig=m_head;
                tmp->m_sig->m_ant=tmp;
                m_head->m_ant=tmp->m_sig;
            }
        }
        void push_front(T d){
            if(!m_head){
                m_head=new Nodo<T>(d);
                m_head->m_sig=m_head;
                m_head->m_ant=m_head;
                m_actual=m_head;
            }
            else{
                Nodo<T>*tmp=new Nodo<T>(d);
                tmp->m_sig=m_head;
                tmp->m_ant=m_head->m_ant;
                m_head->m_ant->m_sig=tmp;
                m_head->m_ant=tmp;
                m_head=tmp;
            }
        }
        void insertar_p(int a, T p){
            if(!m_head){
                m_head=new Nodo<T>(p);
                m_head->m_sig=m_head;
                m_head->m_ant=m_head;
                m_actual=m_head;
                return;
            }
            int z=1;
            Nodo<T>*tmp=m_head;
            while(z<a){
                tmp=tmp->m_sig;
                z++;
            }
            cout<<z<<"--"<<endl;
            Nodo<T>*tmp2=new Nodo<T>(p);
            tmp->m_ant->m_sig=tmp2;
            tmp2->m_ant=tmp->m_ant;
            tmp->m_ant=tmp2;
            tmp2->m_sig=tmp;
            if(z==1){
                m_head=tmp2;
            }
        }
        void reinicio(){
            m_actual=m_head;
        }
        void imprimir(){
            if(!m_head){
                return;
            }
            cout<<m_actual->m_dato<<endl;
            m_actual=m_actual->m_sig;
        }
        void find(T d){
            if(!m_head){
                return;
            }
            Nodo<T>*tmp=m_head;
            int z=1;
            int m=0;
            if(d==tmp->m_dato){
                m++;
                cout<<"Dato: "<<tmp->m_dato<<", Posicion: "<<z<<endl;
            }
            while(tmp->m_sig!=m_head){
                tmp=tmp->m_sig;
                z++;
                if(d==tmp->m_dato){
                    m++;
                    cout<<"Dato: "<<tmp->m_dato<<", Posicion: "<<z<<endl;
                }
            }
            if(!m){
                cout<<"No se ha encontrado el dato"<<endl;
            }
        }
        void max(){
            if(!m_head){
                return;
            }
            Nodo<T>*tmp=m_head;
            T m=m_head->m_dato;
            if(m<tmp->m_dato){
                m=tmp->m_dato;
            }
            while(tmp->m_sig!=m_head){
                tmp=tmp->m_sig;
                if(m<tmp->m_dato){
                    m=tmp->m_dato;
                }
            }
            cout<<"El maximo es: "<<m<<endl;
        }
        void pares(){
            if(!m_head){
                return;
            }
            Nodo<T>*tmp=m_head;
            int pares=0;
            if(tmp->m_dato%2==0){
                pares++;
            }
            while(tmp->m_sig!=m_head){
                tmp=tmp->m_sig;
                if(tmp->m_dato%2==0){
                    pares++;
                }
            }
            cout<<"El numero de pares es: "<<pares<<endl;
        }
        /*
UNANSE!!!!!!!!!!!!!!!!!
https://meet.google.com/zzt-qufo-zba?authuser=1
*/
/*
UNANSE!!!!!!!!!!!!!!!!!
https://meet.google.com/zzt-qufo-zba?authuser=1
*/
/*
UNANSE!!!!!!!!!!!!!!!!!
https://meet.google.com/zzt-qufo-zba?authuser=1
*/
};
int main(){
    ListaCircularDoble<int> A;
    A.insertar_p(1,1);
    A.insertar_p(2,3);
    A.insertar_p(3,5);
    A.insertar_p(1,5);
    A.reinicio();
    for (int i=0; i<4; i++){
        A.imprimir();
    }
    A.find(5);
    A.max();
    A.pares();
    return 0;
}