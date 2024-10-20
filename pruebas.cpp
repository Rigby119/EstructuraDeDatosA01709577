/*
findPokemon
clear
showSortData
showAllData
mergeSort y sus derivadas
*/

#include <iostream> // Using std::cout and so
#include <vector> // To use std::vector and so
#include <string> // To use std::string and so
#include <sstream> //
#include <fstream> // To read the databases file
#include <map> // For making the types "Pla" is "Plant" and so

#include "pokemon.h"
#include "dataOrganizer.h"

std::vector<Pokemon*> fileReader(std::string ruta) {
    std::ifstream dataBase(ruta);

    if (! dataBase.is_open()) { 
        std::cerr << "No se pudo acceder a la base de datos" << std::endl;
        exit(1);
    }

    std::vector<std::vector<std::string>> pokemonData; // Matriz de datos
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

    std::vector<Pokemon*> pokemons;

    for (int i = 0; i < pokemonData.size(); i++) {
        Pokemon * p = new Pokemon(pokemonData[i][0],pokemonData[i][1],pokemonData[i][2],
        pokemonData[i][3],pokemonData[i][4],pokemonData[i][5],pokemonData[i][6]);
        pokemons.push_back(p);
    }

    return pokemons;
}

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

int main () {
    std::vector<Pokemon*> pokemons = fileReader("databaseUnsorted.txt");

    std::cout << "Pokemon #5: " << pokemons[4] -> getName() << std::endl;

    mergeSort(pokemons, 0);

    std::cout << "Pokemon #5: " << pokemons[4] -> getName() << std::endl;

    pokemons[4] -> showAllData();
    pokemons[4] -> showSortData();
    pokemons[4] -> showSortData(0);

    std::cout << "Pokemon #1: " << pokemons[0]->getName() << std::endl;
    pokemons[0] -> clear();
    std::cout << "Pokemon #1: " << pokemons[0]->getName() << std::endl;

    std::cout << "Pikachu is on the #" << findPokemon(pokemons, "Pikachu") + 1 << " position" << std::endl;

    for (Pokemon* p : pokemons) {
        p -> clear();
        delete p;
    }

    std::vector<Pokemon*> test2 = fileReader("NonExistentFile.txt");

    std::cout << "NoReachablePoint You should not reach this message";

    return 0;
}