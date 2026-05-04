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

void selectionSort(std::vector<int>& arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
          min_idx = j;
      }
    }
    std::swap(arr[min_idx], arr[i]);
  }
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