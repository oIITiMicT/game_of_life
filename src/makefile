CC = gcc
deps = main.o alloc.o evolve.o generator.o nieghbors.o tester.o

autkom: $(deps)
	$(CC) $(deps) -o autkom

main.o: evolve.h tester.h
alloc.o: alloc.h
evolve.o: evolve.h
tester.o: tester.h
generator.o: generator.h
nieghbors.o: nieghbors.h
