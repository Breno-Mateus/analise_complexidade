#include "coleta_dados.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>

void realizarExperimento(AlgoritmoOrdenacao algoritmo, std::string nomeAlgoritmo, std::vector<int> tamanhos, int repeticoes) {
  std::cout << "\n--- Iniciando Experimento: " << nomeAlgoritmo << " ---" << std::endl;
  std::cout << "n\t\t| Tempo Médio (ms)" << std::endl;
  std::cout << "------------------------------------" << std::endl;

  // Configura a semente do gerador uma única vez usando o relógio atual
  srand(time(NULL)); 

  for (int i = 0; i < (int)tamanhos.size(); i++) {
    int n = tamanhos[i];
    double somaTempos = 0.0;

    for (int r = 0; r < repeticoes; r++) {  
      std::vector<int> vetor_desordenado(n);

      // Preenche o vetor com números aleatórios
      for (int j = 0; j < n; j++) {
        vetor_desordenado[j] = rand() % (n * 10); 
      }

      // Medir o tempo de execução do algoritmo
      auto inicio = std::chrono::high_resolution_clock::now();
      algoritmo(vetor_desordenado);
      auto fim = std::chrono::high_resolution_clock::now();

      std::chrono::duration<double, std::milli> duracao = fim - inicio;
      somaTempos += duracao.count();
    }
    
    // Calcula o tempo médio e exibe os resultados
    double tempoMedio = somaTempos / repeticoes;
    std::cout << n << "\t\t| " << tempoMedio << " ms" << std::endl;
  }
    
  std::cout << "------------------------------------" << std::endl;
}


void verificarCrescimento(double t1, double t2) {
  double razaoEntrada = 2;
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