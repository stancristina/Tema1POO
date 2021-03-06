#include <iostream>
#include <sstream>
#include "Polynomial.hpp"
#include <string.h>
#include <cstdlib>
#include <vector>
#include <math.h>
using namespace std;

void Polynomial :: setDegree(int degree)
{
    this->degree = degree;
}

int Polynomial :: getDegree()
{
    return this->degree;
}

void Polynomial :: setCoef(vector<double> coef)
{
    this->coef = coef;
}

vector<double> Polynomial :: getCoef()
{
    return this->coef;
}

Polynomial :: Polynomial(int degree, vector<double> coef)
{
    this->degree = degree;
    this->coef = coef;
}

Polynomial :: Polynomial(const Polynomial &polynom)
{
    this->degree = polynom.degree;
    this->coef = polynom.coef;
}

///Composed overloaded operators

Polynomial Polynomial :: operator+=(Polynomial &secondTerm)
{
    vector<double> newCoef;
    int index;
    for(index = 0; index <= max(this->degree, secondTerm.getDegree()); index++ )
    {
        newCoef.push_back(0);
        if(index <= this->degree)
            newCoef[index] += (this->coef)[index];
        if(index <= secondTerm.getDegree())
            newCoef[index] += (secondTerm.getCoef())[index];

    }
    while(newCoef.size() > 1 && newCoef[newCoef.size()-1] == 0)
    {
        newCoef.pop_back();
    }
    int newDegree = newCoef.size() - 1;
    this->coef = newCoef;
    this->degree = newDegree;
    return *this;
}

Polynomial Polynomial :: operator+=(double freeTerm)
{
    (this->coef)[0]+=freeTerm;
    return *this;
}

Polynomial Polynomial :: operator-=(Polynomial &secondTerm)
{
    vector<double> newCoef;
    int index;
    for(index = 0; index <= max(this->degree, secondTerm.getDegree()); index++)
    {
        newCoef.push_back(0);
        if(index <= this-> degree)
            newCoef[index] = (this->coef)[index];
        if(index <= secondTerm.getDegree())
            newCoef[index] -= (secondTerm.getCoef())[index];
    }
    while(newCoef.size() > 1 && newCoef[newCoef.size() - 1]== 0)
    {
        newCoef.pop_back();
    }
    int newDegree = newCoef.size() - 1;
    this->coef = newCoef;
    this->degree = newDegree;
    return *this;
}

Polynomial Polynomial :: operator-=(double freeTerm)
{
    (this->coef)[0]-=freeTerm;
    return *this;
}

Polynomial Polynomial :: operator*=(Polynomial &secondTerm)
{
    int newDegree = this->degree + secondTerm.getDegree();
    vector<double> newCoef(newDegree + 1, 0);
    int index1,index2;
    for(index1 = 0; index1 <= this->degree; index1++)
    {
        for(index2 = 0; index2 <= secondTerm.getDegree(); index2++)
        {
            newCoef[index1 + index2] += (this->coef)[index1] * (secondTerm.getCoef())[index2];
        }
    }
    this->degree = newDegree;
    this->coef = newCoef;
    return *this;
}

Polynomial Polynomial :: operator *=(double freeTerm)
{
    int index;
    for(index = 0; index < coef.size(); index++)
    {
        coef[index] *= freeTerm;
    }
    return *this;
}

Polynomial Polynomial :: operator/=(Polynomial &secondTerm)
{
    Polynomial *ob = new Polynomial();
    Polynomial *polynomialCopy = new Polynomial(*this);
    while(polynomialCopy->degree >= secondTerm.degree)
    {
        double multiplicator = polynomialCopy->coef[polynomialCopy->degree] / secondTerm.coef[secondTerm.degree];
        int degreeDif = polynomialCopy->degree - secondTerm.degree;

        Polynomial monomial;
        monomial.degree = degreeDif;
        while(monomial.coef.size() <= monomial.degree)
        {
            monomial.coef.push_back(0);
        }
        monomial.coef[monomial.degree] = multiplicator;
        (*ob) += monomial;

        Polynomial polynomialToSubstract = secondTerm * monomial;
        (*polynomialCopy) -= polynomialToSubstract;
    }

    ///In polynomialCopy se afla restul
    ///In *ob se afla catul
    //Polynomial x = secondTerm * (*ob) + (*polynomialCopy) ;
    this->degree = ob->degree;
    this->coef = ob->coef;
    return (*ob);

}

Polynomial Polynomial :: operator/=(double freeTerm)
{
    vector <double> newCoef;
    newCoef.push_back(freeTerm);
    Polynomial secondTerm(0, newCoef);
    Polynomial *ob = new Polynomial ((*this) / secondTerm);
    this->degree = ob->degree;
    this-> coef = ob->coef;
    return *ob;
}

