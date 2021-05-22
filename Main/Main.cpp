#include <iostream>
#include "TMonom.h"
#include "TPolinom.h"

int main()
{
    TMonom a(new double[1]{ 3 }, 1, 1);
    TMonom b(new double[1]{ 1 }, 1, 1);
    TMonom c(new double[1]{ 2 }, 1, 1);

    TPolinom p1, p2, p3;
    p1 += a;
    p1 += b;
    p2 += c;

    p3 = p1 * p2;
    cout << p3 << endl;
    p3 = p1 + p2;
    cout << p3 << endl;
    p3 = p1 - p2;
    cout << p3 << endl;
    return 0;
}