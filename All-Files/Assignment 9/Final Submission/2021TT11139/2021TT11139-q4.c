#include <stdio.h>
int odd_day(int XX, int YY, int ZZZZ)
    {
    int odd = 0;
    int y1 = (ZZZZ-1)%400;
    if(y1>=300){
        y1 = y1%300;
        odd = odd + 1;
    }
    else if(y1>=200 && y1<300){
        y1 = y1%200;
        odd = odd + 3;
    }
    else if(y1>=100 && y1<200){
        y1 = y1%100;
        odd = odd + 5;
    }
    int k1 = y1/4;
    odd = odd + (2*k1);
    int k2 = y1 - k1;
    odd = odd + k2;
    odd = odd%7;
    


    int odd1 = 0;
    int KK = 1;

    while(KK<YY){
    if (KK == 1 || KK == 3 || KK == 5 || KK == 7 || KK == 8 || KK == 10 || KK == 12){
        odd1 = odd1 + 3;
    }
    else if(KK == 4 || KK == 6 || KK == 9 || KK == 11){
        odd1 = odd1 + 2;
    }
    else if (KK == 02){
        if(ZZZZ%4 == 0){
            odd1 = odd1 + 1;
        }
    }
    KK++;
    }
    
    int odd2 = XX;
    int final = odd + odd1 + odd2;
    return final%7;
    }
int birt(int XX, int YY, int ZZZZ, int AA, int BB, int CCCC)
{   // function you have to implement
    int bday = 0;
    int i = odd_day(XX,YY,ZZZZ);
    int m = 6-i;

    if(i != 6){
        i = i + m;
    }

    int KKKK = ZZZZ;
    int j;

    while(KKKK<=CCCC){
        // printf("%d\n",KKKK);
        if(XX == 29 && YY == 02 && KKKK%4 != 0){
            j = odd_day(01,03,KKKK);
            // printf("%d\n",j);
        }
        else{
            j = (odd_day(XX,YY,KKKK));
            // printf("%d\n",j);
        }
        if(KKKK == CCCC){
            
            if(YY<BB){
                if(XX == 29 && YY == 02 && AA == 01 && BB == 03){
                    bday = bday + 0;
                }
                else{
                if((j+m)%7 == 1){
                bday = bday + 1;
                }}
            }
            else if(YY==BB){
                if(XX<AA){

                    if((j+m)%7 == 1){
                        bday = bday + 1;
                    }
                }
            }    
        }
        else{
            if(((j+m)%7) == 1){
                bday = bday + 1;
            }
        }
        KKKK = KKKK+1;
    }
    int result = bday; 
    return result; 
}
int main()                   
{
    int XX, YY, ZZZZ, AA, BB, CCCC;
    scanf("%d", &XX);          
    scanf("%d", &YY);            
    scanf("%d", &ZZZZ);          
    scanf("%d", &AA);          
    scanf("%d", &BB);            
    scanf("%d", &CCCC);           
    // printf("%d-%d-%d and %d-%d-%d \n",XX, YY, ZZZZ, AA, BB, CCCC);
    int result = birt(XX, YY, ZZZZ, AA, BB, CCCC);  
    printf("%d\n",result);
    return 0;               
}
