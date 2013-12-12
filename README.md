c-2013-tp8
==========

L'objectif est de réécrire certaines commandes Unix en utilisant tableaux, fonctions et pointeurs.

Chaînes de caractères
---------------------
En C, les chaînes de caractère (*string* en anglais) sont des tableaux de `char` se terminant par le caractère de code 0. Exemples :
* définition / affichage :
```c
```

* définition avec la syntaxe tableau :
```c
```

* fonctions courantes (dans `string.h`) :
```c
```

echo
----
La commande `echo` affiche ses arguments. On les lits dans les arguments donnés à `main` :

```c
#include <stdio.h>

int main(int argc, char ** argv) {
  int i;
  for (i = 0; i < argc; i++)
    printf("%s", argv[i]);
  return 0;
}
```

ls
--
