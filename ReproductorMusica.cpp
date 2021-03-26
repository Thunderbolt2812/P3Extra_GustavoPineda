#include "ReproductorMusica.hpp"
ReproductorMusica::ReproductorMusica() {

}
ReproductorMusica::ReproductorMusica(vector<Cancion*> canciones,vector<Genero*>generos,vector<Playlist*>playlists,vector<Album*>albumes) {
	this->canciones=canciones;
	this->generos=generos;
	this->playlists=playlists;
	this->albumes=albumes;
}
void ReproductorMusica::cargarArchivos(string CArchivo,string GArchivo,string PArchivo,string AArchivo) {
	cout<<"Canciones.bin"<<endl;
	ifstream CancionesBin;
	Cancion c;
	CancionesBin.open(CArchivo,ios::in|ios::binary);
	while(!CancionesBin.eof()) {
		CancionesBin.read(reinterpret_cast<char*>(&c),sizeof(Cancion));
		if(!CancionesBin.eof()) {
			cout << "Nombre: "<<c.getNombre()<<"', Artista: "<<c.getArtistaC()<<", Genero: "<<c.getGenero_c()->getNombre()<<", Duracion:"<<c.getDuracion()<<endl;
		}
	}
	CancionesBin.close();
	cout<<endl;
	cout<<"Generos.bin"<<endl;
	ifstream GenerosBin;
	Genero g;
	GenerosBin.open(GArchivo,ios::in|ios::binary);
	while(!GenerosBin.eof()) {
		GenerosBin.read(reinterpret_cast<char*>(&g),sizeof(Genero));
		if(!GenerosBin.eof()) {
			cout << "ID: "<<g.getIdGenero()<<"', Nombre: "<<g.getNombre()<<endl;
		}
	}
	GenerosBin.close();
	cout<<endl;
	cout<<"Playlists.bin"<<endl;
	ifstream PlaylistsBin;
	Playlist p;
	PlaylistsBin.open(PArchivo,ios::in|ios::binary);
	while(!PlaylistsBin.eof()) {
		PlaylistsBin.read(reinterpret_cast<char*>(&p),sizeof(Playlist));
		if(!PlaylistsBin.eof()) {
			cout << "Nombre: "<<p.getNombre()<<endl;
			for(int i = 0;i<p.getCanciones().size();i++){
				Cancion* ca = p.getCanciones().at(i);
				cout<<(i+1)<<") "<<	ca->getNombre()<<endl;
			}
		}
	}
	PlaylistsBin.close();
	cout<<endl;
	cout<<"Albumes.bin"<<endl;
	ifstream AlbumesBin;
	Album a;
	AlbumesBin.open(AArchivo,ios::in|ios::binary);
	while(!AlbumesBin.eof()) {
		AlbumesBin.read(reinterpret_cast<char*>(&a),sizeof(Album));
		if(!AlbumesBin.eof()) {
			cout << "Nombre: "<<a.getNombre()<<"Artista(s): "<<a.getArtistaA()<<endl;
			for(int i = 0;i<a.getCanciones().size();i++){
				Cancion* can = a.getCanciones().at(i);
				cout<<(i+1)<<") "<<	can->getNombre()<<endl;
			}
		}
	}
	PlaylistsBin.close();
	cout<<endl;
}
void ReproductorMusica::escribirCanciones(string Narchivo) {
	ofstream CancionesB;
	CancionesB.open(Narchivo, ios::binary | ios::out);
	for(int i = 0; i<this->canciones.size(); i++) {
		CancionesB.write((char*)this->canciones.at(i), sizeof(Cancion));
	}
	CancionesB.close();
}
void ReproductorMusica::escribirAlbumes(string Narchivo) {
	ofstream AlbumesB;
	AlbumesB.open(Narchivo, ios::binary | ios::out);
	for(int i = 0; i<this->albumes.size(); i++) {
		AlbumesB.write((char*)this->albumes.at(i), sizeof(Album));
	}
	AlbumesB.close();
}
void ReproductorMusica::escribirGeneros(string Narchivo) {
	ofstream GenerosB;
	GenerosB.open(Narchivo, ios::binary | ios::out);
	for(int i = 0; i<this->generos.size(); i++) {
		GenerosB.write((char*)this->generos.at(i), sizeof(Genero));
	}
	GenerosB.close();
}
void ReproductorMusica::escribirPlaylists(string Narchivo) {
	ofstream PlaylistsB;
	PlaylistsB.open(Narchivo, ios::binary | ios::out);
	for(int i = 0; i<this->playlists.size(); i++) {
		PlaylistsB.write((char*)this->playlists.at(i), sizeof(Playlist));
	}
	PlaylistsB.close();
}