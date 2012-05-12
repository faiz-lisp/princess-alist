/*
 * Genereate one magic matrix cycle. <https://github.com/xiaogaozi/princess-alist>
 * Copyright (C) 2010  xiaogaozi <gaochangjian@gmail.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int i;
    printf("Please input a number (<=25): ");
    scanf("%d", &i);

    int j, direction = 1, x = 0, y = -1;
    int matrix[25][25];
    for (j = 1; j != i * i + 1; ++j)
    {
        switch (direction)
        {
            case 1 :  // right
                ++y;
                break;
            case 2 :  // down
                ++x;
                break;
            case 3 :  // left
                --y;
                break;
            case 4 :  // up
                --x;
                break;
        }

        matrix[x][y] = j;

        if (x == 0 && y == 0)
            continue;

        if (x + y == i - 1 && x < y)
            direction = 2;
        else if (x == y && direction == 2)
            direction = 3;
        else if (x + y == i - 1 && x > y)
            direction = 4;
        else if (x - y == 1 && direction == 4)
            direction = 1;
    }

    printf("\n");
    for (x = 0; x != i; ++x)
    {
        for (y = 0; y != i; ++y)
            printf("%d\t", matrix[x][y]);
        printf("\n");
    }

    exit(EXIT_SUCCESS);
}
