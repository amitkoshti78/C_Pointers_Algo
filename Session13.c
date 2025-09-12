//
// Created by Amit Koshti on 12/09/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct Student {
    int roll_number;
    char name[20];
    struct Student* next;
};

struct Student* head = NULL;

// Create a new node safely
struct Student* create_node(int roll_number, const char name[]) {
    struct Student* new_node = malloc(sizeof(struct Student));
    if (!new_node) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    new_node->roll_number = roll_number;
    strncpy(new_node->name, name, sizeof(new_node->name) - 1);
    new_node->name[sizeof(new_node->name) - 1] = '\0';
    new_node->next = NULL;
    return new_node;
}

// Add node at end
void add_node_end(int roll_number, const char name[]) {
    struct Student* addNodeEnd = create_node(roll_number, name);
    if (head == NULL) {
        head = addNodeEnd;
    } else {
        struct Student* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = addNodeEnd;
    }
}

// Add node at front
void add_node_front(int roll_number, const char name[]) {
    struct Student* addNodeFront = create_node(roll_number, name);
    addNodeFront->next = head;
    head = addNodeFront;
}

// Delete node at end
void delete_node_end() {
    if (head == NULL) {
        printf("#### Linked list is empty ####\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct Student* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

// Delete by roll number (fixed)
void delete_roll_number(int roll_number) {
    if (head == NULL) {
        printf("#### Linked list is empty ####\n");
        return;
    }

    if (head->roll_number == roll_number) {
        struct Student* tofree = head;
        head = head->next;
        free(tofree);
        return;
    }

    struct Student* temp = head;
    while (temp->next != NULL && temp->next->roll_number != roll_number) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("#### Roll number %d not found ####\n", roll_number);
        return;
    }

    struct Student* tofree = temp->next;
    temp->next = tofree->next;
    free(tofree);
}

// Insert at location
void insert_at_location(int roll_number, const char name[], int location) {
    struct Student* new_node = create_node(roll_number, name);
    if (location <= 0) {
        printf("#### Invalid location ####\n");
        free(new_node);
        return;
    }

    if (location == 1 || head == NULL) {
        new_node->next = head;
        head = new_node;
        return;
    }

    struct Student* temp = head;
    int i = 1;
    while (temp->next != NULL && i < location - 1) {
        i++;
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

// Print linked list
void print_linked_list() {
    if (head == NULL) {
        printf("#### Linked list is empty ####\n");
        return;
    }
    struct Student* temp = head;
    int i = 1;
    while (temp != NULL) {
        printf("[%d] %d, %s --> ", i, temp->roll_number, temp->name);
        temp = temp->next;
        i++;
    }
    printf("NULL\n");
}

// Free entire list
void free_list() {
    struct Student* temp = head;
    while (temp != NULL) {
        struct Student* tofree = temp;
        temp = temp->next;
        free(tofree);
    }
    head = NULL;
}

// Main program
int main() {
    int roll_number, location, choice = 0;
    char name[20];

    do {
        printf("\n $$$ Main Menu $$$\n");
        printf("1. Add node at front\n");
        printf("2. Add node at end\n");
        printf("3. Print linked list\n");
        printf("4. Delete node at end\n");
        printf("5. Delete using roll number\n");
        printf("6. Insert at location\n");
        printf("0. Exit Program\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &roll_number);
                printf("Enter name: ");
                scanf("%19s", name);
                add_node_front(roll_number, name);
                break;
            case 2:
                printf("Enter roll number: ");
                scanf("%d", &roll_number);
                printf("Enter name: ");
                scanf("%19s", name);
                add_node_end(roll_number, name);
                break;
            case 3:
                print_linked_list();
                break;
            case 4:
                delete_node_end();
                break;
            case 5:
                printf("Enter roll number: ");
                scanf("%d", &roll_number);
                delete_roll_number(roll_number);
                break;
            case 6:
                printf("Enter roll number: ");
                scanf("%d", &roll_number);
                printf("Enter name: ");
                scanf("%19s", name);
                printf("Insert location: ");
                scanf("%d", &location);
                insert_at_location(roll_number, name, location);
                break;
            case 0:
                printf("Exiting and freeing memory...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);

    free_list();
    return 0;
}
