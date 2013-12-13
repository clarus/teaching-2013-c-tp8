#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv) {
  int i, n_option = 0;
  for (i = 1; i < argc; i++) {
    if (i == 1 && strcmp(argv[1], "-n") == 0)
      n_option = 1;
    else {
      printf("%s", argv[i]);
      if (i == argc - 1) {
        if (!n_option)
          printf("\n");
      } else
        printf(" ");
    }
  }
  return 0;
}
