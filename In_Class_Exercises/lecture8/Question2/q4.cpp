#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX_WORD_LENGTH = 80;
const int MAX_PHRASE_LENGTH = 1000;

/* definition of a node */
struct Node;
typedef Node *Node_ptr;

struct Node
{
	char word[MAX_WORD_LENGTH];
	Node_ptr ptr_to_next_node;
};

/* Function to assign a linked list to "a_node" */
void assign_list(Node_ptr &a_list);

/* Function to assign a new dynamic node variable to "a_node" */
void assign_new_node(Node_ptr &a_node);

/* Function to print the strings in the list "a_node" */
void print_list(Node_ptr a_node);

void printBackwards(Node_ptr a_node);

void printForwards(Node_ptr a_node);


void print_list_back(Node_ptr a_node);

/* MAIN PROGRAM */
int main()
{
	Node_ptr my_list = NULL;

	assign_list(my_list);

	cout << "\nTHE LIST IS NOW, IN ITERATIONS:\n";
	print_list(my_list);

	cout << "\nTHE  LIST IS NOW, IN RECURSION :\n";
	printForwards(my_list);

	cout << "\nTHE BACKWARDS LIST IS NOW, IN RECURSION :\n";
	printBackwards(my_list);

	cout << "\nTHE BACKWARDS LIST IS NOW, IN ITERATIONS:\n";
	print_list_back(my_list);

	cout<<endl;
	return 0;
}
/* END OF MAIN PROGRAM */
	
/* DEFINITION OF FUNCTION "assign_list" */
void assign_list(Node_ptr &a_list)
{
	Node_ptr current_node, last_node;
	
	assign_new_node(a_list);
	cout << "Enter first word (or '.' to end list): ";
	cin >> a_list->word;
	if (!strcmp(".",a_list->word))
	{
		delete a_list;
		a_list = NULL;
	} 
	current_node = a_list;
	
	while (current_node != NULL)
	{
		assign_new_node(last_node);
		cout << "Enter next word (or '.' to end list): ";
		cin >> last_node->word;
		if (!strcmp(".",last_node->word))
		{
			delete last_node;
			last_node = NULL;
		}
		current_node->ptr_to_next_node = last_node;
		current_node = last_node;
	}
}	
/* END OF FUNCTION DEFINITION */

/* DEFINITION OF FUNCTION "assign_new_node" */
void assign_new_node(Node_ptr &a_node)
{
        a_node = new (nothrow) Node;
	if (a_node == NULL) 
	{
		cout << "sorry - no more memory\n"; 
		exit(1);
	}
}
/* END OF FUNCTION DEFINITION */

/* DEFINITION OF FUNCTION "print_list" */
void print_list(Node_ptr a_node)
{
  while (a_node != NULL)
	{
		cout << a_node->word << " ";
		a_node = a_node->ptr_to_next_node;
	}
}
/* END OF FUNCTION DEFINITION */



void printBackwards(Node_ptr a_node){
  Node_ptr one_node;
  one_node= a_node->ptr_to_next_node;
  if(one_node !=NULL){

    printBackwards(one_node);

  }
  cout << a_node->word << " ";

}





void printForwards(Node_ptr a_node){

  Node_ptr one_node;
  cout << a_node->word << " ";
  one_node= a_node->ptr_to_next_node;
  if(one_node !=NULL){

     printForwards(one_node);

  }
 
}

void print_list_back(Node_ptr a_node){
  
  char phrase[MAX_PHRASE_LENGTH];
  //int count=0;
  strcpy(phrase, a_node->word);
      strcat(phrase, " ");
  a_node=a_node->ptr_to_next_node;

  while (a_node != NULL)
    {
      strcat(phrase,a_node->word);
      strcat(phrase, " ");
      a_node = a_node->ptr_to_next_node;
      //count++
    }
  int count= strlen(phrase)-2;
 

  while( count>=0){
    while(phrase[count]!=' '&&count>=0){
      count--;
    }
    for (int internalCount=count+1; phrase[internalCount]!=' '; internalCount++){
      cout<<phrase[internalCount];
    }
    cout<<" ";
    count--;

  }
  

}


