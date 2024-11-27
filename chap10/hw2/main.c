#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node {
    int data;
    struct node *next;
};

void addq(struct node **head, struct node **tail, int data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (*tail == NULL) {
        *head = *tail = new_node;
    } else {
        (*tail)->next = new_node;
        *tail = new_node;         
    }
}

int delete(struct node **head, struct node **tail) {
    if (*head == NULL) {
        printf("Queue is empty!\n");
        return -1; 
    }

    struct node *temp = *head;
    int deleted_data = temp->data;

    *head = (*head)->next;
    if (*head == NULL) {    
        *tail = NULL;
    }
    free(temp); 
    return deleted_data;
}

void print_queue(struct node *head) {
    if (head == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    struct node *current = head;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
    printf("\n");
}

void handle_non_integer_input(struct node *head, const char *input) {
    if (!isdigit(input[0])) {
		printf("Print queue\n");
        print_queue(head);
    }
}

int main() {
    struct node *head = NULL;
    struct node *tail = NULL; 
    char input[100];
    int data;

    while (1) {
        fgets(input, 100, stdin);

        char *newline = strchr(input, '\n');
        if (newline) {
            *newline = '\0';
        }

        if (sscanf(input, "%d", &data) == 1) {
            addq(&head, &tail, data);
        } else {
            handle_non_integer_input(head, input);
			break;
        }
    }

    return 0;
}

