#include <iostream> // Using std::cout and so
#include <vector> // To use std::vector and so
#include <string> // To use std::string and so
#include <sstream> //
#include <fstream> // To read the databases file
#include <map> // For making the types "Pla" is "Plant" and so
#include <stack> // For printing the info of multiple pokemons from a search
#include <cstdlib> // For cleaning the console
#include <iomanip> // Permite usar setw y setfill para escribir el archivo de salida

#include "pokemon.h"
#include "dataOrganizer.h"

std::vector<Pokemon*> pokemons;
int pokedex, accion, sort; // Sort 1 es Sum, Sort 2 es Avg y Sort 3 es ID
void selectPokedex();
void mostrarAccionesPokedex();
void todos();
void nombre();
void tipo();

/*
Peor caso: O(n)
Promedio: O(n)
Mejor caso: O(n)
*/
std::vector<Pokemon*> fileReader(std::string ruta) {
    std::ifstream dataBase(ruta);

    if (! dataBase.is_open()) { 
        std::cerr << "No se pudo acceder a la base de datos" << std::endl;
        exit(1);
    }

    std::vector< std::vector<std::string> > pokemonData; // Matriz de datos
    std::vector<std::string> values; // Vector de datos por linea

    std::string line; // String de linea
    std::string value; // String de atributo
    

    while (std::getline(dataBase, line)) {
        std::stringstream ss(line);
        values.clear();
        value = "";

        while (std::getline(ss, value, ',')) {
            values.push_back(value);
        }

        pokemonData.push_back(values);
    }

    dataBase.close();

    std::vector<Pokemon*> pokes;

    for (int i = 0; i < pokemonData.size(); i++) {
        Pokemon * p = new Pokemon(pokemonData[i][0],pokemonData[i][1],pokemonData[i][2],
        pokemonData[i][3],pokemonData[i][4],pokemonData[i][5],pokemonData[i][6]);
        pokes.push_back(p);
    }

    return pokes;
}

/*
Peor caso: O(n) // Al final del vector
Promedio: O(n) // En cualquier posición
Mejor caso: O(1) // Asumiendo que está al principio del vector
*/
int findPokemon(std::vector<Pokemon*> pks, std::string nm) {
    int index = 0;
    for (Pokemon* p:pks) {
        if (p->getName() == nm) {
            return index;
        }
        index++;
    }
    std::cout << "Pokemon no encontrado";
    return -1;
}

/*
Peor caso: O(n)
Promedio: O(n)
Mejor caso: O(n) 
El programa siempre verá todos los pokemones del vector
*/
std::stack<Pokemon*> findPokemonsType(std::vector<Pokemon*> pks, std::string type) {
    std::stack<Pokemon*> prompt;

    for (Pokemon* p:pks) {
        if (p->getType1() == type || p->getType2() == type) {
            prompt.push(p);
        }
    }

    if (prompt.empty()) {
        std::cout << "No hay pokemons de tipo " << type << std::endl;
    }

    return prompt;
}

/*
Peor caso: O(n)
Promedio: O(n)
Mejor caso: O(n)
Esta funcion muestra todos los pokemons del vector
*/
void showData(std::string input, std::vector<Pokemon*> pks, int sort) {
    if (input == "1") {
        for (Pokemon* p : pks) {p -> showSortData();}
    } else if (input == "2") {
        for (Pokemon* p : pks) {p -> showSortData(sort);}
    } else {
        for (Pokemon* p : pks) {p -> showAllData();}
    }
}

/*
Peor caso: O(1)
Promedio: O(1)
Mejor caso: O(1)
Solo imprime mensajes y llama a otra función
*/
void welcome() {
    system("cls");

    std::cout << "\nBienvenido a la Pokedex Tool!\n\n";
    selectPokedex();
}

/*
Peor caso: O(i)
Promedio: O(i)
Mejor caso: O(i)
Dónde i es la cantidad de veces que el usuario se equivoca +1
*/
void repeat() {
    int opt = -1;
    while (opt == -1) {
        std::cout << "\nQuieres ejecutar alguna otra funcion?\n";
        std::cout << "\n1.- Si";
        std::cout << "\n2.- No";
        std::cout << "\n>>> ";
        std::cin >> opt;
        if (opt == 1) {
            mostrarAccionesPokedex();
        } else if (opt == 2) {
            system("cls");
            std::cout << "Hasta luego";
        } else {
            opt = -1;
        }
    }
}

/*
Peor caso: O(i)
Promedio: O(i)
Mejor caso: O(i)
Dónde i es la cantidad de veces que el usuario se equivoca +1
*/
void selectPokedex() {
    system("cls");
    int opcion = -1;

    while (opcion == -1) {
        std::cout << "Seleccione la Pokedex a la que desea acceder:\n\n";
        std::cout << "1.- Pokedex Nacional\n";
        std::cout << "2.- Pokedex de Kanto\n\n";
        std::cout << "Ingrese su opcion: ";
        
        std::cin >> opcion;
        
        if (opcion == 1) {
            pokemons = fileReader("databaseNational.txt");
            pokedex = 1;
        } else if (opcion == 2) {
            pokemons = fileReader("databaseKanto.txt");
            pokedex = 2;
        } else {
            system("cls");
            std::cout << "\nOpcion no valida. Por favor introduce un valor valido.\n";
            opcion = -1;
        }
    }
    mostrarAccionesPokedex();
}

