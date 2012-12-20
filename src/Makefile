
CC=g++
SHARE_FLAGS=-shared
TARGET=libyangutil.so

all:
	make -C mytime
	make -C mystring
	make -C mythread

create_yangutil:
	$(CC) $(SHARE_FLAGS) -o $(TARGET) \
	mytime/objs/* \
	mystring/objs/* \
	mythread/objs/*
	
	cp $(TARGET) ../test/shared_test
	cp ./mytime/*.h ../test/shared_test/include/mytime
	cp ./mystring/*.h ../test/shared_test/include/mystring
	cp ./mythread/*.h ../test/shared_test/include/mythread

clean:
	make clean -C mytime
	make clean -C mystring
	make clean -C mythread

	

	
