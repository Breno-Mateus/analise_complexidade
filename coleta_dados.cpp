#include "coleta_dados.hpp"
#include <iostream>
#include <chrono>
#include <random>

void realizarExperimento(AlgoritmoOrdenacao alg, std::string nomeAlg, std::vector<int> tamanhos, int repeticoes) {
  std::cout << "\n--- Iniciando Experimento: " << nomeAlg << " ---" << std::endl;
  std::cout << "n\t\t| Tempo Médio (ms)" << std::endl;
  std::cout << "------------------------------------" << std::endl;

  std::random_device rd;
  std::mt19937 gen(rd());

  for (int i = 0; i < (int)tamanhos.size(); i++) {
    int n = tamanhos[i];
    double somaTempos = 0.0;

    for (int r = 0; r < repeticoes; r++) {
      std::vector<int> v(n);
      std::uniform_int_distribution<> dis(1, n * 10);
      for (int j = 0; j < n; j++) {
        v[j] = dis(gen);
      }

      auto start = std::chrono::high_resolution_clock::now();
      alg(v);
      auto end = std::chrono::high_resolution_clock::now();

      std::chrono::duration<double, std::milli> duracao = end - start;
      somaTempos += duracao.count();
    }

    double tempoMedio = somaTempos / repeticoes;

    std::cout << n << "\t\t| " << tempoMedio << " ms" << std::endl;
  }
      
  std::cout << "------------------------------------" << std::endl;
}