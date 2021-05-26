/*C Program to create 2 process one parent process must bring odd numbers up to limit n.
At the same time child process must bring even numbers up to n. Also print the process id*/
#include <stdio.h>
#include <unistd.h>

void main()
{
	int limit;
	printf("Enter the limit :- ");
	scanf("%d",&limit);

	//fork() system call returns a process ID, pid_t data type representing process ID
	pid_t pid;
	pid=fork();//creates a child process
	//return value of fork() = 0 -> Child process
	//return value of fork() > 0 -> Parent process
	//return value of fork() < 0 -> Error!

	if (pid==0)//child process
	{
		printf("--------------\n");
		printf("Child process\n");
		printf("--------------\n");
		printf("Even numbers upto limit %d :-\n",limit);
		for (int i = 0; i <= limit; ++i)
		{
			if(i%2==0)
				printf("%d ",i);
		}
		printf("\n");
		printf("Process ID of Child process : %d\n",getpid());
		

	}
	else
	{
		printf("--------------\n");
		printf("Parent process\n");
		printf("--------------\n");
		printf("Odd numbers upto limit %d \n",limit);
		for (int i = 0; i <= limit; ++i)
		{
			if(i%2!=0)
				printf("%d ",i);
		}
		printf("\n");
		printf("Process ID of Parent process : %d\n",getpid());
	}

}
