# 📊 Проект по численным методам

**Коллекция вычислительных алгоритмов на C и ассемблере**  
*Эффективные численные решения математических задач*

[![GitHub](https://img.shields.io/badge/GitHub-Репозиторий-blue)](https://github.com/kin0man/project)
![Языки](https://img.shields.io/badge/C-99%25-yellowgreen)
![Языки](https://img.shields.io/badge/ASM-1%25-ff69b4)

## 🌟 Возможности проекта

- **Численное интегрирование**  
  Реализации популярных методов: трапеций, Симпсона и других
- **Поиск корней**  
  Алгоритмы решения нелинейных уравнений
- **Оптимизация производительности**  
  Критические участки кода оптимизированы на ассемблере
- **Модульная структура**  
  Четкое разделение математических операций и логики программы

## 📂 Структура проекта
  ```bash
  project/
  ├── ASM
  │ └── funcs.asm # Высокопроизводительные ассемблерные функции
  ├── C/
  │ ├── integral.c # Решатели ∫ f(x)dx (методы трапеций, Симпсона)
  │ ├── root.c # Алгоритмы поиска корней (бисекция, Ньютон)
  │ ├── funcs.h # Объявления математических функций
  │ ├── main.h # Константы и конфигурация программы
  │ ├── main.c # Интерфейс командной строки
  │ └── test.c # Тесты верификации
  └── Makefile # Автоматизация сборки
  ```


## 📈 Результаты вычислений

### Таблица площадей под кривыми

| Кривая | Начало отрезка | Конец отрезка | Площадь  |
|--------|----------------|---------------|----------|
| 1      | -1.3078        | 1.3437        | 10.0477  |
| 2      | 0.8262         | 1.3437        | 0.6985   |
| 3      | -1.3078        | 0.8262        | 2.7580   |

**Исследуемые функции:**
1. \( y = 1 + \frac{4}{x^4+1} \)
2. \( y = x^3 \)
3. \( y = 2^{-x} \)

**Общая площадь:** \( S = 6.591 \)

### График функций
![image](https://github.com/user-attachments/assets/555f7a54-077c-49a8-b339-439c66837541)


## 🚀 Быстрый старт

1. Клонируйте репозиторий:
   ```bash
   git clone https://github.com/kin0man/project.git
   cd project
2. Соберите и запустите:
    ```bash
    make
    ./program
