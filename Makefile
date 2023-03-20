problem-set: problem-set.o
	g++ -o problem-set problem-set.o
problem-set.o: problem-set.cpp
	g++ -c problem-set.cpp