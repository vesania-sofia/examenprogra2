#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>

#include "ClsFacultad.h"

using namespace std;
int obtenerCodigoFacultad( const char * const );
void nuevaFacultad( fstream& );
void crearArchivoCreditoFacultad();
void mostrarLineaPantallaF(const ClsFacultad &);
void actualizarRegistroF(fstream&);
void mostrarLineaF( ostream&, const ClsFacultad & );
void imprimirRegistroF( fstream& );
void eliminarRegistroF( fstream& );
void escribirBitacoraFacultad(int, string);

int main()
{

int m_iNumeroFacultad=0;
char m_sNombreFacultad[ 0 ];
char m_sNombreEstatus[ 0 ];

    int imenuPrincipal;
   do
    {
	system("cls");

	cout<<"-----------------------------------------------"<<endl;
	cout<<"|---BIENVENIDO AL SISTEMA DE LA UNIVERSIDAD---|"<<endl;
	cout<<"-----------------------------------------------"<<endl;
	cout<<"1. CATALOGOS"<<endl;
	cout<<"2. PROCESOS"<<endl;
	cout<<"3. INFORMES"<<endl;
	cout<<"0. EXIT"<<endl;

	cout<<"-------------------------------"<<endl;
	cout<<"OPCIONES A ESCOGER :     [1/2/3/0]"<<endl;
	cout<<"-------------------------------"<<endl;
	cout<<"INGRESA TU OPCION : ";
    cin>>imenuPrincipal;

    switch(imenuPrincipal)
    {
    case 1:
        {
            int choice2;
            do
            {
                system("cls");
                //Menu segundo nivel
                cout<<"-------------------------------"<<endl;
                cout<<" |   SISTEMA DE CATALOGOS     |"<<endl;
                cout<<"-------------------------------"<<endl;
                cout<<"1. CRUD Facultad"<<endl;
                cout<<"2. CRUD Aulas"<<endl;
                cout<<"3. CRUD Carreras"<<endl;
                cout<<"4. CRUD Cursos"<<endl;
                cout<<"5. CRUD Sedes"<<endl;
                cout<<"0. Volver al menu principal"<<endl;

                cout<<"-------------------------------"<<endl;
                cout<<"Opcion a escoger:[1/2/3/0]"<<endl;
                cout<<"-------------------------------"<<endl;
                cout<<"Ingresa tu Opcion: ";
                cin>>choice2;
                //Menu segundo nivel
                switch(choice2)
                {
                  case 1:
                    {     int iseleccionMenuFacultad;
                        do
                        {
                            system("cls");
                            //archivoempleados
                            // abrir el archivo en modo de lectura y escritura
                            fstream archivoFacultad("registrosFacultad.dat", ios::in | ios::out | ios::binary);

                            // salir del programa si fstream no puede abrir el archivo
                            if ( !archivoFacultad ) {
                                cerr << "No se pudo abrir el archivo." << endl;
                                crearArchivoCreditoFacultad();
                                cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                exit ( 1 );

                               } // fin de instrucci�n if
                            //Menu tercer nivel
                            cout<<"-------------------------------"<<endl;
                            cout<<"|   SISTEMA GESTION FACULTAD  |"<<endl;
                            cout<<"-------------------------------"<<endl;
                            cout<<"1. Ingreso Facultad"<<endl;
                            cout<<"2. Modifica Facultad""<<endl;
                            cout<<"3. Imprimir Regisro de Facultades"<<endl;
                            cout<<"4. Borra Facultad""<<endl;
                            cout<<"0. Volver al menu superior"<<endl;

                            cout<<"-------------------------------"<<endl;
                            cout<<"Opcion a escoger:[1/2/3/4/0]"<<endl;
                            cout<<"------------------------------"<<endl;
                            cout<<"Ingresa tu Opcion: ";
                            cin>>iseleccionMenuFacultad;
                            //menu tercer nivel
                            switch(iseleccionMenuFacultad)
                            {
                            case 1:
                                {
                                    //agregando empleados
                                    system("cls");
                                    nuevaFacultad(archivoFacultad);
                                    accion="Facultad Creado";
                                    ofstream bitacora("bitacora.txt", ios::app | ios::out);
                                    if (!bitacora)
                                    {
                                        cerr << "No se pudo abrir el archivo." << endl;
                                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                        exit ( 3 );
                                    }

                                    bitacora<<left<<setw(8)<< "Codigo:" <<left<<setw(5)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                                    <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                                    <<left<<setw(5)<< "A�o:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                                    <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                                    bitacora.close();
                                }
                                break;
                            case 2:
                                {
                                    //Consultar
                                    system("cls");
                                    consultarRegistro(archivoEmpleados);
                                    getch();
                                    accion="Consulta empleados";
                                    ofstream bitacora("bitacora.txt", ios::app | ios::out);
                                    if (!bitacora)
                                    {
                                        cerr << "No se pudo abrir el archivo." << endl;
                                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                        exit ( 3 );
                                    }

                                    bitacora<<left<<setw(8)<< "Codigo:" <<left<<setw(5)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                                    <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                                    <<left<<setw(5)<< "A�o:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                                    <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                                    bitacora.close();
                                }
                                break;
                            case 3:
                                {
                                    actualizarRegistro(archivoEmpleados);
                                    accion="Modificacion Empleados";
                                    ofstream bitacora("bitacora.txt", ios::app | ios::out);
                                    if (!bitacora)
                                    {
                                        cerr << "No se pudo abrir el archivo." << endl;
                                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                        exit ( 3 );
                                    }

                                    bitacora<<left<<setw(8)<< "Codigo:" <<left<<setw(5)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                                    <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                                    <<left<<setw(5)<< "A�o:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                                    <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                                    bitacora.close();
                                }
                                break;
                            case 4:
                                {
                                    imprimirRegistro(archivoEmpleados);
                                    accion="Imprimir Empleados";
                                    ofstream bitacora("bitacora.txt", ios::app | ios::out);
                                    if (!bitacora)
                                    {
                                        cerr << "No se pudo abrir el archivo." << endl;
                                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                        exit ( 3 );
                                    }

                                    bitacora<<left<<setw(8)<< "Codigo:" <<left<<setw(5)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                                    <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                                    <<left<<setw(5)<< "A�o:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                                    <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                                    bitacora.close();
                                }
                                break;
                            case 5:
                                {
                                    eliminarRegistro(archivoEmpleados);
                                    accion="Eliminar Empleados";
                                    ofstream bitacora("bitacora.txt", ios::app | ios::out);
                                    if (!bitacora)
                                    {
                                        cerr << "No se pudo abrir el archivo." << endl;
                                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                        exit ( 3 );
                                    }

                                    bitacora<<left<<setw(8)<< "Codigo:" <<left<<setw(5)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                                    <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                                    <<left<<setw(5)<< "A�o:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                                    <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                                    bitacora.close();
                                }
                                break;
                            case 6:
                                {
                                    buscarEmpleado(archivoEmpleados);
                                    accion="Buscar Empleados";
                                    ofstream bitacora("bitacora.txt", ios::app | ios::out);
                                    if (!bitacora)
                                    {
                                        cerr << "No se pudo abrir el archivo." << endl;
                                        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                                        exit ( 3 );
                                    }

                                    bitacora<<left<<setw(8)<< "Codigo:" <<left<<setw(5)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                                    <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                                    <<left<<setw(5)<< "A�o:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                                    <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                                    bitacora.close();
                                }
                                break;
                            case 0:
                                break;
                            default:
                                cout<<"Opcion invalida...Por favor prueba otra vez..";
                                getch();
                            }
                        }while(iseleccionMenuEmpleados!= 0);

        }
        break;

    case 0:
        break;
    default:
        cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
        getch();
        break;

    }


    }while(imenuPrincipal!= 0);

}

void nuevoFacultad( fstream &insertarEnArchivoFacultad )
{
   // obtener el n�mero de puesto a crear
   int m_iNumeroFacultad = obtenerCuentaFacultad( "Escriba el nuevo numero de facultad" );

   // desplazar el apuntador de posici�n del archivo hasta el registro correcto en el archivo
   insertarEnArchivoFacultad.seekg(
      ( m_iNumeroFacultad - 1 ) * sizeof( ClsFacultad ) );

   // leer el registro del archivo puesto
   ClsFacultad Facultades;
   insertarEnArchivoFacultad.read( reinterpret_cast< char * >( &Facultades ),
      sizeof( ClsFacultad ) );

   // crear el registro, si �ste no existe ya
   if ( Facultades.mobtenerNumero() == 0 ) {
///////////////////////////////////////////////////////////////////////
      char m_sNombreFacultad[ 20 ];
      char m_sNombreEstatus[ 20 ];



      // el usuario introducela informaci�n
      cout << "Escriba el nombre de la facultad: " << endl;
      cin >> setw( 20 ) >> m_sNombreFacultad;
      cout << "Escriba el estatus : " << endl;
      cin >> setw( 20 ) >> m_sNombreEstatus;


      // usar valores para llenar los valores de la cuenta
      Facultades.mestablecerNumero( m_iNumeroFacultad );
      Facultades.mestablecerNombreF( m_sNombreFacultad );
      Facultades.mestablecerEstatus(m_sNombreEstatus);


      //seguir agragando

      // desplazar el apuntador de posici�n de archivo hasta el registro correcto en el archivo
      insertarEnArchivoFacultad.seekp( ( m_iNumeroFacultad - 1 ) *
         sizeof( ClsFacultad ) );

      // insertar el registro en el archivo
      insertarEnArchivoFacultad.write(
         reinterpret_cast< const char * >( &Facultades ),
         sizeof( ClsFacultad ) );

   } // fin de instrucci�n if

   // mostrar error si la cuenta ya existe
   else
      cerr << "el numero#" << m_iNumeroFacultad
           << " ya contiene informacion." << endl;

} // fin de la funci�n nuevoRegistro
int obtenerCuentaFacultad( const char * const indicadorFacultad )
{
   int m_iNumeroFacultad;

   // obtener el valor del n�mero de cuenta
   do {
      cout << indicadorFacultad << " (1 - 100): ";
      cin >> m_iNumeroFacultad;

   } while ( m_iNumeroFacultad < 1 || m_iNumeroFacultad > 100 );

   return m_iNumeroFacultad;

} // fin de la funci�n obtenerCuenta
void crearArchivoCreditoFacultad()
{
    ofstream archivoFacultad("registrosFacultad.dat", ios::out | ios::binary);
    if(!archivoFacultad)
    {
        cerr<<"No se abrio el archivo"<<endl;
        exit(1);
    }
    ClsFacultad FacultadEnBlanco;
    for(int i=0; i<100; i++)
    {
        archivoFacultad.write(reinterpret_cast<const char * > (&FacultadEnBlanco), sizeof(ClsFacultad));
    }
}

