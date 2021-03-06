#include <stdio.h>
#include <stdlib.h>

typedef struct node {

	int val;
	struct node * next ;

} node_t;

void print_list(node_t * head);
int remove_by_value(node_t ** head, int val);
int remove_item(node_t * head, int n);

void push_last(node_t * head, int val){

	node_t * current = head;

	while(current->next != NULL) {

                current = current->next;
        }

	current->next = malloc(sizeof(node_t));

	current->next->val = val;

        current->next->next = NULL;

	// print_list(head);
}

void push_first(node_t ** head, int val) {

	// printf("Pointer to head: %p\nDouble pointer to head: %p\n", *head, head);

	node_t * new_node;

	new_node = malloc(sizeof(node_t));

	new_node->val = val;

	new_node->next = *head;

	*head = new_node;

	// printf("Pointer to new head: %p\n", new_node);

	// print_list(*head);

}

int remove_by_value(node_t ** head, int value) {

	int retval = -1;

	int position = 0;

	node_t * current;

	current = malloc(sizeof(node_t));

	current = *head;

	while(current != NULL) {

		// printf("Position: %d \t Value: %d\n", position, current->val);

		if(current->val == value) {

			printf("%d is found on the %d position\n", current->val, position);

			remove_item(*head, position);

			return 1;
		}

		position++;

                current = current->next;
        }

	return retval;
}

void remove_first_item(node_t * head) {

	node_t * temp;

	temp = malloc(sizeof(node_t));

	/*

	if (&head == NULL) {

		return -1;
	}

	*/

	temp->val = head->next->val;

	temp->next = head->next->next;

	free(head->next);

	head->next = temp->next;

	head->val = temp->val;

	// return 1;
}

int remove_last_item(node_t * head) {

	node_t * temp = head;

	while(temp->next->next != NULL) {

		temp = temp->next;
	}

	free(temp->next);

	temp->next = NULL;

}

int remove_item(node_t * head, int n) {

	printf("\nHave to remove item at %d position ...\n", n);

	node_t * current;

	current = malloc(sizeof(node_t));

        current = head;

	node_t * temp = NULL;

	if (n == 0) {

		remove_first_item(head);

		return 1;
	}

	for (int i = 0; i < n - 1; i++) {

		// printf("Position: %d \t Value: %d\n", i, current->val);

		if(current->next == NULL) {

			return -1;
		}

		current = current->next;

	}

	temp = current->next;

	current->next = temp->next;

	free(temp);

}


void print_list(node_t * head) {

	node_t * current = head;

	while(current != NULL) {

                printf("\n%d \t %p\n", current->val, current->next);
                current = current->next;
        }

}

static void reverse_list(node_t ** head) {

	node_t * prev = NULL;

	node_t * current = *head;

	node_t * next;

	while(current != NULL) {

		next = current->next;

		current->next = prev;

		prev = current;

		current = next;	

	}

	*head = prev;

}

int main(){

	node_t * head = NULL;

	head = malloc(sizeof(node_t));

	if(head == NULL) {

		return 1;
	}

	head->val = 1;

	head->next = malloc(sizeof(node_t));

	head->next->val = 2;

	head->next->next = NULL;

	push_last(head, 6);

	push_last(head, 8);

	push_first(&head, 36);

	print_list(head);

        // printf("Added 4 items\n\n");

	remove_first_item(head);

	print_list(head);

	/*

        printf("Removed first item\n\n");

	remove_last_item(head);

	print_list(head);

        printf("Removed last item\n\n");

	remove_item(head, 2);

	print_list(head);

        printf("Removed 2nd item\n\n");

	remove_item(head, 1);

        print_list(head);

        printf("Removed 1st item\n\n");

	remove_item(head, 0);

	if (remove_by_value(&head, 36) == -1) {

		printf("\nValue not found in list!\n");

	}

	print_list(head);

	*/

	reverse_list(&head);

	printf("Reversed list: \n");

	print_list(head);

	return 0;

}

