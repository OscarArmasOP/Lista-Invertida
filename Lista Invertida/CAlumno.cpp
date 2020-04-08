#include "CAlumno.h"
#include <iostream>
#include <fstream>

using namespace std;

int CAlumno::getCodigo() {
    return codigo;
    }

void CAlumno::setCodigo(const int& code) {
    codigo = code;
    }

string CAlumno::getNombre() {
    return nombre;
    }

void CAlumno::setNombre(std::string& name) {
    nombre = name;
    }

string CAlumno::getNunicipio() {
    return municipio;
    }

void CAlumno::setMunicipio(std::string& city) {
    municipio = city;
    }

char CAlumno::getSexo() {
    return sexo;
    }

void CAlumno::setSexo(char& sex) {
    sexo = sex;
    }

int CAlumno::getCLSID() {
    return CLSID_ALUMNO;
    }

void CAlumno::guardar(fstream& out) {
    out << this->getCLSID() << endl;
    out << this->getNombre() << endl;
    out << this->getSexo() << endl;
    out << this->getNunicipio() << endl;
    out << this->getCodigo() << endl;

    }

void CAlumno::cargar(fstream& in) {
    string aux;
    char sexos;
    int intAux;
    in >> aux;
    this->setNombre(aux);

    in >> sexos;
    this->setSexo(sexos);

    in >> aux;
    this->setMunicipio(aux);

    in >> intAux;
    this->setCodigo(intAux);
    }

void CAlumno::imprimir() {
    cout << this->getNombre() << endl;
    if(this->getSexo() == 'F') {
        cout << "Mujer" << endl;
        }
    else if(this->getSexo() == 'M') {
        cout << "Hombre" << endl;
        }
    cout << this->getCodigo() << endl << endl;
    }

bool CAlumno::operator==(CAlumno& ca) {
    return this->getNombre() == ca.getNombre();
    }
