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

#define RECURSIVE

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct elem {
    int val;
    struct elem *next;
};

/* Crée une liste simplement chainée à partir des nb_elems éléments du
 * tableau valeurs. */
struct elem *creation_liste(int *valeurs, size_t nb_elems) {
    assert(nb_elems != 0 && valeurs != NULL);
    struct elem *tete = calloc(1, sizeof(struct elem));
    tete->val = valeurs[0];
    struct elem *courant = tete;

    for (size_t i = 1; i < nb_elems; i++) {
        courant->next = calloc(1, sizeof(struct elem));
        courant->next->val = valeurs[i];
        courant = courant->next;
    }

    return tete;
}

/* Libère toute la mémoire associée à la liste passée en paramètre. */
void destruction_liste(struct elem *liste) {
    struct elem *courant = liste;
    while (courant != NULL) {
        struct elem *suivant = courant->next;
        free(courant);
        courant = suivant;
    }
}

/* Affiche les éléments de la liste passée en paramètre sur la sortie
 * standard. */
void affichage_liste(struct elem *liste) {
    for (struct elem *courant = liste; courant != NULL; courant = courant->next) {
        printf("%u ", courant->val);
    }
    printf("\n");
}

/* Inverse la liste simplement chainée passée en paramètre. Le
 * paramètre liste contient l'adresse du pointeur sur la tête de liste
 * à inverser. */
#if !defined RECURSIVE
void inversion_liste(struct elem **liste) {
    /**
       Votre code est à mettre ici !
    */
    if (liste == NULL || *liste == NULL) {
        return;
    }

    struct elem *cur = *liste;
    struct elem *next = cur->next;
    cur->next = NULL;

    while (next != NULL) {
        struct elem *next_next = next->next;
        next->next = cur;
        cur = next;
        next = next_next;
    }

    *liste = cur;
}
#else
struct elem *reverse(struct elem *head)
{
	struct elem *tmp;
	if (head == NULL || head->next == NULL)
           return head;

	tmp = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
	return tmp;
}

void inversion_liste(struct elem **liste)
{
	/**
	   Votre code est à mettre ici !
	*/
        if (liste == NULL || *liste == NULL)
                return;
	*liste = reverse(*liste);
}
#endif

const int TAILLE = 100;

int main(void)
{
    /* Test d'affichage d'une liste créée à la main. */
    struct elem e1, e2, e3;
    e1.val = 0;
    e2.val = 1;
    e3.val = 2;
    e1.next = &e2;
    e2.next = &e3;
    e3.next = NULL;
    affichage_liste(&e1);

    int valeurs[TAILLE];
    for (size_t i = 0; i < TAILLE; i++) {
        valeurs[i] = i;
    }
    struct elem *tab_elem = creation_liste(valeurs, TAILLE);
    assert(tab_elem != NULL);

    printf("Liste créée:\n");
    affichage_liste(tab_elem);
    inversion_liste(&tab_elem);
    assert(tab_elem != NULL);
    printf("Liste inversée:\n");
    affichage_liste(tab_elem);

    struct elem *tmp;
    int idx;
    for (tmp = tab_elem, idx = TAILLE - 1; tmp != NULL; --idx, tmp = tmp->next) {
        assert(tmp->val == idx);
    }

    /* Pour tester le bon fonctionnement de la fonction suivante, on
     * lancera valgrind sur le programme pour vérifier qu'aucune fuite
     * mémoire n'est présente. */
    destruction_liste(tab_elem);

    return EXIT_SUCCESS;
}
