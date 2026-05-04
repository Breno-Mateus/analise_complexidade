CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
TARGET = programa_analise

$(TARGET): main.o coleta_dados.o algoritmos.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o coleta_dados.o algoritmos.o

main.o: main.cpp coleta_dados.hpp algoritmos.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

coleta_dados.o: coleta_dados.cpp coleta_dados.hpp
	$(CXX) $(CXXFLAGS) -c coleta_dados.cpp

algoritmos.o: algoritmos.cpp algoritmos.hpp
	$(CXX) $(CXXFLAGS) -c algoritmos.cpp

clean:
	rm -f *.o $(TARGET)