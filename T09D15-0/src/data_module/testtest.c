#include <stdio.h>
int main (){

double *data;
int n;
scanf("%d", &n);
for (int i = 0; i < n; i++){
    scanf("%d", &data[i]);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - 1; j++){
            if (data[i] > data[j + 1]){
                int q = data[j];
                data[j] = data[j + 1];
                data[j + 1] = q;
            }
        }
    }
for (int i = 0; i < n; i++){
    printf("%d", data[i]);
}
}
return 0;
}
