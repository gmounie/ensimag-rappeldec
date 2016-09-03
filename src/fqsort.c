#include <complex.h>
#include <stdlib.h>
#include <assert.h>

/**
   Ajouter la fonction de comparaison du tri ici
*/


int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	/* initialisation du tableau */
	float complex tableau[100];
	srand48(123456);
	for(int i=0; i < 100; i++) {
		tableau[i] = drand48() + (drand48() * 1.0i);  
	}

	/**
	   Mettre le code d'appel de qsort ici
	*/

	/**
	   Vérification du tri
	*/
	for(int i=0; i < 100-1; i++) {
		assert(carg(tableau[i]) < carg(tableau[i+1]));
	}
	return 0;
} 
