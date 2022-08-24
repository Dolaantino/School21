#include "data_io.h"
#include <stdio.h>
void input(double **data, int *n){
    if (!scanf("%d", n)){
        printf ("n/a");
    };
    *data = (double*)malloc(sizeof(double) * *n);
    for(int i = 0; i < *n; i++){
       if (!scanf("%lf", &(*data)[i])){
           printf ("n/a");
       };
    }
}
void output(double *data, int n){
    for(int i = 0; i < n; i++){
        printf("%lf", data[i]);
    }
}
