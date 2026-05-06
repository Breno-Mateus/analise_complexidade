#include "coleta_dados.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>

void verificarCrescimento(const std::vector<int>& tamanhos, const std::vector<double>& tempos) {
  if (tamanhos.size() < 2) return;

  double somaTaxasCrescimento = 0;
  int intervalos = 0;

  //lógica para calcular a taxa de crescimento média entre os pontos consecutivos
  for (size_t i = 1; i < tamanhos.size(); i++) {
    double n1 = tamanhos[i-1];
    double n2 = tamanhos[i];
    double t1 = tempos[i-1];
    double t2 = tempos[i];

    if (t1 > 0.0001) {
      double razaoN = n2 / n1;
      double razaoT = t2 / t1;
      
      somaTaxasCrescimento += (razaoT / razaoN);
      intervalos++;
    }
  }

  double taxaMedia = somaTaxasCrescimento / intervalos;

  std::cout << "\n>>> ANÁLISE DE VARIAÇÃO MÉDIA <<<" << std::endl;
  std::cout << "Taxa de aceleração média: " << taxaMedia << std::endl;

  if (taxaMedia >= 1.6) {
    std::cout << "Resultado: Melhor ajuste QUADRÁTICO O(n^2)" << std::endl;
  } 
  else if (taxaMedia > 1.05) {
    std::cout << "Resultado: Melhor ajuste LOG-LINEAR O(n log n)" << std::endl;
} 
  else if (taxaMedia >= 0.9) {
    std::cout << "Resultado: Melhor ajuste LINEAR O(n)" << std::endl;
  } 
  else {
    std::cout << "Resultado: Melhor ajuste LOGARÍTMICO O(log n)" << std::endl;
  }
}

void realizarExperimento(AlgoritmoOrdenacao algoritmo, std::string nomeAlgoritmo, std::vector<int> tamanhos, int repeticoes) {
  std::cout << "\n--- Iniciando Experimento: " << nomeAlgoritmo << " ---" << std::endl;
  std::cout << "n\t\t| Tempo Médio (ms)" << std::endl;
  std::cout << "------------------------------------" << std::endl;

  // Configura a semente do gerador uma única vez usando o relógio atual
  srand(time(NULL));

  std::vector<double> tempos(tamanhos.size());

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
    tempos[i] = tempoMedio;
  }

  std::cout << "------------------------------------" << std::endl;
  verificarCrescimento(tamanhos, tempos);
}