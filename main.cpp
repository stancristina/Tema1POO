#include <iostream>
#include <vector>
#include <sstream>
#include <string.h>
#include <cstdlib>
#include <math.h>
using namespace std;

class Polinom
{
    int grad;
    vector<double> coef;
public:
    Polinom(int grad = 0, vector<double> coef = vector<double>(1, 0));
    Polinom(const Polinom &p);

    void setGrad(int grad);
    int getGrad();
    void setCoef(vector <double> coef);
    vector<double> getCoef();
    void afisare();

    friend Polinom operator+(const Polinom &p);
    friend Polinom operator+(const Polinom &p, const Polinom &q);
    friend Polinom operator+(double x, const Polinom &p);
    friend Polinom operator+(const Polinom &p, double x);

    friend Polinom operator-(const Polinom &p);
    friend Polinom operator-(const Polinom &p, const Polinom &q);
    friend Polinom operator-(double x, const Polinom &p);
    friend Polinom operator-(const Polinom &p, double x);

    friend Polinom operator*(const Polinom &p, const Polinom &q);
    friend Polinom operator*(double x, const Polinom &p);
    friend Polinom operator*(const Polinom &p, double x);

    friend bool operator==(const Polinom &p, const Polinom &q);
    friend bool operator==(const Polinom &p, double x);
    friend bool operator==(double x, const Polinom &q);

    friend bool operator!=(const Polinom &p, const Polinom &q);
    friend bool operator!=(const Polinom &p, double x);
    friend bool operator!=(double x, const Polinom &q);

    friend Polinom operator^(Polinom &p, int x);
    friend ostream& operator<<(ostream &os, Polinom &p);
    friend istream& operator>>(istream &is, Polinom &p);

    Polinom operator+=(Polinom &p);
    Polinom operator-=(Polinom &p);
    Polinom operator+=(double x);
    Polinom operator-=(double x);
    Polinom operator*=(Polinom &p);

    double& operator[](int val);
    double operator()(int val);

    string toString();
    operator string();
};

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

Polinom operator+(const Polinom &p)
{
    Polinom *ob = new Polinom(p.grad, p.coef);
    return *ob;
}


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

Polinom operator+(double x, const Polinom &p)
{
    vector<double> newCoef;
    newCoef.push_back(x);
    Polinom q(0, newCoef);
    Polinom *ob = new Polinom(q + p);
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

Polinom operator-(double x, const Polinom &p)
{
    vector<double> newCoef;
    newCoef.push_back(x);
    Polinom q(0, newCoef);
    Polinom *ob = new Polinom (q - p);
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

Polinom operator*(double x, const Polinom &p)
{
    vector<double> newCoef;
    newCoef.push_back(x);
    Polinom q(0, newCoef);
    Polinom *ob = new Polinom (q * p);
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


ostream& operator<<(ostream &os, Polinom &p)
{
    string s = p.toString();
    os << s;
    return os;
}

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

Polinom :: operator string()
{
    return this->toString();
}


int main()
{
    int gradAux=6;
    vector<double> coefAux;
    coefAux.push_back(1.71);
    coefAux.push_back(0);
    coefAux.push_back(1/2.);
    coefAux.push_back(0);
    coefAux.push_back(5);
    coefAux.push_back(4);
    coefAux.push_back(1);
    Polinom p(6, coefAux);

    gradAux = 2;
    coefAux.clear();

    coefAux.push_back(0);
    coefAux.push_back(0);
    coefAux.push_back(1);
    Polinom q(gradAux, coefAux);
    cout<<"p= ";
    p.afisare();
    //p *=q;
    //p +=q;
    //p -=q;
    cout<<"q= ";
    q.afisare();
    //p.setGrad();
    cout<<"R= ";
    //p.afisare();

    Polinom r = p + (double)50;
    cout<<r<<'\n';

    cout << r(1) << '\n';
    cout << r.toString() << '\n';
    cout << (string)r << '\n';


    //Polinom r = (double)40 + p;
    //r.afisare();


    ///Polinom r = (double)100 - p;
    ///r.afisare();

    ///Polinom m = r^3;
     ///m.afisare();

    ///Polinom m = p - (double)20;
    ///m.afisare();

    ///Polinom rmn = p * q;
    ///rmn.afisare();

    ///Polinom mnr = rmn * (double)10;
    ///mnr.afisare();

    ///cout << (p==p) << " " << (p==q) << " ";
    ///cout << (p==(double)5);

    return 0;
}
