#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>

void read_from_terminal(int A[], int len){
    int i = 0;
    int flag_error = 0;

    while(i < len){
        if (scanf("%d",&(A[i])) != 1 && flag_error == 0) {
            printf("n/a");
            flag_error = -1;
        }
        i = i + 1;
    }
}

void sort_array(int A[], int len){
    int i = 0;
    int a;
    int p;

    while(i < len){
        a = i;
        while(a < len){
            if(A[i] > A[a]){
                p = A[i];
                A[i] = A[a];
                A[a] = p;
               
            }
            a = a + 1;
        }
        i = i + 1;
    }
}

void print_sorted_array(int A[], int len){
    int i = 0;
    
    while(i < len-1){
        printf("%d ", A[i]);
        i = i + 1;
    }
    printf("%d\n", A[i]);
}
 
int main () 
{   
    int *A;
    int len;
    int flag_error = 0;
   if (scanf("%d", &len) != 1 && flag_error == 0) {
        printf("n/a");
        flag_error = -1;
    }
    
   
    A = malloc(sizeof(int) * len);
    if(A == NULL){
        printf("%s","n/a");
        return 1; 
    }
    if (flag_error == 0){
    read_from_terminal(A, len);
    sort_array(A, len);
    print_sorted_array(A, len);
    free(A);
    }
   // printf("\n");
   // A = NULL;
   // sleep (100);    

    return 0;
}
    
