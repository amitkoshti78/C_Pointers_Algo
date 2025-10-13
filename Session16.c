//
// Created by Amit Koshti on 13/10/25.
//

#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>

struct BinaryTree {
    int number;
    struct BinaryTree* left;
    struct BinaryTree* right;
};



struct BinaryTree* create_binary_tree_node(int number) {

    struct BinaryTree* new_node = (struct BinaryTree*) malloc(sizeof(struct BinaryTree));
    new_node->number = number;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;

}

struct BinaryTree* add_node(struct BinaryTree* root, int number) {

    /* First node */
    if(root == NULL) {
        return create_binary_tree_node(number);

    }
    else if(number < root->number) {

        root->left = add_node(root->left,number );
    }
    else if(number > root->number) {
        root->right = add_node(root->right,number );
    }
    else {
        printf("Number already exists\n");
    }

    return root;

}

void inorder(struct BinaryTree* root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);               
    printf("%d ", root->number);
    inorder(root->right);
}

int main () {
    struct BinaryTree* root = NULL;
    int number = 0;

    /*   Null <-- 5 --> NULL
     *   NULL <-- 3 <-- 5 --> NULL
     *   NULL <-- 2 <-- 3 <-- 5 --> NULL
     *                   <-- 5 --> NULL
               2  <--    3      --> 4
        NULL<-- --> NULL   NULL <--  -->NULL
        */
   do {
        printf("Enter number: ");
        scanf("%d", &number);
        if(number == -1) {
            break;
        }
        root = add_node(root, number);

    } while (number != -1) ;

    inorder(root);

    return 0;
}