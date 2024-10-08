# Makefile pour le projet de réservation

# Variables
CC = gcc
CFLAGS = -Wall -Wextra
SOURCES = main.c reservation.c util.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = gestion_reservations

# Règle par défaut
all: $(EXECUTABLE)

# Règle pour l'exécutable
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Règle pour les fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
