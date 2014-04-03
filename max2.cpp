#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int runOtherProgram(string fileName);

int main(int argc, char *argv[])
{
    string fileName1 = argv[1];
    string fileName2 = argv[2];
    
    int largestNumber1 = runOtherProgram(fileName1);
    int largestNumber2 = runOtherProgram(fileName2);
    
    cout << "Maximum number for both files is " << (largestNumber1 > largestNumber2 ? largestNumber1 : largestNumber2) << endl;
}

int runOtherProgram(string fileName)
{
    int pid;
	int pc[2]; // Parent to child pipe
	int cp[2]; // Child to parent pipe
	char ch;
	string output = "";


	if( pipe(pc) < 0)
	{
		cout << "Can't make pipe" << endl;
		exit(1);
	}
	if( pipe(cp) < 0)
	{
		cout << "Can't make pipe";
		exit(1);
	}

	switch( pid = fork() )
	{
		case -1: 
				cout << "Can't fork";
				exit(1);
		case 0:
				//Child
				close(1);
				dup(cp[1]);
				close(0);
				dup( pc[0]); 
				close(pc[1]);
				close(cp[0]);
				
				execlp("./max1", "./max1", fileName.c_str(), NULL);
				cout << "No exec" << endl;
				exit(1);
		default:
				//Parent
				close(pc[1]);
				close(cp[1]);
				
				while(read(cp[0], &ch, 1) == 1)
				{
					output += ch;
				}
				
		        break;
	}
	return atoi(output.c_str());
}

