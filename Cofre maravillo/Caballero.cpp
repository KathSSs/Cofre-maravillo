
#include "Caballero.h"

void Caballero::setNombre(std::string n)
{
	nombre = n; 
}

ElementosJuegos* Caballero::getHerramienta(int i, int j)
{
	return inventario[i][j];
}

Caballero::Caballero(){
	hp = 100;
	nombre = "Caballero Misterioso"; 
	for (int i = 0; i < 3; i++) {
		for (int j = i; j < 4; j++) {
			inventario[i][j] = nullptr; 
		}
	}

}

Caballero::Caballero(std::string n) : nombre{ n }, hp{ 100 } {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			inventario[i][j] = nullptr;
		}
	}
}



Caballero::Caballero(std::string m, Herramientas* inven) { 
	hp = 100;
for (int i = 0; i < 3; i++) {
	for (int j = i; j < 4; j++) {
		inventario[i][j] = inven;
	}
}


}

Caballero::Caballero(std::string n, int h)
{
	nombre = n;
	hp = h;
}



Caballero::~Caballero() {
	for (int i = 0; i < 3; i++) {
		for (int j = i; j < 4; j++) {
			delete inventario[i][j]; 
		}
		delete inventario[i]; 
	}
	delete[] inventario;
}


 bool Caballero::setHerramientas(Herramientas* herramienta, int i, int j) {
	//if (i >= 0 && i < 3 && j >= 0 && j < 4) {
	 if (inventario[i][j] == nullptr) {
		 inventario[i][j] = herramienta;
		 return true;
	 }
	 else return false; 
		//else {
			//std::cout << "El espacio en el inventario ya está ocupado. No se pudo agregar la herramienta.\n";
		//
	//}
	//else {
	//	std::cout << "Índices fuera de rango. No se pudo agregar la herramienta al inventario.\n";
	//}
}

void Caballero::eliminarHerramienta(int i, int j) {
	if (i >= 0 && i < 3 && j >= 0 && j < 4) {
		delete inventario[i][j];
		inventario[i][j] = nullptr;
	}
	else {
		// Manejar el caso cuando los índices están fuera de rango
		std::cout << "Índices fuera de rango. No se pudo eliminar la herramienta del inventario.\n";
	}
}

void Caballero::guardarPartida()
{
	std::ofstream file;
	file.open("registros.txt", std::ios::app);

	if (!file.is_open()) {
		std::cout << "Error al abrir el archivo...\n";
	}

	for (int i = 0; i < 3;i++) {
		for (int j = i; i < 4;j++) {
			file << (inventario[i][j]->getNombre()) << " \n ";
		}
	}
	file.close();
}

Caballero* Caballero::cargarPartida()
{
	std::ifstream file;
	file.open("registros.txt", std::ios::in);

	if (!file.is_open()) {
		std::cout << "Error al abrir el archivo...\n";
	}
	std::string buffer;
	std::string nombre;
	int hp;
	ElementosJuegos* ele;
	while (std::getline(file, buffer)) {
		std::istringstream linea{ buffer };
		std::getline(linea, nombre, '|');
		linea >> hp;
		return new Caballero(nombre,hp);

	}
}

void Caballero::mostrarInventario()
{
	std::cout << "Inventario del Caballero:\n";

	for (int i = 0; i < 3; ++i) {
		for (int j = i; j < 4; ++j) {
			if (inventario[i][j] != nullptr) {
				std::cout << "[" << i << "][" << j << "]: " << inventario[i][j]->getNombre() << "\n";
			}
			else {
				std::cout << "[" << i << "][" << j << "]: Vacío\n";
			}
		}
	}
}


std::string Caballero::getNombre() { return nombre; }

int Caballero::getHp() { return hp; }
void Caballero::setHp(int JD) { hp = JD; }