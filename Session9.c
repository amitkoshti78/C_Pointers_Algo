//
// Created by Amit Koshti on 31.07.25.
//

#include <stdio.h>
#include <stdlib.h>


struct triangle {
    int length;
    int height;
    int width;
    int area;
};

int area_tringle() {
    struct triangle t2;
    t2.length = 20;
    t2.height = 10;
    t2.width = 20;
    t2.area = t2.length * t2.height;
    return t2.area;


}

int main() {
    struct triangle t1;
    t1.length = 10;
    t1.height = 5;
    t1.width = 10;
    t1.area = t1.length * t1.height;
    printf("\n Area of Triangle : %d \n", t1.area);


    struct car {
        char model_name[10];
        char number[10];
        char owner[20];
    };
    struct car c1;
    struct car c3;
    struct car *c2 = &c1; //C2 -> C1

    printf("\n Enter the name of the Car : ");
    scanf("%s", c1.model_name);
    printf("\n Enter the number : ");
    scanf("%s", c1.number);
    printf("\n Enter the Owner : ");
    scanf("%s", c1.owner);

    printf("\n Enter the name of the Car : ");
    scanf("%s", c3.model_name);
    printf("\n Enter the number : ");
    scanf("%s", c3.number);
    printf("\n Enter the Owner : ");
    scanf("%s", c3.owner);

    printf("\n C1 : Model : %s \n Number : %s \n Owner : %s \n", c1.model_name, c1.number, c1.owner);

    printf("\n C3 : Model : %s \n Number : %s \n Owner : %s \n", c3.model_name, c3.number, c3.owner);

    printf("\n C2 :Model : %s \n Number : %s \n Owner : %s \n", c2->model_name, c2->number, c2->owner);


    printf("\n Enter the name of the Car : ");
    scanf("%s", c2->model_name);
    printf("\n Enter the number : ");
    scanf("%s", c2->number);
    printf("\n Enter the Owner : ");
    scanf("%s", c2->owner);

    printf("\n C2 : Model : %s \n Number : %s \n Owner : %s \n", c2->model_name, c2->number, c2->owner);
    printf("\n C1 : Model : %s \n Number : %s \n Owner : %s \n", c1.model_name, c1.number, c1.owner);
    printf("\n C3 : Model : %s \n Number : %s \n Owner : %s \n", c3.model_name, c3.number, c3.owner);

    printf("\n Sizeof struct tringle : %d", sizeof(t1));
    printf("\n Sizeof struct car  : %d", sizeof(c1));
    printf("\n size of int %d :", sizeof(int));
    printf("\n size of char : %d", sizeof(char));

    printf("\n Area of t2 : %d", area_tringle());




    // Engine -> node1 -> node2 -> node3 -> node4 -> NULL
    // Engine -> node1 -> node2 -> node3 -> node4 -> NULL
    //        <-       <-       <-       <-       -> NULL

    /*struct Wagen {
        int wagen_number;
        int wagen_type;
        int wagen_seat;
        struct Wagen *next;
    };

    struct Wagen engine;
    struct Wagen *head = &engine;
    struct Wagen node1;
    struct Wagen node2;
    struct Wagen node3;
    struct Wagen node4;

    engine.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = NULL; */


}

