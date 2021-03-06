#include "CSeriableList.h"

using namespace std;


int CSeriableList::getCLSID() {
    return CLSID_SeriableList;
    }

void CSeriableList::guardar(fstream& out) {

    out << this->getCLSID() << endl;
    out << this->sizeLista() << endl;

    CSeriableList::Iterador it;

    for(it = this->beginIt(); it != this->endIt(); ++it) {
        (*it)->guardar(out);
        }
    }

void CSeriableList::cargar(fstream& in) {
    int iTamanio;
    in >> iTamanio;

    for(int i = 0; i < iTamanio; i++) {
        int CLSID;

        in >> CLSID;
        CSeriable* p = Seriablefactory(CLSID);

        p->cargar(in);
        this->insertarFinal(p);

        }
    }

void CSeriableList::imprimir() {
    CSeriableList::Iterador it;

    for(it = this->beginIt(); it != this->endIt(); ++it) {
        (*it)->imprimir();
        }
    }
void CSeriableList::operator=(CSeriableList* myLest) {
    CSeriableList::Iterador it;
    for(it = myLest->beginIt(); it != myLest->endIt(); ++it) {
        this->insertarFinal((*it));
        }
    }
