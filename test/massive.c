#include <stdio.h>
int main (){
// int a;
//int p;
int b;
int n;
int max;
int min;
scanf("%d", &n);
int A[n];
for(int i = 0; i < n; i++){
    scanf("%d", &A[i]);
}
//for(int i = 0; i < n; i++){
    //printf("%d ", A[i]);
//}
max = A[0];
min = A[0];
for(int i = 0; i < n; i++){
    if(max < A[i]){
        A[max] = A[i];
    }
}
for(int i = 0; i < n; i++){
    if(min > A[i]){
        A[min] = A[i];
    }
}
b = A[min];
A[min] = A[max];
A[max] = b;
    for(int i = 0; i < n; i++){
    printf("%d ", A[i]);
}
//b = A[min];
//A[min] = A[max];
//A[max] = b;

//for(int i = 0; i < n; i++){
  //  printf("%d ", A[i]);
//}
//min = A[0];
//for (int i = 0; i < n - 1; i ++){
    //if(A[i] > A[i+1]){
       // min = A[i+1];
    //}
//}
//p = max;
//max = min;
//min = p;
 printf("\n%d\n%d", A[max], A[min]);
return 0;
}