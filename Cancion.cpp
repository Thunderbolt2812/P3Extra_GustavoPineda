#include "Cancion.hpp"

Cancion::Cancion() {

}
Cancion::Cancion(string nombre, string artistaC, Genero* genero_c, string duracion) {
    this->nombre = nombre;
    this->artistaC = artistaC;
    this->genero_c = genero_c;
    this->duracion = duracion;
}
Cancion::~Cancion() {

}
string Cancion::getNombre(){
    return nombre;
}

void Cancion::setNombre(string nombre){
    this->nombre = nombre;
}

string Cancion::getArtistaC(){
    return artistaC;
}

void Cancion::setArtistaC(string artistaC){
    this->artistaC = artistaC;
}

Genero* Cancion::getGenero_c(){
    return genero_c;
}

void Cancion::setGenero_c(Genero* generoc){
    genero_c = generoc;
}

string Cancion::getDuracion(){
    return duracion;
}

void Cancion::setDuracion(string duracion){
    this->duracion = duracion;
}
