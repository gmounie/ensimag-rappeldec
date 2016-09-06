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

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct elem {
    int val;
    struct elem *next;
};

/* Inverse la liste simplement chainée passée en paramètre. Le
 * paramètre liste contient l'adresse du pointeur sur la tête de liste
 * à inverser. */
void inversion_liste(struct elem **liste) {
    /**
       Votre code est à mettre ici !
    */
    if (liste == NULL || *liste == NULL) {
        return;
    }

    struct elem *cur = *liste;
    struct elem *next = cur->next;

    while (next != NULL) {
        struct elem *next_next = next->next;
        next->next = cur;
        cur = next;
        next = next_next;
    }
    *liste = cur;
}

const int TAILLE = 100;

int main(void)
{
    struct elem *tab_elem = malloc(sizeof(struct elem)*TAILLE);
    assert(tab_elem);

    for(int i = 0; i < TAILLE; i++) {
        tab_elem[i] = (struct elem){ i, &tab_elem[i + 1] };
    }
    tab_elem[TAILLE - 1].next = NULL;

    struct elem *tete = &tab_elem[0];

    inversion_liste(&tete);
    assert(tete != NULL);

    struct elem *tmp;
    int idx;
    for (tmp = tete, idx = TAILLE - 1; tmp != NULL; --idx, tmp = tmp->next) {
        assert(tmp->val == idx);
        assert(tmp ==  & tab_elem[idx]);
    }

    free(tab_elem);
    tab_elem = NULL;

    return EXIT_SUCCESS;
}
