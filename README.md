PCN - Partitioning Consecutive Numbers (by Kai Renken, 2018)


- What the program does

PCN partitiones natural numbers from 1 to n, which add up to the same sum as some natural numbers from a to b, such that each part of the partition adds up to exactly one of the numbers between a and b. Further information about the mathematical background can be found in 'docs/A theorem about partitioning consecutive numbers.pdf'.


- How to use

PCN is tested to compile with the GCC and MinGW compilers. Just place all files from 'src' in one folder and compile the 'PCN.cpp'. Executable files for Windows and Linux can be found in 'build'.

Run PCN in command line as follows:

'PCN [Parameter n] [Parameter a] [Parameter b]'

Here, n, a and b as supposed to be natural numbers, such that the sum from 1 to n equals the sum from a to b. The output will be a matrix consisting of b-a+1 lines and n columns, such that the entries in the first line add up to a, the entries in the second line add up to a+1, and so on.


- Tests

PCN has been tested using the Catch2 framework (see: 'https://github.com/catchorg/Catch2')
You can run the tests by placing all files from 'test' in one folder and compile the 'test.cpp'.
