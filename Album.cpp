#include "Album.hpp"
Album::Album() {

}
Album::Album(string nombres) {
    this->nombre = nombre;
}
Album::Album(string nombre,string artistaA,vector<Cancion*> canciones) {
    this->nombre = nombre;
    this->artistaA = artistaA;
    this->canciones = canciones;
}
string Album::getNombre(){
    return nombre;
}

void Album::setNombre(string nombre){
    this->nombre = nombre;
}

string Album::getArtistaA(){
    return artistaA;
}

void Album::setArtistaA(string artista){
    this->artistaA = artistaA;
}

Album::~Album() {
    for (int i = 0;i<canciones.size();i++) {
        delete canciones.at(i);
    }
    canciones.clear();
}

vector<Cancion*> Album::getCanciones(){
    return canciones;
}

void Album::agregarCancion(Cancion* cancion){
    canciones.push_back(cancion);
}
Album* Album::operator*(int a){
	Album* res = new Album();
	string nom = this->getNombre()+ " " + std::to_string(a) + " veces";
	for(int i = 0;i<a;i++){
		for(int j = 0;j<this->canciones.size();j++){
			res->getCanciones().push_back(this->canciones.at(j));
		}
	}
	res->setNombre(nom);
	return res;
}
Album* Album::operator+(Cancion* c){
	Album* res = new Album(this->nombre);
	this->canciones.push_back(c);
	return res;
}