Polynomial Polynomial :: operator%=(Polynomial &secondTerm)
{
    Polynomial *ob = new Polynomial();
    Polynomial *polynomialCopy = new Polynomial(*this);
    while(polynomialCopy->degree >= secondTerm.degree)
    {
        double multiplicator = polynomialCopy->coef[polynomialCopy->degree] / secondTerm.coef[secondTerm.degree];
        int degreeDif = polynomialCopy->degree - secondTerm.degree;

        Polynomial monomial;
        monomial.degree = degreeDif;
        while(monomial.coef.size() <= monomial.degree)
        {
            monomial.coef.push_back(0);
        }
        monomial.coef[monomial.degree] = multiplicator;
        (*ob) += monomial;

        Polynomial polynomialToSubstract = secondTerm * monomial;
        (*polynomialCopy) -= polynomialToSubstract;
    }

    ///In polynomialCopy se afla restul
    ///In *ob se afla catul
    //Polynomial x = secondTerm * (*ob) + (*polynomialCopy) ;
    return (*polynomialCopy);
}

Polynomial Polynomial :: operator%=(double freeTerm)
{
    vector <double> newCoef;
    newCoef.push_back(freeTerm);
    Polynomial secondTerm(0, newCoef);
    Polynomial *ob = new Polynomial ((*this) % secondTerm);
    this->degree = ob->degree;
    this->coef = ob->coef;
    return (*ob);
}

///Unary overloaded operators

Polynomial operator+(const Polynomial &firstTerm)
{
    Polynomial *ob = new Polynomial(firstTerm.degree, firstTerm.coef);
    return *ob;
}

Polynomial operator-(const Polynomial &firstTerm)
{
    vector<double> newCoef = firstTerm.coef;
    int index;
    for(index=0; index < newCoef.size(); index++)
    {
        newCoef[index] = -newCoef[index];
    }
    Polynomial *ob = new Polynomial(firstTerm.degree, newCoef);
    return *ob;
}

///Binary overloaded operators

Polynomial operator+(const Polynomial &firstTerm, const Polynomial &secondTerm)
{
    vector<double> newCoef;
    int index;
    for(index = 0; index <= max(firstTerm.degree, secondTerm.degree); index++ )
    {
        newCoef.push_back(0);
        if(index <= firstTerm.degree)
            newCoef[index] += (firstTerm.coef)[index];
        if(index <= secondTerm.degree)
            newCoef[index] += (secondTerm.coef)[index];

    }
    while(newCoef.size() > 1 && newCoef[newCoef.size()-1] == 0)
    {
        newCoef.pop_back();
    }
    int newDegree = newCoef.size() - 1;
    Polynomial *ob = new Polynomial (newDegree, newCoef);
    return *ob;
}

Polynomial operator+(const Polynomial &firstTerm, double freeTerm)
{
    vector<double> newCoef;
    newCoef.push_back(freeTerm);
    Polynomial secondTerm(0, newCoef);
    Polynomial *ob = new Polynomial(firstTerm + secondTerm);
    return *ob;
}

Polynomial operator+(double freeTerm, const Polynomial &secondTerm)
{
    vector<double> newCoef;
    newCoef.push_back(freeTerm);
    Polynomial firstTerm(0, newCoef);
    Polynomial *ob = new Polynomial(firstTerm + secondTerm);
    return *ob;
}

Polynomial operator-(const Polynomial &firstTerm, const Polynomial &secondTerm)
{
    vector<double> newCoef;
    int index;
    for(index = 0; index <= max(firstTerm.degree, secondTerm.degree); index++)
    {
        newCoef.push_back(0);
        if(index <= firstTerm.degree)
            newCoef[index] = (firstTerm.coef[index]);
        if(index <= secondTerm.degree)
            newCoef[index] -= (secondTerm.coef)[index];
    }
    while(newCoef.size() > 1 && newCoef[newCoef.size() - 1]== 0)
    {
        newCoef.pop_back();
    }
    int newDegree = newCoef.size() - 1;
    Polynomial *ob = new Polynomial (newDegree, newCoef);
    return *ob;
}

Polynomial operator-(const Polynomial &firstTerm, double freeTerm)
{
    vector<double> newCoef;
    newCoef.push_back(freeTerm);
    Polynomial secondTerm(0, newCoef);
    Polynomial *ob = new Polynomial (firstTerm - secondTerm);
    return *ob;
}

Polynomial operator-(double freeTerm, const Polynomial &secondTerm)
{
    vector<double> newCoef;
    newCoef.push_back(freeTerm);
    Polynomial firstTerm(0, newCoef);
    Polynomial *ob = new Polynomial (firstTerm - secondTerm);
    return *ob;
}

