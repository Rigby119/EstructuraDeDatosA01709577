#ifndef POKEMON_H_
#define POKEMON_H_

#include <iostream>
#include <string>

class Pokemon{
private:
    int ID, statSum, statAvg;
    std::string name, type1, type2, category;
public:
    Pokemon();
    Pokemon(int, std::string, std::string, std::string, int, int, std::string);
    Pokemon(std::string, std::string, std::string, std::string, std::string, std::string, std::string);
    
    int getID() {return ID;}
    int getStatSum() {return statSum;}
    int getStatAvg() {return statAvg;}
    std::string getName() {return name;}
    std::string getType1() {return type1;}
    std::string getType2() {return type2;}
    std::string getCategory() {return category;}

    void showSortData();
    void showSortData(int);
    void showAllData();
    void clear();
};

Pokemon::Pokemon() {
    ID = 0;
    statSum = 0;
    statAvg = 0;
    name = "";
    type1 = "";
    type2 = "";
    category = "";
}

Pokemon::Pokemon(int i, std::string n, std::string t1, std::string t2, int sS, int sA, std::string c){
    ID = i;
    statSum = sS;
    statAvg = sA;
    name = n;
    type1 = t1;
    type2 = t2;
    category = c;
}

Pokemon::Pokemon(std::string i, std::string n, std::string t1, std::string t2, std::string sS, std::string sA, std::string c){
    ID = std::stoi(i);
    statSum = std::stoi(sS);
    statAvg = std::stoi(sA);
    name = n;
    type1 = t1;
    type2 = t2;
    category = c;
}

void Pokemon::showSortData() {
    std::cout << name << " - ID: " << ID << ", SumStats: "  << statSum << ", AvgStats: "  << statAvg << std::endl;
}

void Pokemon::showSortData(int opt) {
    if (opt == 0) {
        std::cout << name << " - ID: " << ID << std::endl;
    } else if (opt == 1) {
        std::cout << name << " - SumStats: " << statSum << std::endl;
    } else {
        std::cout << name << " - AvgStats: " << statAvg << std::endl;
    }
}

void Pokemon::showAllData() {
    std::cout << name << " - ID: " << ID << ", SumStats: "  << statSum << ", AvgStats: "  << statAvg;
    std::cout << ", Type 1: " << type1  << ", Type 2: " << type2 << ", Category: " << category << std::endl;
}

void Pokemon::clear() {
    ID = 0;
    statSum = 0;
    statAvg = 0;
    name = "";
    type1 = "";
    type2 = "";
    category = "";
}

#endif