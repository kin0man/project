#include <stdio.h>
#include <math.h>
#include "main.h"

static struct{
    func f;
    func g;
    func f_der;
    func g_der;
} data;

int count = 0;


double F(double x){
    return data.f(x) - data.g(x);
}

double F_der(double x){
    return data.f_der(x) - data.g_der(x);
}

double root(func f, func g, func f_der, func g_der, double a, double b, double eps){
    data.f = f;
    data.g = g;
    data.f_der = f_der;
    data.g_der = g_der;
    double c = a;
    int conv = 1;
    count = 0;
    if (F(c) * F(c + eps) < 0)
        return c;
    if(F_der(a) * (F_der(b) - F_der(a)) > 0){
        c = b;
        conv = -1;
    }
    while(F(c) * F(c + eps * conv) > 0){
        c = c - F(c) / F_der(c);
        count++;
    }
    return c;
}