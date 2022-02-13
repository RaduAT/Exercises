#include <iostream>
#include <string>
#include <limits>
#include <math.h>
#include <iomanip>
class MathFunction
{
protected:
    std::string function_name;

public:
    MathFunction() {}
    virtual float get_value(int x)
    {
        return x;
    }
    virtual float get_max_value(int x, int y)
    {
        return x;
    }
    virtual void afisare() {}
    virtual void print_roots() {}
    void set_func(std::string name)
    {
        this->function_name = name;
    }
    std::string get_func()
    {
        return this->function_name;
    }
};
class Polynomial : public MathFunction
{
protected:
    float *coefficients;

public:
    Polynomial() {}
    Polynomial(float *coeff, int n)
    {
        MathFunction::set_func("Polynomial");
        this->coefficients = new float[n + 1];
        for (int i = 0; i < n; i++)
        {
            this->coefficients[i] = coeff[i];
        }
    }
    void afisare()
    {
        int p;
        std::cout << MathFunction::get_func()
                  << "\n";
        std::cout << "f(x) = ";
        std::cout << this->coefficients[0];
        int i = 1;
        while (*&(this->coefficients[i]) || (*&(this->coefficients[i + 1])))
        {
            p = this->coefficients[i];
            if (p == 0)
            {
            }
            else
            {
                if (p > 0)
                {

                    std::cout << " + ";
                    if (p > 1)
                        std::cout << p;
                }
                else
                {
                    std::cout << " - ";
                    if (p < -1)
                        std::cout << -p;
                }
                if (i == 1)
                    std::cout << "x";
                else
                    std::cout << "x^" << i;
            }
            i++;
        }
        std::cout << "\n";
    }
    float *get_coeff()
    {
        return this->coefficients;
    }
    float get_value(int x)
    {
        float val = 0;
        val = val + this->coefficients[0];
        int i = 1;
        int p;
        while (*&(this->coefficients[i]))
        {
            p = this->coefficients[i];
            val = val + p * pow(x, i);
            i++;
        }
        return val;
    }
    float get_max_value(int x, int y)
    {
        float max = std::numeric_limits<float>::min();
        for (int i = x; i <= y; i++)
        {
            if (this->get_value(i) > max)
                max = this->get_value(i);
        }
        return max;
    }
};
class Quadratic : public Polynomial
{

public:
    Quadratic() {}
    Quadratic(float *coeff) : Polynomial(coeff, 3)
    {
        MathFunction::set_func("Quadratic");
    }
    void afisare()
    {
        int p;
        std::cout << MathFunction::get_func()
                  << "\n";
        std::cout << "f(x) = ";
        std::cout << (Polynomial::get_coeff())[0];
        int i = 1;
        while (*&((Polynomial::get_coeff())[i]))
        {
            p = (Polynomial::get_coeff())[i];
            if (p > 0)
            {

                std::cout << " + ";
                if (p > 1)
                    std::cout << p;
            }
            else
            {
                std::cout << " - ";
                if (p < -1)
                    std::cout << -p;
            }
            if (i != 1)
                std::cout << "x^" << i;
            else
                std::cout << "x";
            i++;
        }
        std::cout << "\n";
    }
    void print_roots()
    {
        float x1, x2, d;
        d = (Polynomial::get_coeff())[1] * (Polynomial::get_coeff())[1] - 4 * (Polynomial::get_coeff())[2] * (Polynomial::get_coeff())[0];
        d = sqrt(d);
        x1 = (-(Polynomial::get_coeff())[1] + d) / 2 * (Polynomial::get_coeff())[2];
        x2 = (-(Polynomial::get_coeff())[1] - d) / 2 * (Polynomial::get_coeff())[2];
        std::cout << std::fixed;
        std::cout << std::setprecision(2);
        if (x1 == x2)
            std::cout << "X1 = X2 = " << x1 << "\n";
        else
        {
            std::cout << "X1 = " << x1 << "\n";
            std::cout << "X2 = " << x2 << "\n";
        }
    }
    float get_value(int x)
    {
        float val = 0;
        val = val + this->coefficients[0];
        int i = 1;
        int p;
        while (*&(this->coefficients[i]))
        {
            p = this->coefficients[i];
            val = val + p * pow(x, i);
            i++;
        }
        return val;
    }
    float get_max_value(int x, int y)
    {
        float max = std::numeric_limits<float>::min();
        for (int i = x; i <= y; i++)
        {
            if (this->get_value(i) > max)
                max = this->get_value(i);
        }
        return max;
    }
};
class Exponential : public MathFunction
{
private:
    const float e = 2.71;
    float constant, exp_coeff;

public:
    Exponential() {}
    Exponential(float constant, float exp_coeff) : constant(constant), exp_coeff(exp_coeff)
    {
        MathFunction::set_func("Exponential");
    }
    void afisare()
    {
        int p;
        std::cout << MathFunction::get_func()
                  << "\n";
        std::cout << "f(x) = " << this->constant << " + " << this->exp_coeff << "e^x";
        std::cout << "\n";
    }
    float get_value(int x)
    {
        float val = 0;
        val = this->constant + exp_coeff * pow(this->e, x);

        return val;
    }
    float get_max_value(int x, int y)
    {
        float max = std::numeric_limits<float>::min();
        for (int i = x; i <= y; i++)
        {
            if (this->get_value(i) > max)
                max = this->get_value(i);
        }
        return max;
    }
};

