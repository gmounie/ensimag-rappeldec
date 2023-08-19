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

const unsigned int SIZE = 10000; // size may be a misleading name

/**
   fibon overwrite the array 4 times the length allocated by main

   Thanks to the C11 array size notation, gcc-12+ detects the bug and
   warns you ! Read the warnings ! Solve them !

   Note that older or other compilers may miss it. Use as recent as
   possible compiler. Even for quite stable language as C, it is
   helpful.

   Note also that with the old classical notation, aka.
     unsigned int size, unsigned int *p

   or if you do not indicate the size of the array in the argument,
   the compiler may not help you.

   @param size size of the array
   @param p array of size "size"
 */
void fibon(unsigned int size, unsigned int p[static size]) {
  for (unsigned int i = 0; i <= size; i++)
    if (i < 2)
      p[i] = i;
    else
      p[i] = p[i - 1] + p[i - 2];
}

int main() {
  assert(SIZE > 2);

  unsigned int *p = malloc(SIZE); // BUG: 4x smaller than correct sizeof( int[SIZE] ));
  assert(p != NULL);

  fibon(SIZE, p);

  free(p);
  return 0;
}
