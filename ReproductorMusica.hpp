#ifndef REPRODUCTORMUSICA_HPP
#define REPRODUCTORMUSICA_HPP
#include<string>
#include<iostream>
#include "Cancion.hpp"
#include "Genero.hpp"
#include "Playlist.hpp"
#include "Album.hpp"
using namespace std;
class ReproductorMusica {
	private:
		vector<Cancion*> prcanciones;
		vector<Genero*> generos;
		vector<Playlist*> playlists;
		vector<Album*> albumes;
	public:
		ReproductorMusica();
		ReproductorMusica(vector<Cancion*>,vector<Genero*>,vector<Playlist*>,vector<Album*>);
		void cargarArchivos(string,string,string,string);
		void escribirCanciones(string);
		void escribirAlbumes(string);
		void escribirGeneros(string);
		void escribirPlaylists(string);
};
#endif