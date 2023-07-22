/**
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or (at
   your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct elem {
  struct elem *next;
} Elem;

// Valid code pattern in Haskell, OCaml or LISP/Scheme, that remove
// terminal recursivity, but not in most imperative languages like
// C/C++ or Python. BUG: call recursivity depth is a linear function
// of the list length. All args, local variables and return adress are
// allocated in the stack at each call. As the stack is commonly
// limited to 8 MB, a stack overflow appears as soon as the list is
// not small. Note: Golang has 2GB stack, hidding this bug most of the
// time.
int list_length_functional_style(Elem *h) {
  if (h == NULL)
    return 0;

  return 1 + list_length_functional_style(h->next);
}

int main() {
  // a small circular list will trigger the bug too
  Elem a;
  Elem b = {.next = &a};
  a = (Elem){.next = &b};
  Elem *head = &a;

  printf("list length: %d\n", list_length_functional_style(head));
  return EXIT_SUCCESS;
}
