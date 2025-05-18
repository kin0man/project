#include <stdio.h>
#include <string.h>
#include <math.h>
#include "funcs.h"
#include "main.h"

extern int count;

// f(x) = sin(3x) + 1
double test_f1(double x) {
    return sin(3*x) + 1;
}

// f'(x) = 3cos(3x)
double test_f1_der(double x) {
    return 3*cos(3*x);
}

// f(x) = cos(x) + x/2
double test_f2(double x) {
    return cos(x) + x/2;
}

// f'(x) = -sin(x) + 1/2 
double test_f2_der(double x) {
    return -sin(x) + 0.5;
}

// f(x) = sqrt(x + 4)
double test_f3(double x) {
    return sqrt(x + 4);
}

// f'(x) = 1/(2*sqrt(x + 4))
double test_f3_der(double x) {
    return 1/(2*sqrt(x + 4));
}


// double f1b(double x){
//     return 1 + 4 / (x * x + 1);
// }

// double df1b(double x){
//     return -(8 * x)/((x * x + 1) * (x * x + 1));
// }

// double f2b(double x){
//     return x * x * x;
// }

// double df2b(double x){
//     return 3 * x * x;
// }

// double f3b(double x){
//     return pow(2, -x);
// }

// double df3b(double x){
//     return -(log(2))/(pow(2, x));
// }



void help(void) {
    printf("Использование: ./program [ОПЦИИ]\n\n");
    printf("Основные опции:\n");
    printf("  -help               Показать это сообщение\n");
    printf("  -test -root         Запустить интерактивный тест нахождения корней\n");
    printf("  -test -integral     Запустить интерактивный тест интегрирования\n");
    printf("  -roots              Показать корни основных функций в основном задании\n");
    printf("  -iters              Показать количество итераций в вычислениях\n\n");
    printf("Комбинированные опции:\n");
    printf("  -test -root -iters  Тест корней с выводом итераций\n");
    printf("  -roots              Основное задание с корнями\n");
    printf("  -iters              Основное задание с итерациями\n");
    printf("  -roots -iters       Основное задание с корнями и итерациями\n\n");
    printf("Примеры использования:\n");
    printf("  ./program -help\n");
    printf("  ./program -test -root\n");
    printf("  ./program -roots -iters\n");
    printf("  ./program -iters\n");
    printf("  ./program            (запуск основного задания без доп. информации)\n\n");
    printf("Описание тестов:\n");
    printf("  Тест корней:        поиск точки пересечения двух выбранных функций\n");
    printf("  Тест интегралов:    вычисление интеграла выбранной функции\n");
    printf("  Основное задание:   вычисление специальной площади между кривыми\n");
}

// Основная вычислительная задача
void main_task(int show_roots, int show_iters){
    const double eps_root = 1e-5;
    const double eps_integral = 1e-4;

    double a1 = -2.0, b1 = -1.0;     // f1 и f3
    double a2 = 0.0, b2 = 1.5;     // f2 и f3
    double a3 = 1.0, b3 = 2.0;     // f1 и f2

    double x1 = root(f1, f3, df1, df3, a1, b1, eps_root);
    int iter1 = count;
    double x2 = root(f2, f3, df2, df3, a2, b2, eps_root);
    int iter2 = count;
    double x3 = root(f1, f2, df1, df2, a3, b3, eps_root);
    int iter3 = count;

    double s1 = integral(f1, x1, x3, eps_integral);
    double s2 = integral(f2, x2, x3, eps_integral);
    double s3 = integral(f3, x1, x2, eps_integral);
    // printf("%lf %lf %lf\n", s1, s2, s3);
    double ans = s1 - s2 - s3;

    if (show_roots){
        printf("Абсциссы пересечений слева-направо: %lf %lf %lf\n", x1, x2, x3);
    }
    if (show_iters){
        printf("Количество итераций: %d %d %d\n", iter1, iter2, iter3);
    }
    printf("Ответ: %lf\n", ans);
}

