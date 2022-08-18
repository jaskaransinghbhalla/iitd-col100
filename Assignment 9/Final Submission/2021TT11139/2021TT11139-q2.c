#include <stdio.h> 
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
    }

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
    float result = mini(angle3,angle4);        
    return result;                 
}

int main()                   
{
    int XX, YY;               
    scanf("%d", &XX);           
    scanf("%d", &YY);                 
    int result = time_angle(XX, YY); 
    printf("%d",result);              
    return 0;                   
}                                                                                                                   
