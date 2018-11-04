#include <iostream>
#include <sstream>
#include "Polynomial.hpp"
#include <string.h>
#include <cstdlib>
#include <vector>
#include <math.h>
using namespace std;

void Polinom :: setGrad(int grad)
{
    this->grad = grad;
}

int Polinom :: getGrad()
{
    return this->grad;
}

void Polinom :: setCoef(vector<double> coef)
{
    this->coef = coef;
}

vector<double> Polinom :: getCoef()
{
    return this->coef;
}

Polinom :: Polinom(int grad, vector<double> coef)
{
    this->grad = grad;
    this->coef = coef;
}

Polinom :: Polinom(const Polinom &p)
{
    this->grad = p.grad;
    this->coef = p.coef;
}
void Polinom :: afisare()
{
    int i;
    for(i = 0; i < coef.size(); i++)
    {
        cout << coef[i] << " ";

    }
    cout<<'\n';
}

///Composed overloaded operators

Polinom Polinom :: operator+=(Polinom &p)
{
    vector<double> newCoef;
    int i;
    for(i = 0; i <= max(this->grad, p.getGrad()); i++ )
    {
        newCoef.push_back(0);
        if(i <= this->grad)
            newCoef[i] += (this->coef)[i];
        if(i <= p.getGrad())
            newCoef[i] += (p.getCoef())[i];

    }
    while(newCoef.size() > 1 && newCoef[newCoef.size()-1] == 0)
    {
        newCoef.pop_back();
    }
    int newGrad = newCoef.size() - 1;
    this->coef = newCoef;
    this->grad = newGrad;
    return *this;
}

Polinom Polinom :: operator+=(double x)
{
    (this->coef)[0]+=x;
    return *this;
}

Polinom Polinom :: operator-=(Polinom &p)
{
    vector<double> newCoef;
    int i;
    for(i = 0; i <= max(this->grad, p.getGrad()); i++)
    {
        newCoef.push_back(0);
        if(i <= this-> grad)
            newCoef[i] = (this->coef)[i];
        if( i <= p.getGrad())
            newCoef[i] -= (p.getCoef())[i];
    }
    while(newCoef.size() > 1 && newCoef[newCoef.size() - 1]== 0)
    {
        newCoef.pop_back();
    }
    int newGrad = newCoef.size() - 1;
    this->coef = newCoef;
    this->grad = newGrad;
    return *this;
}

Polinom Polinom :: operator-=(double x)
{
    (this->coef)[0]-=x;
    return *this;
}

Polinom Polinom :: operator*=(Polinom &p)
{
    int newGrad = this->grad + p.getGrad();
    vector<double> newCoef(newGrad + 1, 0);
    int i,j;
    for(i = 0; i <= this->grad; i++)
    {
        for(j = 0; j <= p.getGrad(); j++)
        {
            newCoef[i+j] += (this->coef)[i] * (p.getCoef())[j];
        }
    }
    this->grad = newGrad;
    this->coef = newCoef;
    return *this;
}

Polinom Polinom :: operator *=(double x)
{
    int i;
    for(i = 0; i< coef.size(); i++)
    {
        coef[i] *= x;
    }
    return *this;
}

///Unary overloaded operators

Polinom operator+(const Polinom &p)
{
    Polinom *ob = new Polinom(p.grad, p.coef);
    return *ob;
}

Polinom operator-(const Polinom &p)
{
    vector<double> newCoef = p.coef;
    int i;
    for(i=0; i< newCoef.size(); i++)
    {
        newCoef[i] = -newCoef[i];
    }
    Polinom *ob = new Polinom(p.grad, newCoef);
    return *ob;
}

///Binary overloaded operators

Polinom operator+(const Polinom &p, const Polinom &q)
{
    vector<double> newCoef;
    int i;
    for(i = 0; i <= max(p.grad, q.grad); i++ )
    {
        newCoef.push_back(0);
        if(i <= p.grad)
            newCoef[i] += (p.coef)[i];
        if(i <= q.grad)
            newCoef[i] += (q.coef)[i];

    }
    while(newCoef.size() > 1 && newCoef[newCoef.size()-1] == 0)
    {
        newCoef.pop_back();
    }
    int newGrad = newCoef.size() - 1;
    Polinom *ob = new Polinom (newGrad, newCoef);
    return *ob;
}

Polinom operator+(const Polinom &p, double x)
{
    vector<double> newCoef;
    newCoef.push_back(x);
    Polinom q(0, newCoef);
    Polinom *ob = new Polinom(p + q);
    return *ob;
}

Polinom operator+(double x, const Polinom &p)
{
    vector<double> newCoef;
    newCoef.push_back(x);
    Polinom q(0, newCoef);
    Polinom *ob = new Polinom(q + p);
    return *ob;
}

Polinom operator-(const Polinom &p, const Polinom &q)
{
    vector<double> newCoef;
    int i;
    for(i = 0; i <= max(p.grad, q.grad); i++)
    {
        newCoef.push_back(0);
        if(i <= p.grad)
            newCoef[i] = (p.coef[i]);
        if( i <= q.grad)
            newCoef[i] -= (q.coef)[i];
    }
    while(newCoef.size() > 1 && newCoef[newCoef.size() - 1]== 0)
    {
        newCoef.pop_back();
    }
    int newGrad = newCoef.size() - 1;
    Polinom *ob = new Polinom (newGrad, newCoef);
    return *ob;
}

Polinom operator-(const Polinom &p, double x)
{
    vector<double> newCoef;
    newCoef.push_back(x);
    Polinom q(0, newCoef);
    Polinom *ob = new Polinom (p - q);
    return *ob;
}

