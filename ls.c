#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

void ls(char * path) {
  int fd, size;
  struct stat stat; // variable représentant le status du fichier
  // (les structures ne sont pas au programme mais nécessaires ici)
  
  fd = open(path, O_RDONLY);
  fstat(fd, &stat); // lecture du status
  size = stat.st_size; // la taille est donnée par le champ st_size
  printf("%6d %s\n", size, path);
  close(fd);
}

int main(int argc, char ** argv) {
  int i;
  if (argc == 1)
    ls(".");
  else
    for (i = 1; i < argc; i++)
      ls(argv[i]);
  return 0;
}
