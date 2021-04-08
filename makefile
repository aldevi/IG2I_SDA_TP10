c=gcc
op=-Wall -Wextra

all : topoffice.exe

topoffice.exe : main.c prod.h lireCommande.o lireProduits.o
	$(c) $(op) main.c lireCommande.o lireProduits.o -o topoffice.exe	

lireCommande.o : lireCommande.c lireCommande.h
	$(c) $(op) -c lireCommande.c -o lireCommande.o

lireProduits.o : lireProduits.c lireProduits.h
	$(c) $(op) -c lireProduits.c -o lireProduits.o

clean :
	rm -rf *.o *.exe