Polinom operator-(double x, const Polinom &p)
{
    vector<double> newCoef;
    newCoef.push_back(x);
    Polinom q(0, newCoef);
    Polinom *ob = new Polinom (q - p);
    return *ob;
}

Polinom operator*(const Polinom &p, const Polinom &q)
{
    int newGrad = p.grad + q.grad;
    vector<double> newCoef(newGrad + 1, 0);
    int i,j;
    for(i = 0; i <= p.grad; i++)
    {
        for(j = 0; j <= q.grad; j++)
        {
            newCoef[i+j] += (p.coef)[i] * (q.coef)[j];
        }
    }
    Polinom *ob = new Polinom(newGrad, newCoef);
    return *ob;

}

Polinom operator*(const Polinom &p, double x)
{
    vector<double> newCoef;
    newCoef.push_back(x);
    Polinom q(0, newCoef);
    Polinom *ob = new Polinom (p * q);
    return *ob;
}

Polinom operator*(double x, const Polinom &p)
{
    vector<double> newCoef;
    newCoef.push_back(x);
    Polinom q(0, newCoef);
    Polinom *ob = new Polinom (q * p);
    return *ob;
}

Polinom operator^(Polinom &p, int x)
{
    Polinom aux;
    aux=aux+1;
    int i;
    for(i=1; i <= x; i++)
    {
        aux *= p;
        aux.afisare();
    }
    Polinom *ob =  new Polinom(aux);
    return *ob;
}

///Relational overloaded operators

bool operator==(const Polinom &p, const Polinom &q)
{
    if(p.grad != q.grad)
        return false;
    int i;
    for(i=0; i <= p.coef.size(); i++)
    {
        if(p.coef[i] != q.coef[i])
            return false;
    }

    return true;
}

bool operator==(const Polinom &p, double x)
{
    if(p.grad != 0)
        return false;
    if(p.coef[0] != x)
        return false;
    return true;
}

bool operator==(double x, const Polinom &p)
{
    if(p.grad != 0)
        return false;
    if(p.coef[0] != x)
        return false;
    return true;
}

bool operator!=(const Polinom &p, const Polinom &q)
{
    return !(p==q);
}
bool operator!=(const Polinom &p, double x)
{
    return !(p==x);
}
bool operator!=(double x, const Polinom &p)
{
    return !(x==p);
}

///Another overloaded operators

double& Polinom :: operator[](int val)
{
    return coef[val];
}

double  Polinom :: operator()(int val)
{
    double aux=0;
    int i;
    for(i = 0; i< coef.size(); i++)
    {
        aux = aux + coef[i] * pow(val,i);
    }
    return aux;
}

///ToString function

string to_string(double t)
{
    ostringstream oss;
    oss << t;
    return oss.str();
}

string Polinom :: toString()
{
    string s="";
    int i;
    for(i=0; i <coef.size(); i++)
    {
        if(coef[i]==0)
            continue;
        if(i==0)
        {
            s=s + "+" + to_string(coef[i]);
            continue;
        }
        if(i == 1)
        {
            s = s + "+";
            if(coef[i] != 1)
            {
                s = s + to_string(coef[i]) + "*";
            }
            s = s + "x";
            continue;
        }
        s = s + "+";
        if(coef[i] != 1)
        {
            s = s + to_string(coef[i]) + "*";
        }
        s = s + "x^" + to_string(i);

    }
    if(s[0]=='+')
        s = s.substr(1,s.length( ));
    return s;
}

///Conversion overloaded operator

Polinom :: operator string()
{
    return this->toString();
}

///Read and write overloaded operators

istream& operator>>(istream &is, Polinom &p)
{
    vector<double> newCoef;
    int newGrad;
    ///Model:  c0+c1*x+..+ck*x^k
    string data;
    is >> data;

    int i;
    char *dataSeq = new char[data.length() + 1];
    for(i = 0; i < data.length(); i++)
        dataSeq[i] = data[i];
    dataSeq[data.length()] = NULL;

    char *word;
    word = strtok(dataSeq, "+");
    while(word != NULL)
    {
        int coef = 0;
        int grad = 0;
        int i = 0;
        ///c0   34435
        if(strstr(word, "*") == NULL && strstr(word, "x") == NULL)
        {
            while(i < strlen(word))
            {
                coef = coef * 10 + (word[i] - 48);
                i++;
            }
        }
        ///c1*x
        if(strstr(word, "x") != NULL && strstr(word, "^") == NULL)
        {
            while(i < strlen(word) && word[i] != '*' && word[i] != 'x')
            {
                coef = coef * 10 + (word[i] - 48);
                i++;
            }
            grad = 1;
        }
        ///ck*x^k    Ex: 6743535*x^8234
        if(strstr(word, "^") != NULL)
        {
            while(word[i] != 'x' && word[i] != '*')
            {
                coef = coef * 10 + (word[i] - 48);
                i++;
            }
            while(word[i] != '^')
                i++;
            i++;
            while(i < strlen(word))
            {
                grad = grad * 10 + (word[i] - 48);
                i++;
            }
        }
        if(coef == 0)
            coef = 1;
        while(grad > newCoef.size()) {
            newCoef.push_back(0);
        }
        newCoef.push_back(coef);
        word = strtok(NULL, "+");
    }
    p.setCoef(newCoef);
    p.setGrad(newCoef.size() - 1);
    return is;
}

ostream& operator<<(ostream &os, Polinom &p)
{
    string s = p.toString();
    os << s;
    return os;
}
