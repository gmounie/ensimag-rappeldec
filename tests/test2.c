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



void test2(void)
{
	initElems();
	/* Allocate all the 1000 elements */
	struct Elem *head = NULL;
	struct Elem *e = 0;
	for(int i=0; i < 1000; i++) {
		e = allocElem();
		u_isnotnull("unexpected allocation failure", e);
		
		e->val = i;
		e->next = head;
		head = e;
	}

	
	/* No element should be free */
	e = allocElem();
	u_isnull("unexpected allocation success", e);

	/* check the list */
	e = head;
	for(int j = 0; j < 1000; j++) {
		u_assert("incoherent val field in Elem",
			 e->val == (1000 -j - 1));
		e = e->next;
	}
	u_isnull("incoherent end of list", e);

	/* No element should be freed as all are in the list */
	gcElems(& head, 1);

	/* No element should be freed */
	e = allocElem();
	u_isnull("unexpected allocation success", e);

	/* check the list */
	e = head;
	for(int j = 0; j < 1000; j++) {
		u_assert("incoherent val field in Elem",
			 e->val == (1000 -j - 1));
		e = e->next;
	}
	u_isnull("incoherent end of list", e);
	
	/* free all elements */
	head = NULL;
	gcElems(& head, 1);
		
		
	/* Allocate all the 1000 elements */
	for(int i=0; i < 1000; i++) {
		e = allocElem();
		u_isnotnull("unexpected allocation failure", e);
		
		e->val = i;
		e->next = head;
		head = e;
	}
	/* No element should be free */
	e = allocElem();
	u_isnull("unexpected allocation success", e);

	/* check the list */
	e = head;
	for(int j = 0; j < 1000; j++) {
		u_assert("incoherent val field in Elem",
			 e->val == (1000 -j - 1));
		e = e->next;
	}
	u_isnull("incoherent end of list", e);
	
	/* free all elements */
	head = NULL;
	gcElems(& head, 1);

	u_success("test2");
}
