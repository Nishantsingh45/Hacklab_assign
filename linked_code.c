
#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node {
	int data;
	struct Node* next;
};

//Adding a new node, 

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node
		= (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
//Deleting a particular node (referenced by the location),
void deleteNode(struct Node** head_ref, int key)
{
	
	struct Node *temp = *head_ref, *prev;


	if (temp != NULL && temp->data == key) {
		*head_ref = temp->next; 
		free(temp); 
		return;
	}

	
	while (temp != NULL && temp->data != key) {
		prev = temp;
		temp = temp->next;
	}

	
	if (temp == NULL)
		return;

	
	prev->next = temp->next;

	free(temp); 
}
//Delete all the nodes from the list which contain a particular data say a number 5 and the next subsequent node
void del_node(struct Node** head_ref, int key)
{
	
	struct Node *temp = *head_ref, *prev;


	if (temp != NULL && temp->data == key) {
		*head_ref = temp->next; 
		free(temp); 
		return;
	}

	
	while (temp != NULL && temp->data != key) {
		prev = temp;
		temp = temp->next;
	}

	
	if (temp == NULL)
		return;

	
	prev->next = temp->next;

	free(temp); 
}
//Delete the complete linked list

void deleteList(struct Node** head_ref)
{
   
   struct Node* current = *head_ref;
   struct Node* next;
 
   while (current != NULL)
   {
       next = current->next;
       free(current);
       current = next;
   }
   
  
   *head_ref = NULL;
}

//Function to display Reverse Linked list
void printReverse(struct Node* head)
{
    
    if (head == NULL)
       return;
      
    printReverse(head->next);
    printf("%d  ", head->data);
}
//Function to find memory occupied by linkedlist
int find_memory(struct Node* head)
{
    //Each node of the list contains an integer and one pointers.
    //We know that an integer occupies 4 bytes in the memory.and pointers
    //occupies 8 bytes . Hence total 12 bytes.
    int count = 0; 
    struct Node* current = head; 
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count*12;
}
//Function to display the linkedlist
void printList(struct Node* node)
{
	while (node != NULL) {
		printf(" %d ", node->data);
		node = node->next;
	}
}


int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	push(&head, 7);
	push(&head, 1);
	push(&head, 3);
	push(&head, 2);
	push(&head, 5);

	puts("Created Linked List: \n");
	printList(head);
	puts("Reverse Linked List: \n");
	printReverse(head);
	puts("Memory : \n");
	printf("%d",find_memory(head));
	deleteNode(&head, 1);
	puts("Linked List after Deletion of 1: \n");
	printList(head);
	puts("Deleting the linked list: \n");
	deleteList(&head);

	
	return 0;
}
