#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node **top, int data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *top;
    *top = new_node;
}

int pop(struct node **top) {
    if (*top == NULL) {
        printf("Stack is empty!\n");
        return -1; 
    }

    struct node *temp = *top;
    int popped_data = temp->data;

    *top = (*top)->next;
    free(temp); 
    return popped_data;
}

void print_stack(struct node *top) {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    struct node *current = top;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
    printf("\n");
}

void handle_non_integer_input(struct node **top, const char *input) {
    if (!isdigit(input[0])) {
        print_stack(*top);
    }
}

int main() {
    struct node *top = NULL; 
    char input[100];
    int data;

    while (1) {
        fgets(input, 100, stdin);

        char *newline = strchr(input, '\n');
        if (newline) {
            *newline = '\0';
        }

        if (sscanf(input, "%d", &data) == 1) {
            push(&top, data);
        } else {
            handle_non_integer_input(&top, input);
			break;
        }
    }

    return 0;
}

