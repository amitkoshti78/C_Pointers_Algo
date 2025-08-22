//
// Created by Amit Koshti on 22.08.25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Node structure
struct Student {
    int roll_number;
    char name[20];
    struct Student* next;
};

struct Student* head = NULL;

/* This function creates a new node of type struct Student.
 * It accepts roll number and name as parameters
 * and this function returns a pointer of type struct Student
 * malloc is used to allocate memory on the heap.
 * malloc returns a pointer to the allocated memory with type void *
 * and it is type casted to struct Student * as this allocated memory is
 * used to store values of struct Student
 * as it is a new node and we don't know where to add it in linked list
 * so it's next pointer is set to NULL
 */

struct Student* create_node(int roll_number, char name[]) {
    struct Student* new_node = (struct Student*) malloc(sizeof(struct Student));
    new_node->roll_number = roll_number;
    strcpy(new_node->name,name);
    new_node->next = NULL;
    return new_node;
}

// Add new node at the end of the linked list
void add_node_end(int roll_number, char name[]) {
    struct Student* addNodeEnd = create_node(roll_number, name);
    /* This is only for the first node */
    if (head == NULL) {
        head = addNodeEnd;

    }
    else {
        /* This is for all other nodes */
        struct Student* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = addNodeEnd;
    }
}

void add_node_front(int roll_number, char name[]) {
    struct Student* addNodeFront = create_node(roll_number, name);
    addNodeFront->next = head;
    head = addNodeFront;
}

void delete_node_end() {
    if (head == NULL) {
        printf("#### Linked list is empty nothing to delete ####\n");
    }
    else if (head->next == NULL) {
        free(head);
        head = NULL;
    }
    else {
        struct Student* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }

}

void print_linked_list() {
    struct Student* temp = head;
    if (head == NULL) {
        printf(" #### Linked list is empty. Nothing to print ####\n");
    }
    else {
        int i = 1;
        while (temp !=NULL) {
            printf("[%d] %d, %s --> ", i, temp->roll_number, temp->name);
            temp = temp->next;
            i++;
        }
        printf("NULL\n");
    }

}

int main() {

    int roll_number;
    char name[20];
    int choice = 0;
    do {
        printf("\n $$$ Main Menu $$$\n");
        printf("Add node at front : 1\n");
        printf("Add node at end : 2\n");
        printf("Print linked list : 3\n");
        printf("Delete node at end : 4\n");
        printf("Exit Program : 0\n");
        printf("\n Enter your choice : ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                printf("Enter roll number : ");
                scanf("%d", &roll_number);
                printf("Enter name : ");
                scanf("%s", name);
                add_node_front(roll_number, name);
                break;
            case 2:
                printf("Enter roll number : ");
                scanf("%d", &roll_number);
                printf("Enter name : ");
                scanf("%s", name);
                add_node_end(roll_number, name);
                break;
            case 3:
                print_linked_list();
                break;
            case 4:
                delete_node_end();
                break;
            case 0:
                printf("Exit Program\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        fflush(stdin);
    } while (choice != 0);

}