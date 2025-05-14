typedef double (*func)(double);
double root(func f, func g, func f_der, func g_der, double a, double b, double eps);
double integral(func f, double a, double b, double eps);

int main(int argc, char *argv[]);
