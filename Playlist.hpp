#pragma once
#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP
#include<iostream>
#include<vector>
#include"Cancion.hpp"
#include "Album.hpp"
#include "Genero.hpp"
using namespace std;
class Playlist {
private:
	string nombre;
	vector<Cancion*> canciones;
public:
	Playlist();
	Playlist(string);
	Playlist(string, vector<Cancion*>);
	~Playlist();
	string getNombre();
	vector<Cancion*> getCanciones();
	void setCanciones(vector<Cancion*>);
	void setNombre(string);
	Playlist* operator+(Cancion*);
	Playlist* operator+(Playlist*);
	Playlist* operator+(Album*);
	Playlist* operator-(Cancion*);
	Playlist* operator-(Genero*);
};
#endif