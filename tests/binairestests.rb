#!/usr/bin/ruby
# -*- coding: utf-8 -*-

# Copyright (C) 2016 Gregory Mounie
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or (at
# your option) any later version.
 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
 
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

require "expect"
require "pty"

def test_binaires
    @pty_read, @pty_write, @pty_pid = PTY.spawn("../build/binaires")

    a = @pty_read.expect(/49/m, 1) # attendre 1 seconde max
    if a.nil?
      puts "Valeur 1 attendue: '49'"
    end
    a = @pty_read.expect(/10/m, 1) # attendre 1 seconde max
    if a.nil?
      puts "Valeur 2 attendue: '10'"
    end
    a = @pty_read.expect(/197/m, 1) # attendre 1 seconde max
    if a.nil?
      puts "Valeur 3 attendue: '197'"
    end
end

test_binaires

