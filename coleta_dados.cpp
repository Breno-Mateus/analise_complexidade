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


void verificarCrescimento(int n1, double t1, int n2, double t2) {
  double razaoEntrada = (double)n2 / n1;
  double razaoTempo = t2 / t1;

  std::cout << "A entrada cresceu " << razaoEntrada << " vezes." << std::endl;
  std::cout << "O tempo cresceu " << razaoTempo << " vezes." << std::endl;

  if (razaoTempo <= (razaoEntrada * 1.2) && razaoTempo >= (razaoEntrada * 0.8)) {
    std::cout << "Parece LINEAR O(n) - (Tempo acompanhou a entrada)" << std::endl;
  } 
  else if (razaoTempo >= (razaoEntrada * razaoEntrada * 0.8)) {
    std::cout << "Parece QUADRATICO O(n^2) - (Tempo cresceu ao quadrado)" << std::endl;
  } 
  else if (razaoTempo < razaoEntrada) {
    std::cout << "Parece LOGARITMICO O(log n) - (Cresceu muito devagar)" << std::endl;
  }
}