Nathaniel Mathers            811053553   nbm54197@uga.edu
Orain Ferguson               811225938   onf32955@uga.edu
Assignment 3

The program makes a doubly linked list and does metheds on the list. It makes the list from the command line file.

Citations:
    Class PowerPoint sides

How to compile
    make 
How to Run 
    main input.txt
    (Input file can be a line of strings, ints, or floats)

Files needed to run
    DoublyLinkedList.cpp
    DoublyLinkedList.h
    main.cpp 
    input files 
        float-input.txt 
        int-input.txt
        int-input2.txt
        string-input.txt
    
Contributions
------------------------------------------------------
Nathaniel:

DoublyLinkedList.cpp 
bug fixing
mem leak fixing
helper methods not specified


------------------------------------------------------
Orain:

DoublyLinkedList.h
main.cpp
bug fixes


------------------------------------------------------
Big O Notation

Delete Subsection Function bigO
BigO(n+2n) = O(n)

void deleteSubsection(start, finish)
{
	if (finish < start)  --------1
    {
        cout << "Lower bound cant be larger than upper bound" << endl;
		return;
    } //if 
    NodeType traverse = head;
	if(traverse is at end of list) --------1
	{
		cout << "Original List: " << endl;
		cout << "Modified List: " << endl;
		return;
	}//if 
	else 
	{
		cout << "Original List: ";
		printList();
	}//else 
    while (traverse is not at end of list) -------------n
    {
        if ((traverse >= start) and (traverse <= finish)) ---------1
        {
            delete (traverse)   -------------n
            Reset traverse to start of list  -------------n
        } //if
    	advance traverse -------- 1 
    }//while
	cout << "Modified List: ";
	printList();
} // deleteSubsection
--------------------------------------------------
Mode Function and helper function bigO
BigO(n*n+2n) = O(n^2)

int countNum(theData)
{
	int i = 0;
	NodeType traverse = head;
	while (traverse != after) -----------n
	{
		if (theData == traverse->data) ----------------1
		{
			i++; ------------n 	
		}//if
		traverse = traverse->next; ------------1
	}//while
	return i;
} // if

/*
 * This method compares the number of times the same variarable appears. 
 * The value that is appears the most is stored in a genaric variable to be 
 * printed out.
*/

void mode()
{
	Generic theData;
	NodeType traverse = head;
	int previous = 0;
	int current = 0;
	while (traverse isnt at the end) -----------n
	{
		current = countNum(traverse);  -------n 
		if(previous < current)  -------- n
		{
			previous = current;
			theData = traverse;
		}//if
		advance traverse 
	} // while
	if(previous == 1 OR previous == current) ---------1
	{
		cout << "There is no mode. There are tied values" << endl;
	}//if
	else
		cout << "Mode: " << theData << endl;
} // mode


--------------------------------------------------
swapAlternate Function bigO
BigO(n + 10n) = O(n)

void swapAlternate()
{
	NodeType traverse = head;
	NodeType traverse2 = head->next;
	NodeType dataBefore;
	NodeType dataAfter;
	cout << "Original List: ";
	print(); 
	while (traverse2 != after AND traverse2 != NULL) -----n
	{
		dataBefore = traverse->back;
		dataAfter = traverse2->next;
		dataBefore->next = traverse2;
		dataAfter->back = traverse; 

		traverse->next = dataAfter;
		traverse2->back = dataBefore;
		traverse->back = traverse2;
		traverse2->next = traverse;
		
		traverse = traverse->next;
		traverse2 = traverse->next;
	} // while
	head = before->next;
	cout << "Swapped List: ";
	print(); 
} // swapAlternate