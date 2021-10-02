//C Program to create a thread called fibanocci, which prints fibanocci series upto a given limit.
// Use 'cc -pthread Thread-Fibanocci.c' or 'gcc -pthread Thread-Fibanocci.c' to compile
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int global[1];

void *printFibanocci(void *arg)
{
    int *arr;
    arr = arg;

    int first = 0, second = 1, third;
    int limit = arr[0];

    printf("First Fibanocci Series Upto %d : \n",limit);
    while (first < limit){

        printf("%d ", first);
        third = first + second;
        first = second;
        second = third;
    
    }
    
    return NULL;
}

int main() 
{
    printf("Enter The Limit : ");
    scanf("%d",&global[0]);


    pthread_t fibanocci; //unsigned integer value that stores the thread id of the thread created.
    pthread_create(&fibanocci,NULL,printFibanocci,global); //thread creation
    pthread_join(fibanocci,NULL);//waiting for the termination of a thread.
    printf("\nThread ID: %lu ",fibanocci );//Printing thread ID

    return 0;
}

/**
 * C program to print Fibonacci series up to n terms
 */

// #include <stdio.h>

// int main()
// {
//     int a, b, c, i, terms;

//     /* Input number from user */
//     printf("Enter number of terms: ");
//     scanf("%d", &terms);

//     /* Fibonacci magic initialization */
//     a = 0;
//     b = 1;
//     c = 0;

//     printf("Fibonacci terms: \n");

//     /* Iterate through n terms */
//     for(i=1; i<=terms; i++)
//     {
//         printf("%d, ", c);

//         a = b;     // Copy n-1 to n-2
//         b = c;     // Copy current to n-1
//         c = a + b; // New term
//     }

//     return 0;
// }
