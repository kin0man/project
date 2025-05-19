#include <stdio.h>
#include <math.h>
#include "main.h"
#include <float.h>


double integral(func f, double a, double b, double eps) {
    int n = 1;
    double start_I;
    double h = (b - a) / (2 * n);
    double even_sum = 0.0;
    double x = a + 2 * h;
    for (int i = 2; i < 2 * n; i += 2){
        even_sum += f(x);
        x += h * 2;
    }
    even_sum *= 2;
    x = a + h;
    double odd_sum = 0.0;
    for (int i = 1; i < 2 * n; i += 2){
        odd_sum += f(x);
        x += h * 2;
    }
    odd_sum *= 4;
    start_I = (f(a) + f(b) + odd_sum + even_sum) * h / 3;
    double I = start_I;
    odd_sum /= 4;
    even_sum /= 2;
    do
    {   
        n *= 2;
        start_I = I;
        double H = (b - a) / (2 * n);
        double even_sum_ = even_sum + odd_sum;
        even_sum_ *= 2;
        double X = a + H;
        double odd_sum_ = 0.0;
        for (int i = 1; i < 2 * n; i += 2){
            odd_sum_ += f(X);
            X += H * 2;
        }
        odd_sum_ *= 4;
        I = (f(a) + f(b) + odd_sum_ + even_sum_) * H / 3;
        even_sum = even_sum_ / 2;
        odd_sum = odd_sum_ / 4;
    } while (fabs(I - start_I) > eps / 15);
    return I;
}

// double integral(func f, double a, double b, double eps){
//     int n = 2;  // Минимальное четное количество интервалов
//     double h = (b - a) / n;
//     double sum_prev = 0.0;
//     double sum_current = DBL_MAX;
    
//     do {
//         double x1 = a;
//         double x2 = a;
//         sum_prev = sum_current;
//         h = (b - a) / n;
//         sum_current = 0;
//         for (int i = 0; i < n; i++){
//             x2 += h;
//             sum_current += (x2 - x1) / 6.0 * (f(x1) + 4.0 * f((x1 + x2) / 2) + f(x2));
//             x1 += h;
//         }
//         n *= 2;
//     } while (fabs(sum_current - sum_prev) / 15 >= eps);
//     return sum_current;
// }