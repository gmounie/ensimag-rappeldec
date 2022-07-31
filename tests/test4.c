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

#include "../src/elempool.h"
#include "utest.h"

void test4(void) {
  init_elems();
  /* Allocate all the 1000 elements */
  struct elem *heads[1000] = {};
  struct elem *e;

  for (int i = 0; i < 1000; i++) {
    e = alloc_elem();
    u_isnotnull("unexpected allocation failure", e);

    e->val = i;
    e->next = heads[i];
    heads[i] = e;
  }
  /* No element should be free */
  e = alloc_elem();
  u_isnull("unexpected allocation success", e);

  /* check the list */
  for (int i = 0; i < 1000; i++) {
    u_assert("incoherent val field in elem", heads[i]->val == i);
    u_isnull("incoherent next field in elem", heads[i]->next);
  }

  /* free none of the elements */
  gc_elems(1000, heads);

  /* No element should be free */
  e = alloc_elem();
  u_isnull("unexpected allocation success", e);

  /* free half of the elements */
  gc_elems(500, heads);

  /* allocate 500 elements */
  for (int i = 500; i < 1000; i++) {
    e = alloc_elem();
    u_isnotnull("unexpected allocation failure", e);

    e->val = i;
    e->next = 0;
    heads[i] = e;
  }

  /* No element should be free */
  e = alloc_elem();
  u_isnull("unexpected allocation success", e);

  /* check the list */
  for (int i = 0; i < 1000; i++) {
    u_assert("incoherent val field in elem", heads[i]->val == i);
    u_isnull("incoherent next field in elem", heads[i]->next);
  }

  /* free all elements */
  heads[0] = 0;
  gc_elems(0, heads);

  u_success("test4");
}