// Тест корней
void run_root_test(int show_iters) {
    // Массивы с именами функций для отображения
    const char* func_names[] = {
        "sin(3x) + 1",
        "cos(x) + x/2",
        "sqrt(x + 4)"
    };
    
    const char* deriv_names[] = {
        "3cos(3x)",
        "-sin(x) + 0.5",
        "1/(2*sqrt(x + 4))"
    };

    func funcs[] = {test_f1, test_f2, test_f3};
    func dfuncs[] = {test_f1_der, test_f2_der, test_f3_der};
    
    int i1, i2;
    double a, b, eps;
    
    printf("Тест нахождения корней:\n");
    printf("Выберите номера двух функций (1-3):\n");
    printf("1. %s (производная: %s)\n", func_names[0], deriv_names[0]);
    printf("2. %s (производная: %s)\n", func_names[1], deriv_names[1]);
    printf("3. %s (производная: %s)\n", func_names[2], deriv_names[2]);
    
    scanf("%d %d", &i1, &i2);
    i1--; i2--;
    
    printf("Выбраны функции:\n");
    printf("f%d: %s\n", i1+1, func_names[i1]);
    printf("f%d: %s\n", i2+1, func_names[i2]);
    
    printf("Введите интервал [a, b]: ");
    scanf("%lf %lf", &a, &b);
    
    printf("Введите эпсилон (точность): ");
    scanf("%lf", &eps);
    
    double ans = root(funcs[i1], funcs[i2], dfuncs[i1], dfuncs[i2], a, b, eps);
    
    printf("\nРезультат:\n");
    printf("Точка пересечения %s и %s: %lf\n", 
           func_names[i1], func_names[i2], ans);
    
    if (show_iters)
        printf("Количество итераций: %d\n", count);
}

// Тест интегралов
void run_integral_test() {
    const char* func_names[] = {
        "sin(3x) + 1",
        "cos(x) + x/2",
        "sqrt(x + 4)"
    };

    func funcs[] = {test_f1, test_f2, test_f3};
    
    int i;
    double a, b, eps;
    
    printf("Тест интегрирования:\n");
    printf("Выберите номер функции (1-3):\n");
    printf("1. %s\n", func_names[0]);
    printf("2. %s\n", func_names[1]);
    printf("3. %s\n", func_names[2]);
    
    scanf("%d", &i);
    i--;
    
    printf("Выбрана функция: %s\n", func_names[i]);
    
    printf("Введите интервал [a, b]: ");
    scanf("%lf %lf", &a, &b);
    
    printf("Введите точность (эпсилон): ");
    scanf("%lf", &eps);
    
    double ans = integral(funcs[i], a, b, eps);
    
    printf("\nРезультат:\n");
    printf("Интеграл от %s на [%.2f, %.2f]: %lf\n", 
           func_names[i], a, b, ans);
}

int main(int argc, char *argv[]){
    int show_roots = 0, show_iters = 0;
    if (argc > 1){
        if (!strcmp(argv[1], "-help")) {
            help();
            return 0;
        }
        else{
            if (!strcmp(argv[1], "-test")) {
                if (!strcmp(argv[2], "-root")){
                    if (argc > 3){
                        if (!strcmp(argv[3], "-iters")) show_iters = 1;

                    }
                    run_root_test(show_iters);
                }
                else if (!strcmp(argv[2], "-integral"))
                    run_integral_test();
                else
                    printf("Введите -root или -integral после -test\n");
                return 0;
            }
            else{ // main -root -integral
                for (int i = 1; i < argc; ++i) {
                    if (!strcmp(argv[i], "-roots"))
                        show_roots = 1;
                    if (!strcmp(argv[i], "-iters"))
                        show_iters = 1;
                }
                main_task(show_roots, show_iters);
                return 0;
            }
        }
    }
    else{
        main_task(0, 0);
        return 0;
    }
    return 0;
}
