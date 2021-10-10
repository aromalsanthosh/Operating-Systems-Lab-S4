#include<stdio.h>
#include<stdlib.h>

int main() {
    int diskQueue[20], n, i, seekTime=0, diff;
    printf("Enter the size of Queue: ");
    scanf("%d", &n);
    printf("Enter the Queue: ");
    for(i=1;i<=n;i++) {                                     /* head element to be read */                       
        scanf("%d",&diskQueue[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &diskQueue[0]);                             /* head element */
    printf("\nMovement of Cylinders\n");
    for(i=0;i<n;i++) {
        diff= abs(diskQueue[i+1] - diskQueue[i]);           /* abs( ) function in C returns the absolute value of an integer, which is always positive. */
        seekTime+= diff;                    
        printf("Move from %d to %d with seek time %d\n", diskQueue[i], diskQueue[i+1], diff);
    }
    printf("\nTotal Seek Time: %d", seekTime);
    printf("\nAverage Seek Time = %f",(float) seekTime/n);
    printf("\n");
    return 0;
}
