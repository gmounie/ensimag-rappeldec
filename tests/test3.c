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

void test3(void) {
  init_elems();
  struct elem *head = NULL;
  struct elem *e;

  /* allocate 2 * 500 but chain only one other 2 */
  for (int i = 0; i < 500; i++) {
    e = alloc_elem();
    u_isnotnull("unexpected allocation failure", e);

    e = alloc_elem();
    u_isnotnull("unexpected allocation failure", e);

    e->val = i;
    e->next = head;
    head = e;
  }
  /* No element should be free */
  e = alloc_elem();
  u_isnull("unexpected allocation success", e);

  /* free the 500 elems not in the liste */
  gc_elems(1, &head);

  /* allocate 500 and chain them */
  for (int i = 0; i < 500; i++) {
    e = alloc_elem();
    u_isnotnull("unexpected allocation failure", e);

    e->val = 500 + i;
    e->next = head;
    head = e;
  }
  /* No element should be free */
  e = alloc_elem();
  u_isnull("unexpected allocation success", e);

  /* check the list */
  e = head;
  for (int j = 0; j < 1000; j++) {
    u_assert("incoherent val field in elem", e->val == (1000 - j - 1));
    e = e->next;
  }
  u_isnull("incoherent end of list", e);

  /* free all elements */
  head = NULL;
  gc_elems(1, &head);

  u_success("test3");
}
