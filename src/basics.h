#pragma once
#include <math.h>
#include <vector>

typedef std::vector<int> line;

int find_pairs_by_step(int step, int steps, bool comp);
int find_first_free_space(int steps, int shift);
int find_second_free_space(int steps, int shift);
void display_howTo();

int find_pairs_by_step(int step, int steps, int shift, bool comp){ // Find pairs of natural numbers with distance 'step' within the most narrow range
    if (step > steps){ return 0; }

    double _step = (double)step; double _steps = (double)steps; double result;

    if (step % 2 == 1) {
        result = ceil(_steps/2) - ceil(_step/2);
    } else {
        result = (ceil(_steps/2) * 2) + floor(_steps/2) - (_step/2);
    }
    if (comp == 0){
        return (int)result + shift;
    } else {
        return (int)result + step + shift;
    }
}

int find_first_free_space(int steps, int shift){ // Find first non-used number within the range of find_pairs_by_step
    double _steps = (double)steps; double result;
    result = (2 * ceil(_steps/2)) + floor(_steps/2);
    return (int)result + shift;
}

int find_second_free_space(int steps, int shift){ // Find second non-used number within the range of find_pairs_by_step
    if (steps == 1){
        return 2 + shift;
    } else if (steps == 0){
        return shift;
    } else {
        double _steps = (double)steps; double result;
        result = (2 * ceil(_steps/2)) + (2 * floor(_steps/2)) + 1;
        return (int)result + shift;
    }
}

void display_howTo(){ // Display how to use PCN
    std::cout << "PCN - Partitioning Consecutive Numbers (written by Kai Renken, 2018)" << std::endl;
    std::cout << std::endl;
    std::cout << "Use 'PCN [Parameter n] [Parameter a] [Parameter b]'" << std::endl;
    std::cout << "Here n, a, and b should be natural numbers," << std::endl << "such that the sum of the numbers from 1 to n" << std::endl << "equals the sum of the numbers from a to b." << std::endl;
    std::cout << "PCN will partition the numbers from 1 to n, such that" << std::endl << "the numbers in each part add up to exactly one number between a and b." << std::endl;
    std::cout << "The output will be b-a+1 lines with n entries, such that" << std::endl << "the numbers in the first line add up to a, the numbers in the" << std::endl << "second line add up to a+1, and so on." << std::endl;
    std::cout << std::endl;
    std::cout << "For example enter 'PCN 5 7 8' and the output will consist" << std::endl << "of 2 lines, since there are 2 numbers between 7 and 8." << std::endl << "The first line will consist of the numbers 4 and 3," << std::endl << "since they add up to 7 and the second line will consist of" << std::endl << "the numbers 5, 2 and 1, since they add up to 8." << std::endl;
    std::cout << std::endl;
    std::cout << "Of course there are more possibilities to partition these numbers" << std::endl << "satisfying the same properties, but until now this is the only" << std::endl << "known general algorithm to realize that partitioning." << std::endl;
}
