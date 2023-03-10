/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct node_t{
    char *data;
    struct node_t *next;
}Node;

Node *yolcu_ekle(char*,Node*);
void yolcu_listele(Node*);

void yolcu_listele(Node *head){
    Node *current_node=head;
    while(current_node!=NULL){
        printf("%s",current_node->data);
        current_node=current_node->next;
    }
}

Node *yolcu_ekle(char *info,Node *head){
    Node *current_node=head;
    Node *new_node;
    
    while(current_node!=NULL&&current_node->next!=NULL){
        current_node=current_node->next;
    }
    
    new_node=(Node*)malloc(sizeof(Node));
    
    new_node->data=malloc(strlen(info)+1);
    
    strcpy(new_node->data,info);
    new_node->next=NULL;
    
    if(current_node!=NULL)
    current_node->next=new_node;
    else
    head=new_node;
        return head;
}

int main()
{
    Node *otobus=NULL;
    
    int i,j;
    
    char buf1[1024];
    char buf2[1024];
    
    char name[1024];
    
    for(i=1;i<=7;++i){
        sprintf(buf1,"---------- %d nolu otobus ---------- \n",i);
        otobus=yolcu_ekle(buf1,otobus);
        for(j=1;j<=7;++j){
            printf("\n%d. otobus icin %d. koltuk numarasına sahip yolcu bilgileri: ",i,j);
            scanf("%s",name);
            
            sprintf(buf2,"%d nolu yolcu - Adi %s \n",j,name);
            otobus=yolcu_ekle(buf2,otobus);
        }
    }
    
    printf("\n Otobusler ve yolcu bilgileri: \n");
    yolcu_listele(otobus);
    return 0;
}
