#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define max 21

typedef struct cars_s{

    char id[max];
    char name[max];
    int price;
    cars_s *next;

}cars_t;


typedef struct producer_s{

    char manuname[max];
    char id[max];
    producer_s *next;
    cars_t *car_head;

}producer_t;


producer_t *read (){

    char buffer[3*max];
    int flag;
    FILE *fpPro=fopen("producer.txt","r");
    FILE *fpCar=fopen("product.txt","r");
    if (fpCar==NULL||fpPro==NULL){
        printf("error in opening\n");
        exit(1);
    }

    producer_t *head=NULL,*tmp,*tmp1,*tmp2;
    cars_t *car=NULL,*tmpcar,*tmpcar1;
    while (fgets(buffer,3*max,fpPro)!=NULL){
        
        tmp=(producer_t*)malloc(sizeof(producer_t));
        if(tmp==NULL){
            printf("error in allocating\n");
            exit(2);
        }
        
        sscanf(buffer,"%s %s",tmp->manuname,tmp->id);
        tmp->next=NULL;
        tmp->car_head=NULL;

        if(head==NULL||strcmp(tmp->manuname,head->manuname)<0){
            tmp->next=head;
            head=tmp;
            
        }else{
            
            tmp1=head;
            tmp2=head->next;
            
            while((tmp2!=NULL) && (strcmp(tmp->manuname,tmp2->manuname)>0)){
                
                tmp1=tmp2;
                tmp2=tmp2->next;

            }

            tmp->next=tmp2;
            tmp1->next=tmp;
            
        }
    }

    while (fgets(buffer,3*max,fpCar)!=NULL){
        
        tmpcar=(cars_t*)malloc(sizeof(cars_t));
        if(tmpcar==NULL){
            printf("error in allocating\n");
            exit(2);
        }

        sscanf(buffer,"%s %s %d",tmpcar->id,tmpcar->name,&tmpcar->price);
        tmpcar->next=NULL;

        tmp1=head;
        while (tmp1->next!=NULL&&strcmp(tmpcar->id,tmp1->id)!=0){
            tmp1=tmp1->next;
        }
        if (tmp1->car_head==NULL){
            tmp1->car_head=tmpcar;       
        }else{
            tmpcar1=tmp1->car_head;
            while (tmpcar1->next!=NULL){
                tmpcar1=tmpcar1->next;
            }
            tmpcar1->next=tmpcar;
            tmpcar->next=NULL;
        }

    }


    
    return head;
}

void print(producer_t *head){

    producer_t *tmp=head;
    cars_t *tmpcar;
    while (tmp!=NULL){
        printf("%s %s\n",tmp->id,tmp->manuname);
        tmpcar=tmp->car_head;
        while (tmpcar!=NULL){
        
            printf("%s %s %d\n",tmpcar->id,tmpcar->name,tmpcar->price);
            tmpcar=tmpcar->next;
        }
        tmp=tmp->next;
    }
    return;
}


int main (){

    producer_t *head;


    head=read();
    print(head);

    return 0;
}