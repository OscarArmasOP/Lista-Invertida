#include "Seriable.h"

#include "CSeriableList.h"
#include "CSeriableListInver.h"


using namespace std;

CSeriable* Seriablefactory(int CLSID) {

    CSeriable *pSerializable = 0;

    switch(CLSID) {
        case CLSID_LISTA_INVERTIDA:
            pSerializable = new CSeriableListInver;
            break;
        case CLSID_SeriableList:
            pSerializable = new CSeriableList;
            break;
        }

    return pSerializable;

    }
