all: threads.o performance

threads.o:
	g++ -pthread -g --std=c++1z main.cpp -o $@

performance: threads.o
	./performace_test.sh

clean:
	rm -rf *.png *.measures *.o
