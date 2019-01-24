#include<stdio.h>
#include"conversion.h"
int main(){
    int T;
    char input_file[32];
    char output_file[32];
    char dict[17];
    scanf("%d%s%s%s", &T, input_file, output_file, dict);
    if(T)ascii2bin(input_file, output_file, dict);
    else bin2ascii(input_file, output_file, dict);
    return 0;
}