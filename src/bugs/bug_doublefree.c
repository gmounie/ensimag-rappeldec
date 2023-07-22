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

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

const unsigned int SIZE = 100;

// Double free heap allocated array p, inside and outside fibon
// function. NB : C11 array size argument.
// Old alternative : uint *p
void fibon(const unsigned int size, unsigned int p[static size]) {
  for (unsigned int i = 0; i < size; i++)
    if (i < 2)
      p[i] = i;
    else
      p[i] = p[i - 1] + p[i - 2];
  free(p); // BUG: you must free only once
}

int main() {
  assert(SIZE > 2);

  unsigned int *p = malloc(sizeof(int[SIZE]));
  assert(p != NULL);

  fibon(SIZE, p);

  free(p); // BUG: you must free only once
  return EXIT_SUCCESS;
}
