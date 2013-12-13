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
### Questions :
* Écrire un programme qui demande le nom de l'utilisateur puis l'affiche.
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

### Questions :
* Séparer l'affichage des arguments par des espaces et terminer par un retour à la ligne.
* Prendre en charge l'option `-n` qui désactive l'affichage du dernier retour à la ligne.

ls
--
