#include <stdio.h> // mandatory include

int odd_day(int XX, int YY, int ZZZZ)
    {
    int odd = 0;
    int y1 = ZZZZ%400;
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

    int odd1 = 0;
    int KK = 01;
    while(KK<YY){
    if (YY == 01 || YY == 03 || YY == 05 || YY == 07 || YY == 8 || YY == 10 || YY == 12){
        odd1 = odd1 + 3;
    }
    else if(YY == 04 || YY == 06 || YY == 9 || YY == 11){
        odd1 = odd1 + 2;
    }
    else if (YY == 02){
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
        while(KKKK<=CCCC){
            if(KKKK == CCCC){
                if(YY<BB && XX<AA){
                    if((odd_day(XX,YY,KKKK)+m)%7 == 1){
                    bday = bday + 1;
                }
                }
                else{
                    bday = bday + 0;
                }
            }
            else{
                if((odd_day(XX,YY,KKKK)+m)%7 == 1){
                    bday = bday + 1;
    
                }
            }
        KKKK = KKKK+1;
        }
        int result = bday; 
        return result; 
}


int main()                       // mandatory main function
{
    int XX, YY, ZZZZ, AA, BB, CCCC;             // variable 
    scanf("%d", &XX);           // input of Date of birth
    scanf("%d", &YY);            // input of Month of birth
    scanf("%d", &ZZZZ);           // input of Year of birth
    scanf("%d", &AA);           // input of Date of death
    scanf("%d", &BB);            // input of Month of death
    scanf("%d", &CCCC);            // input of Year of death
    //printf("%d-%d-%d and %d-%d-%d \n",XX, YY, ZZZZ, AA, BB, CCCC);
    int result = birt(XX, YY, ZZZZ, AA, BB, CCCC);  // calling function
    printf("%d",result);               // printing result
    return 0;                   // return statment
}
