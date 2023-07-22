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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct elem {
  struct elem *next;
} Elem;

uint64_t list_length(Elem *h) {
  uint64_t l = 0;
  while (h != NULL) {
    h = h->next;
    l++;
  }
  return l;
}

int main(int argc, char *argv[static argc +1]) {
  (void)argc;

  int mypid = getpid();
  printf("My PID is: %d. Catch me with 'gdb %s %d' !\n", mypid, argv[0], mypid);
  // build a short and smallcircular list in stack
  Elem a;
  Elem b = {.next = &a};
  a = (Elem){.next = &b};
  Elem *head = &a;
  // infinite loop in list_length
  printf("list length: %lu\n", list_length(head));
  return EXIT_SUCCESS;
}
