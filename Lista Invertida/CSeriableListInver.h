#ifndef CSERIABLELISTINVER_H_INCLUDED
#define CSERIABLELISTINVER_H_INCLUDED

#include "Seriable.h"
#include "ListaInvetida.h"

#define CLSID_LISTA_INVERTIDA 753

typedef ListaInvertida<CSeriable*> CSeriableObjectListInver;

class CSeriableListInver : public CSeriableObjectListInver, public CSeriable {
    public:
        virtual int getCLSID();
        virtual void guardar(fstream& out);
        virtual void cargar(fstream& in);
        virtual void imprimir();

        void guardarAl(fstream& out2);

    };

#endif // CSERIABLELISTINVER_H_INCLUDED
