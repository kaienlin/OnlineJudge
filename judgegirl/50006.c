// READ THE DESCRIPTION CAREFULLY !!!!!!!

int eval(int exp[])
{   
    int result = 0;
    int product = exp[1];
    int i = 2;
    int opr = 1;
    while ( i <= exp[0] - 1 ) {
        if ( exp[i] == 1 ) {
            result += opr - 1 ? -product : product;
            product = exp[i + 1];
            opr = 1;
        } else if ( exp[i] == 2 ) {
            result += opr - 1 ? -product : product;
            product = exp[i + 1];
            opr = 2;
        } else if ( exp[i] == 3 ) {
            product *= exp[i + 1];
        } else if ( exp[i] == 4 ) {
            if ( exp[i + 1] == 0 ) {
                return -2147483647; // I miss that the return value of zero-division error is different form operand error
            }
            product /= exp[i + 1];
        } else {
            return -2147483646;
        }
        i += 2;
    }
    return result += opr - 1 ? -product : product;
}
