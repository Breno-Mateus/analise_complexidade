# Análise de Complexidade de Algoritmos 📊

Este repositório contém uma ferramenta desenvolvida em C++ para realizar a **análise empírica de desempenho** de algoritmos clássicos de ordenação e busca. O objetivo principal é confrontar os tempos de execução coletados na prática com as complexidades teóricas definidas pela notação **Big-O**.

## 🧠 Algoritmos Analisados

### Ordenação
* **Insertion Sort**: Complexidade quadrática $O(n^2)$.
* **Merge Sort**: Complexidade log-linear $O(n \log n)$.

### Busca
* **Busca Sequencial**: Complexidade linear $O(n)$.
* **Busca Binária**: Complexidade logarítmica $O(\log n)$ (executada em vetores previamente ordenados).

## 🚀 Como Usar (Via Makefile)

O projeto utiliza um `Makefile` para automatizar o processo de compilação e limpeza, garantindo que as flags de otimização e o padrão C++17 sejam aplicados corretamente.

### Compilação
Para compilar o projeto e gerar o executável, basta rodar o comando:
```bash
make
```

### Execução
Após a compilação bem-sucedida, execute o programa com:
```bash
make test
```

### Limpeza
Para remover os arquivos binários e o executável gerado, utilize:
```bash
make clean
```

### 🛠️ Metodologia Experimental
O sistema foi projetado para garantir a precisão dos dados através de:
* **Amostragem Múltipla**: Cada algoritmo é executado diversas vezes para cada tamanho de entrada (n) para obter uma média estável. 
* **Progressão Geométrica**: Os tamanhos de entrada dobram a cada teste para facilitar a observação das taxas de crescimento.
* **Veredito Automático**: O código inclui uma função de análise que calcula a taxa de aceleração média e sugere qual função matemática ($n^2$, $n \log n$, etc.) melhor descreve os dados reais.

### 📁 Estrutura do Repositório
* **main.cpp**: Ponto de entrada do programa e configuração dos parâmetros de teste.
* **algoritmos.cpp/hpp**: Implementação rigorosa dos algoritmos de busca e ordenação.
* **coleta_dados.cpp/hpp**: Lógica de cronometragem e análise estatística de crescimento.
* **Makefile**: Script de automação de compilação.
* **README.md**: Documentação do projeto.