#include <iostream>

#include "CSeriableListInver.h"
#include "CSeriableList.h"
#include "CAlumno.h"

using namespace std;

int main() {
    int codigo, opc;
    char sexo; ///M,F
    string nombre, municipio;

    CSeriableListInver* myInverList = (new CSeriableListInver);

    fstream salida;
    fstream entrada;

    fstream salida2;
    fstream entrada2;

    int CLSID;
    entrada.open("listas.txt", ios_base::in);

    entrada >> CLSID;

    if(CLSID == CLSID_LISTA_INVERTIDA) {
        myInverList->cargar(entrada);

        myInverList->imprimir();
        system("pause");
        }
    entrada.close();
    do {
        system("cls");
        cout << "[1] Agregar Alumno" << endl;
        cout << "[2] Eliminar Lista de Municipio" << endl;
        cout << "[3] Mostrar" << endl;
        cout << "[0] Salir" << endl << endl;

        cout << "Elija su opcion: ";
        cin >> opc;
        cin.ignore();

        switch(opc) {
            case 1: {
                system("cls");
                CAlumno* myAl(new CAlumno);

                cout << "Ingrese el nombre: ";
                getline(cin, nombre);
                myAl->setNombre(nombre);

                cout << "Ingrese el sexo (M/F): ";
                cin >> sexo;
                myAl->setSexo(sexo);
                cin.ignore();

                cout << "Ingrese el nombre el municipio: ";
                getline(cin, municipio);
                myAl->setMunicipio(municipio);

                cout << "Ingrese el codigo : ";
                cin >> codigo;
                myAl->setCodigo(codigo);

                if(myInverList->isEmpty()) {
                    CSeriableList* myLista = new CSeriableList;
                    myLista->insertarFinal(myAl);

                    myInverList->insertarFinal(municipio, myLista);
                    }
                else if(myInverList->existe(municipio)) {
                    CSeriableList* myLista = myInverList->getLista(municipio);
                    myLista->insertarFinal(myAl);
                    }
                else {
                    CSeriableList* myLista = new CSeriableList;
                    myLista->insertarFinal(myAl);

                    myInverList->insertarFinal(municipio, myLista);
                    }

                system("pause");
                break;

                }
            case 2: {
                system("cls");
                if(myInverList->isEmpty()) {
                    cout << "Lista Vacia" << endl;
                    system("pause");
                    break;
                    }

                cout << "Ingrese el municipio a eliminar: ";
                cin >> municipio;

                if(myInverList->existe(municipio)) {
                    myInverList->eliminarBusqueda(municipio);
                    }
                else {
                    cout << "No existe ese municipio" << endl;
                    break;
                    }

                system("pause");
                break;
                }
            case 3:
                system("cls");

                myInverList->imprimir();

                system("pause");
                break;
            case 0:
                cout << "Gracias por ingresar" << endl;

                salida.open("listas.txt", ios_base::out);
                myInverList->guardar(salida);
                salida.close();

                salida2.open("alumnos.txt", ios_base::out);
                myInverList->guardarAl(salida2);
                salida2.close();

                break;
            default:
                cout << "No es una opcion valida" << endl;
                system("pause");
                break;
            }
        }
    while(opc != 0);
    return 0;
    }
