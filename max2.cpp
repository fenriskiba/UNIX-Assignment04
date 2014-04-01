#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

int runOtherProgram(string fileName);

int main(int argc, char *argv[])
{
    string fileName1 = argv[1];
    string fileName2 = argv[2];
    
    int largestNumber1 = runOtherProgram(fileName1);
    int largestNumber2 = runOtherProgram(fileName2);
    
    cout << "Maximum number for" << fileName1 << "is " << largestNumber1 << endl;
    cout << "Maximum number for" << fileName2 << "is " << largestNumber2 << endl;
}
