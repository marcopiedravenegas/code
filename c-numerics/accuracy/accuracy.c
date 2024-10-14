#include <stdio.h>
#include <float.h>

int main() {
    float sum_float = 0.0;
    double sum_double = 0.0;
    for(size_t k = 1; k <= 100000; ++k) {
        sum_float+=0.1;
        sum_double+=0.1;
    }
    printf("FLT_DIG: %d, sum_float:  %.10f\n", FLT_DIG, sum_float);
    printf("DBL_DIG: %d, sum_double: %.10f\n", DBL_DIG, sum_double);
}
