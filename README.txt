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
Bug fixing
Memory leak fixing
Helper methods not specified


------------------------------------------------------
Orain:

DoublyLinkedList.h
main.cpp
Bug fixes
Minor memory leak fixing
Giving logic ideas for methods


------------------------------------------------------
Big O Notation


Delete Subsection Function bigO
BigO(n+2n) = O(n)

void deleteSubsection(start, finish)
{
	if (finish < start)  --------1
    {
        print "Lower bound cant be larger than upper bound" --------1
		return;
    } //if 
    NodeType traverse = head; --------1
	if(traverse is at end of list) --------1
	{
		print "Original List: "--------1
		print "Modified List: "--------1
		return;
	}//if 
	else 
	{
		print "Original List: "--------1
		printList();--------1
	}//else 
    while (traverse is not at end of list) -------------n
    {
        if ((traverse great than or equal start) AND (traverse less than or equal finish)) ---------1
        {
            delete (traverse)   -------------n
            Reset traverse to start of list at head -------------n
        } //if
    	advance traverse -------- 1 
    }//while
	print"Modified List: "
	printList();
} // deleteSubsection





--------------------------------------------------
Mode Function and helper function bigO
BigO(n*n+2n) = O(n^2)

int countNum(theData)
{
	int i = 0;
	NodeType traverse = head;
	while (traverse not at end of list) -----------n
	{
		if (theData == traverse->data) ----------------1
		{
			increase i; ------------n 	
		}//if
		traverse = traverse next value; ------------1
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
		print "There is no mode. There are tied values"
	}//if
	else
		print "Mode: " + theData 
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
	print "Original List: "
	print(); 
	while (traverse2 != after AND traverse2 != NULL) -----n
	{
		dataBefore = traverse back value;-----n
		dataAfter = traverse2 next value;-----n
		dataBefore next value = traverse2;-----n
		dataAfter back value = traverse; 

		traverse next value = dataAfter;-----n
		traverse2 back value = dataBefore;-----n
		traverse back value = traverse2;-----n
		traverse2 next value = traverse;-----n
		
		traverse = traverse next value ;-----n
		traverse2 = traverse next value ;-----n
	} // while
	head = before next value;
	print "Swapped List: ";
	print(); 
} // swapAlternate