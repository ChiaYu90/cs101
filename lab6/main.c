#include <stdio.h>
#include <stdlib.h>

int _sum(int x, int y){
    return x+y;
}
int _sub(int x, int y){
    return x-y;
}
int _mult(int x, int y){
    return x*y;
}
int _div(int x, int y){
    return x/y;
}
int _power(int x, int y){
    if (y == 1) return x;
    else return _power(x, y-1)*x;
}
/*
int _power(int x, int y){
    int sum = 1;
    while(y--) sum *=x;
    return sum;
}*/

int main(void){
    int x, y, choise;
    int(*ope[5])(int , int );
    ope[0] = _sum;
    ope[1] = _sub;
    ope[2] = _mult;
    ope[3] = _div;
    ope[4] = _power;
    printf("Enter to integer:");
    scanf("%d%d", &x, &y);
    printf("Enter 0 :+, 1 : -, 2 : *, 3 : /, 4 : ^");
    scanf("%d", &choise);
    printf("%d", ope[choise](x,y));
    return 0;
}
