#include <stdio.h>
#include <stdlib.h>

int key[20],n,m;
int *ht,ind;
int count=0;

void insert(int key){
    ind=key%m;
    while(ht[ind]!=-1){
        ind=(ind+1)%m;
    }
    ht[ind]=key;
    count++;
}
void display(){
    int i;
    if(count==0){
        printf("\n Hash table is empty");
        return;
    }
    printf("\n Hash table contents are:\n");
    for(i=0;i<m;i++){
        printf("T[%d]->%d\n",i,ht[i]);
    }
}
int main(){
    int i;
    printf("NAME:Bhavana K S\nUSN:1BM24CS070");
    printf("\nEnter the number of employee records(N):");
    scanf("%d",&n);
    printf("\nEnter the two digit memory locations(m) for hash table:");
    scanf("%d",&m);
    ht=(int*)malloc(m*sizeof(int));
    for(i=0;i<m;i++){
        ht[i]=-1;
    }
    printf("\nEnter the four digit key values(K) for N Employee Records:\n");
    for(i=0;i<n;i++){
        scanf("%d",&key[i]);
    }
    for(i=0;i<n;i++){
        if(count==m){
            printf("\n Hash table is full. Cannot insert record %d",i+1);
            break;
        }
        insert(key[i]);
    }
    display();
    free(ht);
    return 0;
}
