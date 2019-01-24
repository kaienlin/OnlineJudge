#include "fraction.h"

Frac normal(long long a, long long b) {
    Frac ans;
    long long tmpa = a;
    long long tmpb = b;
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b; // handle negative number
    while ( a != 0 && b != 0 ) {
        if ( a > b ) {
            a %= b;
        } else if ( a < b ) {
            b %= a;
        } else {
            b = 0;
        }
    }
    long long gcd = a == 0 ? b : a;
    ans.a = tmpa / gcd;
    ans.b = tmpb / gcd;
    return ans;
}
Frac add(Frac x, Frac y) {
    return normal(x.a * y.b + y.a * x.b, x.b * y.b);
}
Frac subtract(Frac x, Frac y) {
    return normal(x.a * y.b - y.a * x.b, x.b * y.b);
}
Frac multipy(Frac x, Frac y) {
    return normal(x.a * y.a, x.b * y.b);
}
Frac divide(Frac x, Frac y) {
    return normal(x.a * y.b, x.b * y.a);
}
