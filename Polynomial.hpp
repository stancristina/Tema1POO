#ifndef POLYNOMIAL_HPP_INCLUDED
#define POLYNOMIAL_HPP_INCLUDED
#include <vector>
#include <string.h>
#include <iostream>
#include <math.h>
using namespace std;

class Polinom
{
public:
    Polinom(int grad = 0, vector<double> coef = vector<double>(1, 0));

    Polinom(const Polinom &p);

    void setGrad(int grad);
    int getGrad();

    void setCoef(vector <double> coef);
    vector<double> getCoef();

    void afisare();

    Polinom operator+=(Polinom &p);
    Polinom operator+=(double x);
    Polinom operator-=(Polinom &p);
    Polinom operator-=(double x);
    Polinom operator*=(Polinom &p);
    Polinom operator*=(double x);
    Polinom operator/=(Polinom &p);
    Polinom operator/=(double x);
    Polinom operator%=(Polinom &p);
    Polinom operator%=(double x);


    friend Polinom operator+(const Polinom &p);
    friend Polinom operator-(const Polinom &p);

    friend Polinom operator+(const Polinom &p, const Polinom &q);
    friend Polinom operator+(const Polinom &p, double x);
    friend Polinom operator+(double x, const Polinom &p);

    friend Polinom operator-(const Polinom &p, const Polinom &q);
    friend Polinom operator-(const Polinom &p, double x);
    friend Polinom operator-(double x, const Polinom &p);

    friend Polinom operator*(const Polinom &p, const Polinom &q);
    friend Polinom operator*(const Polinom &p, double x);
    friend Polinom operator*(double x, const Polinom &p);

    friend Polinom operator/(const Polinom &p, const Polinom &q);
    friend Polinom operator/(const Polinom &p, double x);
    friend Polinom operator/(double x, const Polinom &p);

    friend Polinom operator%(const Polinom &p, const Polinom &q);
    friend Polinom operator%(const Polinom &p, double x);
    friend Polinom operator%(double x, const Polinom &p);

    friend Polinom operator^(Polinom &p, int x);

    friend bool operator==(const Polinom &p, const Polinom &q);
    friend bool operator==(const Polinom &p, double x);
    friend bool operator==(double x, const Polinom &q);

    friend bool operator!=(const Polinom &p, const Polinom &q);
    friend bool operator!=(const Polinom &p, double x);
    friend bool operator!=(double x, const Polinom &q);

    double operator()(int val);
    double& operator[](int val);

    string toString();

    operator string();

    friend istream& operator>>(istream &is, Polinom &p);
    friend ostream& operator<<(ostream &os, Polinom &p);

private:
    int grad;
    vector<double> coef;
};

#endif // POLYNOMIAL_HPP_INCLUDED
