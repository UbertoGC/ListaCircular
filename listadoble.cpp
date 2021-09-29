#include<iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

template<typename T>
class Nodo
{
    public:
        T m_dato;
        int rep;
        Nodo<T> * m_sig;
        Nodo<T> * m_ant;
    public:
        Nodo(T d){
            rep=1;
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
        //CONTAR REPETICIONES
        void rep_count(T p){
            Nodo<T> *tmp=m_head;
            int m=0;
            if(p==tmp->m_dato){
                m++;
            }
            while(tmp->m_sig!=m_head){
                tmp=tmp->m_sig;
                if(p==tmp->m_dato){
                    m++;
                }
            }
            tmp=m_head;
            if(p==tmp->m_dato){
                tmp->rep=m;
            }
            while(tmp->m_sig!=m_head){
                tmp=tmp->m_sig;
                if(p==tmp->m_dato){
                    tmp->rep=m;
                }
            }
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
                //Repeticiones
                rep_count(d);
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
                //Repeticiones
                rep_count(d);
            }
        }
        //INSERTAR PARTE FRONTAL
        void push_front_r(T d, Nodo<T>*tmp){
            if(tmp->m_sig!=m_head){
                push_front_r(d,tmp->m_sig);
            }
            else{
                tmp->m_sig=new Nodo<T>(d);
                tmp->m_sig->m_sig=m_head;
                tmp->m_sig->m_ant=tmp;
                m_head->m_ant=tmp->m_sig;
                m_head=tmp->m_sig;
                //Repeticiones
                rep_count(d);
            }
        }
        void push_front_r(T d){
            if(!m_head){
                m_head=new Nodo<T>(d);
                m_head->m_sig=m_head;
                m_head->m_ant=m_head;
            }
            else{
                Nodo<T>*tmp=m_head;
                push_front_r(d,tmp);
            }
        }
        void push_front_i(T d){
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
                m_head=tmp->m_sig;
                rep_count(d);
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
            //Repeticiones
            rep_count(p);
        }
        //INSERTAR DE FORMA ALFABETICA
        void add_alphabet(T d){
            if(!this->m_head) this->insertar_p(1,d);
            else{
                Nodo<T> * tmp = m_head;
                int pos = 1;
                int band=1;
                if(d<=tmp->m_dato){
                    insertar_p(pos,d);
                }
                else{
                    while(tmp->m_sig!=m_head){
                        pos++;
                        tmp=tmp->m_sig;
                        if(d<=tmp->m_dato){
                            band=0;
                            break;
                        }
                    }
                    if(band){
                        insertar_p(pos+1,d);
                    }
                    else{
                        insertar_p(pos,d);
                    }
                    
                }
                cout<<pos<<endl;
            }
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
        //IMPRIMIR
        void imprimir_r(Nodo<T> *tmp){
            cout<<tmp->m_dato;
            if(tmp->m_sig!=m_head){
                cout<<" ";
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
                cout<<" "<<tmp->m_dato;
            }
            cout<<endl;
        }
        //LEER TXT
        void leer(){
            ifstream archivo;
            archivo.open("blogdenotas.txt");
            if(archivo.fail()){
                cout<<"Error, archivo no encontrado"<<endl;
                return;
            }
            string m2;
            while(!archivo.eof()){
                archivo>>m2;
                this->push_back_i(m2);
            }
            Nodo<T>*tmp=m_head;
            T d=tmp->m_dato;
            rep_count(d);
            while(tmp->m_sig!=m_head){
                tmp=tmp->m_sig;
                d=tmp->m_dato;
                rep_count(d);
            }
            archivo.close();
        }
        //IMPRIMIR CON REPETICIONES
        void imprimir_rep(){
            if(!m_head){
                return;
            }
            Nodo<T>*tmp=m_head;
            cout<<tmp->m_dato;
            while(tmp->m_sig!=m_head){
                tmp=tmp->m_sig;
                cout<<" "<<tmp->m_dato;
            }
            cout<<endl;
            tmp=m_head;
            cout<<tmp->rep;
            while(tmp->m_sig!=m_head){
                tmp=tmp->m_sig;
                cout<<" "<<tmp->rep;
            }
            cout<<endl;
        }
//MENU
};
int main(){
    ListaCircularDoble<string> A;
    A.leer();
    A.imprimir_rep();
    return 0;
}