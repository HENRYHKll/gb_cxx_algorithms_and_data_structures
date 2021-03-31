#include <iostream>

int main(int argc, char** args)
{
    int n = 0;
    std::cout << "enter number" << std::endl;
    std::cin >> n;

    for (int i = 2; i < n / 2; i++)
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
