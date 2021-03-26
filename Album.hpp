#ifndef ALBUM_HPP
#define ALBUM_HPP
#include<string>
#include<vector>
#include<iostream>
#include"Cancion.hpp"
using namespace std;
class Album {
private:
	string nombre;
	string artistaA;
	vector<Cancion*> canciones;
public:
	Album();
	Album(string,string,vector<Cancion*>);
	~Album();
	string getNombre();
	string getArtistaA();
	vector<Cancion*> getCanciones();
	void setNombre(string);
	void setArtistaA(string);
	void agregarCancion(Cancion*);
	Album* operator*(int);
	Album* operator+(Cancion*);
};
#endif