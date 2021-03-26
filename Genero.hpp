#ifndef GENERO_HPP
#define GENERO_HPP
#include<string>
#include<iostream>
using namespace std;
class Genero {
private:
	int idGenero;
	string nombre;
public:
	Genero();
	Genero(int,string);
	~Genero();
	int getIdGenero();
	void setIdGenero(int);
	string getNombre();
	void setNombre(string);

};
#endif