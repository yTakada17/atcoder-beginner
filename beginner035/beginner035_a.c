#include<stdio.h>

int main(){
int w,h;
int i;
scanf("%d %d",&w,&h);
while(1){
if(w%16==0 && h%9==0){
printf("16:9\n");
break;
}
else if(w%4==0 && h%3==0){
printf("4:3\n");
break;
}

i++;
}
return 0;
}
