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

#ifndef BITSET1000_H
#define BITSET1000_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
  bool bt1k_get(long unsigned int n);
  void bt1k_set(long unsigned int n, bool val);
  void bt1k_reset();

#ifdef __cplusplus
}
#endif

#endif
