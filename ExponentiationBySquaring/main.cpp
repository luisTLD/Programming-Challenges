#include <iostream>
#include <chrono>

// Function declarations for exponentiation
unsigned long long exponentiationBySquaringRec(unsigned long long base, int exponent);
unsigned long long exponentiationBySquaring(unsigned long long base, int exponent);
unsigned long long normalExponentiation(unsigned long long base, int exponent);

int main()
{
    int base, exponent;
    std::cout << "Enter the base and exponent: " << std::endl;
    std::cin >> base >> exponent;

    const unsigned int numIterations = 1000000;

    auto startNormal = std::chrono::high_resolution_clock::now();
    unsigned long long resultNormal;
    for (int i = 0; i < numIterations; ++i)
    {
        resultNormal = normalExponentiation(base, exponent);
    }
    auto endNormal = std::chrono::high_resolution_clock::now();
    unsigned long long durationNormal = std::chrono::duration_cast<std::chrono::nanoseconds>(endNormal - startNormal).count();
    std::cout << "Normal Exponentiation result: " << resultNormal << std::endl;
    std::cout << "Normal Exponentiation time: " << durationNormal / numIterations << " nanoseconds." << std::endl;

    // Measuring the time for iterative exponentiation by squaring
    auto startIterative = std::chrono::high_resolution_clock::now();
    unsigned long long resultIterative;
    for (int i = 0; i < numIterations; ++i)
    {
        resultIterative = exponentiationBySquaring(base, exponent);
    }
    auto endIterative = std::chrono::high_resolution_clock::now();
    unsigned long long durationIterative = std::chrono::duration_cast<std::chrono::nanoseconds>(endIterative - startIterative).count();
    std::cout << "Iterative Exponentiation by Squaring result: " << resultIterative << std::endl;
    std::cout << "Iterative Exponentiation by Squaring time: " << durationIterative / numIterations << " nanoseconds." << std::endl;

    // Measuring the time for recursive exponentiation by squaring
    auto startRecursive = std::chrono::high_resolution_clock::now();
    unsigned long long resultRecursive;
    for (int i = 0; i < numIterations; ++i)
    {
        resultRecursive = exponentiationBySquaringRec(base, exponent);
    }
    auto endRecursive = std::chrono::high_resolution_clock::now();
    unsigned long long durationRecursive = std::chrono::duration_cast<std::chrono::nanoseconds>(endRecursive - startRecursive).count();
    std::cout << "Recursive Exponentiation by Squaring result: " << resultRecursive << std::endl;
    std::cout << "Recursive Exponentiation by Squaring time: " << durationRecursive / numIterations << " nanoseconds." << std::endl;

    return 0;
}

// Normal exponentiation using a for loop
unsigned long long normalExponentiation(unsigned long long base, int exponent)
{
    unsigned long long result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }
    return result;
}

// Iterative optimized exponentiation by squaring
unsigned long long exponentiationBySquaring(unsigned long long base, int exponent)
{
    unsigned long long result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result *= base;
            exponent -= 1;
        }

        base *= base;
        exponent /= 2;
    }

    return result;
}

// Recursive optimized exponentiation by squaring
unsigned long long exponentiationBySquaringRec(unsigned long long base, int exponent)
{
    if (exponent == 0) return 1;
    else if (exponent % 2 == 0) return exponentiationBySquaringRec(base * base, exponent / 2);
    else return base * exponentiationBySquaringRec(base, exponent - 1);
}
