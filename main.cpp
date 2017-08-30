#include <iostream>
using namespace std;

class Nodo
{
public:
    int valor;
    Nodo* nextRigth;
    Nodo* nextLeft;
    Nodo(int val){
        this->valor = val;
        nextLeft = NULL;
        nextRigth = NULL;
    }
    
};

class Arbol{
public:
    Nodo* inicio;
    Arbol(){
        inicio = 0;
    }



    void insertNodo(Nodo* nuevo){
        if(inicio == NULL)
        {
            inicio = nuevo;
        }
        else{
            Nodo* temp = inicio;
            while(temp!=NULL)
            {
                if(nuevo->valor < temp->valor){
                    if(temp->nextLeft == NULL){
                        temp->nextLeft = nuevo;
                        break;
                    }else{
                        temp = temp->nextLeft;
                    }
                }
                else if(nuevo->valor > temp->valor){
                    if(temp->nextRigth == NULL){
                        temp->nextRigth = nuevo;
                        break;
                    }else{
                        temp = temp->nextLeft;
                    }
                }
            }
            
        }
        
    }
    bool buscarValor(Nodo* busc ,int num){
        if(busc == NULL){
            return false;
        }
        else if(busc->valor == num){
            return true;
        }
        else{
            return num > busc->valor?buscarValor(busc->nextRigth,num):buscarValor(busc->nextLeft,num);
        }
        return false;
    }
};

int main()
{
    Arbol mi_arbol;
    mi_arbol.insertNodo(new Nodo(2));
    mi_arbol.insertNodo(new Nodo(1));
    string msg = mi_arbol.buscarValor(mi_arbol.inicio,1)?"true":"false"; 
    cout << msg;

    return 0;
}

