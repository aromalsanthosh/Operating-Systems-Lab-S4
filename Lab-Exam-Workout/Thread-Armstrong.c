//C Program to create a thread called armstrong, which checks if a number is armstrong or not.
// Use 'cc -pthread Thread-Armstrong.c' or 'gcc -pthread Thread-Armstrong.c' to compile
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int global[1];

void *checkArmstrong(void *arg)
{
    int *arr;
    arr = arg;

    int num,digit,sum=0,i;
    num = arr[0];
    digit = num;
    while(digit!=0)
    {
        i = digit%10;
        sum = sum + i*i*i;
        digit = digit/10;
    }
    if(num == sum)
    {
        printf("%d is an Armstrong number\n",num);
    }
    else
    {
        printf("%d is not an Armstrong number\n",num);
    }

    return NULL;
}

int main() 
{
    printf("Enter The Number : ");
    scanf("%d",&global[0]);


    pthread_t armstrong; //unsigned integer value that stores the thread id of the thread created.
    pthread_create(&armstrong,NULL,checkArmstrong,global); //thread creation
    pthread_join(armstrong,NULL);//waiting for the termination of a thread.
    printf("\nThread ID: %lu ",armstrong );//Printing thread ID

    return 0;
}
