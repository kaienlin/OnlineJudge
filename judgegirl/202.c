#include <stdio.h>

int main(void)
{
    int a, b, c, d, e, f, g;
    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);

    int numerator1, numerator2;
    int denominator1, denominator2;
    int result_nu, result_de, result_int = 0;
    int tmp_nu, tmp_de;

    if ( a > 0 ) {
        numerator1 = a * c + b;
    } else {
        numerator1 = a * c - b;
    }

    if ( e > 0 ) {
        numerator2 = e * g + f;
    } else {
        numerator2 = e * g - f;
    }

    switch(d) {
        case 0:
            numerator1 *= g;
            numerator2 *= c;
            result_nu = numerator1 + numerator2;
            result_de = c * g;
            break;
        case 1:
            numerator1 *= g;
            numerator2 *= c;
            result_nu = numerator1 - numerator2;
            result_de = c * g;
            break;
        case 2:
            result_nu = numerator1 * numerator2;
            result_de = c * g;
            break;
        case 3:
            result_nu = numerator1 * g;
            result_de = numerator2 * c;
            break;
    }

    if ( result_nu == 0 ) {
        result_de = 1;
        printf("0\n%d\n%d\n", result_nu, result_de);
    }

    //針對除法造成分母為負數的情況
    if ( result_de < 0) {
        result_nu = -result_nu;
        result_de = -result_de;
    }

    tmp_nu = result_nu > 0 ? result_nu : -result_nu;
    tmp_de = result_de;

    //reduction
    while ( tmp_nu != 0 && tmp_de != 0) {
        if ( tmp_nu > tmp_de ) {
            tmp_nu -= tmp_de;
        } else {
            tmp_de -= tmp_nu;
        }
    }
    if ( tmp_nu == 0 ) {
        result_nu /= tmp_de;
        result_de /= tmp_de;
    } else {
        result_nu /= tmp_nu;
        result_de /= tmp_nu;
    }

    // 化假分數為帶分數
    if ( result_nu > result_de || -result_nu > result_de) {
        if ( result_nu > 0 ) {
            result_int += result_nu / result_de;
            result_nu = result_nu % result_de;
        } else {
            result_int += result_nu / result_de;
            result_nu = -(result_nu % result_de);
        }
    } else if ( result_nu == result_de || -result_nu == result_de ) {
        if ( result_nu > 0 ) {
            result_int = 1;
            result_nu = 0;
            result_de = 1;
        } else {
            result_int = -1;
            result_nu = 0;
            result_de = 1;
        }
    }

    printf("%d\n%d\n%d\n", result_int, result_nu, result_de);

    return 0;
}
