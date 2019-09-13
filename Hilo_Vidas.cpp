#include <time.h>
#include <windows.h>
#include <process.h>
#include <iostream>
#include "Jugador.cpp"

#ifndef HILO_VIDAS_CPP
#define HILO_VIDAS_CPP

using namespace std;

class Hilo_Vidas{
	private:
		bool vive;
		int espera;
		string texto;
		Jugador* j;
		
	public:
		Hilo_Vidas(){
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
			_beginthread(&Hilo_Vidas::runner, 0, static_cast<void*>(this));
		}
		
		static void runner(void*o){
			static_cast<Hilo_Vidas*>(o)->runnerEstatico();
		}
		
		void runnerEstatico(){
			while(vive){
				if(j->getVida()<j->getVida_max()){
					cout<<"+1 de Vida!"<<endl;
					j->setVida(j->getVida()+1);
				}
				else{
					cout<<"Vidas Completas"<<endl;
				}
				Sleep(espera);
				if(!vive){
					_endthread();
					j->~Jugador();
				}
			}
		}
};

#endif

