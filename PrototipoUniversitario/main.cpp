#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{

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
