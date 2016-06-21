SDLINC = -I/Library/Frameworks/SDL2.framework/Headers/

all: joytest

test: joytest
	./joytest

joytest: joytest.cpp
	g++ -Wall -o joytest $(SDLINC) joytest.cpp -lSDL2

clean:
	rm -rf joytest *.o

edit:
	vim joytest.cpp
