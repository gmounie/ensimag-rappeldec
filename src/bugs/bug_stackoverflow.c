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

typedef struct elem {
  struct elem *next;
} Elem;

int functional_list_length(Elem *h) {
  if (h == NULL)
    return 0;

  return 1 + functional_list_length(h->next); // BUG: unbounded
                                              // recursivity thus
                                              // potential stack
                                              // overflow
}

int main() {
  // a circular list will trigger the bug
  Elem a;
  Elem b = {&a};
  a = (Elem){&b};
  Elem *head = &a;

  printf("list length: %d\n", functional_list_length(head));
  return 0;
}
