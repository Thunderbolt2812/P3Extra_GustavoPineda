#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Cancion.hpp"
#include "Album.hpp"
#include "Genero.hpp"
#include "Playlist.hpp"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int idG = 0;
int main(int argc, char** argv) {
	vector<Cancion*> canciones;
	vector<Genero*> generos;
	vector<Album*> albumes;
	vector<Playlist*> playlists;
	int opcion1 = 0;
	while(opcion1!=5) {
		cout << "Bem Vindo" << endl;
		cout<< "Ingrese una opcion"<<endl;
		cout<<"1) Mantenimiento"<<endl;
		cout<<"2) Operador *"<<endl;
		cout<<"3) Operador +"<<endl;
		cout<<"4) Operador -"<<endl;
		cout<<"5) Salir Corriendo"<<endl;
		cout << "Opcion: ";
		cin >> opcion1;
		switch(opcion1) {
			//MANTENIMIENTO
			case 1: {
				int opcion2 = 0;
				while(opcion2!=7) {
					cout<< "Ingrese una opcion"<<endl;
					cout<<"1) Agregar Cancion"<<endl;
					cout<<"2) Modificar una Cancion"<<endl;
					cout<<"3) Eliminar una Cancion"<<endl;
					cout<<"4) Listar Canciones"<<endl;
					cout<<"5) Listar Albumes"<<endl;
					cout<<"6) Listar Playlists"<<endl;
					cout<<"7) Regresar al Menu anterior"<<endl;
					cout<<"Opcion: ";
					cin>>opcion2;
					cout<<endl;
					switch(opcion2) {
						case 1: {
							string nombre,artista,duracion,genero;
							cout<<"Ingrese el nombre de la cancion: ";
							cin>>nombre;
							cout<<endl;
							cout<<"Ingrese el artista de la cancion: ";
							cin>>artista;
							cout<<endl;
							cout<<"Ingrese el genero de la cancion: ";
							cin>>genero;
							cout<<endl;
							Genero* g = new Genero(idG,genero);
							idG++;
							cout<<"Ingrese la duracion de la cancion en formato (2:30): ";
							cin>>duracion;
							cout<<endl;
							canciones.push_back(new Cancion(nombre,artista,g,duracion));
							generos.push_back(g);
							break;
						}
						case 2: {
							for(int i = 0; i<canciones.size(); i++) {
								Cancion* aux = canciones.at(i);
								cout<<(i+1)<<") "<<aux->getNombre();
							}
							int pos;
							cout<<"Ingrese el numero de posicion de la cancion que desea modificar: ";
							cin>>pos;
							while(pos>canciones.size()||pos<=0) {
								cout<<"La posicion que ingreso es invalida porfavor ingrese una posicion valida."<<endl;
								cout<<"Ingrese la posicion: ";
								cin>>pos;
							}
							int opcion3 = 0;
							while(opcion3!=5) {
								cout<< "Ingrese una opcion"<<endl;
								cout<<"1) Modificar Nombre"<<endl;
								cout<<"2) Modificar Artista"<<endl;
								cout<<"3) Modificar Genero"<<endl;
								cout<<"4) Modificar Duracion"<<endl;
								cout<<"5) Regresar al Menu anterior"<<endl;
								cout<<"Opcion: ";
								cin>>opcion3;
								cout<<endl;
								switch(opcion3) {
									case 1: {
										string nombre_n;
										cout<<"Ingrese el nuevo nombre de la cancion: ";
										cin>>nombre_n;
										Cancion* modi = canciones.at(pos-1);
										modi->setNombre(nombre_n);
										cout<<"Modificacion de nombre exitosa "<<endl;
										break;
									}
									case 2: {
										string artista_n;
										cout<<"Ingrese el nuevo artista de la cancion: ";
										cin>>artista_n;
										Cancion* modi = canciones.at(pos-1);
										modi->setArtistaC(artista_n);
										cout<<"Modificacion de artista exitosa "<<endl;
										cout<<endl;
										break;
									}
									case 3: {
										Genero* g2;
										bool existe = false;
										string genero_n;
										cout<<"Ingrese el nuevo genero de la cancion: ";
										cin>>genero_n;
										for(int i = 0; i<generos.size(); i++) {
											Genero* g1 = generos.at(i);
											string gn = g1->getNombre();
											if(gn==genero_n) {
												existe = true;
												g2 = g1;
											}
										}
										if(!existe) {
											Genero* nuevo_g = new Genero(idG,genero_n);
											generos.push_back(nuevo_g);
											Cancion* modi = canciones.at(pos-1);
											modi->setGenero_c(nuevo_g);
										} else {
											Cancion* modi = canciones.at(pos-1);
											modi->setGenero_c(g2);
										}
										cout<<"Modificacion de genero exitosa "<<endl;
										cout<<endl;
										break;
									}
									case 4: {
										string duracion_n;
										cout<<"Ingrese la nueva duracion de la cancion en formato (2:30): ";
										cin>>duracion_n;
										cout<<endl;
										Cancion* modi = canciones.at(pos-1);
										modi->setDuracion(duracion_n);
										cout<<"Modificacion de Duracion exitosa"<<endl;
										break;
									}
								}
							}
							break;
						}
						case 3: {
							for(int i = 0; i<canciones.size(); i++) {
								Cancion* aux = canciones.at(i);
								cout<<(i+1)<<") "<<aux->getNombre();
							}
							int pos;
							cout<<endl;
							cout<<"Ingrese el numero de posicion de la cancion que desea eliminar: ";
							cin>>pos;
							while(pos>canciones.size()||pos<=0) {
								cout<<"La posicion que ingreso es invalida porfavor ingrese una posicion valida."<<endl;
								cout<<"Ingrese la posicion: ";
								cin>>pos;
							}
							delete canciones.at(pos-1);
							canciones.erase(canciones.begin()+(pos-1));
							break;
						}
						case 4: {
							for(int i = 0; i<canciones.size(); i++) {
								Cancion* cancion = canciones.at(i);
								cout<<(i+1)<<") "<<	cancion->getNombre()<<endl;
							}
							break;
						}
						case 5: {
							if(!albumes.empty()) {
								for(int i = 0; i<albumes.size(); i++) {
									Album* A = albumes.at(i);
									string nombreA = A->getNombre();
									string artista = A->getArtistaA();
									cout<<"Nombre del Album: "<<nombreA<<setw(5)<<"Artista: "<<artista;
									for(int j =0; j<A->getCanciones().size(); j++) {
										Cancion* c = canciones.at(j);
										cout<<(j+1)<<") "<<c->getNombre()<<endl;
									}
									cout<<endl;
								}
							} else {
								cout<<"No hay albumes creados, porfavor cree un album primero";
								cout<<endl;
							}
							break;
						}
						case 6: {
							if(!playlists.empty()) {
								for(int i = 0; i<playlists.size(); i++) {
									Playlist* P = playlists.at(i);
									string nombreP = P->getNombre();
									cout<<"Nombre de la Playlist: "<<nombreP<<endl<<endl;
									for(int j =0; j<P->getCanciones().size(); j++) {
										Cancion* c = canciones.at(j);
										cout<<(j+1)<<") "<<c->getNombre()<<endl;
									}
									cout<<endl;
								}
							} else {
								cout<<"No hay playlists creadas, porfavor cree una primero";
								cout<<endl;
							}
							break;
						}
					}
					cout<<endl;
				}
				break;
			}
			//OPERADOR *
			case 2: {
				bool existe = false;
				string albumd;
				if(!albumes.empty()) {
					for(int i = 0; i<albumes.size(); i++) {
						Album* A = albumes.at(i);
						string nombreA = A->getNombre();
						string artista = A->getArtistaA();
						cout<<"Nombre del Album: "<<nombreA<<setw(5)<<"Artista: "<<artista;
						for(int j =0; j<A->getCanciones().size(); j++) {
							Cancion* c = canciones.at(j);
							cout<<(j+1)<<") "<<c->getNombre()<<endl;
						}
						cout<<endl;
					}
					string nombre;
					Album* ai;
					cout<<"Ingrese el nombre del Album que desea agregar varias veces: ";
					cin>>nombre;
					cout<<endl;
					for(int i =0; i<albumes.size(); i++) {
						Album* a = albumes.at(i);
						string nombre1 = a->getNombre();
						if(nombre == nombre1) {
							ai = a;
						}
					}
					int num;
					cout<<"Ingrese el numero de veces: ";
					cin>>num;
					//ai = ai * num;
					Playlist* p = new Playlist();
					p->setNombre(ai->getNombre()+to_string(num)+"veces");
					playlists.push_back(p);
				} else {
					cout<<"No hay almbumes creados, cree un album primero"<<endl;
				}
				break;
			}
			//OPERADOR +
			case 3: {
				int opcion4 = 0;
				while(opcion4!=5) {
					cout<< "Ingrese una opcion"<<endl;
					cout<<"1) Playlist + Cancion"<<endl;
					cout<<"2) Playlist + Album"<<endl;
					cout<<"3) Album + Cancion"<<endl;
					cout<<"4) Playlist + Playlist"<<endl;
					cout<<"5) Regresar al Menu anterior"<<endl;
					cout<<"Opcion: ";
					cin>>opcion4;
					cout<<endl;
					switch(opcion4) {
						//PLAYLIST + CANCION
						case 1: {
							int opcionA = 0;
							while(opcionA != 3) {
								cout<< "Ingrese una opcion"<<endl;
								cout<<"1) Crear Nueva Playlist"<<endl;
								cout<<"2) Usar Playlist Existente"<<endl;
								cout<<"3) Regresar al Menu anterior"<<endl;
								cout<<"Opcion: ";
								cin>>opcionA;
								cout<<endl;
								switch(opcionA) {
									case 1: {
										if(!canciones.empty()) {
											int cont = 1;
											char resp = 's';
											string nombrePlaylist;
											cout<<"Ingrese el nombre de la nueva playlist: ";
											cin>>nombrePlaylist;
											Playlist* Playl = new Playlist();
											Playl->setNombre(nombrePlaylist);
											cout<<endl;
											while(resp == 's'||resp == 'S') {
												for(int i = 0; i<canciones.size(); i++) {
													Cancion* cancion = canciones.at(i);
													cout<<(i+1)<<") "<<	cancion->getNombre()<<endl;
												}
												int pos;
												cout<<endl;
												cout<<"Ingrese la posicion de la cancion que desea agregar a su Playlist "<<nombrePlaylist<<": ";
												cin>>pos;
												while(pos-1<0||pos-1>canciones.size()) {
													cout<<"Posicion invalida, ingrese de nuevo: ";
													cin>>pos;
												}
												Playl->operator+(canciones.at(pos-1));
												if(cont == 1) {
													Playl->setNombre(nombrePlaylist);
													playlists.push_back(Playl);
												}
												cout<<endl;
												cont++;
												cout<<"Desea agregar otra cancion a la playlist? (S/N): ";
												cin>>resp;
											}
										} else {
											cout<<"No hay canciones, porfavor agregue almenos una cancion"<<endl;
										}
										break;
									}
									case 2: {
										if(!playlists.empty()) {
											char resp = 's';
											for(int i = 0; i<playlists.size(); i++) {
												Playlist* P = playlists.at(i);
												string nombreP = P->getNombre();
												cout<<(i+1)<<") Nombre de la Playlist: "<<nombreP<<endl<<endl;
												for(int j =0; j<P->getCanciones().size(); j++) {
													Cancion* c = canciones.at(j);
													cout<<(j+1)<<") "<<c->getNombre()<<endl;
												}
												cout<<endl;
											}
											cout<<endl;
											int pos1;
											cout<<"Ingrese la posicion de la playlist a la cual desea agregarle la cancion: ";
											cin>>pos1;
											while(pos1-1<0||pos1-1>playlists.size()) {
												cout<<"Posicion invalida, ingrese de nuevo: ";
												cin>>pos1;
											}
											while(resp == 's'||resp == 'S') {
												Playlist* Playl = playlists.at(pos1-1);
												for(int i = 0; i<canciones.size(); i++) {
													Cancion* cancion = canciones.at(i);
													cout<<(i+1)<<") "<<	cancion->getNombre()<<endl;
												}
												int pos;
												cout<<endl;
												cout<<"Ingrese la posicion de la cancion que desea agregar a su Playlist "<<Playl->getNombre()<<": ";
												cin>>pos;
												while(pos-1<0||pos-1>canciones.size()) {
													cout<<"Posicion invalida, ingrese de nuevo: ";
													cin>>pos;
												}
												Playl->operator+(canciones.at(pos-1));
												cout<<endl;
												cout<<"Desea agregar otra cancion a la playlist? (S/N): ";
												cin>>resp;
											}
										} else {
											cout<<"No hay playlists creadas porfavor cree almenos 1"<<endl;
										}
										break;
									}
								}
							}
							break;
						}
						//PLAYLIST+ALBUM
						case 2: {
							if(!playlists.empty()) {
								if(!albumes.empty()) {
									for(int i = 0; i<playlists.size(); i++) {
										Playlist* P = playlists.at(i);
										string nombreP = P->getNombre();
										cout<<"Nombre de la Playlist: "<<nombreP<<endl<<endl;
										for(int j =0; j<P->getCanciones().size(); j++) {
											Cancion* c = canciones.at(j);
											cout<<(j+1)<<") "<<c->getNombre()<<endl;
										}
										cout<<endl;
									}
									int pos;
									cout<<"Ingrese la posicion del playlist que desea usar: ";
									cin>>pos;
									while(pos-1<0||pos-1>playlists.size()) {
										cout<<"Posicion invalida vuelva a ingresarla: ";
										cin>>pos;
									}
									for(int i = 0; i<albumes.size(); i++) {
										Album* A = albumes.at(i);
										string nombreA = A->getNombre();
										string artista = A->getArtistaA();
										cout<<"Nombre del Album: "<<nombreA<<setw(5)<<"Artista: "<<artista<<endl;
										cout<<"Canciones: "<<endl;
										for(int j =0; j<A->getCanciones().size(); j++) {
											Cancion* c = canciones.at(j);
											cout<<(j+1)<<") "<<c->getNombre()<<endl;
										}
										cout<<endl;
										int pos2;
										cout<<"Ingrese la posicion del album que desea usar: ";
										cin>>pos2;
										while(pos2-1<0||pos2-1>playlists.size()) {
											cout<<"Posicion invalida vuelva a ingresarla: ";
											cin>>pos2;
										}
										Playlist* pl = playlists.at(pos-1);
										pl->operator+(albumes.at(pos2-1));
									}
								} else {
									cout<<"Lista de albumes vacia, agregue un album"<<endl;
								}
							} else {
								cout<<"Lista de playlists vacia, agregue una playlist"<<endl;
							}
							break;
						}
						//ALBUM + CANCION
						case 3: {
							if(!canciones.empty()) {
								int opcionA = 0;
								while(opcionA != 3) {
									cout<< "Ingrese una opcion"<<endl;
									cout<<"1) Crear Nuevo Album"<<endl;
									cout<<"2) Usar Album Existente"<<endl;
									cout<<"3) Regresar al Menu anterior"<<endl;
									cout<<"Opcion: ";
									cin>>opcionA;
									cout<<endl;
									switch(opcionA) {
										case 1: {
											int cont = 1;
											char resp = 's';
											string nombreAlbum;
											cout<<"Ingrese el nombre del nuevo album: ";
											cin>>nombreAlbum;
											cout<<endl;
											Album* a;
											Album* al = new Album();
											al->setNombre(nombreAlbum);
											while(resp == 's'||resp == 'S') {
												for(int i = 0; i<canciones.size(); i++) {
													Cancion* cancion = canciones.at(i);
													cout<<(i+1)<<") "<<	cancion->getNombre()<<endl;
												}
												int pos;
												cout<<endl;
												cout<<"Ingrese la posicion de la cancion que desea agregar a su Album: ";
												cin>>pos;
												cout<<endl;
												while(pos-1<0||pos-1>canciones.size()) {
													cout<<"Posicion invalida, ingrese de nuevo: ";
													cin>>pos;
												}
												bool igual = true;
												string artista1;
												if(cont>1) {
													for(int j = 0; j < al->getCanciones().size(); j++) {
														Cancion* c1 = al->getCanciones().at(j);
														artista1 = c1->getArtistaC();
														for(int i = 0; i<al->getCanciones().size(); i++) {
															Cancion* c = al->getCanciones().at(i);
															string artista = c->getArtistaC();
															if(artista1==artista) {
																igual = false;
															}
														}
													}
												}
												a->operator+(canciones.at(pos-1));
												string artistas;
												if(!igual) {
													string artistas = "Various Artists";
												} else {
													string artistas = artista1;
												}
												if(cont==1) {
													al->setArtistaA(artistas);
													al->setNombre(nombreAlbum);
													albumes.push_back(al);
													cout<<"Rola agregada exitosamente"<<endl;
												}
												cout<<endl;
												cout<<"Desea agregar otra cancion al Album? (S/N): ";
												cin>>resp;
												cont++;
											}
										}
										break;
										case 2: {
											if(!albumes.empty()) {
												char resp = 's';
												for(int i = 0; i<albumes.size(); i++) {
													Album* A = albumes.at(i);
													string nombreAl = A->getNombre();
													cout<<"Nombre del Album: "<<nombreAl<<endl<<endl;
													for(int j =0; j<A->getCanciones().size(); j++) {
														Cancion* c = canciones.at(j);
														cout<<(j+1)<<") "<<c->getNombre()<<endl;
													}
													cout<<endl;
												}
												cout<<endl;
												int pos1;
												cout<<"Ingrese la posicion del Album al cual desea agregarle la cancion: ";
												cin>>pos1;
												while(pos1-1<0||pos1-1>albumes.size()) {
													cout<<"Posicion invalida, ingrese de nuevo: ";
													cin>>pos1;
												}
												while(resp == 's'||resp == 'S') {
													Album* Al = albumes.at(pos1-1);
													for(int i = 0; i<canciones.size(); i++) {
														Cancion* cancion = canciones.at(i);
														cout<<(i+1)<<") "<<	cancion->getNombre()<<endl;
													}
													int pos;
													cout<<endl;
													cout<<"Ingrese la posicion de la cancion que desea agregar a su Album: ";
													cin>>pos;
													while(pos<0||pos>canciones.size()) {
														cout<<"Posicion invalida, ingrese de nuevo: ";
														cin>>pos;
													}
													Al->operator+(canciones.at(pos-1));
													cout<<endl;
													cout<<"Desea agregar otra cancion al Album? (S/N): ";
													cin>>resp;
												}
											} else {
												cout<<"No hay albumes creados porfavor cree almenos 1"<<endl;
											}
											break;
										}
									}
								}
							}
							break;
						}
						//PLAYLIST + PLAYLIST
						case 4: {
							if(!playlists.empty()) {
								int posp;
								for(int i = 0; i<playlists.size(); i++) {
									Playlist* aux = playlists.at(i);
									cout<<(i+1)<<") "<<aux->getNombre();
								}
								cout<<endl;
								cout<<"Ingrese la posicion de la playlist que desea agregarle otra playlist: ";
								cin>>posp;
								string nombreP;
								cout<<endl;
								Playlist* Pl = new Playlist();
								Pl = playlists.at(posp-1);
								nombreP = Pl->getNombre();
								for(int i = 0; i<playlists.size(); i++) {
									Playlist* aux2 = playlists.at(i);
									cout<<(i+1)<<") "<<aux2->getNombre();
								}
								int pos;
								cout<<"Ingrese la posicion de la playlist que desea agregar a su playlist "<<nombreP<<": ";
								cin>>pos;
								while(pos-1>playlists.size()||pos-1<0) {
									cout<<"La posicion que ingreso es invalida porfavor ingrese una posicion valida."<<endl;
									cout<<"Ingrese la posicion: ";
									cin>>pos;
								}
								Pl->operator+(playlists.at(pos-1));
								cout<<"Playlist Agregada exitosamente";
							}
							break;
						}
					}
				}
				break;
			}
			//OPERADOR -
			case 4: {
				int opcion5 = 0;
				while(opcion5!=3) {
					cout<<"Ingrese una opcion"<<endl;
					cout<<"1) Playlist - Cancion"<<endl;
					cout<<"2) Playlist - Genero"<<endl;
					cout<<"3) Volver al menu anterior"<<endl;
					cout<<"Opcion: ";
					cin>>opcion5;
					switch(opcion5) {
						case 1: {
							if(!playlists.empty()) {
								Playlist* Play = new Playlist();
								for(int i = 0; i<playlists.size(); i++) {
									Playlist* P = playlists.at(i);
									string nombreP = P->getNombre();
									cout<<"Nombre de la Playlist: "<<nombreP<<endl<<endl;
									cout<<"Canciones: "<<endl;
									for(int j =0; j<P->getCanciones().size(); j++) {
										Cancion* c = canciones.at(j);
										cout<<(j+1)<<") "<<c->getNombre()<<endl;
									}
									cout<<endl;
								}
								int vali = 0;
								string ply;
								cout<<"Ingrese el nombre de la playlist a la cual le quiere eliminar una cancion: ";
								cin>>ply;
								cout<<endl;
								for(int i = 0; i<playlists.size(); i++) {
									Playlist* playlist1 = playlists.at(i);
									string nombre = playlist1->getNombre();
									if(nombre==ply) {
										Play = playlists.at(i);
										vali = 1;
									}
								}
								if(vali==1) {
									int vali2 = 0;
									string cn;
									cout<<"Ingrese el nombre de la cancion que va a eliminar: ";
									cin>>cn;
									Cancion* Can;
									for(int i = 0; i<canciones.size(); i++) {
										Cancion* C1 = canciones.at(i);
										string nombre = C1->getNombre();
										if(cn==nombre) {
											Cancion* Can = C1;
											vali2 = 1;
										}
									}
									if(vali2 == 1) {
										Play->operator+(Can);
										cout<<"Cancion eliminada exitosamente"<<endl;
									} else {
										cout<<"Esa Cancion no existe porfavor ingrese una cancion valida"<<endl;
									}
								} else {
									cout<<"Esa playlist no existe, ingrese un nombre valido"<<endl;
								}
							} else {
								cout<<"No hay playlists creadas, cree una playlist primero"<<endl;
							}
							break;
						}
						case 2: {
							if(!playlists.empty()) {
								Playlist* Play;
								for(int i = 0; i<playlists.size(); i++) {
									Playlist* P = playlists.at(i);
									string nombreP = P->getNombre();
									cout<<"Nombre de la Playlist: "<<nombreP<<endl<<endl;
									for(int j =0; j<P->getCanciones().size(); j++) {
										Cancion* c = canciones.at(j);
										cout<<(j+1)<<") "<<c->getNombre()<<endl;
									}
									cout<<endl;
								}
								int vali = 0;
								string plad;
								cout<<"Ingrese el nombre de la playlist a la cual va a eliminarle las canciones de cierto genero: ";
								cin>>plad;
								for(int i = 0; i<playlists.size(); i++) {
									Playlist* playlist1 = playlists.at(i);
									string nombre = playlist1->getNombre();
									if(nombre==plad) {
										Play = playlists.at(i);
										vali = 1;
									}
								}
								if(vali == 1) {
									string generon;
									int vali2 = 0;
									cout<<"Ingrese el nombre del genero que desea quitar de la playlist: ";
									cin>>generon;
									Genero* Gen;
									string nombreG;
									for(int i = 0; i<generos.size(); i++) {
										Genero* G1 = generos.at(i);
										string nombre = G1->getNombre();
										if(generon==nombre) {
											Gen = G1;
											vali2 = 1;
											nombreG = nombre;
										}
									}
									if(vali2==1) {
										Play->operator-(Gen);
										cout<<"Canciones de Genero "<<nombreG<<endl;
									} else {
										cout<<"Este genero no existe, ingrese uno valido"<<endl;
									}
								} else {
									cout<<"Playlist ingresada es invalida"<<endl;
								}
							} else {
								cout<<"No hay playlists creadas, cree una playlist primero"<<endl;
							}
							break;
						}
					}
				}
				break;
			}
		}
	}
	for(int i = 0; i<canciones.size(); i++) {
		delete canciones.at(i);
	}
	for(int i = 0; i<generos.size(); i++) {
		delete generos.at(i);
	}
	for(int i = 0; i<albumes.size(); i++) {
		delete albumes.at(i);
	}
	for(int i = 0; i<playlists.size(); i++) {
		delete playlists.at(i);
	}
	cout<<endl;
	return 0;
}