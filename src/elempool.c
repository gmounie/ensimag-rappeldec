/**
   Copyright (C) 2015-2016 by Gregory Mounie

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

#include "elempool.h"
#include "bitset1000.h"
#include <stdlib.h>
#include <string.h>

static unsigned char *memoire_elem_pool = 0;

/**
   Fonction allouant un element
*/
struct elem *alloc_elem(void) {
  /* ajouter votre code ici / add your code here */
  return 0;
}

/**
   Fonction ramasse-miette sur les elements qui ne sont pas
   atteignables depuis les têtes de listes

   @param nbheads number of list heads in array heads
   @param heads array of list heads
*/
void gc_elems(const int nbheads, struct elem *const heads[nbheads]) {
  /* ajouter votre code ici / add your code here */
  (void)nbheads; // to remove
  (void)heads;   // to remove
}

void init_elems() {
  bt1k_reset();
  if (memoire_elem_pool == NULL) {
    memoire_elem_pool = malloc(sizeof(struct elem[1000]));
  }
  memset(memoire_elem_pool, 0, sizeof(struct elem[1000]));
}
