#include <stdio.h>
#include <math.h>
#include "main.h"
#include <float.h>

double interval(double a, double b, double fa, double fm, double fb) {
    return (b - a) / 6 * (fa + 4 * fm + fb);
}

double recursive_integral(func f, double a, double b, double fa, double fm, double fb, double eps){
    double m = (a + b) / 2;
    double m1 = (a + m) / 2;
    double m2 = (m + b) / 2;
    double fm1 = f(m1);
    double fm2 = f(m2);
    double s_prev = interval(a, b, fa, fm, fb);
    double s_left = interval(a, m, fa, fm1, fm);
    double s_right = interval(m, b, fm, fm2, fb);
    double s_current = s_left + s_right;
    if (fabs(s_prev - s_current) < 15 * eps)
        return s_current;
    return recursive_integral(f, a, m, fa, fm1, fm, eps) +
           recursive_integral(f, m, b, fm, fm2, fb, eps);
}

double integral(double (*f)(double), double a, double b, double eps) {
    double fa = f(a);
    double fb = f(b);
    double fm = f((a + b) / 2);
    return recursive_integral(f, a, b, fa, fm, fb, eps);
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