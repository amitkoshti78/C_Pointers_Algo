#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll_number;
    char name[20];
    int sem;
    int sub1;
    int sub2;
    int sub3;
    struct Student* next;
    struct Student* prev;
};

struct Student* head = NULL;
struct Student* tail = NULL;

struct Student* create_node(int roll_number, const char name[], int sem, int sub1, int sub2, int sub3) {
    struct Student* new_node = (struct Student*) malloc(sizeof(struct Student));
    new_node->roll_number = roll_number;
    new_node->sem = sem;
    strcpy(new_node->name, name);
    new_node->sub1 = sub1;
    new_node->sub2 = sub2;
    new_node->sub3 = sub3;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void insrt_at_end(int roll_number, const char name[], int sem, int sub1, int sub2, int sub3) {
    struct Student* new_node = create_node(roll_number, name, sem, sub1, sub2, sub3);
    if(head == NULL) {
        head = new_node;
        tail = new_node;
        return;
    }
    if(head->next == NULL) {
        head->next = new_node;
        new_node->prev = head;
        tail = new_node;
        return;
    }
    struct Student* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
    tail = new_node;

}

void display_linked_list() {
    struct Student* temp = head;
    if(head == NULL) {
        printf("\n Linked list is empty");
        return;
    }
    while(temp != NULL) {
        printf("\n Roll number: %d", temp->roll_number);
        printf("\n Name: %s", temp->name);
        printf("\n Sem: %d", temp->sem);
        printf("\n Sub1: %d", temp->sub1);
        printf("\n Sub2: %d", temp->sub2);
        printf("\n Sub3: %d", temp->sub3);
        temp = temp->next;
    }
}

void display_linked_list_back() {
    struct Student* temp = tail;
    if(temp == NULL) {
        printf("\n Linked list is empty");
        return;
    }

    while(temp != NULL) {
        printf("\n Roll number: %d", temp->roll_number);
        printf("\n Name: %s", temp->name);
        printf("\n Sem: %d", temp->sem);
        printf("\n Sub1: %d", temp->sub1);
        printf("\n Sub2: %d", temp->sub2);
        printf("\n Sub3: %d", temp->sub3);
        temp = temp->prev;
    }
}

void delete_linked_list() {
    struct Student* temp = head;
    while(temp != NULL) {
        struct Student* tofree = temp;
        temp = temp->next;
        free(tofree);
    }
    head = NULL;
    tail = NULL;
}

void main() {
    int roll_number;
    char name[20];
    int sem;
    int sub1;
    int sub2;
    int sub3;
    int choice = 0;

    do {
        printf("\n Enter roll number: ");
        scanf("%d", &roll_number);
        getchar();
        printf("\n Enter name: ");
        scanf("%s", name);
        printf("\n Enter sem: ");
        scanf("%d", &sem);
        printf("\n Enter sub1: ");
        scanf("%d", &sub1);
        printf("\n Enter sub2: ");
        scanf("%d", &sub2);
        printf("\n Enter sub3: ");
        scanf("%d", &sub3);
        insrt_at_end(roll_number, name, sem, sub1, sub2, sub3);
        printf("\n Enter 0 to exit: ");
        scanf("%d", &choice);

    } while (choice != 0);
    printf("\n Linked List printed in Forward order: ");
    display_linked_list();
    printf("\n Linked List printed in Reverse order: ");
    display_linked_list_back();

    delete_linked_list();

}

