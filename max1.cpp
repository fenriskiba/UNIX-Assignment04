#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <climits>

using namespace std;

int findLargestInFile(string fileName);

int main(int argc, char *argv[])
{
    string fileName = argv[1];
    
    int largestNumber = findLargestInFile(fileName);
    
    cout << largestNumber;
    return 0;
}

int findLargestInFile(string fileName)
{
    int largest = INT_MAX;
    int current;
    string line;
    ifstream myfile(fileName.c_str());
    
    if (myfile.is_open())
    {
        while(getline(myfile,line))
        {
            current = atoi(line.c_str());
            if(largest == INT_MAX)
            {
                largest = current;
            }
            else if(largest < current)
            {
                largest = current;
            }
        }
        
        myfile.close();
    }
    
    return largest;
}

