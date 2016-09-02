/**
   Copyright (C) 2015 by Gregory Mounie 
   
   This file is part of ExamGC

   ExamGC is free software: you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.


   ExamGC is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>. 
*/

#include "utest.h"
#include "../src/elempool.h"


void test0(void)
{  
	initElems();
	struct Elem *e = allocElem();
	u_isnotnull("unexpected allocation failure", e);
	e->val = 10;
	e->next = 0;
	/* free all the elements */
	gcElems(& e, 1);
	/* free all the elements */
	gcElems(& e, 0);
	u_success("test0");
}
