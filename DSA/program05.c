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

#include<conio.h> int count=0,n;

int tower(int n, char s, char t, char d) {
  if (n == 1) {
    printf("\n Move disc 1 from %c to %c", s, d);
    count++;
    return 1;
  }
  tower(n - 1, s, d, t);
  printf("\n Move disc %d from %c to %c", n, s, d);
  count++;
  tower(n - 1, t, s, d);
}
int main() {
  printf("\n Enter the no. of discs:");
  scanf("%d", & n);
  tower(n, 'A', 'B', 'C');
  printf("\n The no. of disc moves is:%d", count);
  getch();
}
