#include <assert.h>
#include <complex.h>
#include <stdlib.h>

/**
   Ajouter la fonction de comparaison du tri ici
*/

int triarg(const void *a, const void *b) {
  double complex const *ca = a;
  double complex const *cb = b;

  double tmp = (carg(*ca) - carg(*cb));
  if (tmp < 0.0)
    return -1;
  if (tmp == 0.0)
    return 0;
  return 1;
}
const int TAILLE = 100;

int main(void) {
  /* initialisation du tableau */
  double complex tableau[TAILLE];
  srand48(123456);
  for (int i = 0; i < TAILLE; i++) {
    tableau[i] = drand48() + (drand48() * 1.0i);
  }

  /**
     Mettre le code d'appel de qsort ici
  */

  qsort(tableau, 100, sizeof(double complex), triarg);

  /**
     Vérification du tri
  */
  for (int i = 0; i < TAILLE - 1; i++) {
    assert(carg(tableau[i]) <= carg(tableau[i + 1]));
  }

  return EXIT_SUCCESS;
}
