#pragma once
#include <vector>
#include "basics.h"

class Matrix {

public:
    Matrix(int _lines, int _columns) :lines(_lines), columns(_columns){
        matrix.resize(lines); // Set size of the vector of lines
        for (int i = 0; i < lines; i++) {
            matrix[i].resize(columns); // set size of each line within the vector of lines
        }
    }

    int getLines(){ return lines; } // Get number of lines
    int getColumns(){ return columns; } // Get size of a line
    int getEntry(int _line, int _column){ return matrix[_line][_column]; } // Get a certain entry of the matrix
    void setEntry(int _line, int _column, int _entry){ matrix[_line][_column] = _entry; } // Set a certain entry of the matrix

private:
    int lines;
    int columns;
    std::vector<line> matrix;
};
