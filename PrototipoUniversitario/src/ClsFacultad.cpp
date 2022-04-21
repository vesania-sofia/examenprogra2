#include "ClsFacultad.h"
#include<conio.h>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cstring>

ClsFacultad::ClsFacultad(int ivalorNumeroF, string svalorNombreFacultad, string svalorEstatus)
{
    mestablecerNumeroF(ivalorNumeroF);
    mestablecerNombreF(svalorNombreFacultad);
    mestablecerEstatus(svalorEstatus);
}

int ClsFacultad::mobtenerNumero() const
{
    return m_iNumeroFacultad;
}

void ClsFacultad::mestablecerNumeroF (int ivalorNumeroF)
{
    m_iNumeroFacultad = ivalorNumeroF;
}

string ClsFacultad::mobtenerNombreF() const
{
    return m_sNombreFacultad;
}


void ClsFacultad::mestablecerNombreF( string scadenaNombreF )
{

   const char *svalorNombreFacultad = scadenaNombreF.data();
   int ilongitud = strlen( svalorNombreFacultad );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sNombreFacultad, svalorNombreFacultad, ilongitud );


   m_sNombreFacultad[ ilongitud ] = '\0';

}

string ClsFacultad::mobtenerNombreEstatus() const
{
    return m_sNombreEstatus;
}


void ClsFacultad::mestablecerNombreEstatus( string scadenaNombreEstatus )
{

   const char *svalorNombreEstatus = scadenaNombreEstatus.data();
   int ilongitud = strlen( svalorNombreEstatus );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sNombreEstatus, svalorNombreEstatus, ilongitud );


   m_sNombreEstatus[ ilongitud ] = '\0';

}

