#include <stdio.h>
#include <stdlib.h>
struct day{
    char *dayname;
    int date;
    char *activity;
};
struct day create(){
    struct day newday;
    newday.dayname = (char*)malloc(20*sizeof(char));
    newday.activity = (char*)malloc(20*sizeof(char));
    printf("Enter Day Name: ");
    scanf("%s",newday.dayname);
    printf("Enter Date: ");
    scanf("%d",&newday.date);
    printf("Enter Activity: ");
    scanf("%s",newday.activity);
    return newday;
}
void read(struct day calendar[], int numdays){
    for(int i =0;i<numdays;i++){
        printf("Day %d: \n",i+1);
        calendar[i] = create();
    }
}
void display(struct day calendar[], int numdays){
    for(int i =0;i<numdays;i++){
        printf("Day %d: \n",i+1);
        printf("Day Name: %s\nDate: %d\nActivity: %s\n\n",calendar[i].dayname, calendar[i].date, calendar[i].activity);
    }
}
int main(){
    printf("Enter number of days: ");
    int num;
    scanf("%d",&num);
    struct day Calendar[num];
    printf("Enter detais: ");
    read(Calendar,num);
    display(Calendar,num);
    for(int i =0;i<num;i++){
        free(Calendar[i].dayname);
        free(Calendar[i].activity);
    }
}
