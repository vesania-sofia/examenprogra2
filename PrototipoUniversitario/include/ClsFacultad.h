#include<string>
#include<iostream>

#ifndef CLSFACULTAD_H
#define CLSFACULTAD_H

using std::string;

class ClsFacultad
{
    public:
        ClsPuestos( int = 0, string = "", string = "");

        void mestablecerNumero( int) ;
        int mobtenerNumero() const;

        void mestablecerNombreF( string );
        string mobtenerNombreF() const;

        void mestablecerEstatus ( string );
        string mobtenerEstatus() const;


    protected:

    private:
        int m_iNumeroFacultad;
        char m_sNombreFacultad[ 20 ];
        char m_sNombreEstatus[ 20 ];


};



#endif // PUESTO_H
