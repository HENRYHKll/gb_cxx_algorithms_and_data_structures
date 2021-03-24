# Урок 3. Сложность алгоритма и простые алгоритмы
- 1.Написать функцию проверки, является ли число простым
- 1.1.Блок-схему
- 1.2.В коде на языке С/C++
- 2.При помощи инструментов визуализации алгоритмов создать простую блок-схему, описывающую алгоритм сложения чисел от [1] до [10]

Результатом домашней работы должны стать три файла - две картинки с блок-схемами и одна программа на языке С/C++.

## 1. Code является ли число простым
# 1.1.Блок-схему

![Иллюстрация к проекту](https://github.com/HENRYHKll/gb_cxx_algorithms_and_data_structures/blob/lesson3/lesson3/aads3-1.png)


# 1.2.В коде на языке С/C++

```sh
#include <iostream>

int main(int argc, char** args)
{
    int n = 0;
    std::cout << "enter number" << std::endl;
    std::cin >> n;

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            std::cout << n << " number is not prime, because to divide by " << i
                      << std::endl;
            return 0;
        }
    }
    std::cout << n << " number is prime" << std::endl;
    return 0;
}

```
## 2. Блок-схема, описывающая алгоритм сложения чисел от [1] до [10]

![Иллюстрация к проекту](https://github.com/HENRYHKll/gb_cxx_algorithms_and_data_structures/blob/lesson3/lesson3/aads3-2.png)
