#include <time.h>
#include <windows.h>
#include <process.h>
#include <iostream>
#include "Jugador.cpp"

#ifndef HILO_DINERO_CPP
#define HILO_DINERO_CPP

using namespace std;

class Hilo_Dinero{
	private:
		bool vive;
		int espera;
		string texto;
		Jugador* j;
		
	public:
		Hilo_Dinero(){
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
			_beginthread(&Hilo_Dinero::runner, 0, static_cast<void*>(this));
		}
		
		static void runner(void*o){
			static_cast<Hilo_Dinero*>(o)->runnerEstatico();
		}
		
		void runnerEstatico(){
			while(vive){
				//MessageBox(0, texto.c_str(), "Advertencia", MB_OK);
				cout<<"+1 de Dinero!"<<endl;
				j->setDinero(j->getDinero()+1);
				Sleep(espera);
				if(!vive){
					_endthread();
					j->~Jugador();
				}
			}
		}
};

#endif

