#include<iostream>
//Josue 973672214
//
//Moises 962936628
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

    public:
        Nodo(T d){
            m_dato = d; 
            m_sig = 0;
        } 
};
template<typename T>
class ListaCircular{
    private:
        Nodo<T> *head;
    public:

        ListaCircular(){
            this->head = 0;
        }
        void pushBack(T value){

            if(!this->head){
                this->head=new Nodo<T>(value);
                this->head->m_sig=this->head;
            }
            
            else{

                Nodo<T>*aux=this->head;

                while(aux->m_sig!=this->head){
                    aux=aux->m_sig;
                }

                aux->m_sig=new Nodo<T>(value);
                aux->m_sig->m_sig=this->head;
            
            }
            
        }

        void recursive_push_back(T data)
        {
            if (!this->head) return;
            recursive_push_back(T data, Node<T> * node);
        }

        void recursive_push_back(T data, Node<T>* node)
        {
            if (node->m_sig != this->head)
            {
                recursive_push_back(T data, Node<T>* node);
            }
            Nodo<T> * new_node = new Nodo<T>(data);
            node->m_sig = new Nodo<T>(value);
            node->m_sig->m_sig = this->head;
        }


        void push_front(T data)
        {
            if (!this->head)
            {
                this->head = new Nodo<T>(data);
                this->head->m_sig = this->head;
            }
            else
            {
                Nodo<T> * new_node = new Nodo<T>(data);
                Nodo<T> * aux = this->head;
                for(;aux->m_sig != this->head;aux = aux->m_sig);
                aux->m_sig = new_node;
                new_node->m_sig = this->head;
                this->head = new_node;
            }
            
        
        }

        void recursive_push_front(T data)
        {
            if (!this->head) return;
            recursive_push_front(T data, Node<T> * node);
        }

        void recursive_push_front(T data, Node<T>* node)
        {
            if (node->m_sig != this->head)
            {
                recursive_push_back(T data, Node<T>* node);
            }
            Nodo<T> * new_node = new Nodo<T>(data);
            node->m_sig = new_node;
            new_node->m_sig = this->head;
            this->head = new_node;
        }

        void insert(T data, int pos)
        {
            Nodo<T> * new_node = new Nodo<T>(data);
            Nodo<T> * aux = this->head;
            int c {0};
            while(c != pos)
            {
                aux = aux->m_sig;
                c++; 
            }
            new_node->m_sig = aux;
            aux->m_sig = new_node;
            if(c == 0)
            {
                this->head = new_node;
            }

            
        }
        void print(){

            if(!this->head){
                return;
            }
            Nodo<T>*aux=this->head->m_sig;
            cout<<this->head->m_dato << " - ";
            while(aux!=this->head){
                cout << aux->m_dato<<" - ";
                aux = aux->m_sig;

            }
            cout<<endl;
            
        }
        bool Find(T value){

            if(!this->head){
                return false;
            }

            Nodo<T>*aux=this->head->m_sig;
            while(aux!=this->head){
                if(aux->m_dato==value){
                    return true;
                }
                aux=aux->m_sig;
            }
            return (this->head->m_dato==value);

        }

        bool FindRecursive(Nodo<T>*aux,T num){
            if(!this->head){
                return false; 
            }
            else if(aux->m_dato==num){

            }
            
        }
        bool FindRecursive(){
            
        }

        
        int max()
        {
            Nodo<T>*aux = this->head;
            int max {0};
            for(;aux->m_sig != this->head;aux = aux->m_sig)
            {
                if (aux->m_dato > max)
                {
                    max = aux->m_dato;
                }
            }
            if(aux->m_dato > max)
            {
                max = aux->m_dato;
            }
            return max;

        }

        int recursive_max()
        {
            if(!this->head) return 0;
            int tmp {INT_MIN};
            if (this->head->m_dato > tmp)
            {
                tmp = this->head->m_dato;
            } 
            return recursive_max(this->head->m_sig,tmp); 
        }

        int recursive_max(Nodo<T> * node,int tmp)
        {

            if(node != this->head)
            {
                if (node->m_dato > tmp)
                {
                    tmp = node->m_dato;
                }
                return recursive_max(node->m_sig,tmp);
            }
            return tmp;
        }


};
int main(){

    ListaCircular<int>test;
    
    test.push_front(8);
    test.push_front(1);
    test.push_front(3);
    test.push_front(2);
    test.push_front(6);
    test.push_front(5);
    test.push_front(9);

    test.insert(2,1);
    test.insert(7,1);

    cout << test.max() << '\n';
    test.print();
    cout<<test.Find(7)<<" ";

    return 0;
}