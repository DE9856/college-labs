#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student{
  char usn[20], name[20], program[20];
  int sem;
  long phno;
  struct Student *next;
};
typedef struct Student *student;
student start = NULL;

student create(){
  student getnode = (student)malloc(sizeof(struct Student));
  printf("Enter the details of the student: ");
  printf("\nEnter the USN: ");
  scanf("%s", getnode->usn);
  printf("Enter the name: ");
  scanf("%s", getnode->name);
  printf("Enter the program: ");
  scanf("%s", getnode->program);
  printf("Enter the semester: ");
  scanf("%d", &getnode->sem);
  printf("Enter the phone number: ");
  scanf("%ld", &getnode->phno);
  getnode->next = NULL;
  return getnode;
}

void insert_front(){
  student node = create();
  if(start == NULL)
    start = node;
  else{
    node->next = start;
    start = node;
  }
}

void delete_front(){
  if(start==NULL){
    printf("List is empty");
    return;
  }
  student temp = start;
  start = start->next;
  printf("Deleted Student USN is: %s", temp->usn);
  free(temp);
}

void insert_rear(){
  student node = create();
  if(start==NULL)
    start = node;
  else{
    student temp = start;
    while(temp->next!=NULL)
      temp = temp->next;
    temp->next = node;
  }
}

void delete_rear(){
  if(start==NULL){
    printf("List is Empty");
    return;
  }
  if(start->next==NULL){
    printf("Deleted node USN: %s",start->usn);
    free(start);
    start = NULL;
    return;
  }
  student temp = start, prev = NULL;
  while(temp->next!=NULL){
    prev = temp;
    temp = temp->next;
  }
  printf("Deleted Student USN is: %s", temp->usn);
  free(temp);
  prev->next = NULL;
}

void create_list(){
  int n;
  printf("Enter the number of students: ");
  scanf("%d", &n);
  for(int i=0;i<n;i++)
    insert_front();
}

void status(){
  if(start==NULL){
    printf("The list is Empty");
    return;
  }
  student temp = start;
  int count =0;
  printf("Student Details are: \n");
  while(temp!=NULL){
    printf("\nUSN: %s\nName: %s\nProgram: %s\nSemester: %d\nPhno: %ld\n", temp->usn, temp->name, temp->program, temp->sem, temp->phno);
    count++;
    temp = temp->next;
  }
  printf("Number of students are: %d", count);
}

void stack_demo(){
  int choice;
  printf("\nStack Demo\n\n1.Push\n2.Pop\n3.Display\n4.Exit\n\n");
  while(1){
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
      case 1: insert_front(); break;
      case 2: delete_front(); break;
      case 3: status(); break;
      case 4: printf("Exiting Stack Demo"); return;
      default: printf("Invalid Choice");
    }
  }
}

int main(){
  int choice;
  printf("SINGLY LINKED LIST\n\n1.Create List\n2.Display\n3.Insert Front\n4.Delete Front\n5.Insert Rear\n6.Delete Rear\n7.Stack Demo\n8.Exit");
  while(1){
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
      case 1:create_list(); break;
      case 2: status();break;
      case 3: insert_front(); break;
      case 4: delete_front();break;
      case 5: insert_rear();break;
      case 6:delete_rear();break;
      case 7:stack_demo();break;
      case 8:printf("Exiting...");exit(0);
      default: printf("Invalid Choice");
    }
  }
}
