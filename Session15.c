//
// Created by amit.koshti on 13/10/2025.
//
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

// Define structure for a tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Stack structure for Node pointers
struct Stack {
    struct Node* items[STACK_SIZE];
    int top;
};

// Stack operations
void initStack(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == STACK_SIZE - 1;
}

void push(struct Stack* stack, struct Node* node) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->items[++stack->top] = node;
}

struct Node* pop(struct Stack* stack) {
    if (isEmpty(stack))
        return NULL;
    return stack->items[stack->top--];
}

struct Node* peek(struct Stack* stack) {
    if (isEmpty(stack))
        return NULL;
    return stack->items[stack->top];
}

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Non-recursive insertion
struct Node* insert(struct Node* root, int value) {
    struct Node* newNode = createNode(value);

    if (root == NULL)
        return newNode;

    struct Node* current = root;
    struct Node* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (value < current->data)
            current = current->left;
        else if (value > current->data)
            current = current->right;
        else {
            printf("Duplicate value %d ignored.\n", value);
            free(newNode);
            return root;
        }
    }

    if (value < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}

// Non-recursive search
struct Node* search(struct Node* root, int key) {
    struct Node* current = root;
    while (current != NULL) {
        if (key == current->data)
            return current;
        else if (key < current->data)
            current = current->left;
        else
            current = current->right;
    }
    return NULL;
}

// Non-recursive inorder traversal using stack
void inorder(struct Node* root) {
    struct Stack stack;
    initStack(&stack);
    struct Node* current = root;

    while (current != NULL || !isEmpty(&stack)) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }

        current = pop(&stack);
        printf("%d ", current->data);
        current = current->right;
    }
}

// Find minimum value node (used for deletion)
struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Delete node (partially iterative)
struct Node* deleteNode(struct Node* root, int key) {
    struct Node* parent = NULL;
    struct Node* current = root;

    // Find the node to delete
    while (current != NULL && current->data != key) {
        parent = current;
        if (key < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (current == NULL) {
        printf("Key %d not found.\n", key);
        return root;
    }

    // Case 1: Node with no child
    if (current->left == NULL && current->right == NULL) {
        if (current == root)
            root = NULL;
        else if (parent->left == current)
            parent->left = NULL;
        else
            parent->right = NULL;
        free(current);
    }

    // Case 2: Node with one child
    else if (current->left == NULL || current->right == NULL) {
        struct Node* child = (current->left) ? current->left : current->right;

        if (current == root)
            root = child;
        else if (parent->left == current)
            parent->left = child;
        else
            parent->right = child;

        free(current);
    }

    // Case 3: Node with two children
    else {
        struct Node* successor = findMin(current->right);
        int val = successor->data;
        root = deleteNode(root, successor->data); // recursion only for successor cleanup
        current->data = val;
    }

    return root;
}

// Free tree iteratively (postorder using 2 stacks)
void freeTree(struct Node* root) {
    if (root == NULL)
        return;

    struct Stack stack1, stack2;
    initStack(&stack1);
    initStack(&stack2);
    push(&stack1, root);

    while (!isEmpty(&stack1)) {
        struct Node* node = pop(&stack1);
        push(&stack2, node);

        if (node->left)
            push(&stack1, node->left);
        if (node->right)
            push(&stack1, node->right);
    }

    while (!isEmpty(&stack2)) {
        free(pop(&stack2));
    }
}

int main() {
    struct Node* root = NULL;
    int n, value, choice, key;

    printf("How many nodes to insert? ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    while (1) {
        printf("\n=== MENU ===\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display (Inorder)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &key);
                if (search(root, key))
                    printf("%d found in tree.\n", key);
                else
                    printf("%d not found.\n", key);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                freeTree(root);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
