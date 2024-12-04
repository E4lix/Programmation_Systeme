# Variables
CC = gcc            # Le compilateur à utiliser
CFLAGS = -g -W -Wall -std=c99  # Options de compilation (ex: afficher tous les warnings, générer des informations de débogage)

# 1. Règle pour compiler l'exécutable 'Thread'
Thread: Exo3.o
	$(CC) Exo3.o $(CFLAGS) -o Thread

# 2. Règle pour compiler les fichiers objet (.o)
Exo3.o: Exo3.c

# 3. Règle pour nettoyer les fichiers générés (optionnel mais souvent utile)
clean:
	rm -f *.o Thread