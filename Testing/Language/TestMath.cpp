#include "gtest/gtest.h"

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

using frexpValues = std::tuple<double, double, int>;
constexpr size_t inputVlue = 0U;
constexpr size_t expectedSignificand = 1U;
constexpr size_t expectedExponent = 2U;
class TestFrexp :public ::testing::TestWithParam<frexpValues>{};
INSTANTIATE_TEST_CASE_P(
        ParamsForTestFrexp,
        TestFrexp,
        ::testing::Values(
                frexpValues{428362.33201, 0.81703633, 19},
                frexpValues{42.0,         0.65625,    6},
                frexpValues{10.0,         0.625,      4},
                frexpValues{8.0,          0.5,        4}, // 8.0 = 0.5 * 2^4
                frexpValues{0.51,         0.50999999, 0},
                frexpValues{0.5,          0.5,        0},
                frexpValues{0.499,        0.99800003, -1},
                frexpValues{0.4,          0.80000001, -1},
                frexpValues{0.0,          0.0,        0},
                frexpValues{0.0001,       0.81919998, -13},
                frexpValues{-8.0,         -0.5,       4}, // -8.0 = -0.5 * 2^4
                frexpValues{-42.0,        -0.65625,   6}
        ),);

TEST_P(TestFrexp, testFrexp_paramValues_successful)
{
    frexpValues params = GetParam();

    int exponent;
    ASSERT_FLOAT_EQ(get<expectedSignificand>(params), ::frexp(get<inputVlue>(params), &exponent));
    ASSERT_EQ(get<expectedExponent>(params), exponent);
}

TEST(TestRounding, rounding)
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

    q = ::frexp(x, &e);
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

