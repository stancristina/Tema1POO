#include <iostream>
#include <vector>
#include <sstream>
#include <string.h>
#include <cstdlib>
#include <math.h>
#include "Polynomial.cpp"
using namespace std;

int main()
{
    int degreeAux=6;
    vector<double> coefAux;
    coefAux.push_back(1.71);
    coefAux.push_back(0);
    coefAux.push_back(1/2.);
    coefAux.push_back(0);
    coefAux.push_back(5);
    coefAux.push_back(4);
    coefAux.push_back(1);
    Polynomial p(6, coefAux);

    degreeAux = 2;
    coefAux.clear();

    coefAux.push_back(0);
    coefAux.push_back(0);
    coefAux.push_back(1);
    Polynomial q(degreeAux, coefAux);
    cout<<"p= ";
    p.afisare();
    //p *=q;
    //p +=q;
    //p -=q;
    cout<<"q= ";
    q.afisare();
    //p.setDegree();
    cout<<"R= " << '\n';
    //p.afisare();

   // Polynomial r = p + (double)50;
    //cout<<r<<'\n';

    //cout << r(1) << '\n';
    //cout << r.toString() << '\n';
   // cout << (string)r << '\n';


    //Polynomial r = (double)40 + p;
    //r.afisare();


    ///Polynomial r = (double)100 - p;
    ///r.afisare();

    ///Polynomial m = r^3;
     ///m.afisare();

    ///Polynomial m = p - (double)20;
    ///m.afisare();

    ///Polynomial rmn = p * q;
    ///rmn.afisare();

    ///Polynomial mnr = rmn * (double)10;
    ///mnr.afisare();

    ///cout << (p==p) << " " << (p==q) << " ";
    ///cout << (p==(double)5);

    vector<double> cf1;
    cf1.push_back(0);
    cf1.push_back(8);
    cf1.push_back(18);
    cf1.push_back(2);
    cf1.push_back(7);
    cf1.push_back(8);
    int degree1 = 5;
    Polynomial p1(degree1, cf1);

    vector<double> cf2;
    cf2.push_back(1);
    cf2.push_back(2);
    cf2.push_back(0);
    cf2.push_back(4);
    int degree2 = 3;
    Polynomial p2(degree2, cf2);

    Polynomial p3 = p1 / p2;
    cout << p3 << '\n';


    return 0;
}
