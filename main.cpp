#include "algoritmos.hpp"
#include "coleta_dados.hpp"

int main() {
  std::vector<int> tamanhos = {1000, 2000, 4000, 8000, 16000, 32000};

  realizarExperimento(insertionSort, "InsertionSort", tamanhos, 10);
  realizarExperimento(selectionSort, "SelectionSort", tamanhos, 10);

  return 0;
}