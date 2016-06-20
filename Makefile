SDLINC = -I/Library/Frameworks/SDL2.framework/Headers/

all: joytest

test: joytest
	./joytest

joytest: joytest.cpp
	g++ -o joytest $(SDLINC) joytest.cpp -lSDL2

clean:
	rm -rf $(PLUGIN_TARGET) joytest *.o

edit:
	vim $(PLUGIN).cpp
