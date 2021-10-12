#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <fstream> 
#include <string.h>
#include <sstream>
#include <string>
#include "DoublyLinkedList.h"

using namespace std;
int main(int argc, char *argv[]) 
{
	string userSelect; 
	char userSelectChar; 
	bool exit = false; 

	string subLine;
	int valueOfInt;
	float valueOfFloat;
	ifstream intFile;
	ifstream floatFile;
	ifstream stringFile;
  	


	cout <<"Enter list type (i - int, f - float, s - std:string): "; 
	cin >> userSelect; 
	while(userSelect.size()!=1) 
      {
        cout << "Invalid command, try again!" <<endl;
        cout << "Enter a command: ";
        cin >> userSelect;
      }
      userSelectChar = userSelect[0];
	switch (userSelectChar)
	{
	case 'i':
		intFile.open(argv[1]);
  		if (!intFile.is_open())
		{
			cout << "Unable to open int file" << endl;
		}
		while (getline(intFile, subLine,' '))//Gets each variable until it hits a space or EOF
		{
			valueOfInt = stoi(subLine);
			cout << valueOfInt << " ";
			//insert method
		}
		cout << endl;
		break;
	
	case 'f':
		floatFile.open(argv[2]);
  		if (!floatFile.is_open())
		{
			cout << "Unable to open float file" << endl;
		}
		while (getline(floatFile, subLine,' '))//Gets each variable until it hits a space or EOF
		{
			valueOfFloat = stof(subLine);
			cout << valueOfFloat << " ";
			//insert method
		}
		cout << endl;
		break;
	case 's':
		stringFile.open(argv[3]);
  		if (!stringFile.is_open())
		{
			cout << "Unable to open string file" << endl;
		}
		while (getline(stringFile, subLine,' '))//Gets each variable until it hits a space or EOF
		{
			cout << subLine << " ";
			//insert method
		}
		cout << endl;
		break;
	default:
		
		break;
	}
	while (exit == false)
	{
		cout << "insert (i), delete (d), length (l), print (p), deleteSub (b), mode (m), printReverse(r), swapAtl(s), quit (q)"<< endl;
		cout << "Enter a Command: ";
		cin >> userSelect; 
		while(userSelect.size()!=1) 
		{
			cout << "Invalid command, try again!" <<endl;
			cout << "Enter a command: ";
			cin >> userSelect;
		}
		userSelectChar = userSelect[0];
		switch (userSelectChar)
			{
			case 'i':
				/* code */
				break;
			
			case 'd':
				
				break;
			case 'l':

				break;
			case 'p':

				break;
			case 'b':

				break;
			case 'm':

				break;
			case 'r':

				break;
			case 's':

				break;
			case 'q':
				cout << "Quitting..." <<endl;
				exit = true; 
				break;
			default:

				break;
			}
	}
	return 0;
} // main
