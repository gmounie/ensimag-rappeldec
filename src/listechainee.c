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

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct elem {
  long unsigned int val;
  struct elem *next;
};

/* Affiche les éléments de la liste passée en paramètre sur la sortie
 * standard. */
void affichage_liste(struct elem const *const liste) {
  /**
     Votre code est à mettre ici !
  */
  (void)liste; // to remove
}

/* Crée une liste simplement chainée à partir des nb_elems éléments du
 * tableau valeurs. */
struct elem *creation_liste(size_t nb_elems,
                            long unsigned int const valeurs[nb_elems]) {
  /**
     Votre code est à mettre ici !
  */
  (void)nb_elems; // to remove
  (void)valeurs;  // to remove
  return NULL;
}

/**
   Libère toute la mémoire associée à la liste passée en paramètre.

   @param liste head list, pointer on first element, not NULL
*/
void destruction_liste(struct elem liste[static 1]) {
  /**
     Votre code est à mettre ici !
  */
  (void)liste; // to remove
}

/**
 * Inverse la liste simplement chainée passée en paramètre. Le
 * paramètre liste contient l'adresse du pointeur sur la tête de liste
 * à inverser.
 * @param liste head list address, not NULL
 */
void inversion_liste(struct elem *liste[static 1]) {
  /**
     Votre code est à mettre ici !
  */
  (void)liste; // to remove
}

const long unsigned int TAILLE = 100;
const long unsigned int TAILLE_GRANDE = 1000000;

int main(void) {
  /* Test d'affichage d'une liste créée à la main. */
  struct elem e1, e2, e3;
  e1.val = 0;
  e2.val = 1;
  e3.val = 2;
  e1.next = &e2;
  e2.next = &e3;
  e3.next = NULL;
  affichage_liste(&e1);

  long unsigned int valeurs[TAILLE];
  for (size_t i = 0; i < TAILLE; i++) {
    valeurs[i] = i;
  }

  struct elem *tab_elem = creation_liste(TAILLE, valeurs);
  assert(tab_elem != NULL);

  /* Test que la liste dans l'ordre */
  struct elem *tmp;
  long unsigned int idx;
  for (tmp = tab_elem, idx = 0; tmp != NULL; idx++, tmp = tmp->next) {
    assert(tmp->val == idx);
  }
  /* Test que la liste est complète (à la suite du test sur l'ordre) */
  assert(idx == TAILLE);

  printf("Liste créée:\n");
  affichage_liste(tab_elem);
  inversion_liste(&tab_elem);
  assert(tab_elem != NULL);
  printf("Liste inversée:\n");
  affichage_liste(tab_elem);

  /* Vérifie que la liste est inversée et complète */
  for (tmp = tab_elem, idx = TAILLE - 1; tmp != NULL; --idx, tmp = tmp->next) {
    assert(tmp->val == idx);
  }
  assert(idx == (long unsigned int)(0UL - 1));

  /* Pour tester le bon fonctionnement de la fonction suivante, on
   * lancera valgrind sur le programme pour vérifier qu'aucune fuite
   * mémoire n'est présente. */
  destruction_liste(tab_elem);

  /* vérification avec une liste très longue (1M) élément pour faire
   * exploser les implémentations récursives (taille de la pile == 8Mo) */
  long unsigned int *valeurs_nombreuses = malloc(sizeof(long unsigned int[TAILLE_GRANDE]));
  for (size_t i = 0; i < TAILLE_GRANDE; i++) {
    valeurs_nombreuses[i] = i;
  }

  tab_elem = creation_liste(TAILLE, valeurs_nombreuses);
  assert(tab_elem != NULL);
  destruction_liste(tab_elem);
  
  return EXIT_SUCCESS;
}
