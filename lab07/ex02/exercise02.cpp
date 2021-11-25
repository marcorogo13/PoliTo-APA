#include <stdio.h>
#include <stdlib.h>
#include <math.h>







int mult(int a, int b){
    int res;
    
    if(b==1){
        return a;
    }

    return(a+mult(a,b-1));
    
}


void d2b(int d,int b[],int *n){

    if(d==0){
        return;
    }

    *b=d%2;
    *n++;
    
    printf("*n=%d",*n);
    
    d2b(d/2,++b,n);

    return;
}


int main(){


int a,b;
int n=0,binary[20];

printf("Enter a,b to multiply:\n");
scanf("%d %d",&a,&b);
printf("%d\n",mult(a,b));

d2b(mult(a,b),binary,&n);
printf("in binary it's:\n");
printf("n=%d",n);

for(int i=0;i<n;i++){
    printf("%d",binary[20-i]);
}
printf("\n");

return 0;
}