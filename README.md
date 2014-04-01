UNIX-Assignment04
=================

Project For UNIX Systems Programming to practice executing programs within programs.

Problem:

1. Write a filter program in C/C++ called max1 that takes a text file of integers as input and it returns the maximum number of the input.          
 
2. Write a C/C++ program called max2 that takes two text files of integers as inputs and returns the max number from the input files.  The program is run by the following command:
 
>max2  infile1  infile2
 
It is required:

1. To create two child processes that run max1 to find the maximum,

2. To use the parent process finding the max from the two numbers returned by the child processes and printing the result to the standard output, and

3. To use pipe for inter-process communication.
