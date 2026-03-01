#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define MAX 100
double stack[MAX];
int top = -1;
int isFull(){
    return top==MAX-1;
}
int isEmpty(){
    return top ==-1;
}
void push(double val){
    if(!isFull()){
        stack[++top] = val; 
    }
}
double pop(){
    if(!isEmpty())
        return(stack[top--]);
}
double eval_op(char op, double a, double b){
    switch(op){
        case '+': return a+b;break;
        case '-': return a-b;break;
        case '*':return a*b;break;
        case '/': return a/b;break;
        case '%': return fmod(a,b);break;
        case '^': return pow(a,b);break;
        default: printf("Invalid Operator");return 0.0;
    }
}
int main(){
    char suf[50];
    printf("Enter the suffix expression: ");
    scanf("%s",suf);
    for(int i =0;suf[i]!='\0';i++){
        if(isdigit((unsigned char)suf[i]))
            push(suf[i]-'0');
        else if(isalpha((unsigned char)suf[i])){
            double val;
            printf("Enter the value of %c: ",suf[i]);
            scanf("%lf",&val);
            push(val);
        }
        else{
            double op2 = pop();
            double op1 = pop();
            push(eval_op(suf[i],op1,op2));
        }
    }
    printf("Result: %lf",pop());
    return 0;
}
