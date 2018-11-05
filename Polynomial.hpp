#ifndef POLYNOMIAL_HPP_INCLUDED
#define POLYNOMIAL_HPP_INCLUDED
#include <vector>
#include <string.h>
#include <iostream>
#include <math.h>
using namespace std;

class Polynomial
{
public:
    Polynomial(int degree = 0, vector<double> coef = vector<double>(1, 0));

    Polynomial(const Polynomial &polynom);

    void setDegree(int degree);
    int getDegree();

    void setCoef(vector <double> coef);
    vector<double> getCoef();

    Polynomial operator+=(Polynomial &secondTerm);
    Polynomial operator+=(double freeTerm);
    Polynomial operator-=(Polynomial &secondTerm);
    Polynomial operator-=(double freeTerm);
    Polynomial operator*=(Polynomial &secondTerm);
    Polynomial operator*=(double freeTerm);
    Polynomial operator/=(Polynomial &secondTerm);
    Polynomial operator/=(double freeTerm);
    Polynomial operator%=(Polynomial &secondTerm);
    Polynomial operator%=(double freeTerm);


    friend Polynomial operator+(const Polynomial &firstTerm);
    friend Polynomial operator-(const Polynomial &firstTerm);

    friend Polynomial operator+(const Polynomial &firstTerm, const Polynomial &secondTerm);
    friend Polynomial operator+(const Polynomial &firstTerm, double freeTerm);
    friend Polynomial operator+(double freeTerm, const Polynomial &secondTerm);

    friend Polynomial operator-(const Polynomial &firstTerm, const Polynomial &secondTerm);
    friend Polynomial operator-(const Polynomial &firstTerm, double freeTerm);
    friend Polynomial operator-(double freeTerm, const Polynomial &secondTerm);

    friend Polynomial operator*(const Polynomial &firstTerm, const Polynomial &secondTerm);
    friend Polynomial operator*(const Polynomial &firstTerm, double freeTerm);
    friend Polynomial operator*(double freeTerm, const Polynomial &secondTerm);

    friend Polynomial operator/(const Polynomial &firstTerm, const Polynomial &secondTerm);
    friend Polynomial operator/(const Polynomial &firstTerm, double freeTerm);
    friend Polynomial operator/(double freeTerm, const Polynomial &secondTerm);

    friend Polynomial operator%(const Polynomial &firstTerm, const Polynomial &secondTerm);
    friend Polynomial operator%(const Polynomial &firstTerm, double freeTerm);
    friend Polynomial operator%(double freeTerm, const Polynomial &secondTerm);

    friend Polynomial operator^(Polynomial &firstTerm, int x);

    friend bool operator==(const Polynomial &firstTerm, const Polynomial &secondTerm);
    friend bool operator==(const Polynomial &firstTerm, double freeTerm);
    friend bool operator==(double freeTerm, const Polynomial &secondTerm);

    friend bool operator!=(const Polynomial &firstTerm, const Polynomial &secondTerm);
    friend bool operator!=(const Polynomial &firstTerm, double freeTerm);
    friend bool operator!=(double freeTerm, const Polynomial &secondTerm);

    double operator()(int val);
    double& operator[](int val);

    string toString();

    operator string();

    friend istream& operator>>(istream &is, Polynomial &term);
    friend ostream& operator<<(ostream &os, Polynomial &term);

private:
    int degree;
    vector<double> coef;
};

#endif // POLYNOMIAL_HPP_INCLUDED
