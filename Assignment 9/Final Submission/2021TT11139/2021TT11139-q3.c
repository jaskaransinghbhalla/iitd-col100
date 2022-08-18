#include <stdio.h>
long int combination(int x, int y){
    if(y == 1)
        return(x);
    else{
        return(x*combination(x-1,y-1)/y);
    }
}
int food(int x, int y, int m, int n){         
    return combination(x+y,x)*combination(m-x+n-y,m-x);        
}
int main()                       
{
    int  x, y, m, n;             
    scanf("%d", &x);           
    scanf("%d", &y);            
    scanf("%d", &m);           
    scanf("%d", &n);            
    printf("%d\n",food(x, y, m, n));
    return 0;                
}
