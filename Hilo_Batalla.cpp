#include <time.h>
#include <windows.h>
#include <process.h>
#include <iostream>
#include <stdio.h>  
#include <stdlib.h> 
#include <time.h> 
#include "Jugador.cpp"

using namespace std;
class Hilo_Dinero;
class Hilo_Vidas;

#ifndef HILO_BATALLA_CPP
#define HILO_BATALLA_CPP

#include "Hilo_Dinero.cpp"
#include "Hilo_Vidas.cpp"

class Hilo_Batalla{
	private:
		bool vive;
		int espera;
		string texto;
		
	public:
		Hilo_Batalla(){
		}
		
		void setVive(bool v){
			vive = v;
		}
		
		void setTexto(string t){
			texto = t;
		}
		
		void setEspera(int e){
			espera = e;
		}
		
		void stop(){
			vive=false;
		}
		
		void run(){
			_beginthread(&Hilo_Batalla::runner, 0, static_cast<void*>(this));
		}
		
		static void runner(void*o){
			static_cast<Hilo_Batalla*>(o)->runnerEstatico();
		}
		
		void runnerEstatico(){
			Jugador* j;
			int vida_op;
			int opc_op;
			int opc=0;
			int ganadas=0;
			int num;
			srand (time(NULL));
			num = rand() % 99 + 1;
			vida_op = rand() % 4 + 1;
			Hilo_Dinero hd;
			Hilo_Vidas hv;
			cout<<"Num "<<num<<endl;
			if(num <=80){
				hd.stop();
				hv.stop();
				while(vive){
					do{
						cout<<endl;
						cout<<"BATALLA ENCONTRADA!"<<endl;
						cout<<"Vida Jugador: "<<j->getVida()<<endl;
						cout<<"Vida Oponente: "<<vida_op<<endl;
						opc=menu();
						opc_op = rand() % 3 + 1;
						cout<<"Opcion Oponente "<<opc_op<<endl;
						if(opc==2 && opc_op==1 || opc==3 && opc_op==2 || opc==1 && opc_op==3){
							cout<<"Gana Jugador"<<endl;
							ganadas++;
							vida_op--;
						}
						else if(opc_op==2 && opc==1 || opc_op==3 && opc==2 || opc_op==1 && opc==3){
							cout<<"Gana Oponente"<<endl;
							j->setVida(j->getVida()-1);
						}
						else{
							cout<<"Empate"<<endl;
						}
						
					}while(ganadas==j->getNivel() || j->getVida()==0 || vida_op==0);
					
					if(ganadas==j->getNivel() || vida_op==0){
						cout<<"Gana Jugador la Batalla "<<endl;
						j->setNivel(j->getNivel()+1);
						j->setVida_max(j->getVida_max()+1);
						j->~Jugador();
						hd.setVive(true);
						hd.setEspera(7000);
						hv.setVive(true);
						hv.setEspera(6000);
						_endthread();
					}
					else{
						cout<<"Gana Oponente la Batalla "<<endl;
						j->~Jugador();
						_endthread();
						system("exit");
					}
					Sleep(espera);
					if(!vive){
						_endthread();
						j->~Jugador();
					}
				}
			/*	Sleep(espera);
				if(!vive){
					_endthread();
					j->~Jugador();
				}*/
			}
			else{
				Sleep(espera);
				if(!vive){
					_endthread();
					j->~Jugador();
				}
			}
		}
		
		int menu(){
			int opc=0;
			while (true){
				cout<<"Opciones:"<<endl
					<<"1.-Piedra"<<endl
					<<"2.-Papel"<<endl
					<<"3.-Tijera"<<endl;
					
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
};

#endif

