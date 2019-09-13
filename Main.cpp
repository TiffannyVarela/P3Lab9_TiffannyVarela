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
	Jugador h;
	Hilo_Batalla hb;
	Hilo_Dinero hd;
	//Hilo_Vidas hv;
	
	cout<<"Ingresa tu Nombre: ";
	cin>>nombre;
	j = new Jugador(nombre, 0, 1, 3, 1);

	//hilo batalla
	h.setVive_batalla(true);
	h.setEspera(4000);
	h.run_batalla();
	
	//hilo dinero
	hd.setVive(true);
	hd.setEspera(7000);
	hd.run();
	//h.setVive(true);
	//h.setEspera(7000);
	//h.run();
	
	//hilo vidas
	h.setVive_vidas(true);
	h.setEspera_vidas(6000);
	h.run_vidas();
	//hv.setVive(true);
	//hv.setEspera(6000);
	//hv.run();
	do{
		cout<<"MENU"<<endl
			<<"1.-Ver Datos"<<endl
			<<"2.-Curar Punto de Vida <$1>"<<endl
			<<"3.-Salir"<<endl
			<<"Ingrese opcion: ";
			cin>>opc;
		switch(opc){
			
			case 1:
				cout<<"Nivel: ";
				cout<<j->getNivel()<<endl;
				cout<<"Dinero: ";
				cout<<j->getDinero()<<endl;
				cout<<"Vida: ";
				cout<<j->getVida()<<"/"<<j->getVida_max()<<endl;
				break;
				
			case 2:
				if(j->getDinero()>0 && j->getVida() < j->getVida_max()){
					cout<<"Vida Agregada"<<endl;
					j->setDinero(j->getDinero()-1);
					j->setVida(j->getVida()+1);
				}
				else{
					cout<<"Vidas Completas o Dinero Insuficiente"<<endl;
				}
				break;
				
			case 3:
				//cout<<"Enter para terminar"<<endl;
				//c=getch();
				j->~Jugador();
				h.stop();
				h.stop_vidas();
				h.stop_batalla();
				hd.stop();
				break;
		}
		
	}while(opc!=3);
	return 0;
}

