#include"Genero.hpp"

Genero::Genero(){
}
Genero::Genero(int idGenero,string nombre) {
    this->nombre = nombre;
}
Genero::~Genero() {

}
string Genero::getNombre(){
    return nombre;
}

int Genero::getIdGenero(){
	return idGenero;
}
void Genero::setIdGenero(int idGenero){
	this->idGenero=idGenero;
}
void Genero::setNombre(string nombre){
    this->nombre = nombre;
}