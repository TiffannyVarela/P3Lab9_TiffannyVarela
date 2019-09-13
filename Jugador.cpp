#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>  
#include <stdlib.h> 
#include <time.h>
#include <windows.h>
#include <process.h>
using namespace std;

#ifndef JUGADOR_CPP
#define JUGADOR_CPP

class Jugador{
	protected:
		string nombre;
		int dinero, vida, vida_max, nivel;
		bool vive;
		int espera;
		
		
		bool vive_vidas;
		int espera_vidas;
		
		bool vive_batalla;
		int espera_batalla;
		
	public:
		Jugador(){
			
		}
		
		
		Jugador(string nombre, int dinero, int vida, int vida_max, int nivel){
			this->nombre=nombre;
			this->dinero=dinero;
			this->vida=vida;
			this->vida_max=vida_max;
			this->nivel=nivel;
		}
		
		string getNombre(){
			return this->nombre;
		}
		
		int getDinero(){
			return this->dinero;
		}
		
		int getVida(){
			return this->vida;
		}
				
		int getVida_max(){
			return this->vida_max;
		}
				
		int getNivel(){
			return this->nivel;
		}
		
		void setDinero(int din){
			dinero=din;
		}
		
		void setVida(int vida){
			this->vida=vida;
		}
		
		void setVida_max(int vida_max){
			this->vida_max=vida_max;
		}
		
		void setNivel(int nivel){
			this->nivel=nivel;
		}
		
		~Jugador(){
		}
		
		
		
		
		
		
		
		
		void setVive(bool v){
			vive = v;
		}
		
		void setEspera(int e){
			espera = e;
		}
		
		void stop(){
			vive=false;
		}
		
		void run(){
			_beginthread(&Jugador::runner, 0, static_cast<void*>(this));
		}
		
		static void runner(void*o){
			static_cast<Jugador*>(o)->runnerEstatico();
		}
		
		void runnerEstatico(){
			int tiene = getDinero();
			//cout<<"Tiene "<<tiene<<endl;
			while(vive){
				cout<<endl;
				cout<<"+1 de Dinero!"<<endl;
				cout<<endl;
				setDinero(tiene+1);
				//cout<<"Tiene "<<tiene<<endl;
				Sleep(espera);
				if(!vive){
					_endthread();
				}
			}
		}
		
		
		
		
		void setVive_vidas(bool v_vidas){
			vive_vidas = v_vidas;
		}
		
		void setEspera_vidas(int e_vidas){
			espera_vidas = e_vidas;
		}
		
		void stop_vidas(){
			vive_vidas=false;
		}
		
		void run_vidas(){
			_beginthread(&Jugador::runner_vidas, 0, static_cast<void*>(this));
		}
		
		static void runner_vidas(void*o){
			static_cast<Jugador*>(o)->runnerEstatico_vidas();
		}
		
		void runnerEstatico_vidas(){
			while(vive_vidas){
				if(getVida()<getVida_max()){
					cout<<endl;
					cout<<"+1 de Vida!"<<endl;
					setVida(getVida()+1);
				}
				else{
					cout<<endl;
					cout<<"Vidas Completas"<<endl;
				}
				Sleep(espera_vidas);
				if(!vive_vidas){
					_endthread();
				}
			}
		}
		
		
		
		
		
		
		
		
		
		
		void setVive_batalla(bool v_batalla){
			vive_batalla = v_batalla;
		}
		
		void setEspera_batalla(int e_batalla){
			espera_batalla = e_batalla;
		}
		
		void stop_batalla(){
			vive_batalla=false;
		}
		
		void run_batalla(){
			_beginthread(&Jugador::runner_batalla, 0, static_cast<void*>(this));
		}
		
		static void runner_batalla(void*o){
			static_cast<Jugador*>(o)->runnerEstatico_batalla();
		}
		
		void runnerEstatico_batalla(){
			int vida_op;
			int opc_op;
			int opc=0;
			int ganadas=0;
			int num;
			srand (time(NULL));
			num = rand() % 99 + 1;
			vida_op = rand() % 4 + 1;
			cout<<"Num "<<num<<endl;
			if(num <=80){
				stop_vidas();
				stop();
				while(vive){
					do{
						cout<<endl;
						cout<<"BATALLA ENCONTRADA!"<<endl;
						cout<<"Vida Jugador: "<<getVida()<<endl;
						cout<<"Vida Oponente: "<<vida_op<<endl;
						cout<<"Opciones:"<<endl
						<<"1.-Piedra"<<endl
						<<"2.-Papel"<<endl
						<<"3.-Tijera"<<endl;
						cout<<"Ingrese una opcion: ";
						cin>>opc;
						opc_op = rand() % 3 + 1;
						cout<<"Opcion Oponente "<<opc_op<<endl;
						if(opc==2 && opc_op==1 || opc==3 && opc_op==2 || opc==1 && opc_op==3){
							cout<<"Gana Jugador"<<endl;
							ganadas++;
							vida_op--;
						}
						else if(opc_op==2 && opc==1 || opc_op==3 && opc==2 || opc_op==1 && opc==3){
							cout<<"Gana Oponente"<<endl;
							setVida(getVida()-1);
						}
						else{
							cout<<"Empate"<<endl;
						}
						
					}while(ganadas==getNivel() || getVida()==0 || vida_op==0);
					
					if(ganadas==getNivel() || vida_op==0){
						cout<<"Gana Jugador la Batalla "<<endl;
						setNivel(getNivel()+1);
						setVida_max(getVida_max()+1);
						setVive(true);
						setEspera(7000);
						run();
						setVive_vidas(true);
						setEspera_vidas(6000);
						run_vidas();
						_endthread();
					}
					else{
						cout<<"Gana Oponente la Batalla "<<endl;
						_endthread();
						system("exit");
					}
					Sleep(espera_batalla);
					if(!vive_batalla){
						_endthread();
					}
				}
			}
			else{
				Sleep(espera_batalla);
				if(!vive_batalla){
					setVive(true);
					setEspera(7000);
					run();
					setVive_vidas(true);
					setEspera_vidas(6000);
					_endthread();
				}
			}
		}
};

#endif
