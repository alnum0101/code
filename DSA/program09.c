//Part-A

#include<stdio.h>

#include<stdlib.h>

#include<math.h>

int coef, px, py, pz, x, y, z, i;
int val;
struct node {
  int coef, px, py, pz;
  struct node * next;
};
typedef struct node NODE;
NODE * first;
void insert(int coef, int px, int py, int pz) {
  NODE * temp, * cur;
  temp = (NODE * ) malloc(sizeof(NODE));
  temp -> coef = coef;
  temp -> px = px;
  temp -> py = py;
  temp -> pz = pz;
  if (first == NULL) {
    temp -> next = temp;
    first = temp;
    return;
  }
  if (first -> next == first) {
    first -> next = temp;
    temp -> next = first;
  }
  cur = first;
  while (cur -> next != first) {
    cur = cur -> next;
  }
  cur -> next = temp;
  temp -> next = first;
  return;
}
void display() {
  NODE * cur;
  if (first == NULL) {
    printf("List is empty\n");
    return;
  }
  cur = first;
  while (cur -> next != first) {
    printf("%d ", cur -> coef);
    printf(" x^%d", cur -> px);
    printf(" y^%d", cur -> py);
    printf(" z^%d + ", cur -> pz);
    cur = cur -> next;
  }
  printf("%d ", cur -> coef);
  printf(" x^%d", cur -> px);
  printf(" y^%d", cur -> py);
  printf(" z^%d\n", cur -> pz);
  return;
}
int evaluate(int x, int y, int z) {
  NODE * cur;
  int v, s = 0, v1, v2, v3;
  if (first == NULL) {
    printf("List is empty\n");
    return 0;
  }
  cur = first;
  while (cur -> next != first) {
    v = cur -> coef * pow(x, cur -> px) * pow(y, cur -> py) * pow(z, cur -> pz);
    s = s + v;
    cur = cur -> next;
  }
  v = cur -> coef * pow(x, cur -> px) * pow(y, cur -> py) * pow(z, cur -> pz);
  s = s + v;
  return s;
}
int main() {
  int coef, px, py, pz, x, y, z, i;
  int val;
  first = NULL;
  while (1) {
    printf("1. Insert polynomial at end\n");
    printf("2. Display\n");
    printf("3. Evaluate\n");
    printf("4. Exit\n");
    printf("Enter Choice= \t");
    scanf("%d", & i);
    switch (i) {
    case 1:
      printf("Enter Coefficient= \t");
      scanf("%d", & coef);
      printf("Enter powers of x y z values= \t");
      scanf("%d%d%d", & px, & py, & pz);
      insert(coef, px, py, pz);
      break;
    case 2:
      display();
      break;
    case 3:
      printf("\n Enter x y & z values for evaluation: \t");
      scanf("%d%d%d", & x, & y, & z);
      val = evaluate(x, y, z);
      printf("\nValue=%d\n", val);
      break;
    case 4:
      return 0;
    default:
      printf(" Wrong choice. Enter 1,2 3\n");
      break;
    }
  }
}


//Part-B

#include<stdio.h>

#include<stdlib.h>

#include<math.h>

struct node
//Defining Polynomial fields
{
  int coef, px, py, pz, flag;
  struct node * link;
};
typedef struct node * NODE;
NODE create_list(NODE head) //For creating poly1 & poly2
{
  int i, n, cf, px, py, pz;
  printf("Enter the number of terms : ");
  scanf("%d", & n);
  for (i = 1; i <= n; i++) {
    printf("Enter the Co-ef, px, py, pz : ");
    scanf("%d %d %d %d", & cf, & px, & py, & pz);
    insert(head, cf, px, py, pz);
  }
  return head;
} /*End of create_list()*/
insert(NODE head, int cof, int x, int y, int z) //inserting term to poly
{
  NODE cur, tmp;
  tmp = (NODE) malloc(sizeof(struct node)); //Allocates memory int cf,px,py,pz;
  cur = head -> link;
  tmp -> coef = cof;
  tmp -> px = x;
  tmp -> py = y;
  tmp -> pz = z;
  tmp -> flag = 0;
  while (cur -> link != head) //Identifying last node
    cur = cur -> link;
  cur -> link = tmp;
  tmp -> link = head;
}
NODE add_poly(NODE h1, NODE h2, NODE h3) {
  NODE cur1, cur2, scf;
  cur1 = h1 -> link;
  cur2 = h2 -> link;
  while (cur1 != h1) //Till end of poly1
  {
    if (cur2 == h2)
      cur2 = h2 -> link;
    while (cur2 != h2) //Till end of poly2
    {
      if (cur1 -> px == cur2 -> px && cur1 -> py == cur2 -> py && cur1 -> pz == cur2 -> pz) {
        //Add & insert if co-ef's of both poly is equal
        scf = cur1 -> coef + cur2 -> coef;
        insert(h3, scf, cur1 -> px, cur1 -> py, cur1 -> pz);
        cur2 -> flag = 1;
        cur2 = h2 -> link;
        break;
      }
      cur2 = cur2 -> link;
    }
    if (cur1 == h1)
      break;
    if (cur2 == h2) //If co-ef of poly1 is not matched, insert it to poly3
      insert(h3, cur1 -> coef, cur1 -> px, cur1 -> py, cur1 -> pz);
    cur1 = cur1 -> link;
  }
  cur2 = h2 -> link;
  while (cur2 != h2) //remaining poly2 nodes inserted to poly3
  {
    if (cur2 -> flag == 0)
      insert(h3, cur2 -> coef, cur2 -> px, cur2 -> py, cur2 -> pz);
    cur2 = cur2 -> link;
  }
  return h3;
}
void display(NODE head) {
  NODE cur;
  if (head -> link == head) //if poly is empty
  {
    printf("List is empty\n");
    return;
  }
  cur = head -> link;
  while (cur != head) //display all terms till end
  {
    if (cur -> coef > 0)
      printf(" +%dx^%dy^%dz^%d ", cur -> coef, cur -> px, cur -> py, cur -> pz);
    else if (cur -> coef < 0)
      printf(" %dx^%dy^%dz^%d ", cur -> coef, cur -> px, cur -> py, cur -> pz);
    cur = cur -> link;
  }
  printf("\n");
} /*End of display() */
void main() {
  int choice, data, item, pos;
  NODE head1, head2, head3;
  head1 = (NODE) malloc(sizeof(struct node));
  head1 -> link = head1;
  //poly1
  head2 = (NODE) malloc(sizeof(struct node));
  head2 -> link = head2;
  //poly2
  head3 = (NODE) malloc(sizeof(struct node));
  head3 -> link = head3;
  //poly3
  printf("\n1.Create Polynomial 1\n");
  head1 = create_list(head1);
  printf("\n2.Create Polynomial 2\n");
  head2 = create_list(head2);
  printf("\nPolynomial 1 is :");
  display(head1);
  printf("\nPolynomial 2 is :");
  display(head2);
  head3 = add_poly(head1, head2, head3); //Add both polynomials
  printf("\nAddition of two Polynomial is :");
  display(head3);
}





