#include "algoritmos.hpp"
#include "coleta_dados.hpp"

int main() {
  std::vector<int> tamanhos = {100, 500, 1000, 5000, 10000, 20000};

  //realizarExperimento(insertionSort, "InsertionSort", tamanhos, 10);
  //realizarExperimento(selectionSort, "SelectionSort", tamanhos, 10);

  verificarCrescimento(500, 0.29, 1000, 1.10);

  return 0;
}