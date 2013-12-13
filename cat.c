#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

// Taille maximale d'un fichier que l'on peut lire (1 Mo)
#define MAX_SIZE (1024 * 1024)

void display_file(int fd) {
  char buf[MAX_SIZE];
  // On copie le contenu du fichier dans buf.
  // n est le nombre d'octets lus dans le fichier.
  int i, n = read(fd, buf, MAX_SIZE);
  // On affiche chaque caractère à la main plutôt qu'avec %s,
  // car rien ne garantit que le fichier se termine par un 0.
  for (i = 0; i < n; i++)
    printf("%c", buf[i]);
}

int main(int argc, char ** argv) {
  int i;
  
  if (argc == 1)
    display_file(0); // 0 est le decripteur de fichier de l'entrée standard
  else
    for (i = 1; i < argc; i++) {
      int fd = open(argv[i], O_RDONLY); // le mode d'ouverture est lecture seule
      display_file(fd);
      close(fd);
    }
  return 0;
}
