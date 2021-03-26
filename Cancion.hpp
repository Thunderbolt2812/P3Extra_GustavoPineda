#pragma once
#ifndef CANCION_HPP
#define CANCION_HPP
#include<string>
#include<iostream>
#include"Genero.hpp"
using namespace std;
class Cancion {
private:
	string nombre;
	string artistaC;
	Genero* genero_c;
	string duracion;
public:
	Cancion();
	Cancion(string,string,Genero*,string);
	~Cancion();
	string getNombre();
	string getArtistaC();
	Genero* getGenero_c();
	string getDuracion();
	void setNombre(string);
	void setArtistaC(string);
	void setGenero_c(Genero*);
	void setDuracion(string);
};
#endif