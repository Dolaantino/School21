#include "data_stat.h"

double max(double *data, int n){
        
    double max = data[0];
    for(int i = 1; i < n; i++){
        if(max < data[i]){
            max = data[i];
        }
    }
    return max;
}

double min(double *data, int n){

    double min = data[0];
    for(int i = 1; i < n; i++){
        if(min > data[i]){
            min = data[i];
        }
    }
    return min;
}

double mean(double *data, int n){

    double sred;
    double sum = 0;

    for (int i = 0; i < n; i++){
        sum = sum + data[i];
    }
    sred = sum/n;
    return sred;
}

double variance(double *data, int n){

    double disp;
    double sum = 0;
    double sred = mean(data, n);

    for (int i = 0; i < n; i++){
        sum = sum + (data[i] - sred) * (data[i] - sred);
    }
    disp = sum/n;
    return disp;
}