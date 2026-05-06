#ifndef COLETA_DADOS_HPP
#define COLETA_DADOS_HPP

#include <vector>
#include <string>

typedef void (*AlgoritmoOrdenacao)(std::vector<int>&);

void realizarExperimento(AlgoritmoOrdenacao algoritmo, std::string nomeAlgoritmo, std::vector<int> tamanhos, int repeticoes);

void verificarCrescimento(double t1, double t2);

#endif