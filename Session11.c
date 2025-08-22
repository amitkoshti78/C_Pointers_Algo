//
// Created by Amit Koshti on 21.08.25.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Node structure
struct Node {
    int wagen_number;
    char wagen_name[20];
    struct Node* next;
};

int main() {
    int i = 0;

    struct Node* head =(struct Node *) malloc(sizeof(struct Node));

    head->wagen_number = 100;
    strcpy(head->wagen_name, "Engine"); //new_node->wagen_name = "Engine";
    head->next = NULL;
    printf("\n %d , %s, %p", head->wagen_number, head->wagen_name, head);

    struct Node* new_node1 =(struct Node *) malloc(sizeof(struct Node));
    new_node1->wagen_number = 101;
    strcpy(new_node1->wagen_name, "Wagon1"); //new_node1->wagen_name = "Wagon1";
    new_node1->next = NULL;
    head->next = new_node1;


    struct Node* new_node2 =(struct Node *) malloc(sizeof(struct Node));
    new_node2->wagen_number = 102;
    strcpy(new_node2->wagen_name, "Wagon2"); //new_node2->wagen_name = "Wagon2";
    new_node2->next = NULL;
    new_node1->next = new_node2;

    struct Node* new_node3 =(struct Node *) malloc(sizeof(struct Node));
    new_node3->wagen_number = 103;
    strcpy(new_node3->wagen_name, "Wagon3"); //new_node3->wagen_name = "Wagon3";
    new_node3->next = NULL;
    new_node2->next = new_node3;

    struct Node* temp; ;

    printf("\n");
    for (temp = head; temp != NULL; temp = temp->next) {
        printf("\n %d , %s, %p", temp->wagen_number, temp->wagen_name, temp);
    }

    temp = head;
    printf("\n\n");
    for (i = 0; temp != NULL; i++) {
        printf("  %d , %s ", temp->wagen_number, temp->wagen_name);
        if (temp->next != NULL) {
            printf("*next--> %p", temp->next);
        }
        else {
            printf("*next--> NULL");
        }

        temp = temp->next;
    }
    printf("\n\n");


    printf("head->next %p", head->next->next->next);

}
/* temp =  0x6000023ad120       Engine
 * temp->next = 0x6000023ad140  Wagen1
 * temp->next = 0x6000023ad160  Wagen2
 * temp->next = 0x6000023ad180  Wagen3
 *
 * Engine --> 0x6000023ad120
 * Engine *next--> 0x6000023ad140
 * Wagen1 *next--> 0x6000023ad160
 * Wagen2 *next--> 0x6000023ad180
 * Wagen3 *next--> NULL
 *
 */
