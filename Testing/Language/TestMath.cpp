#include "gtest/gtest.h"

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;


TEST(TestRounding,rounding)
{
    https://habr.com/ru/post/471506/

    double q, x, xr, X;
    unsigned long long int Xr;
    int N, p, E, e, k;

//    cout <<"Input a binary precision p=";
//    cin >> p;
//    cout << "Input a decimal precision N=";
//    cin >> N;
//    cout << endl<<"Input a number and press ENTER:"<<"\n"<<"x= ";
//    cin >> x;
//    cout << "X= "<< setprecision(18) <<x << '\n';
    p = 5;
    N = 15;
    x = 7.6;

    q = frexp(x, &e);
    E = static_cast <int> (e*0.301);
    k = N - E;
    if(E < 0)       //for format xr=d0.d1...dN*10^E (d0≠0).
    {
        k = k + 1;
    }
    X = x * pow(10,k);
    if (X > pow(10,N))
    {
        X = X / 10;
        k = k - 1;
    }

    X = X + 0.5;
    Xr = static_cast<unsigned long long int>(X);
    xr = Xr * pow(10,-k);

    cout << endl <<"Xr= "<<Xr<<"e"<<-k<<'\n';
    cout << "xr="<<xr << endl;
}

