#include <stdio.h>
#include <math.h>
#include "main.h"

extern int count;

double f1(double x){
    return 1 + 4 / (x * x + 1);
}

double f1_der(double x){
    return -(8 * x)/((x * x + 1) * (x * x + 1));
}

double f2(double x){
    return x * x * x;
}

double f2_der(double x){
    return 3 * x * x;
}

double f3(double x){
    return pow(2, -x);
}

double f3_der(double x){
    return -(log(2))/(pow(2, x));
}

int test_root(void){
    //4check:
    //https://www.desmos.com/calculator/21uae1pi7k
    printf("ans: %.3f, count: %d\n", root(f1, f2, f1_der, f2_der, 1.0, 2.0, 0.001), count);
    printf("ans: %.3f, count: %d\n", root(f1, f3, f1_der, f3_der, -2.0, -1.0, 0.001), count);
    printf("ans: %.3f, count: %d\n\n", root(f2, f3, f2_der, f3_der, 0.0, 1.5, 0.001), count);
    printf("%.3f\n", integral(f1, 1.0, 2.0, 0.001));
    printf("%.3f\n", integral(f2, 2.0, -1.0, 0.001));
    printf("%.3f\n", integral(f3, 0.0, 1.5, 0.001));
    //4check:
    //https://mathdf.com/int/ru/#expr=1%2B4%2F(x%5E(2)%2B1)&arg=x&b=1&t=2
    //https://mathdf.com/int/ru/#expr=x%5E3&arg=x&b=-2&t=-1
    //https://mathdf.com/int/ru/#expr=2%5E(-x)&arg=x&b=0&t=1.5
}