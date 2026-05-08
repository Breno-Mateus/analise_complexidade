#include "algoritmos.hpp"
#include "coleta_dados.hpp"

int main() {
  std::vector<int> tamanhos = {1000, 2000, 4000, 8000, 16000, 32000};

  realizarExperimentoOrdenacao(insertionSort, "InsertionSort", tamanhos, 10);
  realizarExperimentoOrdenacao(selectionSort, "SelectionSort", tamanhos, 10);

  realizarExperimentoBusca(buscaSequencial, "Busca Sequencial", tamanhos, 10);
  realizarExperimentoBusca(buscaBinaria, "Busca Binária", tamanhos, 10);

  return 0;
}