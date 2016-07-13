default: 
	g++ recall_rate.cpp Utility.cpp -o recall_rate `pkg-config --cflags --libs opencv`
clean:
	rm -f *.o
