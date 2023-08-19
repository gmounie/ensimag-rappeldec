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
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const uint32_t NB = 100;

void fibon(const uint32_t n, uint32_t p[static n]) {
  // C11 array args, p is guaranteed by programmer to be at least n
  for (uint32_t i = 0; i < n; i++)
    if (i < 1) // BUG: i < 2
      p[i] = i;
    else
      p[i] = p[i - 1] + p[i - 2]; // BUG: read p[-1]
}

int main() {
  assert(NB > 2);
  uint32_t *p = malloc(sizeof(uint32_t[NB]));
  assert(p != NULL);
  memset(p, 0, sizeof(uint32_t[NB]));

  fibon(NB, p);

  free(p);
  return EXIT_SUCCESS;
}
