#include <stdio.h>
#define MAX 3
int stack[MAX];
int top = -1;
int isFull(){
    return top ==MAX-1;
}
int isEmpty(){
    return top == -1;
}
void push(int val){
    if(isFull()){
        printf("Stack Overflow\n ");
        return;
    }
    else{
        stack[++top] = val;
        printf("Pushed %d\n",val);
    }
}
void pop(){
    if(isEmpty()){
        printf("Stack Underflow\n ");
        return;
    }
    else
        printf("Popped: %d\n",stack[top--]);
}
void peek(){
    if (isEmpty()){
        printf("Stack is Empty\n");
        return;
    }
    printf("The topmost element is: %d",stack[top]);
}
void display(){
    if(isEmpty()){
        printf("Stack is Empty\n");
        return;
    }
    else{
        printf("Printing stack from top to bottom: \n");
        for(int i = top;i>=0;i--)
            printf("%d\n",stack[i]);
    }
}
void checkpal(){
    printf("Enter number to check :");
    int num;
    scanf("%d",&num);
    int numcopy = num;
    int final =0;
    int tstack[100];
    int ttop=-1;
    while(numcopy>0){
        int val = numcopy%10;
        tstack[++ttop] = val;
        numcopy = numcopy/10;
    }
    for(int i =0;i<=ttop;i++){
        final= final*10 + tstack[i];
    }
    if(num==final)
        printf("Its a palindrome");
    else
        printf("Its not a palindrome");
}
int main(){
    int choice,val;
    printf("STACK OPERATIONS\n");
    printf("1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.CHECK PALINDROME\n6.EXIT");
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value to push: ");
                scanf("%d",&val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                checkpal();
                break;
            case 6:
                printf("Exiting...");
                return 0;
            default:
                printf("Invalid Choice");
        }
    }
}
