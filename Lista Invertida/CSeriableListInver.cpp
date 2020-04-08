#include "CSeriableListInver.h"

using namespace std;

int CSeriableListInver::getCLSID() {
    return CLSID_LISTA_INVERTIDA;
    }

void CSeriableListInver::guardar(fstream& out) {
    out << this->getCLSID() << endl;
    out << this->sizeLista() << endl;

    CSeriableListInver::IteradorInvertido it;

    for(it = this->beginIt(); it != this->endIt(); ++it) {
        out << (*it) << endl;
        }
    }

void CSeriableListInver::cargar(fstream& in) {

    }

void CSeriableListInver::imprimir() {
    NodoListaInvertida* p = inicio.siguiente;
    if(isEmpty()) {
        cout << "Lista vacia" << endl;
        return;
        }

    while(p != &finalL) {
        cout << p->identificador;

        cout << endl;
        p->myLista->imprimir();
        p = p->siguiente;
        }
    }
    void CSeriableListInver::guardarAl(fstream& out2)
    {
        CSeriableListInver::IteradorInvertido it;

    for(it = this->beginIt(); it != this->endIt(); ++it) {
        (it).pActual->myLista->guardar(out2);
        }
    }
