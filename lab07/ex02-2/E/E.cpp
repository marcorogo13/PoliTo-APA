#include <stdio.h>
#include <string.h>

int ispalindrome (char *s,int l){

    if (l==1||l==0){
        return 1;
    }
    if (s[0]==s[l-1]){
        ispalindrome(&s[1],l-2);
    }else{
        return 0;
    }
}


int main(){

    char *str="mannam";

    printf("%d",ispalindrome(str,strlen(str)));


    return 0;
}