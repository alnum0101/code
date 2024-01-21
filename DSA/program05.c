//-----part A----

#include<stdio.h>

#include<stdlib.h>

#include<math.h>

int i, top = -1;
int op1, op2, res, s[20];
char postfix[90], symb;
void
push(int item) {
  top = top + 1;
  s[top] = item;
}

int
pop() {
  int item;
  item = s[top];
  top = top - 1;
  return item;
}

void
main() {
  printf("\nEnter a valid postfix expression:\n");
  scanf("%s", postfix);
  for (i = 0; postfix[i] != '\0'; i++) {
    symb = postfix[i];
    if (isdigit(symb)) {
      push(symb - '0');
    } else {
      op2 = pop();
      op1 = pop();
      switch (symb) {
      case '+':
        push(op1 + op2);
        break;
      case '-':
        push(op1 - op2);
        break;
      case '*':
        push(op1 * op2);
        break;
      case '/':
        push(op1 / op2);
        break;
      case '%':
        push(op1 % op2);
        break;
      case '$':
      case '^':
        push(pow(op1, op2));
        break;
      default:
        push(0);
      }
    }
  }
  res = pop();
  printf("\n Result = %d", res);
}

//-----part B----

#include<stdio.h>

#include<conio.h>

#include<stdlib.h>

#define SIZE 5
int q[SIZE], i, r = -1, f = 0, option, count = 0, j;
int
main() {
  for (;;) {
    printf("\n 1.Insert 2.Delete\n 3.Display 4.Exit");
    printf("\nEnter your option:");
    scanf("%d", & option);
    switch (option) {
    case 1: //Inserting items to Queue
      if (count == SIZE)
        printf("\n Q is Full\n");
      else {

      }
      break;
      r = (r + 1) % SIZE;
      printf("\nEnter the item:");
      scanf("%d", & q[r]);
      count++;

    case 2: //Deleting items from Queue
      if (count == 0)
        printf("\nQ is empty\n");
      else {

      }
      break;
      printf("\nDeleted item is: %d", q[f]);
      count--;
      f = (f + 1) % SIZE;

    case 3: //Displaying items from Queue
      if (count == 0)
        printf("\nQ is Empty\n");
      else {
        i = f;
        for (j = 0; j < count; j++) {

        }
      }
      break;

      printf(" %d", q[i]);
      i = (i + 1) % SIZE;

    default:
      exit(0);
    }
  }
}
