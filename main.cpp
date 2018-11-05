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
    vector<double> coef1;
    coef1.push_back(0);
    coef1.push_back(8);
    coef1.push_back(18);
    coef1.push_back(2);
    coef1.push_back(7);
    coef1.push_back(8);
    int degree1 = 5;
    Polynomial polynomial1(degree1, coef1);
    cout << "polynomial1: " << polynomial1 << '\n';

    vector<double> coef2;
    coef2.push_back(1);
    coef2.push_back(2);
    coef2.push_back(0);
    coef2.push_back(4);
    int degree2 = 3;
    Polynomial polynomial2(degree2, coef2);
    cout << "polynomial2: " << polynomial2 << '\n';

    cout << '\n';
    Polynomial sum = polynomial1 + polynomial2;
    cout << "polynomial1 + polynomial2: " << sum << '\n';

    cout << '\n';
    Polynomial diff = polynomial1 - polynomial2;
    cout << "polynomial1 - polynomial2: " << diff << '\n';

    cout << '\n';
    Polynomial prod = polynomial1 * polynomial2;
    cout << "polynomial1 * polynomial2: " << prod << '\n';

    cout << '\n';
    Polynomial div = polynomial1 / polynomial2;
    cout << "polynomial1 / polynomial2: " << div << '\n';

    cout << '\n';
    Polynomial mod = polynomial1 % polynomial2;
    cout << "polynomial1 % polynomial2: " << mod << '\n';

    cout << '\n';
    Polynomial pow = polynomial1 ^ 3;
    cout << "polynomial1 ^ 3: " << pow << '\n';

    cout << '\n';
    int eval = polynomial1(3);
    cout << "polynomial1(3): " << eval << '\n';

    cout << '\n';
    Polynomial polynomial3(polynomial1);
    polynomial3[0] = 17;
    string polynomial3ToString = polynomial3.toString();
    cout << "polynomial3ToString: " << polynomial3ToString << '\n';

    cout << '\n';
    bool areEqual = polynomial1 == polynomial2;
    cout << "polynomial1 == polynomial2: " << areEqual << '\n';

    cout << '\n';
    Polynomial positive = +polynomial1;
    cout << "+ polynomial1: " << positive << '\n';

    cout << '\n';
    Polynomial negative = -polynomial1;
    cout << "- polynomial1: " << negative << '\n';

    cout << '\n';
    Polynomial selfSum;
    selfSum += polynomial1;
    cout << "selfSum += polynomial1: " << selfSum << '\n';

    return 0;
}
