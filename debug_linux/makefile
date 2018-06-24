objs = main.o file_io.o
#CC:= /usr/local/toolchain/toolchain-4.5.1/bin/arm-none-linux-gnueabi-gcc
CC:= gcc
app:$(objs)
	$(CC) -o app $(objs)

main.o:init.h
file_io:file_io.h
clean:
	rm app $(objs)
	rm -r user/
