c=gcc
op=-Wall -Wextra

all : topoffice.exe

topoffice.exe : main.c prod.h
	$(c) $(op) main.c -o topoffice.exe	

clean :
	rm -rf *.o *.exe