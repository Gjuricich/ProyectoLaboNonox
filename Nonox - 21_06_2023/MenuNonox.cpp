#include <iostream>
using namespace std;
#include "MenuNonox.h"

void Menu::mostrar(){


      int opcion;

      do{

            cout<<"----------------------------   Menu  ---------------------------"<<endl;
            cout<<"1- Juego nuevo"<<endl;
            cout<<"2- Reglas de juego "<<endl;
            cout<<"3- Puntaje"<<endl;
            cout<<"4- Créditos"<<endl;
            cout<<"0 - Salir"<<endl;
            cin>>opcion;


            switch(opcion){

        case 1:
            //_admin.juegoNuevo();
            system("cls");

            break;

        case 2:
            system("cls");

            break;

        case 3:
            system("cls");

            break;

        case 4:
            system("cls");
            break;

        case 5:
            system("cls");
            break;

        case 0:
            cout<<"Desea Salir? Para confirmar presione 1, de lo contrario cualquier tecla"<<endl;
            int aux;
            cin>>aux;
            if(aux==1){
                return;
            }
            break;



            }



    }while(opcion!=0);





}
