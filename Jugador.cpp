#include <iostream>
#include <string>
#include <string.h>
using namespace std;

#ifndef JUGADOR_CPP
#define JUGADOR_CPP

class Jugador{
	protected:
		string nombre;
		int dinero, vida, vida_max, nivel;
		
	public:
		Jugador(){
		}
		
		Jugador(string nombre){
			this->nombre=nombre;
			dinero=0;
			vida=1;
			vida_max=3;
			nivel=1;
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
		
		void setDinero(int dinero){
			this->dinero=dinero;
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
};

#endif
