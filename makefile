c=gcc
op=-Wall -Wextra

all : topoffice.exe

topoffice.exe : main.c prod.h genererFacture.o
	$(c) $(op) main.c genererFacture.o -o topoffice.exe

genererFacture.o: genererFacture.c genererFacture.h
	$(c) $(op) genererFacture.c -c

clean :
	rm -rf *.o *.exe