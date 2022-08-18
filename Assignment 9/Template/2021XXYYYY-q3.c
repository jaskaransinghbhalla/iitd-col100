#include <stdio.h> // mandatory include

int food(int x, int y, int m, int n){   // function you have to implement
    int result = 3;          // sample variable - you can change this according to your need
    //printf("(%d,%d) and (%d,%d) \n",x,y,m,n);
    return result;                 // return statment
}

int main()                       // mandatory main function
{
    int x, y, m, n;             // variable denoting coordinate of restaurant and delivery location
    scanf("%d", &x);           // x coordinate of restaurant
    scanf("%d", &y);            // y coordinate of restaurant
    scanf("%d", &m);           // x coordinate of delivery location
    scanf("%d", &n);            // y coordinate of delivery location
    //printf("(%d,%d) and (%d,%d) \n",x,y,m,n);
    int result = food(x, y, m, n);  // calling function
    printf("%d",result);               // printing result
    return 0;                   // return statment
}
