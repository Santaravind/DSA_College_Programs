#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct BST {
    int key;
    struct BST *left,*right,*parent;

};
struct BST *root=NULL;

void insert();
void InOrderDisplay(struct BST *);
int main(){
    int x;
    while(1){
    printf(" \nEnter 1 to Add element in BST \nEnter 2 inorder traversal from BST\nEnter 4 for exit :-\nEnter value want to perform with queue:  ");
    scanf("%d",&x);
    
       switch(x){
       case 1:
        insert();
       break;
      case 2:
      InOrderDisplay(root);
       break;

       case 4:
       exit(0);
       break;

       default:
       printf("Enter valid  option\n");
       continue;

        }
    }

    return 0;
}

void insert(){
    struct BST *q,*y,*x=NULL;
    q=(struct BST *)malloc(sizeof(struct BST));
    printf("Enter the key value :\t ");
    scanf("%d",&q->key);
    q->left=NULL;
    q->right=NULL;
      y=root;
      while(y!=NULL){
        x=y;
        if(q->key<=y->key){
            y=y->left;
        }else{
            y=y->right;
        }
      }
      if(x==NULL){
        root=q;
        q->parent=NULL;
      }else{
        q->parent=x;
         if(q->key<=x->key){
            x->left=q;
         }else{
            x->right=q;
         }
      }


}

  void InOrderDisplay(struct BST *root){
    // struct BST *p;
    // p=root;
    // if(p==NULL){
    //     printf("BST not exixt\t");
    //     return;
    // }
     if(root!=NULL){
        InOrderDisplay(root->left);
        printf("%d ", root->key);
        InOrderDisplay(root->right);

     }

}