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

void test1(void) {
  init_elems();
  for (int i = 0; i < 1001; i++) {
    struct elem *e = alloc_elem();
    u_isnotnull("unexpected allocation failure", e);

    e->val = i;
    e->next = 0;
    e = NULL;
    gc_elems(1, &e);
  }
  u_success("test1");
}
