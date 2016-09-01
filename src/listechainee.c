#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct elem {
	int val;
	struct elem* next;
};

void inversion_liste(struct elem **liste){
	/**
	   Votre code est à mettre ici !
	*/
};

const int TAILLE=100;

int main() {
	struct elem *tabelem = malloc(sizeof(struct elem)*TAILLE);
	assert(tabelem);
	
	for(int i=0; i < TAILLE; i++) {
		tabelem[i] = (struct elem){i, & tabelem[i+1] };
	}
	tabelem[TAILLE-1].next = NULL;

	struct elem *tete = & tabelem[0];

	inversion_liste(&tete);
	assert(tete);
	
	struct elem *tmp= tete;
	int idx= TAILLE-1;
	for(;tmp; --idx, tmp=tmp->next) {
		assert(tmp->val == idx);
		assert(tmp ==  & tabelem[idx]);
	}

	return 0;
}
