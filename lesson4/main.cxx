#include <iostream>

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
int recExponentiation(int a, int b)
{
    if (b == 0)
        return 1;
    else
        return a * recExponentiation(a, b - 1);
}

int binExponentiation(int a, int b)
{
    if (b == 0)
        return 1;
    int x = (b % 2) ? a : 1;
    int c = binExponentiation(a, b / 2);
    return x * c * c;
}

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

int main(int argc, char** args)
{
    ConvertDecToBin();
    exponentiation();

    return 0;
}
