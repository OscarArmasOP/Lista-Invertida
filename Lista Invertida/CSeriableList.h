#ifndef CSERIABLELIST_H_INCLUDED
#define CSERIABLELIST_H_INCLUDED

#include "Seriable.h"
#include "Lista.h"

#include <iomanip>

#define CLSID_SeriableList 987

typedef Lista<CSeriable*> CSeriableObjectList;

class CSeriableList : public CSeriableObjectList, public CSeriable {
    public:
        virtual int getCLSID();
        virtual void guardar(fstream& out);
        virtual void cargar(fstream& in);
        virtual void imprimir();

        void operator = (CSeriableList*);

        friend ostream& operator << (ostream &out, CSeriableList &lest) {
            CSeriableList::Iterador it;
            for(it = lest.beginIt(); it != lest.endIt(); ++it) {
                out << (*it) << endl;
                }
            return out;
            }
    };


#endif // CSERIABLELIST_H_INCLUDED
