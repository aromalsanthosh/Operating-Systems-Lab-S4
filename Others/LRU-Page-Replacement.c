#include <stdio.h>

void LRU(int[], int[], int[], int, int);
int findLRU(int[], int);

int main() {
    int i, pCount, fCount, pages[30], frames[20], time[20];
    printf("Number of Frames : ");
    scanf("%d", &fCount);
    // create frames array will null values
    for (i = 0; i < fCount; ++i) {
        frames[i] = -1;
    }
    printf("Number of Pages : ");
    scanf("%d", &pCount);
    printf("Enter the reference string\n");
    for (i = 0; i < pCount; ++i) {
        scanf("%d", &pages[i]);
    }
    LRU(pages, frames, time, fCount, pCount);

    return 0;
}

void LRU(int pages[], int frames[], int time[], int fCount, int pCount) {
    printf("\nRef.String   |\tFrames\n");
    printf("-------------------------------\n");

    int i, j, k, pos, flag, faultCount, counter, queue;
    counter = 0, queue = 0, faultCount = 0;

    for (i = 0; i < pCount; ++i) {
        flag = 0;
        printf("  %d\t|\t", pages[i]);
        // check if already present
        for (j = 0; j < fCount; ++j) {
            if (frames[j] == pages[i]) {
                flag = 1;                                   // this means that the character is already there in one of the frames.
                counter++;
                time[j] = counter;                          // update occurance
                printf("   Hit\n\n");
                break;
            }
        }
        // push if there is free space
        if ((flag == 0) && (queue < fCount)) {              // empty frames[] spaces
            faultCount++;
            counter++;
            frames[queue] = pages[i];
            time[queue] = counter;
            queue++;                                        // queue is to keep the count of number of frames which have been filled.
        }
        // replacement as frames[] is full
        else if ((flag == 0) && (queue == fCount)) {        // the frames are full now
            faultCount++;
            counter++;
            pos = findLRU(time, fCount);
            frames[pos] = pages[i];
            time[pos] = counter;
        }
        // printing
        if (flag == 0) {
            for (k = 0; k < fCount; ++k) {
                printf("%d  ", frames[k]);
            }
            printf("\n\n");
        }
    }
    printf("Total Page Faults = %d\n\n", faultCount);
}

int findLRU(int time[], int fCount) {
    int k, min, pos;
    pos = 0;
    min = time[0];
    for (k = 1; k < fCount; ++k) {
        if (time[k] < min) {
            min = time[k];
            pos = k;
        }
    }
    return pos;
}
