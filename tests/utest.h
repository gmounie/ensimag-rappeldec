#ifndef UTEST_H
#define UTEST_H

/**
   Minimalist unit testing, very partially from an idea of
   http://www.jera.com/techinfo/jtns/jtn002.html

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

#include <stdio.h>

/* u_errnb counts errors and must be instancied somewhere */
extern int u_errnb;


#define FAIL(message, test) do { fprintf(stderr,"FAILURE:(%s) %s; (%s, line %d)\n", #test, message, __FILE__, __LINE__); u_errnb++; return; } while(0)
#define OK(message) do { fprintf(stderr,"SUCCESS: %s\n", message); } while(0)


#define u_assert(message, test) do { if (!(test)) FAIL(message, test); } while(0)
#define u_isnull(message, test) do { if ((test) != NULL) FAIL(message, test); } while(0)
#define u_isnotnull(message, test) do { if ((test) == NULL) FAIL(message, test); } while(0)
#define u_success(message) do { OK(message); } while(0)



#endif
