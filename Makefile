TARGET=exp2-log2-sse

$(TARGET): main.cpp Exp2.o
	g++ -O2 -std=c++11 $^ -o $@ -lm

Exp2.o: Exp2.s
	gcc -c $^

clean:
	rm -rf *.o $(TARGET)
