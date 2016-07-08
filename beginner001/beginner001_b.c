#include <stdio.h>

int main()
{
    int m=0;
    scanf("%d",&m);
    
    if(m<100){
        printf("00\n");
    }
    else if(100<=m&&m<=5*1000){
        if(1000<=m){
            printf("%d\n",(m*10)/1000);
        }
        else{
            printf("0%d\n",m/100);
        }
    }
    else if(6*1000<=m&&m<=30*1000){
        printf("%d\n",(m+50*1000)/1000);
    }
    else if(35*1000<=m&&m<=70*1000){
        printf("%d\n",(((m-30*1000)/5)+80*1000)/1000);
    }
    else if(70*1000<m){
        printf("89\n");
    }
    return 0;
}

