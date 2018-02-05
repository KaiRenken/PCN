#pragma once
#include "basics.h"
#include "Matrix.h"
#include <map>

void find_partitions(int n, int a, int b, Matrix* mat, int iter, int firstLine);

void find_partitions(int n, int a, int b, Matrix* mat, int iter, int firstLine){
    if (a <= n){ // Set entries for all numbers from 1 to n, which are between a and b and call next iteration step
        for (int i = a; i <= n; i++){
            mat->setEntry(i - a + firstLine, iter, i);
            for (int j = iter + 1; j < mat->getColumns(); j++){
                mat->setEntry(i - a + firstLine, j, 0);
            }
        }
        for (int i = n + 1; i <= b; i++){
            mat->setEntry(i - a + firstLine, iter, 0);
        }
        if (a != 1){
            int nextLine = n - a + 1 + firstLine;
            find_partitions(a - 1, n + 1, b, mat, iter + 1, nextLine);
        }
        return;
    }

    int s = b-a+1; int c = (2 * n) - (2 * s) + 1; int m; int steps = c - a; int posX; int posY; int temp; int nextLine;

    if (steps < 0){ steps = 0; }

    std::map<int,int> result;

    for (int i = n; i > n - s; i--){
        result[i] = c - i;
    }

    int i = a; m = c - i;

    while (m > 0){ // Find pairs for negative summing and swap second components
        posX = find_pairs_by_step(m, steps, n - s + 1,0);
        posY = find_pairs_by_step(m, steps, n - s + 1,1);
        temp = result[posX];
        result[posX] = result[posY];
        result[posY] = temp;
        mat->setEntry(i - a + firstLine, iter, posX);
        mat->setEntry(i - a + firstLine, iter + 1, result[posX]);
        mat->setEntry(i - a + (2 * m) + firstLine, iter, posY);
        mat->setEntry(i - a + (2 * m) + firstLine, iter + 1, result[posY]);
        i++; m = c - i;
    }

    if (steps > 0){ // Find pair for zero summing
        posX = find_first_free_space(steps, n - s + 1);
        mat->setEntry(i - a + firstLine, iter, posX);
        mat->setEntry(i - a + firstLine, iter + 1, result[posX]);
    }

    posX = find_second_free_space(steps, n - s + 1);

    if (steps == 0){ // Find pairs for non-zero summing
        for (i = 0; i < s; i++){
            mat->setEntry(i + firstLine, iter, posX);
            mat->setEntry(i + firstLine, iter + 1, result[posX]);
            posX++;
        }
    } else {
        for (i = (2 * steps) + 1; i < s; i++){
            mat->setEntry(i + firstLine, iter, posX);
            mat->setEntry(i + firstLine, iter + 1, result[posX]);
            posX++;
        }
    }

    if (n - (2 * s) > 0){ // Call next iteration step
        for (int i = firstLine; i < s + firstLine; i++){
            posX = mat->getEntry(i, iter);
            posY = mat->getEntry(i, iter + 1);
            if (posX + posY != a + i - firstLine){
                nextLine = i; break;
            }
        }
        for (int i = firstLine; i < nextLine; i++){
            for (int j = iter + 2; j < mat->getColumns(); j++){
                mat->setEntry(i, j, 0);
            }
        }
        if (c - a >= 0){
            find_partitions(n - (2 * s), a + (2 * steps) + 1 - c, b - c, mat, iter + 2, nextLine);
        } else {
            find_partitions(n - (2 * s), a - c, b - c, mat, iter + 2, nextLine);
        }
    } else { // Set remaining entries to zero
        for (int i = iter + 2; i < mat->getColumns(); i++){
            mat->setEntry(mat->getLines() - 1, i, 0);
        }
    }
}
