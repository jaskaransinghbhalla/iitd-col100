#include <stdio.h> // mandatory include
float mini(float a, float b){
        if (a > b){
            return b;
        }
        else if (b > a)
        {
            return a;
        }
        else{
            return a;
        }
        }

float time_angle(int XX, int YY){ 
    if(XX>=12){
        XX = XX - 12;
    }      // function you have to implement
    float time_in_hour = XX*60 + YY;
    float angle_hour = time_in_hour*0.5;
    float angle_minute = YY*6;
    float angle1 = angle_hour - angle_minute, angle2 = angle_minute - angle_hour, angle3;
    if (angle1>=0){
        angle3 = angle1;
    }
    else if (angle2>=0)
    {
        angle3 = angle2;
    }
    float angle4 = 360 - angle3;
    //Min Function
    float result = mini(angle3,angle4);         // sample variable - you can change this according to your need
    return result;                 // return statment
}

int main()                       // mandatory main function
{
    int XX, YY;                 // variable denoting hours and minutes
    scanf("%d", &XX);           // hour input
    scanf("%d", &YY);                       // minute input
    //printf("%d:%d",XX,YY);
    int result = time_angle(XX, YY);  // calling function
    printf("%d",result);               // printing result
    return 0;                   // return statment
}
