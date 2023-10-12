#include <iostream>
#include <vector>

float horner(const std::vector<float>& coefficients, float x)
{
    float p = coefficients[coefficients.size() - 1];
    for (int i = (int) coefficients.size() - 2; i >= 0; i--)
    {
        p = x * p + coefficients[i];
    }
    return p;
}


int main()
{
    std::cout << horner({1, 2, 3}, 4) << std::endl;
    return 0;
}
