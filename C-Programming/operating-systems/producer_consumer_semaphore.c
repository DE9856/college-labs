#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#define MAX 3
int buffer[MAX];
int in=0,out=0;
sem_t full;
sem_t empty;
pthread_mutex_t mutex;
void produce(){
  int item,value;
  sem_getvalue(&empty,&value);
  if(value==0){
    printf("Buffer is Full");
    return;
  }
  printf("Enter item to Produce: ");
  scanf("%d",&item);
  sem_wait(&empty);
  pthread_mutex_lock(&mutex);
  buffer[in] = item;
  in = (in+1)%MAX;
  printf("\nProducer has produced item: %d\n",item);
  pthread_mutex_unlock(&mutex);
  sem_post(&full);
}
void consume(){
  int item,value;
  sem_getvalue(&full,&value);
  if(value==0){
    printf("Buffer is Empty");
    return;
  }
  sem_wait(&full);
  pthread_mutex_lock(&mutex);
  item = buffer[out];
  out = (out+1)%MAX;
  printf("Consumer has consumed item: %d",item);
  pthread_mutex_unlock(&mutex);
  sem_post(&empty);
}
int main(){
  int choice;
  sem_init(&empty,0,MAX);
  sem_init(&full,0,0);
  pthread_mutex_init(&mutex,NULL);
  while(1){
        printf("\n1.Produce\n2.Consume\n3.Exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                produce();
                break;
            case 2:
                consume();
                break;
            case 3:
                printf("exiting..\n");
                sem_destroy(&full);
                sem_destroy(&empty);
                pthread_mutex_destroy(&mutex);
                return 0;
            default:
                printf("invalid choice\n");
        }
    }
    return 0;
}
