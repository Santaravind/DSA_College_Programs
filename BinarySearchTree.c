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
void preOrderDisplay(struct BST *);
void postOrderDisplay(struct BST *);
struct BST *tree_Search(struct BST *, int);
int main(){
    int x;
    while(1){
    printf(" \nEnter 1 to Add element in BST \nEnter 2 inorder traversal from BST\nEnter 3 For pre order travesel\nEnter 4 for post order traversel\nEnter 6 for exit :-\nEnter value want to perform with queue:  ");
    scanf("%d",&x);
    
       switch(x){
       case 1:
        insert();
       break;
      case 2:
      printf("In order traversal:\t");
      InOrderDisplay(root);
       break;
      case 3:
      printf("Pre order traversal:\t");
      preOrderDisplay(root);
       break;
      case 4:
      printf("Post order traversal:\t");
      postOrderDisplay(root);
       break;

       case 6:
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
    // printf("Inorder traversal:\t");
     if(root!=NULL){
        InOrderDisplay(root->left);
        printf("%d ", root->key);
        InOrderDisplay(root->right);

     }

}
  void preOrderDisplay(struct BST *root){
    // struct BST *p;
    // p=root;
    // if(p==NULL){
    //     printf("BST not exixt\t");
    //     return;
    // }
    // printf("Pre order traversal:\t");
     if(root!=NULL){
      printf("%d ", root->key);
        InOrderDisplay(root->left);       
        InOrderDisplay(root->right);

     }

}
  void postOrderDisplay(struct BST *root){
    // struct BST *p;
    // p=root;
    // if(p==NULL){
    //     printf("BST not exixt\t");
    //     return;
    // }
  
     if(root!=NULL){
        InOrderDisplay(root->left);       
        InOrderDisplay(root->right);
        printf("%d ", root->key);
     }

}