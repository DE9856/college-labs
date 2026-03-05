#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Employee{
  char ssn[20], name[20], dept[20], designation[20];
  int sal;
  long phno;
  struct Employee *llink, *rlink;
};
typedef struct Employee *employee;
employee start = NULL;

employee create(){
  printf("Enter Employee Details: ");
  employee getnode = (employee)malloc(sizeof(struct Employee));
  printf("Enter the ssn: ");
  scanf("%s", getnode->ssn);
  printf("Enter the name: ");
  scanf("%s", getnode->name);
  printf("Enter the department: ");
  scanf("%s", getnode->dept);
  printf("Enter the designation: ");
  scanf("%s", getnode->designation);
  printf("Enter the salary: ");
  scanf("%d", &getnode->sal);
  printf("Enter the phone number: ");
  scanf("%ld",&getnode->phno);
  getnode->rlink = NULL;
  getnode->llink = NULL;
  return getnode;
}

void insert_front(){
  employee node = create();
  if(start==NULL)
    start = node;
  else{
    node->rlink = start;
    start->llink = node;
    start = node;
  }
}

void delete_front(){
  if(start==NULL){
    printf("List is Empty");
    return;
  }
  employee temp = start;
  if(temp->rlink==NULL){
    printf("Deleted employee ssn: %s", temp->ssn);
    free(temp);
    start = NULL;
  }
  else{
    start = temp->rlink;
    start->llink = NULL;
    printf("Deleted employee ssn: %s", temp->ssn);
    free(temp);
  }
}


void insert_rear(){
  employee node = create();
  employee temp = start;
  if(start==NULL)
    start = node;
  else{
    while(temp->rlink!=NULL)
      temp = temp->rlink;
    temp->rlink = node;
    node->llink = temp;
  }
}

void delete_rear(){
  if(start==NULL){
    printf("List is Empty");
    return;
  }
  employee temp = start;
  employee prev= NULL;
  if(temp->rlink==NULL){
    free(temp);
    start = NULL;
  }
  else{
    while(temp->rlink!=NULL){
      prev = temp;
      temp = temp->rlink;
    }
    prev->rlink = NULL;
    printf("Delete employee ssn: %s", temp->ssn);
    free(temp);
  }
}

void create_list(){
  int n;
  printf("Enter number of employees: ");
  scanf("%d", &n);
  for(int i=0;i<n;i++)
    insert_rear();
}

void status(){
  if(start==NULL){
    printf("The list is empty");
    return;
  }
  printf("Employee Details: ");
  employee temp = start;
  int count = 0;
  while(temp!=NULL){
    printf("\n\nSSN: %s\nName: %s\nDepartment: %s\nDesignation: %s\nSalary: %d\nPhno:%ld\n\n",temp->ssn, temp->name, temp->dept, temp->designation, temp->sal, temp->phno);
    temp = temp->rlink;
    count++;
  }
  printf("\n\nThe number of employees are: %d\n\n", count);
}

void double_ended_queue_demo(){
  int ch;
  printf("DOUBLE ENDED QUEUE DEMO\n\n1.Insert Front\n2.Delete Front\n3.Insert Rear\n4.Delete Rear\n5.Display\n6.Exit\n\n");
  while(1){
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch(ch){
      case 1: insert_front();break;
      case 2: delete_front();break;
      case 3: insert_rear();break;
      case 4:delete_rear();break;
      case 5:status();break;
      case 6:return;
      default:printf("Invalid Choice");
    }
  }
}

int main(){
  int ch;
  printf("\n\nDOUBLY LINKED LIST\n\n1.Create List\n2.Display\n3.Insert Front\n4.Delete Front\n5.Insert Rear\n6.Delete Rear\n7.Double Ended Queue Demo\n8.Exit\n\n");
  while(1){
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch(ch){
      case 1:create_list();break;
      case 2:status();break;
      case 3:insert_front();break;
      case 4:delete_front();break;
      case 5:insert_rear();break;
      case 6:delete_rear();break;
      case 7:double_ended_queue_demo();break;
      case 8:printf("Exiting...");exit(0);
      default:printf("Invalid Choice");
    }
  }
}
