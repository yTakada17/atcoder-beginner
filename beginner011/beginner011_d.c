#include<stdio.h>
#include<stdlib.h>

int abs(int x){
    if(x<0){
        x=-x;
        }
        return x;
}

void convert(int *x,int *y){
int tmp=(*y-*x)/2;
*x=(*x+*y)/2;
*y=tmp;
return;
}

double shia(double x, double y,int n){
    int i,back=n;
    double riz=1.0;

    for(i=0;i<back/2-x;i++){
        riz=riz*(back-i)/i+1;
        for(;riz>1&&n>0;n--){
            riz/=4.0;
        }
    }

    for(i=0;i<back/2-y;i++){
        riz=riz*(back-i)/(i+1);

        for(;riz>1&&n>0;n--){
            riz/=4.0;
        }
    }
    for(;n>0;n--){
        riz/=4.0;
    }
    return riz;
}


int main(){
    int n,d;
    int x,y,tmp;

    scanf("%d %d",&n,&d);
    scanf("%d %d",&x,&y);

    if(x%d!=0||y%d!=0){
        printf("0.0");
        return 0;
    }
    x=abs(x/d);
    y=abs(y/d);

    if(x+y>n||(x+y)%2!=n%2){
        printf("0.0");
        return 0;
    }

    if(y<x){
        tmp=x;
        x=y;
        y=tmp;
    }

    if(n%2==1){
        y--;
    }
    convert(&x,&y);
    printf("%.10f",shia(x,y,n));
    return 0;
}
