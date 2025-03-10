CXX = g++ #kompiliatorius
CXXFLAGS = -std=c++17 -O3 #kompiliatoriaus veliaveles

EXEC1 = 1strategija
EXEC2 = 2strategija

all: $(EXEC1) $(EXEC2)

$(EXEC1): programaFunkcijos.o strategija1.o
	$(CXX) $(CXXFLAGS) -o $(EXEC1) programaFunkcijos.o strategija1.o

$(EXEC2): programaFunkcijos.o strategija2.o
	$(CXX) $(CXXFLAGS) -o $(EXEC2) programaFunkcijos.o strategija2.o

strategija1.o: 1_strategija/strategija1.cpp
	$(CXX) $(CXXFLAGS) -c 1_strategija/strategija1.cpp -o strategija1.o

strategija2.o: 1_strategija/strategija2.cpp
	$(CXX) $(CXXFLAGS) -c 1_strategija/strategija2.cpp -o strategija2.o

clean:
	rm -f *.o $(EXEC1) $(EXEC2)

run1: $(EXEC1)
	./$(EXEC1)

run2: $(EXEC2)
	./$(EXEC2)