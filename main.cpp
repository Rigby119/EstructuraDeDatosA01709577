#include <iostream> // Using std::cout and so
#include <vector> // To use std::vector and so
#include <string> // To use std::string and so
#include <fstream> // To read the databases file
#include <cctype> // For isdigit()
#include <map> // For making the types "Pla" is "Plant" and so

/*
void copyArray(std::vector<std::vector<int>> &A, std::vector<std::vector<int>> &B, int low, int high) {
	for (int i = 0; i <= high; i++) {
		A[i] = B[i];
	}
}

void mergeArray(std::vector<std::vector<int>> &A, std::vector<std::vector<int>> &B, int low, int mid, int high, int fD) {
	int ind = low;
	
	int i = low;
	int j = mid + 1;

	while (i <= mid && j <= high) {
		if (A[i][fD] < A[j][fD]){
			B[ind][fD] = A[i][fD];
			i++;
		} else {
			B[ind][fD] = A[j][fD];
			j++;
		}
		ind++;
	}

	while (i <= mid) {
		B[ind][fD] = A[i][fD];
		i++;
		ind++;
	}
	
	while (j <= high) {
		B[ind][fD] = A[j][fD];
		j++;
		ind++;
	}

	copyArray(A, B, low, high);
}


void mergeSplit(std::vector<std::vector<int>> &A, std::vector<std::vector<int>> &B, int low, int high, int fD) {

	if (low < high){

		int mid = (high + low) / 2;
		
		mergeSplit(A, B, low, mid, fD);

		mergeSplit(A, B, mid + 1, high, fD);

		mergeArray(A, B, low, mid, high, fD);
	}
}


std::vector<std::vector<int>> mergeSort(const std::vector<std::vector<int>> &source, int filterData) {
	std::vector<std::vector<int>> v(source);
	std::vector<std::vector<int>> tmp(v.size());

	mergeSplit(v, tmp, 0, v.size() - 1, filterData);
	
	return v;
}
*/
void swap(std::vector<std::vector<int>> &v, int i, int j) {
	std::vector<int> aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

std::vector<std::vector<int>> bubbleSort(const std::vector<std::vector<int>> &source, int dataRef) {
	std::vector<std::vector<int>> v(source);

	for (int i = v.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (v[j][dataRef] > v[j + 1][dataRef]) {
				swap(v, j, j + 1);
			}
		}
	}

	return v;
}

bool onlyDigits(std::string str) {
    for (char c : str) {
        if (!std::isdigit(c)) {return false;}
    }
    return true;
}

int main () {
	std::ifstream dataBase("database.txt"); // ifstream es para lectura
	
    if (! dataBase.is_open()) { // Si el archivo no está abierto, marca error
        std::cerr << "No se pudo acceder a la base de datos" << std::endl;
        return 0; // Termina el programa
    }

    std::vector<std::string> pokemonData; // Vector de Datos sin separar
    std::string dataTemp; // String de datos sin separar

    while (std::getline(dataBase, dataTemp)) { // Hasta que ya no haya líneas, lee cada línea
        pokemonData.push_back(dataTemp); // Almacenar cada línea en el vector
    }

    dataBase.close(); // Cerramos el archivo

    std::vector<std::vector <std::string>> dataVecStr;
    std::vector<std::vector <int>> dataVecInt;
	
    std::string temp = "";
    std::vector<std::string> tempVecStrings;
    std::vector<int> tempVecInt;
    
    for (std::string str : pokemonData) {
        tempVecStrings.clear();
        tempVecInt.clear();
        
        for (char c : str) {
            if (c == ',') {
                if (onlyDigits(temp)) {
                    tempVecInt.push_back(std::stoi(temp));
                }
                tempVecStrings.push_back(temp);
                temp = "";
            }            
            else {
                temp += c;  // Acumular el carácter en temp
            }
        }
        tempVecStrings.push_back(temp);
        temp = "";
        dataVecStr.push_back(tempVecStrings);
        dataVecInt.push_back(tempVecInt);
    }

    int dataRef = 1; // 0 ordena por ID, 1 por Stats Totales y 2 por Stats Promedio

    dataVecInt = bubbleSort(dataVecInt, dataRef);

    for (std::vector<int> vec : dataVecInt) {
        int ind = vec[0]-1;
        
        std::cout << "#";
        
        for (int j = 0; j < 7; j++) {
            std::cout << dataVecStr[ind][j] << " ";
        }
        std::cout << std::endl << std::endl;
    }

    return 0;
}