#include <time.h>
#include <windows.h>
#include <process.h>
#include <iostream>
#include <stdio.h>  
#include <stdlib.h> 
#include <time.h> 

#ifndef HILO_CPP
#define HILO_CPP

using namespace std;

class Hilo_Batalla{
	private:
		bool vive;
		int espera;
		string texto;
		
		int num;
		srand (time(NULL));
		
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
			while(vive){
				//MessageBox(0, texto.c_str(), "Advertencia", MB_OK);
				num = rand() % 99 + 1;
				cout<<"Num "<<num<<endl;
				if(num <=80){
					
				}
				else{
				}
				Sleep(espera);
				if(!vive){
					_endthread();
				}
			}
		}
};

#endif

