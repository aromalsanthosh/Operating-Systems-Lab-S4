//C Program to create a thread called swap, which access two integers from the user and swaps the sum.
// Use 'cc -pthread Thread-SwapNum.c' or 'gcc -pthread Thread-SwapNum.c' to compile

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int global[2];

void *swapNumbers(void *arg)
{
    int *arr;
    arr = arg;

    int x,y, temp;
    x = arr[0];
    y = arr[1];
    
    printf("Before Swapping\nx = %d\ny = %d\n", x, y);

    temp = y;
    y = x;
    x = temp;

    printf("After Swapping\nx = %d\ny = %d\n", x, y);


    return NULL;
}


int main() 
{
    printf("Enter The First Number X : ");
    scanf("%d",&global[0]);

    printf("Enter The Second Number Y : ");\
    scanf("%d",&global[1]);

    pthread_t thread;
    pthread_create(&thread, NULL, swapNumbers, global);
    pthread_join(thread, NULL);
    
    return 0;

}