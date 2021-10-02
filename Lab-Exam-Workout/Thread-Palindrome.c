//C Program to create a thread called palindrome, which checks if a number is armstrong or not.
// Use 'cc -pthread Thread-Palindrome.c' or 'gcc -pthread Thread-Palindrome.c' to compile
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int global[1];

void *checkPalindrome(void *arg)
{
    int *arr;
    arr = arg;

    int i,num,rem,rev=0;
    num = arr[0];
    for(i=num;i>0; )
    {
        rem=i%10;
        rev=rev*10+rem;
        i=i/10;
    }
    if(rev==num)
    {
        printf("%d is a Palindrome Number",num);
    }
    else
    {
        printf("%d is not a Palindrome Number",num);
    }

    return NULL;
}

int main() 
{
    printf("Enter The Number : ");
    scanf("%d",&global[0]);


    pthread_t palindrome; //unsigned integer value that stores the thread id of the thread created.
    pthread_create(&palindrome,NULL,checkPalindrome,global); //thread creation
    pthread_join(palindrome,NULL);//waiting for the termination of a thread.
    printf("\nThread ID: %lu ",palindrome );//Printing thread ID

    return 0;
}
