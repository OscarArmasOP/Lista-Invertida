#ifndef CALUMNO_H_INCLUDED
#define CALUMNO_H_INCLUDED

#include <string>

#include "Seriable.h"

#define CLSID_ALUMNO 456

class CAlumno : public CSeriable {
    private:
        std::string nombre;
        char sexo;
        std::string municipio;
        int codigo;

    public:
        int getCodigo();
        void setCodigo(const int& code);

        std::string getNombre();
        void setNombre(std::string& name);

        std::string getNunicipio();
        void setMunicipio(std::string& city);

        char getSexo();
        void setSexo(char& sex);

        virtual int getCLSID();
        virtual void guardar(fstream& out);
        virtual void cargar(fstream& in);

        virtual void imprimir();

        friend ostream& operator << (ostream &out, CAlumno &student) {
            out << student.getNombre() << endl;
            return out;
            }

            bool operator == (CAlumno&);
    };

#endif // CALUMNO_H_INCLUDED
