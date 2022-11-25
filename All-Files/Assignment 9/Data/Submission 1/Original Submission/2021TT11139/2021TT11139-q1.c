#include <stdio.h>

int main(){
    int a,b,c;
    scanf("%d", &a);
    scanf("%d", &b);
    c = a*b;

    if (b!=0){
        printf("%d", c);
    }else{
        int d = 0;
        printf("%d",d);
    }
    return 0;
}