/*
Peor caso: O(i)
Promedio: O(i)
Mejor caso: O(i)
Dónde i es la cantidad de veces que el usuario se equivoca +1
*/
void mostrarAccionesPokedex() {
    system("cls");
    int opcion = -1;

    while (opcion == -1) {
        std::cout << "\nHa seleccionado la Pokedex ";
        if (pokedex == 1) {
            std::cout << "Nacional.\n\n";
        } else {
            std::cout << "de Kanto.\n\n";
        }
        std::cout << "Seleccione una accion:\n\n";
        std::cout << "1.- Listar todos los Pokemon\n";
        std::cout << "2.- Buscar Pokemon por nombre\n";
        std::cout << "3.- Buscar Pokemon por tipo\n";
        std::cout << "4.- Cambiar de Pokedex\n\n";
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;
        if (opcion == 1) {
            todos();
        } else if (opcion == 2) {
            nombre();
        } else if (opcion == 3) {
            tipo();
        } else if (opcion == 4) {
            selectPokedex();
        } else {
            system("cls");
            std::cout << "\nOpcion no valida. Por favor introduce un valor valido.\n";
            opcion = -1;
        }
    }
}

/*
Peor caso: O(i)
Promedio: O(i)
Mejor caso: O(i)
Dónde i es la cantidad de veces que el usuario se equivoca +1
*/
void todos() {
    system("cls");
    int opcion = -1;
    
    while (opcion == -1) {
        std::cout << "\nHa seleccionado: Listar todos los Pokemon.\n\n";
        std::cout << "Seleccione una opcion de listado:\n\n";
        std::cout << "1. Mostrar por ID\n";
        std::cout << "2. Mostrar por stats maximos\n";
        std::cout << "3. Mostrar por stats promedio\n\n";
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;

        if (opcion == 1) {
            system("cls");
            std::cout << "Mostrando Pokemon por ID...\n";
            sort = 3;
        } else if (opcion == 2) {
            system("cls");
            std::cout << "Mostrando Pokemon por stats maximos...\n";
            sort = 1;
        } else if (opcion == 3) {
            system("cls");
            std::cout << "Mostrando Pokemon por stats promedio...\n";
            sort = 2;
        } else {
            system("cls");
            opcion = -1;
            std::cout << "Opcion no valida. Regresando al menu de acciones.\n";
        }
    }
    mergeSort(pokemons, sort);
    showData("1", pokemons, sort);
    repeat();
}

/*
Sin contar mergeSort que tiene su propio análisis:
Peor caso: O(i)
Promedio: O(i)
Mejor caso: O(i)
Dónde i es la cantidad de veces que el usuario se equivoca +1
*/
void nombre() {
    system("cls");
    std::string nombre;
    std::cout << "\nHa seleccionado: Buscar Pokemon por nombre.\n";
    std::cout << "Ingrese el nombre del Pokemon: ";
    std::cin >> nombre;
    std::cout << "Buscando a: " << nombre << "...\n";

    int index = findPokemon(pokemons, nombre);
    if (index != -1) {
        pokemons[index] -> showAllData();
    }
    repeat();
}

/*
Sin contar FindPokemonsType que tiene su propio análisis:
Peor caso: O(i)
Promedio: O(i)
Mejor caso: O(i)
Dónde i es la cantidad de veces que el usuario se equivoca +1
*/
void tipo() {
    system("cls");
    std::string tipo;
    int opcion = -1;

    std::cout << "\nHa seleccionado: Buscar Pokemon por tipo.\n";
    std::cout << "Ingrese el tipo del Pokemon: ";
    std::cin >> tipo;
    std::cout << "\nBuscando Pokemon del tipo: " << tipo << "...\n";

    std::stack<Pokemon*> stackPokes = findPokemonsType(pokemons, tipo);
    
    if (!stackPokes.empty()) {
        int sizeStack = stackPokes.size();
        std::cout << "\nSe encontraron " << sizeStack << " Pokemon de tipo: " << tipo << "\n";
        while (opcion == -1) {
            std::cout << "\nQuieres verlos?\n";
            std::cout << "\n1.- Si";
            std::cout << "\n2.- No";
            std::cout << "\n>>> ";
            std::cin >> opcion;

            if (opcion == 1) {
                std::cout << "\nPokemon de tipo: " << tipo << "\n";
                for (int i = 0; i < sizeStack; i++) {
                    std::cout << "- " << stackPokes.top() -> getName() << std::endl;
                    stackPokes.pop();
                }
            } else if (opcion == 2) {
                for (int i = 0; i < sizeStack; i++) {
                    stackPokes.pop();
                }
            }
        }
    }    
    repeat();
}

/*
Guardado del archivo
Peor caso: O(n)
Promedio: O(n)
Mejor caso: O(n)
Debe recorrer el vector completo
*/
// Para análisis de complejidad del programa, revisar readme
int main () {
    int opt;

    welcome();
    
    std::string ruta;

    if (pokedex == 1) {
        ruta = "databaseNational.txt";
    } else {
        ruta = "databaseKanto.txt";
    }


    std::ofstream archivo(ruta);

    if (!archivo) {
        std::cerr << "Error al abrir el archivo" << std::endl;
    }

    for (int i = 0; i < pokemons.size(); ++i) {
        Pokemon* p = pokemons[i];
        
        std::ostringstream ss;
        archivo << std::setw(4) << std::setfill('0') << p->getID() << ","        
                << p->getName() << ","    
                << p->getType1DB() << ","
                << p->getType2DB() << ","
                << p->getStatSum() << ","
                << p->getStatAvg() << ","
                << p->getCategory();

        if (i != pokemons.size() - 1) {
            archivo << std::endl;
        }
    }

    archivo.close();
    std::cout << "\nArchivo guardado exitosamente en " << ruta << std::endl;

    // Delete all Pokemon
    for (Pokemon* p : pokemons) {
        p -> clear();
        delete p;
    }

    return 0;
}