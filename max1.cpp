#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

int collectNumbersFromFile(string fileName, int* numberList);
int findLargestFromList(int* numberList, int listSize);

int main(int argc, char *argv[])
{
    string fileName = argv[1];
    int* numberList;
    
    int listSize = collectNumbersFromFile(fileName, numberList);
    int largestNumber = findLargestFromList(numberList, listSize);
    
    cout << largestNumber;
    
    return 0;
}

int collectNumbersFromFile(string fileName, int* numberList);

int findLargestFromList(int* numberList, int listSize)
{
    int smallest = numberList[0];
    for(int i = 0; i < listSize; i++)
    {
        if(smallest > numberList[i];
            smallest = numberList[i];
    }
    
    return smallest;
}
