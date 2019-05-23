ME:=  $(patsubst %.cpp,%.o,$(wildcard *.cpp))

all:$(FILENAME)

%.o : %.cpp
	g++  $< -o $@;

% : %.o
	./$@.o;

clean:
	rm -rf *.o
