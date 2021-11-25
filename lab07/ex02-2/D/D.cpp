#include <stdio.h>
#include <ctype.h>



int countspaces(char *s){
    int n;

    if(s[0]=='\0'){
        return 1;
    }
    if(isspace(s[0])!=0){
        return (1+countspaces(&s[1]));
        
    }else{
        return countspaces(&s[1]);
    }
}



int main(){

    char *str="   ";
    printf("%d",countspaces(str));
    return 0;

}