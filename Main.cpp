#include <iostream>
#include <string>
#include <string.h>
#include <CONIO.h>


#include <stdio.h>  
#include <stdlib.h> 
#include <time.h> 


#include "Jugador.cpp"

using namespace std;

int menu();

int main(){
	
	int opc =0;
	string nombre;
	Jugador* j;
	int num;
	
	
	srand (time(NULL));
	num = rand() % 99 + 1;
	cout<<"Num "<<num<<endl;
	
	cout<<"Ingresa tu Nombre: ";
	cin>>nombre;
	j = new Jugador(nombre);
	
	do{
		
		switch(opc=menu()){
			case 1:
				cout<<"Nivel: ";
				cout<<j->getNivel()<<endl;
				cout<<"Dinero: ";
				cout<<j->getDinero()<<endl;
				cout<<"Vida: ";
				cout<<j->getVida()<<"/"<<j->getVida_max()<<endl;
				break;
				
			case 2:
				break;
				
			case 3:
				j->~Jugador();
				break;
		}
		
	}while(opc!=3);
	return 0;
}

int menu(){
	int opc=0;
	while (true){
		cout<<"MENU"<<endl
			<<"1.-Ver Datos"<<endl
			<<"2.-Curar Punto de Vida <$1>"<<endl
			<<"3.-Salir"<<endl;
			
		cout<<"Ingrese una opcion: ";
		cin>>opc;
		if(opc>=1 && opc<=3){
			return opc;
		}
		else{
			cout<<"Opcion elegida no es valida"<<endl;
		}
	}
	return 0;
}
