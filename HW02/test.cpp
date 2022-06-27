#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>                // needed to use tolower()
#pragma warning(disable: 4996) // for Visual Studio Only

 
#define MAX_NAME_LENGTH 35

 
typedef enum { noble = 0, hayden } library; // enumeration type library

 
struct bookDetails {
    char bookName[MAX_NAME_LENGTH];
    int pubYear;
    library libName;
    int noOfCopies;
    struct bookDetails* next;       // pointer to next node
} *list = NULL;                                 // Declare linked list 'list'

 
// forward declaration of functions (already implmented)
void flushStdIn();
void executeAction(char);

 
// functions that need implementation:
int addNode(char* bookName_input, int pubYear_input, char* libName_input, int noOfCopies_input); // 10 points
void displayList();                                             // 10 points
int countNodes();                                               // 5 points
int deleteNode(char* bookName_input);   // 10 points
void swapNodes(struct bookDetails* node1, struct bookDetails* node2);   // 5 points
void sortList();                                                // 10 points

 

 
int main()
{
    char choice = 'i';              // initialized to a dummy value
    do
    {
        printf("\nCSE240 HW6\n");
        printf("Please enter your selection:\n");
        printf("\t a: add a new book to the list\n");
        printf("\t d: display entire list of books\n");
        printf("\t r: remove a book\n");
        printf("\t s: sort the list by book name\n");
        printf("\t q: quit\n");
        choice = tolower(getchar());
        flushStdIn();
        executeAction(choice);
    } while (choice != 'q');

 
    return 0;
}

 
// flush out leftover '\n' characters
void flushStdIn()
{
    char c;
    do c = getchar();
    while (c != '\n' && c != EOF);
}

 
// Ask for details from user for the given selection and perform that action
// Read the function case by case
void executeAction(char c)
{
    char bookName_input[MAX_NAME_LENGTH];
    unsigned int pubYear_input, noOfCopies_input, result= 0;
    char libName_input[10];
    switch (c)
    {
    case 'a':       // add book
        // input book details from user
        printf("\nPlease enter book name: ");
        fgets(bookName_input, sizeof(bookName_input), stdin);
        bookName_input[strlen(bookName_input) - 1] = '\0';      // discard the trailing '\n' char
        printf("Please enter publication year: ");
        scanf("%d", &pubYear_input);
        flushStdIn();
        printf("Please enter library name (noble/hayden): ");
        fgets(libName_input, sizeof(libName_input), stdin);
        libName_input[strlen(libName_input) - 1] = '\0';        // discard the trailing '\n' char
        printf("Please enter no. of copies of book: ");
        scanf("%d", &noOfCopies_input);
        flushStdIn();
        // add the book to the list
        result = addNode(bookName_input, pubYear_input, libName_input, noOfCopies_input);
        if (result == 0)
            printf("\nThat book is already on the list! \n\n");
        else
            printf("\nBook successfully added to the list! \n\n");
        break;
    case 'd':               // display the list
        displayList();
        break;
    case 'r':               // remove book
        printf("\nPlease enter book name: ");
        fgets(bookName_input, sizeof(bookName_input), stdin);
        bookName_input[strlen(bookName_input) - 1] = '\0';      // discard the trailing '\n' char
        result = deleteNode(bookName_input);
        if (result == 0)
            printf("\nBook does not exist or the list is empty! \n\n");
        else
            printf("\nBook successfully removed from the list! \n\n");
        break;
    case 's':               // sort the list
        sortList();
        break;
    case 'q':               // quit
        break;
    default: printf("%c is invalid input!\n",c);
    }
}

 
// Q1 : addNode (10 points)
// This function is used to insert a new book into the list. You can simply insert the new book to the end of the linked list.
// Do not allow the book to be added to the list if it already exists in the list. You can do that by checking the names of the books already in the list.
// If the book already exists then return 0 without adding book to the list. If the book does not exist in the list then go on to add the book at the end of the list and return 1.
// NOTE: You must convert the string 'libName_input' to an enum type and store it in the list because the struct has enum type for library name.

 
int addNode(char* bookName_input, int pubYear_input, char* libName_input, int noOfCopies_input)
{
    struct bookDetails* tempList = list;    // work on a copy of 'list'
    while(tempList)
    {
        if(strcmp(tempList->bookName,bookName_input) == 0 )
            return 0;
        if(tempList->next != NULL)
            tempList = tempList->next;
        else
            break;
    }
    struct bookDetails* newBook =(struct bookDetails*)malloc(sizeof(struct bookDetails));
    strcpy(newBook->bookName,bookName_input);
    if(strcmp(libName_input,"noble") == 0)
        newBook->libName=noble;
    else
        newBook->libName=hayden;
    newBook->noOfCopies=noOfCopies_input;
    newBook->pubYear=pubYear_input;
    newBook->next=NULL;
    if(tempList)
        tempList->next = newBook;
    else{
        tempList = newBook;
        list = tempList;
    }
    return 1;               // remove this line while implementing this funtion
    // It is added to avoid compile error for empty function
}

 
// Q2 : displayList (10 points)
// This function displays the linked list of books with the book details (struct elements) of each book.
// Parse through the linked list and print the book details one after the other. See expected output screenshots in homework question file.
// NOTE: Library name is stored in the struct as enum type. You need to display 'Noble' or 'Hayden' as library name for the book.
void displayList()
{
    struct bookDetails* tempList = list;                            // work on a copy of 'list'
    while(tempList!= NULL)
    {
        printf("Book Name: %s\n",tempList->bookName);
        printf("Publication Year: %d\n",tempList->pubYear);
        printf("Library: %s\n",tempList->libName? "hayden" : "noble");
        printf("No. of Copies: %d\n",tempList->noOfCopies);
        tempList = tempList->next;
    }
}

 
// Q3: countNodes (5 points)
// This function counts the number of books on the linked list and returns the number.
// You may use this function in other functions like deleteNode(), sortList(), addNode().
// Its helpful to call this function in other functions, but not necessary.
int countNodes()
{
    int count=0;
    struct bookDetails* tempList = list;
    while(tempList!= NULL)
    {
        tempList = tempList->next;
        count+=1;
    }
    return count;               // remove this line while implementing this funtion
    // It is added to avoid compile error for empty function
}

 
// Q4 : deleteNode (10 points)
// This function deletes the node specified by the book name.
// Parse through the linked list and remove the node containing this book name.
// NOTE: After you remove the node, make sure that your linked list is not broken.
// (Hint: Visualize the list as: list......-> node1 -> removed_node -> node2 -> ...end.
//        After removing "removed_node", the list is broken into "list ....node1" and "node2.... end". Stitch these lists.)

 
int deleteNode(char* bookName_input)
{
    // create a copy of 'list' to parse the list
    struct bookDetails* curr = list;
    if(strcmp(curr->bookName,bookName_input) == 0)
    {
        list = curr->next;
        free(curr);
        return 1;
    }
    struct bookDetails* prev=curr;
    while(curr!= NULL)
    {
        if(strcmp(curr->bookName,bookName_input) ==0)
        {
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    if(curr != NULL)
    {
        prev->next = curr->next;
        free(curr);
        return 1;
    }
    return 0;               // remove this line while implementing this funtion
    // It is added to avoid compile error for empty function
}

 
// Q5 : swapNodes (5 points)
// This function swaps the elements of parameters 'node1' and 'node2' (not the first and second node of 'list')
// This function should not alter the 'next' element of the nodes.
// NOTE: This function is to be used in the sorting logic in sortList()
// Hint: The swap logic is similar to swapping two simple integer/string variables
void swapNodes(struct bookDetails* node1, struct bookDetails* node2)
{
    char bookName[MAX_NAME_LENGTH];
    strcpy(bookName,node1->bookName);
    int pubYear=node1->pubYear;
    library libName = node1->libName;
    int noOfCopies = node1->noOfCopies;
    strcpy(node1->bookName,node2->bookName);
    node1->pubYear = node2->pubYear;
    node1->libName = node2->libName;
    node1->noOfCopies = node2->noOfCopies;
    strcpy(node2->bookName,bookName);
    node2->libName = libName;
    node2->noOfCopies = noOfCopies;
    node2->pubYear = pubYear;
}

 
// Q6 : sortList (10 points)
// This function sorts the linked list by alphabetical order of book name.
// Parse the list and compare the book names to check which one should appear before the other in the list.
// Sorting should happen within the list. That is, you should not create a new linked list of books having sorted books.
// Hint: One of the string library function can be useful to implement this function because the sorting needs to happen by book name which is a string.
//       Use swapNodes() to swap the nodes in the sorting logic

 

 
void sortList()
{
    int swapped;
    struct bookDetails *ptr1;
    struct bookDetails *lptr = NULL;

 
    if (list == NULL)
        return;
    do
    {
        swapped = 0;
        ptr1 = list;
        while (ptr1->next != lptr)
        {
            if (strcmp(ptr1->bookName,ptr1->next->bookName)>0)
            {
                swapNodes(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}
