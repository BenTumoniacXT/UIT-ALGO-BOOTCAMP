#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

long double d, a1, a2, v, t;

long double calc()
{
    long double rs;

    long double a = (long double)1 / (a1 * 2) + (long double)1 / (a2 * 2), v2 = (-t + sqrt(t * t + 4 * a * d)) / (a * 2);
    if (v2 <= v) rs = v2 / a1 + v2 / a2 + t;
        else rs = d / v + v / (2 * a1) + v / (2 * a2);

    return rs + 5e-14;
}

int main()
{
    cin >> d >> a1 >> a2 >> v >> t;
    cout << setprecision(12) << fixed << calc();

    return 0;
}