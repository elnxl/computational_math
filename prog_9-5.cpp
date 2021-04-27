#include <functional>
#include <iostream>
#include <cmath>

class NewtonCortes
{
public:
    using Function = std::function<double(double)>;

private:
    Function m_function;

public:
    NewtonCortes(Function func = Function{})
        : m_function{func}
    {
    }

    double solve(double a, double b, int degree, int divisions)
    {
        static int const koef[10][10] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                         1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
                                         1, 4, 1, 0, 0, 0, 0, 0, 0, 0,
                                         1, 3, 3, 1, 0, 0, 0, 0, 0, 0,
                                         7, 32, 12, 32, 7, 0, 0, 0, 0, 0,
                                         19, 75, 50, 50, 75, 19, 0, 0, 0, 0,
                                         41, 216, 27, 272, 27, 216, 41, 0, 0, 0,
                                         751, 3577, 1323, 2989, 2989, 1323, 3577, 751, 0, 0,
                                         989, 5888, -928, 10496, -4540, 10496, -928, 5888, 989, 0,
                                         2857, 15741, 1080, 19344, 5778, 5778, 19344, 1080, 15741, 2857};
        static double const mltp[10] = {1, 1.0 / 2, 1.0 / 3, 3.0 / 8, 2.0 / 45, 5.0 / 288, 1.0 / 140, 7.0 / 17280, 4.0 / 14175, 9.0 / 89600};

        if (!m_function)
            throw std::exception{"Function is not empty"};

        if (degree < 0 || degree > 9)
            throw std::exception{"Wrong degree"};
        if (a >= b)
            throw std::exception{"Wrong segment"};
        if (divisions < 1)
            throw std::exception{"Wrong number of divisions"};

        double sum = 0;
        double const h = (b - a) / (double)((int64_t)degree * divisions);

        for (int j = 0; j < divisions; j++)
        {
            double part_sum = 0;
            for (int i = 0; i <= degree; i++)
                part_sum += koef[degree][i] * m_function(a + (i + j * (int64_t)degree) * h);
            sum += mltp[degree] * part_sum * h;
        }

        return sum;
    }
};

int main()
{
    try
    {
        auto function = [](double d) { return std::pow(d, 5) + 2 * std::pow(d, 4) + 3 * std::pow(d, 3) + 4 * std::pow(d, 2) + 5 * d + 6.; };
        const char *const function_str = "x^5 + 2*x^4 + 3*x^3 + 4*x^2 + 5*x + 6";
        double const start = -7., finish = 7.;
        double result = NewtonCortes{function}.solve(start, finish, 9, 10);

        std::cout << "Function: " << function_str << " "
                  << "[" << start << ", " << finish << "]\n";
        std::cout << "Result: " << result << std::endl;
        return 0;
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }

    return 1;
}
