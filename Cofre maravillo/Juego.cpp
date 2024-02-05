#include "Juego.h"

Juego::Juego() : caballero() {
    inicializarTablero();
    colocarElementosAleatorios<Espada>(7, 'E');
    colocarElementosAleatorios<Ballesta>(6, 'B');
    colocarElementosAleatorios<Yesca>(10, 'Y');
    colocarElementosAleatorios<Daga>(5, 'D');
    colocarElementosAleatorios<Tentaculos>(14, 'T');
    colocarElementosAleatorios<Ogro>(12, 'O');
    colocarElementosAleatorios<Gargolas>(10, 'G');
    colocarElementosAleatorios<Items>(6, 'H');
    colocarElementosAleatorios<CofreMaravilloso>(1, 'C');
}

Juego::Juego( Caballero c)
{
    caballero = c;
    
}

Juego::~Juego() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            delete matriz[i][j];
            matriz[i][j] = nullptr;
        }
        delete matriz[i];
    }
    delete[] matriz;
}

void Juego::inicializarTablero() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            matriz[i][j] = nullptr;

          
        }
    }
}

#include <iomanip>  // Necesario para std::setw

void Juego::imprimirTablero() {
    std::cout << "---------------------------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < 9; i++) {
        std::cout << "|";
        for (int j = 0; j < 9; j++) {
            std::cout << std::setw(12);  // Ajusta el ancho del campo
            if (matriz[i][j] != nullptr) {
                std::cout << matriz[i][j]->getNombre();
            }
            else {
                std::cout << " ";
            }
            std::cout << "|";
        }
        std::cout << "\n---------------------------------------------------------------------------------------------------------------------------\n";
    }
}

bool Juego::puedeDerrotarlo(Enemigos* enemi) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            ElementosJuegos* aux = caballero.getHerramienta(i, j);
            if (aux != nullptr) {
                if (typeid(*aux) == typeid(Ballesta) && typeid(*enemi) == typeid(Gargolas)) {
                    return true;
                }
                else if (typeid(*aux) == typeid(Espada)) {
                    if (typeid(*enemi) == typeid(Ogro) || typeid(*enemi) == typeid(Gargolas)) {
                        return true;
                    }
                }
                else if (typeid(*aux) == typeid(Yesca) && typeid(*enemi) == typeid(Tentaculos)) {
                    return true;
                }
                else if (typeid(*aux) == typeid(Daga) && typeid(*enemi) == typeid(Ogro)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Juego::reduccionDeVida(Enemigos* ene, Caballero& knight) {
    int reduccion;
    reduccion = knight.getHp() - ene->getHpAtaque();

    if (reduccion > 0) {
        knight.setHp(reduccion);
        return true;
    }
    else {
        return false;
    }
}

ElementosJuegos* Juego::revisaSiesHerramienta(ElementosJuegos* elem) {
    if (typeid(*elem) == typeid(Herramientas)) {
        return elem;
    }
    return nullptr;
}

bool Juego::ingresaHerramienta(ElementosJuegos* elem, Caballero& Knight) {
    ElementosJuegos* herramienta = revisaSiesHerramienta(elem);

    if (herramienta != nullptr) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (Knight.setHerramientas(dynamic_cast<Herramientas*>(herramienta), i, j)) {
                    std::cout << "Se ha agregado la herramienta al inventario del caballero.\n";
                    return true;
                }
            }
        }
    }
    return false;
}

void Juego::jugar() {
    while (caballero.getHp() > 0) {
        imprimirTablero();

        int x, y;
        std::cout << "Ingrese las coordenadas para mover al caballero (x y): ";
        std::cin >> y >> x;

        // Verificar límites del tablero
        if (x < 0 || x > 9 || y < 0 || y > 9) {
            std::cout << "Coordenadas inválidas. Intente de nuevo.\n";
            continue;
        }

        ElementosJuegos* elemento = matriz[x][y];
        if (elemento != nullptr) {
            system("cls");

            if (typeid(*elemento) == typeid(CofreMaravilloso)) {
                std::cout << "¡Encontraste el cofre maravilloso! ¡Has ganado el juego!\n";
               //terminar el juego 
                
            }
            else if (revisaSiesHerramienta(elemento)) {
                ingresaHerramienta(elemento, caballero);
            }
            else if (typeid(*elemento) == typeid(Enemigos)) {
                Enemigos* enemigo = dynamic_cast<Enemigos*>(elemento);
                if (puedeDerrotarlo(enemigo)) {
                    std::cout << "¡Has derrotado al enemigo!\n";
                    delete matriz[x][y];
                    matriz[x][y] = nullptr;
                }
                else {
                    std::cout << "No puedes derrotar a este enemigo. ¡Te han atacado!\n";
                    if (reduccionDeVida(enemigo, caballero)) {
                        std::cout << "Reduccion de vida por ataque del enemigo\n";
                    }
                    else if (caballero.getHp() == 0) {
                        std::cout << "TE HAS QUEDADO SIN VIDA. PIERDES EL JUEGO\n";
                    }
                }
            }
            else {
                std::cout << "Has encontrado un elemento: " << typeid(*elemento).name() << "\n";
                if (typeid(*elemento) == typeid(Items)) {
                    std::cout << "Te da 15 hp" << std::endl;
                    caballero.setHp(caballero.getHp() + 15);
                }
            }

            // Eliminar el elemento del tablero después de ser encontrado o interactuar con él
            delete matriz[x][y];
            matriz[x][y] = nullptr;
        }
        else {
            std::cout << "No hay nada en estas coordenadas. Intenta de nuevo.\n";
        }
    }

    std::cout << "¡Fin del juego!\n";
}

void Juego::guardarPartida()
{
    std::ofstream file;
    file.open("registros.txt", std::ios::app);

    if (!file.is_open()) {
        std::cout << "Error al abrir el archivo...\n";
    }
    caballero.guardarPartida();
   
    for (int i = 0; i < 9;i++) {
        for (int j = i; i < 9;j++) {
            file << (matriz[i][j]->getNombre()) << " | ";
            file << (matriz[i][j]->getCantidad()) << " \n ";
        }
    }
    file.close();
}

Juego* Juego::cargarPartida()
{
    std::ifstream file;
    file.open("registros.txt", std::ios::in);

    if (!file.is_open()) {
        std::cout << "Error al abrir el archivo...\n";
    }

    std::string buffer;
    std::string caballero;
    std::string nomElemento; //Cosas de la matriz
    int cantidad;
    /*int filas = 9;
    int columna = 9;*/
   /* std::string*** datos = new std::string * *[filas];*/
   while (std::getline(file, buffer)) {
       std::istringstream linea{ buffer };
       std::getline(linea, nomElemento, '|');
       linea >> cantidad;
       // usuarios.push_back(new Usuario(cedula, nombre, edad));
       return new Juego(caballero);
       file.close();
   }
}


template <typename T>
void Juego::colocarElementosAleatorios(int cantidad, char caracter) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<int> distribucion(0, 8);

    for (int i = 0; i < cantidad; ++i) {
        int x, y;
        do {
            x = distribucion(rng);
            y = distribucion(rng);
        } while (matriz[x][y] != nullptr);

        matriz[x][y] = new T();
      
    }
}