Polynomial operator*(const Polynomial &firstTerm, const Polynomial &secondTerm)
{
    int newDegree = firstTerm.degree + secondTerm.degree;
    vector<double> newCoef(newDegree + 1, 0);
    int index1, index2;
    for(index1 = 0; index1 <= firstTerm.degree; index1++)
    {
        for(index2 = 0; index2 <= secondTerm.degree; index2++)
        {
            newCoef[index1 + index2] += (firstTerm.coef)[index1] * (secondTerm.coef)[index2];
        }
    }
    Polynomial *ob = new Polynomial(newDegree, newCoef);
    return *ob;

}

Polynomial operator*(const Polynomial &firstTerm, double freeTerm)
{
    vector<double> newCoef;
    newCoef.push_back(freeTerm);
    Polynomial secondTerm(0, newCoef);
    Polynomial *ob = new Polynomial (firstTerm * secondTerm);
    return *ob;
}

Polynomial operator*(double freeTerm, const Polynomial &secondTerm)
{
    vector<double> newCoef;
    newCoef.push_back(freeTerm);
    Polynomial firstTerm(0, newCoef);
    Polynomial *ob = new Polynomial (firstTerm * secondTerm);
    return *ob;
}

Polynomial operator/(const Polynomial &firstTerm, const Polynomial &secondTerm)
{
    Polynomial *ob = new Polynomial();
    Polynomial *polynomialCopy = new Polynomial(firstTerm);
    while(polynomialCopy->degree >= secondTerm.degree)
    {
        double multiplicator = polynomialCopy->coef[polynomialCopy->degree] / secondTerm.coef[secondTerm.degree];
        int degreeDif = polynomialCopy->degree - secondTerm.degree;

        Polynomial monomial;
        monomial.degree = degreeDif;
        while(monomial.coef.size() <= monomial.degree)
        {
            monomial.coef.push_back(0);
        }
        monomial.coef[monomial.degree] = multiplicator;
        (*ob) += monomial;

        Polynomial polynomialToSubstract = secondTerm * monomial;
        (*polynomialCopy) -= polynomialToSubstract;
    }

    ///In polynomialCopy se afla restul
    ///In *ob se afla catul
    //Polynomial x = q * (*ob) + (*polynomialCopy) ;
    return (*ob);
}

Polynomial operator/(const Polynomial &firstTerm, double freeTerm)
{
    vector <double> newCoef;
    newCoef.push_back(freeTerm);
    Polynomial secondTerm(0, newCoef);
    Polynomial *ob = new Polynomial (firstTerm / secondTerm);
    return *ob;
}

Polynomial operator/(double freeTerm, const Polynomial &secondTerm)
{
    vector <double> newCoef;
    newCoef.push_back(freeTerm);
    Polynomial firstTerm(0, newCoef);
    Polynomial *ob = new Polynomial (firstTerm / secondTerm);
    return *ob;
}

Polynomial operator%(const Polynomial &firstTerm, const Polynomial &secondTerm)
{
    Polynomial *ob = new Polynomial();
    Polynomial *polynomialCopy = new Polynomial(firstTerm);
    while(polynomialCopy->degree >= secondTerm.degree)
    {
        double multiplicator = polynomialCopy->coef[polynomialCopy->degree] / secondTerm.coef[secondTerm.degree];
        int degreeDif = polynomialCopy->degree - secondTerm.degree;

        Polynomial monomial;
        monomial.degree = degreeDif;
        while(monomial.coef.size() <= monomial.degree)
        {
            monomial.coef.push_back(0);
        }
        monomial.coef[monomial.degree] = multiplicator;
        (*ob) += monomial;

        Polynomial polynomialToSubstract = secondTerm * monomial;
        (*polynomialCopy) -= polynomialToSubstract;
    }

    ///In polynomialCopy se afla restul
    ///In *ob se afla catul
    //Polynomial x = q * (*ob) + (*polynomialCopy) ;
    return (*polynomialCopy);
}

Polynomial operator%(const Polynomial &firstTerm, double freeTerm)
{
    vector <double> newCoef;
    newCoef.push_back(freeTerm);
    Polynomial secondTerm(0, newCoef);
    Polynomial *ob = new Polynomial (firstTerm % secondTerm);
    return (*ob);
}

Polynomial operator%(double freeTerm, const Polynomial &secondTerm)
{
    vector <double> newCoef;
    newCoef.push_back(freeTerm);
    Polynomial firstTerm(0, newCoef);
    Polynomial *ob = new Polynomial (firstTerm % secondTerm);
    return (*ob);
}

Polynomial operator^(Polynomial &base, int power)
{
    Polynomial aux;
    aux = aux+1;
    int index;
    for(index = 1; index <= power; index++)
    {
        aux *= base;
        ///aux.afisare();
    }
    Polynomial *ob =  new Polynomial(aux);
    return *ob;
}

