#ifndef DATAORGANIZER_H_
#define DATAORGANIZER_H_

#include "pokemon.h"
#include <vector>

void copyArray(std::vector<Pokemon*> &A, std::vector<Pokemon*> &B, int low, int high) {
    for (int i = low; i <= high; ++i) {
        *A[i] = *B[i];
    }
}

void mergeArray(std::vector<Pokemon*> &A, std::vector<Pokemon*> &B, int low, int mid, int high, int opt) {
    int ind = low;
    int i = low;
    int j = mid + 1;
    
    while (i <= mid && j <= high) {
        int a, b;
        if (opt == 1) {
            a = A[i] -> getStatSum();
            b = A[j] -> getStatSum();
        } else if (opt == 2) {
            a = A[i] -> getStatAvg();
            b = A[j] -> getStatAvg();
        } else {
            a = A[i] -> getID();
            b = A[j] -> getID();
        }
        if (a < b) {
            *B[ind] = *A[i];
            i++;
        } else {
            *B[ind] = *A[j];
            j++;
        }
        ind++;
    }

    while (i <= mid) {
        *B[ind] = *A[i];
        i++;
        ind++;
    }

    while (j <= high) {
        *B[ind] = *A[j];
        j++;
        ind++;
    }

    copyArray(A, B, low, high);
}

void mergeSplit(std::vector<Pokemon*> &A, std::vector<Pokemon*> &B, int low, int high, int opt) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSplit(A, B, low, mid, opt);
        mergeSplit(A, B, mid + 1, high, opt);
        mergeArray(A, B, low, mid, high, opt);
    }
}

std::vector<Pokemon*> mergeSort(const std::vector<Pokemon*> &source, int opt) {
    std::vector<Pokemon*> v(source);
    std::vector<Pokemon*> tmp(v.size(), nullptr);

    for (size_t i = 0; i < tmp.size(); ++i) {
        tmp[i] = new Pokemon();
    }

    mergeSplit(v, tmp, 0, v.size() - 1, opt);

    for (Pokemon* p : tmp) {
        delete p;
    }

    return v;
}

#endif