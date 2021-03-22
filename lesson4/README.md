# Урок 3. Сложность алгоритма и простые алгоритмы
- 1.Реализовать функцию перевода чисел из десятичной системы в двоичную, используя рекурсию.
- 2.Реализовать функцию возведения числа [a] в степень [b]:
- a) Рекурсивно.
- b) Рекурсивно, используя свойство чётности степени (то есть, если степень, в которую нужно возвести число, чётная, основание возводится в квадрат, а показатель делится на два, а если степень нечётная - результат умножается на основание, а показатель уменьшается на единицу)
- 3.Реализовать нахождение количества маршрутов шахматного короля с препятствиями (где единица - это наличие препятствия, а ноль - свободная для хода клетка)

Результатом работы должен стать один файл с кодом на языке С, содержащий функцию main и четыре функции, соответствующие каждому из заданий.



## 1. Реализовать функцию перевода чисел из десятичной системы в двоичную, используя рекурсию
```sh
void recDectoBin(int n)
{
    if (n < 0)
    {
        std::cout << "-";
        recDectoBin(-n);
    }
    else if (n < 2)
    {
        std::cout << n;
        return;
    }
    else
    {
        recDectoBin(n / 2);
        int res = n % 2;
        std::cout << res;
    }
}

void ConvertDecToBin()
{
    int n = 0;
    std::cout << "Convert nuber" << std::endl;
    std::cin >> n;
    std::cout << "Convert to bin = ";
    recDectoBin(n);
    std::cout << std::endl;
}

```

## 2. Реализовать функцию возведения числа [a] в степень [b]:

```sh
void exponentiation()
{
    int a = 0, b = 0;
    std::cout << "Enter nuber Exponentiation" << std::endl;
    std::cin >> a;
    std::cout << "to the level" << std::endl;
    std::cin >> b;
    std::cout << "Bin Exponentiation = " << binExponentiation(a, b)
              << std::endl;
    std::cout << "Rec Exponentiation = " << recExponentiation(a, b)
              << std::endl;
}

```

## a) Рекурсивно.

```sh
int recExponentiation(int a, int b)
{
    if (b == 0)
        return 1;
    else
        return a * recExponentiation(a, b - 1);
}
```

## b) Рекурсивно, используя свойство чётности степени

```sh
int binExponentiation(int a, int b)
{
    if (b == 0)
        return 1;
    int x = (b % 2) ? a : 1;
    int c = binExponentiation(a, b / 2);
    return x * c * c;
}
```

## 3.Реализовать нахождение количества маршрутов шахматного короля с препятствиями (где единица - это наличие препятствия, а ноль - свободная для хода клетка)

в процессе 


