#include <iostream>
#include <string>
#include <string.h>
#include <CONIO.h>


#include "Jugador.cpp"
#include "Hilo_Batalla.cpp"
#include "Hilo_Dinero.cpp"
#include "Hilo_Vidas.cpp"

using namespace std;

int menu();

int main(){
	
	int opc =0;
	string nombre;
	Jugador* j;
	int c = getch;
	Hilo_Batalla hb;
	Hilo_Dinero hd;
	Hilo_Vidas hv;
	
	cout<<"Ingresa tu Nombre: ";
	cin>>nombre;
	j = new Jugador(nombre);
	
	do{
		
		switch(opc=menu()){
			//hilo batalla
			hb.setVive(true);
			hb.setEspera(10000);
			hb.run();
			
			//hilo dinero
			hd.setVive(true);
			hd.setEspera(7000);
			hd.run();
			
			//hilo vidas
			hv.setVive(true);
			hv.setEspera(6000);
			hv.run();
			
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
				hb.stop();
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
