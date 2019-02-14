#include "Matrix.h"
#include "basics.h"

Matrix::Matrix(int pLines, int pColumns) {

        lines = pLines;
        columns = pColumns;

		// Set size of the vector of lines
        matrix.resize(lines);

        // Set size of each line within the vector of lines
        for (int i = 0; i < lines; i++) {
            matrix[i].resize(columns);
        }
    }

	// Get number of lines
    int Matrix::getLines() {
		return lines;
	}

	// Get size of a line
    int Matrix::getColumns() {
		return columns;
	}

	// Get a certain entry of the matrix
    int Matrix::getEntry(int pLine, int pColumn) {
		return matrix[pLine][pColumn];
	}

	// Set a certain entry of the matrix
    void Matrix::setEntry(int pLine, int pColumn, int pEntry) {
		matrix[pLine][pColumn] = pEntry;
	}
