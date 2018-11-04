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

   // Polinom r = p + (double)50;
    //cout<<r<<'\n';

    //cout << r(1) << '\n';
    //cout << r.toString() << '\n';
   // cout << (string)r << '\n';


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
