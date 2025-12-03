CXXFLAGS="-std=c++20"


all: 1/1 1/2 2/1 2/2 3/1

1/1: 1/1.cpp
	$(CXX) 1/1.cpp -o 1/1 $(CXXFLAGS)

1/2: 1/2.cpp
	$(CXX) 1/2.cpp -o 1/2 $(CXXFLAGS)

2/1: 2/1.cpp
	$(CXX) 2/1.cpp -o 2/1 $(CXXFLAGS)

2/2: 2/2.cpp
	$(CXX) 2/2.cpp -o 2/2 $(CXXFLAGS)

3/1: 3/1.cpp
	$(CXX) 3/1.cpp -o 3/1 $(CXXFLAGS)

clean:
	rm 1/1 1/2 2/1 2/2 3/1
