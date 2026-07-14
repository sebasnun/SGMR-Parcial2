CXX = g++
CXXFLAGS = -Wall -std=c++17
SRC = src/main.cpp src/Recurso.cpp src/RecursoVehicular.cpp src/RecursoHumano.cpp \
      src/Ambulancia.cpp src/Helicoptero.cpp src/Medico.cpp src/Rescatista.cpp \
      src/Mision.cpp src/Controlador.cpp
OUT = sgmr

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
