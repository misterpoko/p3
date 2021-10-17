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
	char userSelectChar,listType;
	bool exit = false;  
	string subLine, upperBound, lowerBound;
	int valueOfInt;
	float valueOfFloat;
	bool check = true;
	char caseI = 'i';
	char caseF = 'f';
	char caseS = 's';

	DoublyLinkedList<int> listy;
	DoublyLinkedList<float> listy2;
	DoublyLinkedList<string> listy3;

	ifstream inFile;
	
	cout << "Enter list type(i - int, f - float, s - std:string): ";
	cin >> userSelect; 
	while (check)
	{
		while(userSelect.size()!=1) 
		{
			cout << "Invalid command, try again!" <<endl;
			cout << "Enter a command: ";
			cin >> userSelect;
		}
		listType = userSelect[0];
		int s= 1;
		if (caseI == userSelect[0]) // int case
		{
			
			check = false;
			inFile.open(argv[1]);
			if (!inFile.is_open())
			{
				cout << "Unable to open int file" << endl;
			}
			while (getline(inFile, subLine,' '))//Gets each variable until it hits a space or EOF
			{
				valueOfInt = stoi(subLine);
				listy.insertItem(valueOfInt);
			} // while
			cout << endl;
		}
		else if (caseF == userSelect[0] )
		{
			check = false;
			inFile.open(argv[1]);
			if (!inFile.is_open())
			{
				cout << "Unable to open float file" << endl;
			}
			while (getline(inFile, subLine,' '))//Gets each variable until it hits a space or EOF
			{
				valueOfFloat = stof(subLine);
				listy2.insertItem(valueOfFloat);
			}
			cout << endl;
		}
		else if (caseS == userSelect[0])
		{
			check = false;
			inFile.open(argv[1]);
			if (!inFile.is_open())
			{
				cout << "Unable to open string file" << endl;
			}
			while (getline(inFile, subLine,' '))//Gets each variable until it hits a space or EOF
			{
				listy3.insertItem(subLine);
			}
			cout << endl;
		}
		else 
		{
			cout << "Invalid command, try again!" <<endl;
			cout << "Enter a command: ";
			cin >> userSelect;
		}
	}
	cout << "Command Options \ninsert (i), delete (d), length (l), print (p), deleteSub (b), mode (m), printReverse(r), swapAtl(s), quit (q)"<< endl;
	while (exit == false)
	{
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
					cout<< "Enter Item to insert: ";
					cin >> userSelect; 
					if(caseI == listType)
					{
						valueOfInt = stoi(userSelect);
						listy.insertItem(valueOfInt);
						listy.print();
					}
					else if(caseF ==listType)
					{
						valueOfFloat = stof(userSelect);
						listy2.insertItem(valueOfFloat);
						listy2.print();
					}
					else
					{
						listy3.insertItem(userSelect);
						listy3.print();
					}
				break;
			
			case 'd':
					cout<< "Enter Item to delete: ";
					cin >> userSelect; 
					if(caseI == listType)
					{
						valueOfInt = stoi(userSelect);
						listy.deleteItem(valueOfInt);
						listy.print();
					}
					else if(caseF ==listType)
					{
						valueOfFloat = stof(userSelect);
						listy2.deleteItem(valueOfFloat);
						listy2.print();
					}
					else
					{
						listy3.deleteItem(userSelect);
						listy3.print();
					}
				break;
			case 'l':
					if(caseI == listType)
					{
						cout << "The length is: " << listy.lengthIs() << endl;
					}
					else if(caseF ==listType)
					{
						cout << "The length is: " << listy2.lengthIs()<< endl;
					}
					else
					{
						cout << "The length is: " << listy3.lengthIs()<< endl;
					}
				break;
			case 'p':
					if(caseI == listType)
					{
						listy.print();
					}
					else if(caseF ==listType)
					{
						listy2.print();
					}
					else
					{
						listy3.print();
					}
				break;
			case 'b':
					cout<< "Enter lower bound: "; 
					cin >> lowerBound;
					cout << "Enter upper bound: ";
					cin >> upperBound;
					if(caseI == listType)
					{	
						int upper,lower; 
						upper = stoi(upperBound);
						lower = stoi(lowerBound);
						listy.deleteSubsection(lower,upper);
					}
					else if(caseF ==listType)
					{	
						float upper,lower; 
						upper = stof(upperBound);
						lower = stof(lowerBound);
						listy2.deleteSubsection(lower,upper);
					}
					else
					{
						listy3.deleteSubsection(lowerBound,upperBound);
					}
				break;
			case 'm':
					if(caseI == listType)
					{
						listy.mode();
					}
					else if(caseF ==listType)
					{
						listy2.mode();
					}
					else
					{
						listy3.mode();
					}
				break;
			case 'r':
					if(caseI == listType)
					{
						listy.printReverse();
					}
					else if(caseF ==listType)
					{
						listy2.printReverse();
					}
					else
					{
						listy3.printReverse();
					}
				break;
			case 's':
					if(caseI == listType)
					{
						
					}
					else if(caseF ==listType)
					{

					}
					else
					{
						
					}
				break;
			case 'q':
				cout << "Quitting..." <<endl;
				exit = true; 
				break;
			default:
				cout << "Invalid command, try again!" << endl;
				break;
			}
	}
	return 0;
} // main
