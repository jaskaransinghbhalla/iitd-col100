#include <stdio.h> // mandatory include
int factorial(int n){
    if (n == 1 || n == 0){
        return 1;
    }
    int fact;
    fact = n * factorial(n-1);    
    return fact;
}
int food(int x, int y, int m, int n){   // function you have to implement

    int w1 = factorial(x+y)/(factorial(x)*factorial(y));
    int w2 = factorial ((m - x) + (n - y))/(factorial(m-x)*factorial(n-y));
    int result = w1*w2;          // sample variable - you can change this according to your need
    //printf("(%d,%d) and (%d,%d) \n",x,y,m,n);
    return result;               // return statment
}
int main()                       // mandatory main function
{
    int x, y, m, n;             // variable denoting coordinate of restaurant and delivery location
    scanf("%d", &x);           // x coordinate of restaurant
    scanf("%d", &y);            // y coordinate of restaurant
    scanf("%d", &m);           // x coordinate of delivery location
    scanf("%d", &n);            // y coordinate of delivery location
    //printf("(%d,%d) and (%d,%d) \n",x,y,m,n);
    
    int result = food(x, y, m, n);  // calling function              // printing result
    printf("%d",result);
    return 0;                   // return statment
}
