#include <iostream>
#include <math.h>
#include <cstdlib>
#include "find_partitions.h"
#include "basics.h"
#include "Matrix.h"

int main(int argn, char *argv[]){

    if (argn != 4){ display_howTo(); return 0; } // Check number of input arguments

    int n = strtol(argv[1], NULL, 0); int a = strtol(argv[2], NULL, 0); int b = strtol(argv[3], NULL, 0); // Convert input arguments to integers

    if (n == 0 || a == 0 || b == 0){ display_howTo(); return 0; } // Check if conversion succeeded

    double _n = (double)n; double _a = (double)a; double _b = (double)b;
    if ((_n * (_n + 1)) / 2 != ((_a + _b) / 2) * (_b - _a + 1)){ display_howTo(); return 0; } // Check if input arguments satisfy the assumptions of the statement

    Matrix* mat = new Matrix(b-a+1,n); // Create the output matrix

    find_partitions(n,a,b,mat,0,0); // Compute the partitioning

    for (int i = 0; i < b-a+1; i++){
        for (int j = 0; j < n; j++){
           std::cout << mat->getEntry(i,j) << " "; // Display the output
        }
        std::cout << std::endl;
    }

    delete mat;
    return 0;
}
