CXX       := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

BIN     := bin
SRC     := src
INCLUDE := include
LIB     := lib
LIBRARIES   := -l sfml-graphics -l sfml-system -l sfml-window -l sfml-audio -l sfml-network
EXECUTABLE  := MTdigitalRain


all: $(BIN)/$(EXECUTABLE)

run: all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES) -static

clean:
	@echo "Clearing..."
	del $(BIN)/$(EXECUTABLE).exe