#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./decision.h"
#include "../data_module/data_process.h"
#include "../data_libs/data_io.h"

int main() {
    double *data;
    int n;

    input(&data, &n);

    if (make_decision(data, n)) {
        printf("YES");
    } else {
        printf("NO");
    }
    free(data);
    return 0;
}
