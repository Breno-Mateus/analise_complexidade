#include "algoritmos.hpp"
#include <algorithm>

void insertionSort(std::vector<int>& arr) {
  int n = arr.size();
  for (int i = 1; i < n; i++) {
    int chave = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > chave) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = chave;
}
}

void merge(std::vector<int>& arr, int esquerda, int meio, int direita) {
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[esquerda + i];
    for (int j = 0; j < n2; j++) R[j] = arr[meio + 1 + j];

    int i = 0, j = 0, k = esquerda;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void executarMergeSort(std::vector<int>& arr, int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        executarMergeSort(arr, esquerda, meio);
        executarMergeSort(arr, meio + 1, direita);
        merge(arr, esquerda, meio, direita);
    }
}

void mergeSort(std::vector<int>& arr) {
    if (arr.empty()) return;
    executarMergeSort(arr, 0, arr.size() - 1);
}

int buscaSequencial(const std::vector<int>& arr, int alvo) {
  for (int i = 0; i < (int)arr.size(); i++) {
    if (arr[i] == alvo) {
      return i;
    }
  }
  return -1;
}

int buscaBinaria(const std::vector<int>& arr, int alvo) {
  int esquerda = 0;
  int direita = arr.size() - 1;

  while (esquerda <= direita) {
    int meio = esquerda + (direita - esquerda) / 2;

    if (arr[meio] == alvo) {
      return meio;
    }
    if (arr[meio] < alvo) {
      esquerda = meio + 1;
    } else {
      direita = meio - 1;
    }
  }
  return -1;
}