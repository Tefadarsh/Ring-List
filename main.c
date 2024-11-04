#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *pRight;
    struct Node *pLeft;
}*pStart=NULL;
struct Node* creatNode(int);
void add(int);
void printList();
void freeList();
int getDataFromIndex(int);
int getndexFromData(int);
void insert(int,int);
int count();
int main()
{
    add(5);
    add(8);
    add(9);
    add(10);
    add(11);
//
//    printf("%d",getndexFromData(16));

    insert(6,5);
    printList();
    //printf("%d",getDataFromIndex(2));
    //printList();


    return 0;
}


struct Node* creatNode(int data){
   struct Node*pNode =(struct Node*)malloc(sizeof(struct Node));
   if(pNode!=NULL){
       pNode->data=data;
       pNode->pRight=NULL;
       pNode->pLeft=NULL;

   }
    return pNode;
}


void add(int data){
   struct Node*pNode=creatNode(data);
   if(pNode){
        if(pStart==NULL){
            pStart=pNode;
        }
        else{
            if(pStart->pRight==NULL){
                pStart->pRight=pNode;
                pStart->pLeft=pNode;
                pNode->pRight=pStart;
                pNode->pLeft=pStart;
            }
            else{
                pStart->pLeft->pRight=pNode;
                pNode->pLeft= pStart->pLeft;
                pNode->pRight=pStart;

            }
        }

   }
}

void printList(){
    struct Node*current=pHead;
    while(current!=NULL){
        printf("%d",current->data);
        current=current->pRight;
    }
    printf("\n");
}

void freeList(){
    struct Node*current=pHead;
    while(current!=NULL){
        struct Node*next=current->pRight;
        free(current);
        current=next;
    }
    pHead=NULL;
    pEnd=NULL;
}


int getDataFromIndex(int index){
    struct Node*current=pHead;
    if(current!=NULL){
        for(int i=0;i<index;i++){
                current=current->pRight;

        }
        return current->data;
    }
    else{
        return -1;
    }

}

int count(){
    struct Node*current=pHead;
    if(current!=NULL){
        int count=0;
        while(current!=NULL){
            current=current->pRight;
            count++;
        }
        return count;
    }
    else{
        return -1;
    }
}


int getndexFromData(int data){
    struct Node*current=pHead;
    if(current!=NULL){
            int index=0;
            while(current!=NULL){
                if(data==current->data){
                    return index;
                }
                else{
                   current=current->pRight;
                   index++;

                }
            }
            return -1; //data not in the list



    }
    else{
        printf("List is Empty");
        return -1;
    }

}

void insert(int data,int index){
    int numNodes=count();
    if(index<0 || index>numNodes){
         printf("Index does not belong to the List\n");
    }
    struct Node*pNode=creatNode(data);
    if(pNode==NULL){
        return;
    }

    if(index==0){
        if(pHead==NULL){
            pHead=pNode;
            pEnd=pNode;
        }
        else{
            pHead->pLeft=pNode;
            pNode->pRight=pHead;
            pHead=pNode;
        }

    }
    else if(index==numNodes){
            pEnd->pRight=pNode;
            pNode->pLeft=pEnd;
            pEnd=pNode;
    }
    else{
        struct Node*current=pHead;
        for(int i=0;i<index;i++){
            current=current->pRight;

        }
        pNode->pRight = current;
        pNode->pLeft = current->pLeft;
        if(current->pLeft!=NULL){

           current->pLeft->pRight=pNode;
        }
        current->pLeft=pNode;

    }


}
