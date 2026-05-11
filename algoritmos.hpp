#ifndef ALGORITMOS_HPP
#define ALGORITMOS_HPP

#include <vector>
#include <string>

// Ordenação
void insertionSort(std::vector<int>& arr);
void mergeSort(std::vector<int>& arr);

// Busca
int buscaSequencial(const std::vector<int>& arr, int alvo);
int buscaBinaria(const std::vector<int>& arr, int alvo);

#endif