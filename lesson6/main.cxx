#include <cmath>
#include <iostream>

void bubbles()
{
    const int row           = 3;
    const int col           = 3;
    int       arr[row][col] = { { 1, 9, 2 }, { 5, 7, 6 }, { 4, 3, 8 } };
    std::cout << "sorce arr" << std::endl;

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            std::cout << (arr[i][j]);
        }
        std::cout << std::endl;
    }

    std::cout << "sort arr" << std::endl;

    for (int k = 0; k < row; ++k)
    {
        for (int l = 0; l < col; ++l)
        {
            for (int i = 0; i < row; ++i)
            {
                for (int j = 0; j < col; ++j)
                {
                    if (i + 1 == row & j + 1 == col)
                    {
                        continue;
                    }
                    else
                    {
                        if (j + 1 == row & arr[i][j] > arr[i + 1][0])
                        {
                            int temp      = arr[i][j];
                            arr[i][j]     = arr[i + 1][0];
                            arr[i + 1][0] = temp;
                        }
                        else
                        {
                            if (arr[i][j] > arr[i][j + 1])
                            {

                                int temp      = arr[i][j];
                                arr[i][j]     = arr[i][j + 1];
                                arr[i][j + 1] = temp;
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            std::cout << (arr[i][j]);
        }
        std::cout << std::endl;
    }
}

void algorithmTPK()
{
    const int SIZE = 11;
    float     arr[SIZE], calculation;

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << "Enter nuber - " << i << std::endl;
        std::cin >> (arr[i]);
    }

    for (int i = 0; i < SIZE / 2; i++)
    {
        float temp        = arr[i];
        arr[i]            = arr[SIZE - i - 1];
        arr[SIZE - i - 1] = temp;
    }

    for (int i = 0; i < SIZE; i++)
    {
        calculation = sqrt(fabs(arr[i])) + 5 * pow(arr[i], 3);

        if (calculation > 400)
            std::cout << "Calc" << i + 1 << " > 400" << std::endl;
    }
}

int main(int argc, char** args)
{
    bubbles();
    algorithmTPK();
    return 0;
}
