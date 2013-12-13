c-2013-tp8
==========

L'objectif est de réécrire certaines commandes Unix en utilisant tableaux, fonctions et pointeurs.

Chaînes de caractères
---------------------
En C, les chaînes de caractère (*string* en anglais) sont des tableaux de `char` se terminant par le caractère de code 0. Exemples :
* définition / affichage :
```c
char s[] = "hello";
printf("%s", s);
```

* définition avec la syntaxe tableau :
```c
char s[] = {'h', 'e', 'l', 'l', 'o', 0};
printf("%s", s);
```

* fonctions courantes (dans `string.h`) :
```c
length = strlen(s); // longueur de s
test = strcmp(s1, s2); // 0 ssi s1 = s2
```
### Questions
* Écrire un programme qui demande le nom de l'utilisateur puis l'affiche.
* Réécrire `printf("%s", ...)` à partir de `printf("%c", ...)`.
* Réécrire la fonction `strlen`.
* Réécrire la fonction `strcmp`.

echo
----
La commande `echo` affiche ses arguments. On les lits dans les arguments donnés à `main` :

```c
#include <stdio.h>

int main(int argc, char ** argv) {
  int i;
  for (i = 1; i < argc; i++)
    printf("%s", argv[i]);
  return 0;
}
```
`argc` signifie "argument count" et `argv` "argument values". On ne lit pas `argv[0]` car c'est le nom du programme lui-même.

### Questions
* Séparer l'affichage des arguments par des espaces et terminer par un retour à la ligne.
* Prendre en charge l'option `-n` qui désactive l'affichage du dernier retour à la ligne.

cat
---
La commande `cat` affiche le contenu d'un fichier. Un fichier est représenté par un "file descriptor" (`fd`). On l'ouvre avec `open`, le lit avec `read` et le ferme avec `close`. Fonction affichant le contenu d'un fichier :
```c
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
```
### Questions
* Écrire une commande `cat` qui affiche le contenu de chaque fichier donné en argument (on fera attention à refermer chaque fichier). On n'hésitera pas à chercher dans la documentation.
* Améliorer `cat` pour prendre en compte le cas sans argument (affichage de l'entrée standard). Le descripteur de l'entrée standard est 0.

ls
--
La commande `ls` affiche le contenu d'un dossier ou la description d'un fichier. Exemple affichant la taille en octets des fichiers donnés en arguments :
```c
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
```
### Questions
* Afficher la taille en octets, Ko, Mo ou Go suivant la valeur. On écrira une fonction auxiliaire effectuant ce traitement.
* À l'aide de la documentation, ajouter l'affichage des droits d'accès (tels que donnés par `ls -l`).
* Ajouter un maximum de fonctionnalités : affichage du contenu d'un dossier, option `-R`, ...
