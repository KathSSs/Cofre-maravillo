#include "Juego.h"

Juego::Juego() :caballero("Knight Camila") {
    inicializarTablero(); 
    colocarElementosAleatorios<Espada>(7, 'E');
    colocarElementosAleatorios <Ballesta>(6, 'B');
    colocarElementosAleatorios<Yesca>(10,'Y');
    colocarElementosAleatorios<Daga>(5, 'D');
    colocarElementosAleatorios<Tentaculos>(14, 'T');
    colocarElementosAleatorios<Ogro>(12, 'O'); 
    colocarElementosAleatorios<Gargolas>(10, 'G');
    colocarElementosAleatorios<Items>(6, 'H');
    colocarElementosAleatorios<CofreMaravilloso>(1, 'C');
}

Juego::~Juego()
{
    for (int i = 0; i < 9; i++) {
        for (int j = i; j < 9; j++) {
            if(matriz[i][j]!=nullptr)
           delete matriz[i][j];
        }
        delete matriz[i];
    }
    delete[]matriz;
}

void Juego::inicializarTablero()
{
    for (int i = 0; i < 9; i++) {
        for (int j = i; j < 9; j++) {
            matriz[i][j] = nullptr;
        }
    }

}

void Juego::imprimirTablero()
{
    for (int i = 0; i < 9; i++) {
        for (int j = i; j < 9; j++) {
            if (matriz[i][j] != nullptr) {
                std::cout << "\t" << tablero[i][j] <<"  ";
            }
        }
        std::cout << "\n";
    }
}

bool Juego::puedeDerrotarlo(Enemigos* enemi)
{
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

ElementosJuegos* Juego::revisaSiesHerramienta()
{
    ElementosJuegos* aux;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
          aux=  matriz[i][j];
          if (typeid(*aux) == typeid(Herramientas)) {
              return aux;
          }
        }
    } 
}

bool Juego::ingresaHerramienta(Caballero&  Knight ) 
{
    ElementosJuegos* h= revisaSiesHerramienta();

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            Knight.setHerramientas(h, i, j);
        }
    }
}

void Juego::jugar()
{
    while (caballero.getHp() > 0) {
        imprimirTablero();

        int x, y;
        std::cout << "Ingrese las coordenadas para mover al caballero (x y): ";
        std::cin >> x >> y;

        // Verificar límites del tablero
        if (x < 0 || x >= 9 || y < 0 || y >= 9) {
            std::cout << "Coordenadas inválidas. Intente de nuevo.\n";
            continue;
        }

        ElementosJuegos* elemento = matriz[x][y];
        if (elemento != nullptr) {
            if (typeid(*elemento) == typeid(CofreMaravilloso)) {
                std::cout << "¡Encontraste el cofre maravilloso! ¡Has ganado el juego!\n";
                break;
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
                        std::cout << "TE HAS QUEDADO SIN VIDA. PIERDES EL JUEGO\n" ;
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




template <typename T>
void Juego:: colocarElementosAleatorios(int cantidad, char caracter) {
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
        tablero[x][y] = caracter;
    }
}


