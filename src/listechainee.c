/**
   Copyright (C) 2016 by Gregory Mounie 
   
   This file is part of RappelDeC

   RappelDeC is free software: you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.


   RappelDeC is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>. 
*/

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
	struct elem *tete = NULL;
	while (*liste) {
		struct elem *tmp = *liste;
		*liste = (*liste)->next;
		tmp->next = tete;
		tete = tmp;
	}
	*liste = tete;
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

	free(tabelem);
	tabelem=NULL;
	return 0;
}
