#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Poly{
  int coef, x,y,z;
  struct Poly *next;
};
typedef struct Poly *poly;

poly createhead(){
  poly head = (poly)malloc(sizeof(struct Poly));
  head->coef = 0;
  head->x  = head->y = head->z = -1;
  head->next = head;
  return head;
}

poly createnode(){
  poly node = (poly)malloc(sizeof(struct Poly));
  printf("\nEnter the coefficient: ");
  scanf("%d", &node->coef);
  printf("\nEnter the x,y,z exponents: ");
  scanf("%d%d%d", &node->x, &node->y, &node->z);
  node->next = NULL;
  return node;
}

void insert_rear(poly head){
  poly temp = head;
  poly node = createnode();
  while(temp->next!=head)
    temp = temp->next;
  temp->next = node;
  node->next = head;
}

void display(poly head){
  poly temp = head->next;
  if(temp==head){
    printf("\nPolynomial is empty");
    return;
  }
  while(temp!=head){
    printf(" %d * x^%d * y^%d * z^%d ",temp->coef, temp->x, temp->y, temp->z);
    temp = temp->next;
    if(temp!=head)
      printf(" + ");
  }
}

void evaluate(){
  poly head = createhead();
  int n,x,y,z;
  printf("Enter the number of terms in the polynomial: ");
  scanf("%d", &n);
  for(int i=0;i<n;i++)
    insert_rear(head);
  printf("Enter the x,y,z values: ");
  scanf("%d%d%d", &x, &y, &z);
  double result = 0.0;
  poly temp = head->next;
  while(temp!=head){
    result+= (temp->coef * pow(x,temp->x) * pow(y,temp->y) * pow(z,temp->z));
    temp = temp->next;
  }
  display(head);
  printf("The result of the polynomial is: %lf", result);
}

void insert_or_add(poly head, int coef, int x, int y, int z){
  
  poly temp = head->next;
  while(temp!=head){
    if(temp->x == x && temp->y ==y && temp->z ==z){
      temp->coef+=coef;
      return;
    }
    temp = temp->next;
  }
  
  poly node = (poly)malloc(sizeof(struct Poly));
  node->coef = coef;
  node->x = x;
  node->y = y;
  node->z = z;
  temp = head;
  while(temp->next!=head)
    temp = temp->next;
  temp->next = node;
  node->next = head;
}

void polysum(){
  poly head1 = createhead();
  poly head2 = createhead();
  poly sumhead = createhead();
  int n1,n2;
  
  printf("Enter no. of terms in polynomial 1: ");
  scanf("%d", &n1);
  printf("Enter polynomial 1 details: ");
  for(int i=0;i<n1;i++)
    insert_rear(head1);
  
  printf("Enter no. of terms in polynomial 2: ");
  scanf("%d",&n2);
  printf("Enter polynomial 2 details: ");
  for(int i=0;i<n2;i++)
    insert_rear(head2);
  
  poly temp = head1->next;
  while(temp!=head1){
    insert_or_add(sumhead, temp->coef, temp->x, temp->y, temp->z);
    temp = temp->next;
  }
  
  temp = head2->next;
  while(temp!=head2){
    insert_or_add(sumhead, temp->coef, temp->x, temp->y, temp->z);
    temp = temp->next;
   } 
  
  
  printf("\nPolynomial 1: ");
  display(head1);
  printf("\nPolynomial 2: ");
  display(head2);
  printf("Sum of Polynomials: ");
  display(sumhead);
}

void main(){
  int ch;
  printf("\nMENU: ");
  printf("\n1.Express and Evaluate a Polynomial\n2.Find the sum of two polynomials\n3.Exit\n\n");
  while(1){
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch(ch){
      case 1: evaluate();break;
      case 2: polysum();break;
      case 3: printf("Exiting...");exit(0);
    }
  }
}

