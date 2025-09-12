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

void delete_roll_number(int roll_number) {
    if (head == NULL) {
        printf("#### Linked list is empty nothing to delete ####\n");
    }
    else if(head -> next == NULL) {
        free(head);
        head = NULL;
    }
    else if(head->roll_number == roll_number) {
            struct Student* delete_node = head;
            head = head->next;
            free(delete_node);
    }
    else {

      struct Student* temp = head;
      while(temp->next->roll_number != roll_number && temp->next != NULL) {
            temp = temp->next;
      }
      if(temp->next->roll_number == roll_number && temp->next->next != NULL) {
            struct Student* delete_node = temp->next;
            temp->next = temp->next->next;
            free(delete_node);

           //struct Student* tnode = temp->next->next;
           //free(temp->next);
           //temp->next = tnode;
       }
        if(temp->next->roll_number == roll_number && temp->next->next == NULL) {
                free(temp->next);
                temp->next = NULL;
        }
    }
}

void insert_at_location(int roll_number, char name[], int location) {
    struct Student* new_node = create_node(roll_number, name);
    int i = 1;

    struct Student* temp = head;
    if (head == NULL)
        head = new_node;
    else if (location == 1) {
         new_node->next = head;
         head = new_node;
    }
    else {
        location = location - 1;
        if (location < 1) {
            printf("#### Invalid location ####\n");
            return;
        }
        while (temp->next != NULL && i < location) {
            i++;
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
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
    int location;

    int choice = 0;

    do {
        printf("\n $$$ Main Menu $$$\n");
        printf("Add node at front : 1\n");
        printf("Add node at end : 2\n");
        printf("Print linked list : 3\n");
        printf("Delete node at end : 4\n");
        printf("Delete using roll number : 5\n");
        printf("Insert at location : 6\n");
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
            case 5:
                printf("Enter roll number : ");
                scanf("%d", &roll_number);
                delete_roll_number(roll_number);
                break;
            case 6:
                printf("Enter roll number : ");
                scanf("%d", &roll_number);
                printf("Enter name : ");
                scanf("%s", name);
                printf("Insert location : ");
                scanf("%d", &location);
                insert_at_location(roll_number, name, location);
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