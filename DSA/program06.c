#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    struct node *prev;
    int ssn, phno;
    float sal;
    char name[20], dept[10], desg[20];
    struct node *next;
};

typedef struct node NODE;

NODE *h, *temp, *temp1, *temp2, *temp4;

int count = 0;

void create() {
    int ssn, phno;
    float sal;
    char name[20], dept[10], desg[20];
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    temp->prev = NULL;
    temp->next = NULL;
    printf("\n Enter ssn, name, department, designation, salary and phno of employee: ");
    scanf("%d %s %s %s %f %d", &ssn, name, dept, desg, &sal, &phno);
    temp->ssn = ssn;
    strcpy(temp->name, name);
    strcpy(temp->dept, dept);
    strcpy(temp->desg, desg);
    temp->sal = sal;
    temp->phno = phno;
    count++;
}

void insertbeg() {
    create();
    if (h == NULL) {
        h = temp;
        temp1 = h;
    } else {
        temp->next = h;
        h->prev = temp;
        h = temp;
    }
}

void insertend() {
    create();
    if (h == NULL) {
        h = temp;
        temp1 = h;
    } else {
        temp1->next = temp;
        temp->prev = temp1;
        temp1 = temp;
    }
}

void displaybeg() {
    temp2 = h;
    if (temp2 == NULL) {
        printf("List empty to display\n");
        return;
    }
    printf("\n Linked list elements from beginning: \n");
    while (temp2 != NULL) {
        printf("%d %s %s %s %f %d\n", temp2->ssn, temp2->name, temp2->dept, temp2->desg, temp2->sal, temp2->phno);
        temp2 = temp2->next;
    }
    printf(" No of employees = %d ", count);
}

int deleteend() {
    if (h == NULL) {
        printf("List is empty.\n");
        return 1;
    }
    struct node *temp;
    temp = h;
    if (temp->next == NULL) {
        free(temp);
        h = NULL;
    } else {
        temp2 = temp1->prev;
        temp2->next = NULL;
        printf("%d %s %s %s %f %d\n", temp1->ssn, temp1->name, temp1->dept, temp1->desg, temp1->sal, temp1->phno);
        free(temp1);
    }
    count--;
    return 0;
}

int deletebeg() {
    if (h == NULL) {
        printf("List is empty.\n");
        return 1;
    }
    struct node *temp;
    temp = h;
    if (temp->next == NULL) {
        free(temp);
        h = NULL;
    } else {
        h = h->next;
        printf("%d %s %s %s %f %d", temp->ssn, temp->name, temp->dept, temp->desg, temp->sal, temp->phno);
        free(temp);
    }
    count--;
    return 0;
}

int main() {
    int ch, n, i;
    h = NULL;
    temp = temp1 = NULL;
    printf("-----MENU-----\n");
    printf("\n 1 - create a DLL of n employees");
    printf("\n 2 - Display from beginning");
    printf("\n 3 - Insert at end");
    printf("\n 4 - delete at end");
    printf("\n 5 - Insert at beginning");
    printf("\n 6 - delete at beginning");
    printf("\n 7 - DEMO\n");
    printf("\n 8 - EXIT\n");
    while (1) {
        printf("\n Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\n Enter no of employees: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++)
                    insertend();
                break;

            case 2:
                displaybeg();
                break;

            case 3:
                insertend();
                break;

            case 4:
                deleteend();
                break;

            case 5:
                insertbeg();
                break;

            case 6:
                deletebeg();
                break;

            case 7:
                printf("This DLL can be used as Double Ended Queue by inserting and deleting from both ends.\n");
                break;

            case 8:
                exit(0);

            default:
                printf("wrong choice\n");
        }
    }
    return 0;
}
