// Lab_6_2.cpp
// Боднар Роман
// Лабораторна робота № 6.2
// Варіант 2
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Прототипи функцій
void Create(int* a, const int size, const int Low, const int High);
void Print(int* a, const int size);
int FindMinOddIndex(int* a, const int size);

int main()
{
    // Ініціалізація генератора випадкових чисел
    srand((unsigned)time(NULL));

    const int n = 12;
    int a[n];
    int Low = -10;
    int High = 35;
    int minOddIndex;

    // Формування масиву за допомогою генератора випадкових чисел
    Create(a, n, Low, High);

    // Виведення створеного масиву у вигляді рядка
    cout << "Initial array:" << endl;
    Print(a, n);

    // Пошук індексу найменшого непарного елемента
    minOddIndex = FindMinOddIndex(a, n);

    // Виведення результату виконання завдання
    if (minOddIndex != -1) {
        cout << "Index of the smallest odd element: " << minOddIndex << endl;
        cout << "Value of this element: " << a[minOddIndex] << endl;
    }
    else {
        cout << "No odd elements found in the array." << endl;
    }

    return 0;
}

// Функція формування масиву випадковими числами
void Create(int* a, const int size, const int Low, const int High)
{
    int i;

    for (i = 0; i < size; i++) {
        a[i] = Low + rand() % (High - Low + 1);
    }
}

// Функція виведення масиву у рядок
void Print(int* a, const int size)
{
    int i;

    for (i = 0; i < size; i++) {
        cout << setw(4) << a[i];
    }
    cout << endl;
}

// Функція пошуку індексу найменшого непарного елемента масиву
int FindMinOddIndex(int* a, const int size)
{
    int minVal;
    int minIndex;
    int i;

    minIndex = -1;

    // Пошук першого непарного елемента для ініціалізації
    for (i = 0; i < size; i++) {
        if (a[i] % 2 != 0) {
            minVal = a[i];
            minIndex = i;
            break;
        }
    }

    // Якщо непарних елементів немає, повертаємо -1
    if (minIndex == -1) {
        return -1;
    }

    // Пошук меншого непарного елемента серед решти
    for (i = minIndex + 1; i < size; i++) {
        if (a[i] % 2 != 0 && a[i] < minVal) {
            minVal = a[i];
            minIndex = i;
        }
    }

    return minIndex;
}