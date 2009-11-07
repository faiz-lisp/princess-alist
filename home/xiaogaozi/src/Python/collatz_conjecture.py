#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Collatz Conjecture. <http://code.google.com/p/princess-alist/>
# Copyright (C) 2009  xiaogaozi <gaochangjian@gmail.com>
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

import matplotlib.pyplot as plt

def CollatzConjecture(n):
    """Collatz Conjecture"""
    t = 0
    while n != 1:
        t += 1
        if n % 2 == 0:
            n /= 2
        else:
            n = n * 3 + 1
    return t

if __name__ == "__main__":
    x = range(2, 1000000)
    y = []
    for n in x:
        y.append(CollatzConjecture(n))
    plt.plot(x, y, 'ro')
    plt.axis([0, x[len(x) - 1] + 100, 0, y[len(y) - 1] + 150])
    plt.show()
