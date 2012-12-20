
CC=g++
CFLAGS=-c -fPIC

SRC=${wildcard *.cpp}
OBJS=${SRC:%.cpp=objs/%.o}

all : $(OBJS)

objs/%.o : %.cpp
	$(CC) $(CFLAGS) $(SHARE_FLAGS) -o $@ $<
	
clean:
	rm -f objs/*
	