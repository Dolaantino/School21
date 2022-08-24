#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
void sort(struct door* doors);
void closes(struct door* doors);
void output(struct door* doors);

int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    sort(doors);
    closes(doors);
    output(doors);

    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}
void sort(struct door* doors) {
    struct door temp[DOORS_COUNT];
    for (int i = 0; i < DOORS_COUNT; i++) {
        for (int a = 0; a < DOORS_COUNT; a++) {
           if (doors[i].id < doors[a].id) {
                temp[i] = doors[i];
                doors[i] = doors[a];
                doors[a] = temp[i];
            }
         }
    }
}
void output(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        printf("%d , %d \n", doors[i].id, doors[i].status);
    }
}
void closes(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = 0;
    }
}
