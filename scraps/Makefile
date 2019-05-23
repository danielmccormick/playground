ME:=  $(patsubst %.cpp,%.o,$(wildcard *.cpp))

all:$(FILENAME)

%.o : %.cpp
	g++ $< -o $@ -std=c++11;

% : %.o
	./$@.o;

clean:
	rm -rf *.o