///Relational overloaded operators

bool operator==(const Polynomial &firstTerm, const Polynomial &secondTerm)
{
    if(firstTerm.degree != secondTerm.degree)
        return false;
    int index;
    for(index = 0; index <= firstTerm.coef.size(); index++)
    {
        if(firstTerm.coef[index] != secondTerm.coef[index])
            return false;
    }

    return true;
}

bool operator==(const Polynomial &firstTerm, double freeTerm)
{
    if(firstTerm.degree != 0)
        return false;
    if(firstTerm.coef[0] != freeTerm)
        return false;
    return true;
}

bool operator==(double freeTerm, const Polynomial &secondTerm)
{
    if(secondTerm.degree != 0)
        return false;
    if(secondTerm.coef[0] != freeTerm)
        return false;
    return true;
}

bool operator!=(const Polynomial &firstTerm, const Polynomial &secondTerm)
{
    return !(firstTerm == secondTerm);
}

bool operator!=(const Polynomial &firstTerm, double freeTerm)
{
    return !(firstTerm == freeTerm);
}

bool operator!=(double freeTerm, const Polynomial &secondTerm)
{
    return !(freeTerm == secondTerm);
}

///Another overloaded operators

double& Polynomial :: operator[](int val)
{
    return coef[val];
}

double  Polynomial :: operator()(int val)
{
    double aux=0;
    int index;
    for(index = 0; index < coef.size(); index++)
    {
        aux = aux + coef[index] * pow(val, index);
    }
    return aux;
}

///ToString function

string to_string(double freeTerm)
{
    ostringstream oss;
    oss << freeTerm;
    return oss.str();
}

string Polynomial :: toString()
{
    string stringToReturn="";
    int index;
    for(index = 0; index < coef.size(); index++)
    {
        if(coef[index] == 0)
            continue;
        if(index == 0)
        {
            stringToReturn = stringToReturn + "+" + to_string(coef[index]);
            continue;
        }
        if(index == 1)
        {
            stringToReturn = stringToReturn + "+";
            if(coef[index] != 1)
            {
                stringToReturn = stringToReturn + to_string(coef[index]) + "*";
            }
            stringToReturn = stringToReturn + "x";
            continue;
        }
        stringToReturn = stringToReturn + "+";
        if(coef[index] != 1)
        {
            stringToReturn = stringToReturn + to_string(coef[index]) + "*";
        }
        stringToReturn = stringToReturn + "x^" + to_string(index);

    }
    if(stringToReturn[0]=='+')
        stringToReturn = stringToReturn.substr(1, stringToReturn.length());
    return stringToReturn;
}

///Conversion overloaded operator

Polynomial :: operator string()
{
    return this->toString();
}

///Read and write overloaded operators

istream& operator>>(istream &is, Polynomial &term)
{
    vector<double> newCoef;
    int newDegree;
    ///Model:  c0+c1*x+..+ck*x^k
    string data;
    is >> data;

    int index;
    char *dataSeq = new char[data.length() + 1];
    for(index = 0; index < data.length(); index++)
        dataSeq[index] = data[index];
    dataSeq[data.length()] = NULL;

    char *word;
    word = strtok(dataSeq, "+");
    while(word != NULL)
    {
        int coef = 0;
        int degree = 0;
        int index = 0;
        ///c0   34435
        if(strstr(word, "*") == NULL && strstr(word, "x") == NULL)
        {
            while(index < strlen(word))
            {
                coef = coef * 10 + (word[index] - 48);
                index++;
            }
        }
        ///c1*x
        if(strstr(word, "x") != NULL && strstr(word, "^") == NULL)
        {
            while(index < strlen(word) && word[index] != '*' && word[index] != 'x')
            {
                coef = coef * 10 + (word[index] - 48);
                index++;
            }
            degree = 1;
        }
        ///ck*x^k    Ex: 6743535*x^8234
        if(strstr(word, "^") != NULL)
        {
            while(word[index] != 'x' && word[index] != '*')
            {
                coef = coef * 10 + (word[index] - 48);
                index++;
            }
            while(word[index] != '^')
                index++;
            index++;
            while(index < strlen(word))
            {
                degree = degree * 10 + (word[index] - 48);
                index++;
            }
        }
        if(coef == 0)
            coef = 1;
        while(degree > newCoef.size()) {
            newCoef.push_back(0);
        }
        newCoef.push_back(coef);
        word = strtok(NULL, "+");
    }
    term.setCoef(newCoef);
    term.setDegree(newCoef.size() - 1);
    return is;
}

ostream& operator<<(ostream &os, Polynomial &term)
{
    string stringToPrint = term.toString();
    os << stringToPrint;
    return os;
}



