#include <stdio.h>
#include <stdlib.h>
#include <math.h>



void gray(int **matrix,int n,int i){

    int a,b,j,k;
    
    if(i==2){
        matrix[1][n-1]=1;
        return;
    }

    i=i/2;
    gray(matrix,n,i);
    

    for(a=0;a<i;a++){
        for(b=n-1;b>=(n-(int)log2((float)i));b--){
           matrix[i+a][b]=matrix[i-a-1][b];
        }
    }

    for(j=i;j<2*i;j++){
        
        matrix[j][n-(int)log2((float)i)-1]=1;
    
    }

    for(k=0;k<(int)pow((float)2,(float)n);k++){
        for(j=0;j<n;j++){
            printf("%d ",matrix[k][j]);
        }
        printf("\n");
    }
    printf("\n");printf("\n");
    
    return;

}








int main (){

    int n,i,j;
    int **matrix;
    printf("enter n:\n");
    scanf("%d",&n);

    
    
    matrix=(int**)malloc((int)pow((float)2,(float)n)*sizeof(int**));
    if (matrix==NULL){
        printf("error in allocating matrix**\n");
        exit (2);
    }
    for (i=0;i<(int)pow((float)2,(float)n);i++){
        matrix[i]=(int*)malloc(n*sizeof(int));
        if(matrix[i]==NULL){
            printf("error in allocating matrix*\n");
        }
        for(j=0;j<n;j++){
            matrix[i][j]=0;
        }


    }


    gray (matrix,n,(int)pow((float)2,(float)n));


    for(i=0;i<(int)pow((float)2,(float)n);i++){
        for(j=0;j<n;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
