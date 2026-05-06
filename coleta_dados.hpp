#ifndef COLETA_DADOS_HPP
#define COLETA_DADOS_HPP

#include <vector>
#include <string>

typedef void (*AlgoritmoOrdenacao)(std::vector<int>&);

void realizarExperimento(AlgoritmoOrdenacao alg, std::string nomeAlg, std::vector<int> tamanhos, int repeticoes);

void verificarCrescimento(int n1, double t1, int n2, double t2);

#endif