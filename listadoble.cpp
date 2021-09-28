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
    public:
        ListaCircularDoble(){
            m_head=0;
        }
        //INSERTAR PARTE FINAL
        void push_back_r(T d, Nodo<T>*tmp){
            if(tmp->m_sig!=m_head){
                push_back_r(d,tmp->m_sig);
            }
            else{
                tmp->m_sig=new Nodo<T>(d);
                tmp->m_sig->m_sig=m_head;
                tmp->m_sig->m_ant=tmp;
                m_head->m_ant=tmp->m_sig;
            }
        }
        void push_back_r(T d){
            if(!m_head){
                m_head=new Nodo<T>(d);
                m_head->m_sig=m_head;
                m_head->m_ant=m_head;
            }
            else{
                Nodo<T>*tmp=m_head;
                push_back_r(d, tmp);
            }
        }
        void push_back_i(T d){
            if(!m_head){
                m_head=new Nodo<T>(d);
                m_head->m_sig=m_head;
                m_head->m_ant=m_head;
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
        //INSERTAR PARTE FRONTAL
        void push_front_r(Nodo<T>*tmp){
            tmp->m_sig=m_head;
            tmp->m_ant=m_head->m_ant;
            m_head->m_ant->m_sig=tmp;
            m_head->m_ant=tmp;
            m_head=tmp;
        }
        void push_front_r(T d){
            if(!m_head){
                m_head=new Nodo<T>(d);
                m_head->m_sig=m_head;
                m_head->m_ant=m_head;
            }
            else{
                Nodo<T>*tmp=new Nodo<T>(d);
                push_front_r(tmp);
            }
        }
        void push_front_i(T d){
            if(!m_head){
                m_head=new Nodo<T>(d);
                m_head->m_sig=m_head;
                m_head->m_ant=m_head;
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
        //INSERTAR POR POSICION
        void insertar_p(int a, T p){
            if(!m_head){
                m_head=new Nodo<T>(p);
                m_head->m_sig=m_head;
                m_head->m_ant=m_head;
                return;
            }
            int z=1;
            Nodo<T>*tmp=m_head;
            while(z<a){
                tmp=tmp->m_sig;
                z++;
            }
            Nodo<T>*tmp2=new Nodo<T>(p);
            tmp->m_ant->m_sig=tmp2;
            tmp2->m_ant=tmp->m_ant;
            tmp->m_ant=tmp2;
            tmp2->m_sig=tmp;
            if(z==1){
                m_head=tmp2;
            }
        }
        //IMPRIMIR
        void imprimir_r(Nodo<T> *tmp){
            cout<<tmp->m_dato;
            if(tmp->m_sig!=m_head){
                cout<<" -- ";
                imprimir_r(tmp->m_sig);
            }
            else{
                cout<<endl;
            }
        }
        void imprimir_r(){
            if(!m_head){
                return;
            }
            Nodo<T>*tmp=m_head;
            imprimir_r(tmp);
        }
        void imprimir_i(){
            if(!m_head){
                return;
            }
            Nodo<T>*tmp=m_head;
            cout<<tmp->m_dato;
            while(tmp->m_sig!=m_head){
                tmp=tmp->m_sig;
                cout<<" -- "<<tmp->m_dato;
            }
            cout<<endl;
        }
        //BUSCAR
        void find_r(T d, Nodo<T> *tmp, int z, int &m){
            if(d==tmp->m_dato){
                cout<<"Dato: "<<tmp->m_dato<<", Posicion: "<<z<<endl;
                m++;
            }
            if(tmp->m_sig!=m_head){
                find_r(d,tmp->m_sig,z+1,m);
            }
        }
        void find_r(T d){
            if(!m_head){
                return;
            }
            Nodo<T>*tmp=m_head;
            int z=1;
            int m=0;
            find_r(d,tmp,z,m);
            if(m==0){
                cout<<"No se ha encontrado el dato"<<endl;
            }
        }
        void find_i(T d){
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
        //MAXIMO
        void max_r(T &m,Nodo<T> *tmp){
            if(m<tmp->m_dato){
                m=tmp->m_dato;
            }
            if(tmp->m_sig!=m_head){
                max_r(m,tmp->m_sig);
            }
        }
        void max_r(){
            if(!m_head){
                return;
            }
            Nodo<T>*tmp=m_head;
            T m=m_head->m_dato;
            max_r(m,tmp);
            cout<<"El maximo es: "<<m<<endl;
        }
        void max_i(){
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
        //PARES
        void pares_r(int &pares, Nodo<T> *tmp){
            if(tmp->m_dato%2==0){
                pares++;
            }
            if(tmp->m_sig!=m_head){
                pares_r(pares, tmp->m_sig);
            }
        }
        void pares_r(){
            if(!m_head){
                return;
            }
            Nodo<T>*tmp=m_head;
            int pares=0;
            pares_r(pares,tmp);
            cout<<"El numero de pares es: "<<pares<<endl;
        }
        void pares_i(){
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
    A.insertar_p(1,2);
    A.find_r(3);
    A.max_r();
    A.pares_r();
    A.imprimir_r();
    A.push_back_r(3);
    A.push_back_r(3);
    A.push_back_r(5);
    A.find_r(3);
    A.max_r();
    A.pares_r();
    A.imprimir_r();
    return 0;
}
