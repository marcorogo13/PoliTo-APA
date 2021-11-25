#include <stdio.h>


void triangle(int n,int i,int j){
    
    if(i>n){
        return;
    }
    if(j>i){
        
        printf("\n");
        triangle(n,++i,0);
        return; 
    }
    
    printf("%d",i);
    triangle(n,i,++j);
    
    return;
}


int main (){
    int n;
    printf("enter size of triangle:\n");
    scanf("%d",&n);

    triangle(n,1,1);

    return 0;
}