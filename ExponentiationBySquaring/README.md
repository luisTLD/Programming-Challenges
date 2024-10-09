# Exponentiation Benchmarking

This project demonstrates three different approaches for calculating exponentiation and measures the time taken for each method over **1,000,000 iterations**. The execution time is measured in **nanoseconds** for each method.

## Features

- **Normal Exponentiation**: Calculates exponentiation using a simple `for` loop.
- **Iterative Exponentiation by Squaring**: An optimized iterative method to calculate exponentiation.
- **Recursive Exponentiation by Squaring**: An optimized recursive method for exponentiation.

Each method is benchmarked and the average time taken per iteration (in nanoseconds) is printed to the console.

## Exponentiation by Squaring

Exponentiation by squaring is an optimization technique that reduces the number of multiplications required to calculate the power of a number. Instead of multiplying the base by itself repeatedly, the algorithm squares the base and divides the exponent, exploiting the properties of exponents:

- If the exponent is **even**, we can reduce the problem to calculating the power of the base squared with half the exponent.
- If the exponent is **odd**, we multiply the base by the result of the power with one less exponent (making it even).

### Key Idea

- **Even Exponent**: \( b^e = (b^2)^{e/2} \)
- **Odd Exponent**: \( b^e = b \times (b^2)^{(e-1)/2} \)

This reduces the number of multiplications, making the algorithm more efficient compared to a simple loop.

## Maximum Representable Number

In this implementation, the largest number that can be represented is \( 2^{63} \), which is the maximum value of a 64-bit signed integer. The `unsigned long long` type in C++ is used to store the results of the exponentiation, and it can hold values up to \( 2^{64} - 1 \), but the practical limit for exponentiation would be \( 2^{63} \) due to the nature of exponentiation by squaring.

