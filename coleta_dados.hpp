#ifndef COLETA_DADOS_HPP
#define COLETA_DADOS_HPP

#include <vector>
#include <string>

typedef void (*AlgoritmoOrdenacao)(std::vector<int>&);
typedef int (*AlgoritmoBusca)(const std::vector<int>&, int);

void realizarExperimentoOrdenacao(AlgoritmoOrdenacao algoritmo, std::string nomeAlgoritmo, std::vector<int> tamanhos, int repeticoes);

void realizarExperimentoBusca(AlgoritmoBusca algoritmo, std::string nomeAlgoritmo, std::vector<int> tamanhos, int repeticoes);

void verificarCrescimento(const std::vector<int>& tamanhos, const std::vector<double>& tempos);

#endif