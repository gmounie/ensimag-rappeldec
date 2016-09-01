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

#include <stdlib.h>
#include <string.h>
#include "elempool.h"
#include "bitset1000.h"

static unsigned char *memoireElemPool = 0;

/**
   Fonction allouant un element
*/
struct Elem* allocElem() {
	/* ajouter votre code ici / add your code here */
	return 0;
}

/**
   Fonction ramasse-miette sur les elements qui ne sont pas
   atteignables depuis les têtes de listes
*/
void gcElems( struct Elem ** heads, int nbheads) {
	/* ajouter votre code ici / add your code here */
}

void initElems() {
	bt1k_reset();
	if (! memoireElemPool)
	  memoireElemPool = malloc(1000 * sizeof(struct Elem));
	memset(memoireElemPool, 0, 1000 * sizeof(struct Elem));
}
