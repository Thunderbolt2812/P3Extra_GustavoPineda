#include"Playlist.hpp"

Playlist::Playlist() {

}
Playlist::Playlist(string nombre) {
	this->nombre = nombre;
}
Playlist::Playlist(string nombre, vector<Cancion*>canciones) {
	this->nombre = nombre;
	this->canciones = canciones;
}
Playlist::~Playlist() {

}
string Playlist::getNombre() {
	return nombre;
}

void Playlist::setNombre(string nombre) {
	this->nombre = nombre;
}

vector<Cancion*> Playlist::getCanciones() {
	return canciones;
}

void Playlist::setCanciones(vector<Cancion*>cancione) {
	this->canciones = cancione;
}

Playlist* Playlist::operator+(Cancion* c) {
	Playlist* retVal = new Playlist(this->nombre);
	this->canciones.push_back(c);
	retVal->setCanciones(this->canciones);
	return retVal;
}

Playlist* Playlist::operator+(Album* a) {
	Playlist* res = new Playlist(this->nombre);
	for(int i = 0; i<a->getCanciones().size(); i++) {
		Cancion* aux2 = a->getCanciones().at(i);
		this->canciones.push_back(aux2);
	}
	return res;
}
Playlist* Playlist::operator+(Playlist* p) {
	Playlist* res = new Playlist(this->nombre);
	for(int i = 0; i<p->getCanciones().size(); i++) {
		this->canciones.push_back(p->getCanciones().at(i));
	}
	return res;
}
Playlist* Playlist::operator-(Cancion* c) {
	Playlist* res = new Playlist(this->nombre);
	string nom = c->getNombre();
	if(!this->canciones.empty()) {
		for(int i = 0; i<this->canciones.size(); i++) {
			Cancion* aux2 = this->canciones.at(i);
			string nom2 = aux2->getNombre();
			if(nom==nom2) {
				this->canciones.erase(this->canciones.begin()+i);
			}
		}
	}else {
		cout<<"La playlist ya esta vacia"<<endl;
		return res;
	}
}
Playlist* Playlist::operator-(Genero* g) {
	Playlist* res;
	string nom = g->getNombre();
	for(int i = 0; i<this->canciones.size(); i++) {
		Cancion* aux2 = this->canciones.at(i);
		Genero* gen = aux2->getGenero_c();
		string nom2 = gen->getNombre();
		if(nom==nom2) {
			this->canciones.erase(this->canciones.begin()+1);
		}
	}
	return res;
}