class DiscreteFunction : public MathFunction
{

    float x_values[1000];
    float y_values[1000];

public:
    DiscreteFunction() {}
    std::string find_best_aproximation()
    {
        return NULL;
    }
};
int main()
{
    int n, termeni, c;
    float coef[10];
    float exp_coeff, consta;
    std::string nume;
    std::cin >> n;
    MathFunction *functii[100];
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> nume;
        if (nume == "Polynomial")
        {
            std::cin >> termeni;
            for (int j = 0; j < termeni; j++)
            {
                std::cin >> coef[j];
            }
            functii[k++] = new Polynomial(coef, termeni);
        }
        if (nume == "Quadratic")
        {
            for (int j = 0; j < 3; j++)
            {
                std::cin >> coef[j];
            }
            functii[k++] = new Quadratic(coef);
        }
        if (nume == "Exponential")
        {
            std::cin >> consta;
            std::cin >> exp_coeff;
            functii[k++] = new Exponential(consta, exp_coeff);
        }
    }
    std::cin >> c;
    if (c == 1)
    {
        for (int i = 0; i < n; i++)
        {
            functii[i]->afisare();
        }
    }
    if (c == 2)
    {

        for (int i = 0; i < n; i++)
        {
            if (functii[i]->get_func() == "Quadratic")
                functii[i]->print_roots();
        }
    }
    if (c == 3)
    {
        int min, max;
        std::cin >> min >> max;
        for (int i = 0; i < n; i++)
        {
            std::cout << std::fixed;
            std::cout << std::setprecision(2);
            std::cout << functii[i]->get_max_value(min, max) << "\n";
        }
    }
    if (c == 4)
    {
        float best = std::numeric_limits<float>::max();
        float current;
        int ibest;
        int xunu, xdoi, xtrei;
        int yunu, ydoi, ytrei;
        std::cin >> xunu >> xdoi >> xtrei;
        std::cin >> yunu >> ydoi >> ytrei;
        for (int i = 0; i < n; i++)
        {
            current = 0;
            current = abs(yunu - functii[i]->get_value(xunu)) + abs(ydoi - functii[i]->get_value(xdoi)) + abs(ytrei - functii[i]->get_value(xtrei));
            if (current < best)
            {
                best = current;
                ibest = i;
            }
        }
        functii[ibest]->afisare();
        std::cout << best;
    }
    return 0;
}