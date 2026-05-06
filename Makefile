programa_analise: main.o coleta_dados.o algoritmos.o
	g++ -Wall -std=c++17 main.o coleta_dados.o algoritmos.o -o programa_analise

main.o: main.cpp coleta_dados.hpp algoritmos.hpp
	g++ -Wall -std=c++17 -c main.cpp

coleta_dados.o: coleta_dados.cpp coleta_dados.hpp
	g++ -Wall -std=c++17 -c coleta_dados.cpp

algoritmos.o: algoritmos.cpp algoritmos.hpp
	g++ -Wall -std=c++17 -c algoritmos.cpp

test: programa_analise
	./programa_analise

clean:
	rm -f *.o programa_analise