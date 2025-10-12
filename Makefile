# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -I Ssh -I Menu

# Fichiers sources
SRC = main.c Ssh/ssh.c Ssh/ssh_menu.c Menu/menu.c

# Fichiers objets
OBJ = $(SRC:.c=.o)

# Nom de l'exécutable
TARGET = programme

# Règle principale
all: $(TARGET)

# Lien final
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Compilation de chaque fichier .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyer les fichiers générés
clean:
	rm -f $(OBJ) $(TARGET)

# Recompiler entièrement
rebuild: clean all
