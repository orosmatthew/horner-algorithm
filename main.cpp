#include <iostream>
#include <vector>

/**
 * Pretty prints a polynomial given coefficients
 * @param coefficients An array of coefficients of a polynomial from lowest to highest degrees
 */
void print_polynomial(const std::vector<float>& coefficients)
{
    for (int i = (int)coefficients.size() - 1; i > 0; i--) {
        std::cout << coefficients[i] << "x^" << i << " + ";
    }
    std::cout << coefficients[0] << std::endl;
}

/**
 * Evaluates a polynomial at a given point by Horner's rule
 * @param coefficients An array of coefficients of a polynomial from lowest to highest degrees
 * @param x Where the polynomial is evaluated at
 * @returns The value of the polynomial at x
 */
float horner(const std::vector<float>& coefficients, float x)
{
    float p = coefficients[coefficients.size() - 1];
    for (int i = (int)coefficients.size() - 2; i >= 0; i--) {
        std::cout << "\tp = " << x << " * " << p << " + " << coefficients[i];
        p = p * x + coefficients[i];
        std::cout << " = " << p << std::endl;
    }
    return p;
}

int main()
{
    // generic polynomial
    print_polynomial({ 5, 4, 3, 2 });
    std::cout << "At x = " << 1 << std::endl;
    std::cout << horner({ 5, 4, 3, 2 }, 1) << std::endl;
    std::cout << "==============================" << std::endl;

    // evaluates to 0
    print_polynomial({ 0, -6, 11, -6, 1 });
    std::cout << "At x = " << 3 << std::endl;
    std::cout << horner({ 0, -6, 11, -6, 1 }, 3) << std::endl;
    std::cout << "==============================" << std::endl;

    // a larger polynomial
    print_polynomial({ 10, -8, 1, -3, 0, 7 });
    std::cout << "At x = " << 2 << std::endl;
    std::cout << horner({ 10, -8, 1, -3, 0, 7 }, 2) << std::endl;
    std::cout << "==============================" << std::endl;

    // combinations of 1 and 0
    print_polynomial({ 1, 1, 1, 0, 1, 0, 1 });
    std::cout << "At x = " << -1 << std::endl;
    std::cout << horner({ 1, 1, 1, 0, 1, 0, 1 }, -1) << std::endl;
    std::cout << "==============================" << std::endl;

    // constant value
    print_polynomial({ 1 });
    std::cout << "At x = " << 30 << std::endl;
    std::cout << horner({ 1 }, 30) << std::endl;
    std::cout << "==============================" << std::endl;

    return 0;
}
