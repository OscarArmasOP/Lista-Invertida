#ifndef LISTAINVETIDA_H_INCLUDED
#define LISTAINVETIDA_H_INCLUDED

#include "CSeriableList.h"
#include "Seriable.h"

template<class T>
class ListaInvertida {
    protected:

        class NodoListaInvertida {
            protected:
                CSeriableList* myLista;
                string identificador;

                NodoListaInvertida* siguiente;
                NodoListaInvertida* anterior;
            public:
                void insertaSiguiente(string aux, CSeriableList *myLista);
                string eliminaSiguiente();

                friend class ListaInvertida;
                friend class CSeriableListInver;

            };

        class IteradorInvertido {
            protected:
                NodoListaInvertida* pActual;
            public:
                void operator = (IteradorInvertido&);
                bool operator != (IteradorInvertido&);
                bool operator == (IteradorInvertido&);
                IteradorInvertido& operator ++ (); ///Prefijo
                IteradorInvertido& operator -- ();
                string& operator * ();

                friend class ListaInvertida;
                friend class CSeriableListInver;
            };

        IteradorInvertido it;
        NodoListaInvertida inicio;
        NodoListaInvertida finalL;

    public:
        ListaInvertida();
        ~ListaInvertida();

        void insertarInicio(string aux, CSeriableList myLista);
        void insertarFinal(string aux, CSeriableList *myLista2);

        string eliminarInicio();
        string eliminarFinal();

        int sizeLista();

        bool isEmpty();

        void imprimir();

        void vacia();

        IteradorInvertido& beginIt();
        IteradorInvertido& endIt();

        CSeriableList* getLista(string aux);

        bool existe(string aux);

        void eliminarBusqueda(string aux);
    };

template<class T>
ListaInvertida<T>::ListaInvertida() {
    inicio.siguiente = &finalL;
    finalL.anterior = &inicio;
    inicio.anterior = nullptr;
    finalL.siguiente = nullptr;
    }

template<class T>
ListaInvertida<T>::~ListaInvertida() {
    vacia();
    }


template<class T>
void ListaInvertida<T>::NodoListaInvertida::insertaSiguiente(string aux, CSeriableList *myLista) {
    NodoListaInvertida* nuevo(new NodoListaInvertida);

    nuevo->identificador = aux;
    nuevo->myLista = myLista;

    nuevo->anterior = this;
    nuevo->siguiente = this->siguiente;
    this->siguiente = nuevo;
    nuevo->siguiente->anterior = nuevo;
    }

template<class T>
string ListaInvertida<T>::NodoListaInvertida::eliminaSiguiente() {
    string aux = this->siguiente->identificador;
    NodoListaInvertida* nodAux = this->siguiente;

    this->siguiente = this->siguiente->siguiente;
    this->siguiente->anterior = this;

    nodAux->myLista->vacia();

    delete nodAux;

    return aux;
    }

template<class T>
void ListaInvertida<T>::IteradorInvertido::operator=(IteradorInvertido& p) {
    this->pActual = p.pActual;
    }

template<class T>
bool ListaInvertida<T>::IteradorInvertido::operator!=(IteradorInvertido& p) {
    return this->pActual != p.pActual;
    }

template<class T>
bool ListaInvertida<T>::IteradorInvertido::operator==(IteradorInvertido& p) {
    return this->pActual == p.pActual;
    }

template<class T>
typename ListaInvertida<T>::IteradorInvertido& ListaInvertida<T>::IteradorInvertido::operator++() {
    this->pActual = this->pActual->siguiente;
    return (*this);
    }

template<class T>
typename ListaInvertida<T>::IteradorInvertido& ListaInvertida<T>::IteradorInvertido::operator--() {
    this->pActual = this->pActual->anterior;
    return (*this);
    }

template<class T>
string& ListaInvertida<T>::IteradorInvertido::operator*() {
    return this->pActual->identificador;
    }

template<class T>
void ListaInvertida<T>::insertarInicio(string aux, CSeriableList myLista) {
    inicio.insertaSiguiente(aux, myLista);
    }

template<class T>
void ListaInvertida<T>::insertarFinal(string aux, CSeriableList* myLista2) {
    finalL.anterior->insertaSiguiente(aux, myLista2);
    }

template<class T>
string ListaInvertida<T>::eliminarInicio() {
    return inicio.eliminaSiguiente();
    }

template<class T>
string ListaInvertida<T>::eliminarFinal() {
    return finalL.anterior->anterior->eliminaSiguiente();
    }

template<class T>
int ListaInvertida<T>::sizeLista() {
    int contador = 0;
    NodoListaInvertida* p = inicio.siguiente;

    while(p != &finalL) {
        contador++;
        p = p->siguiente;
        }

    return contador;
    }

template<class T>
bool ListaInvertida<T>::isEmpty() {
    if(inicio.siguiente == &finalL) {
        return true;
        }
    return false;
    }

template<class T>
void ListaInvertida<T>::imprimir() {
    NodoListaInvertida* p = inicio.siguiente;
    if(isEmpty()) {
        cout << "Lista vacia" << endl;
        return;
        }

    while(p != &finalL) {
        cout << p->identificador;
        cout << p->myLista << endl;
        p = p->siguiente;
        }
    }

template<class T>
void ListaInvertida<T>::vacia() {
    while(!isEmpty()) {
        inicio.eliminaSiguiente();
        }
    }

template<class T>
typename ListaInvertida<T>::IteradorInvertido& ListaInvertida<T>::beginIt() {
    it.pActual = inicio.siguiente;
    return it;
    }

template<class T>
typename ListaInvertida<T>::IteradorInvertido& ListaInvertida<T>::endIt() {
    it.pActual = &finalL;
    return it;
    }

template< class T>
bool ListaInvertida<T>::existe(string aux) {
    IteradorInvertido it;

    for(it = this->beginIt(); it != this->endIt(); ++it) {
        if((*it) == aux) {
            return true;
            }
        }
    return false;
    }

template<class T>
CSeriableList* ListaInvertida<T>::getLista(string aux) {
    IteradorInvertido it;

    for(it = this->beginIt(); it != this->endIt(); ++it) {
        if((*it) == aux) {
            return (it).pActual->myLista;
            }
        }
    }

template <class T>
void ListaInvertida<T>::eliminarBusqueda(string aux) {
    IteradorInvertido it;

    for(it = this->beginIt(); it != this->endIt(); ++it) {
        if((*it) == aux) {
            (it).pActual->anterior->eliminaSiguiente();
            }
        }
    }

#endif // LISTAINVETIDA_H_INCLUDED
