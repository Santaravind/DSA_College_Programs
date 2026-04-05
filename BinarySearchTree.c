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
struct BST *tree_Min(struct BST *);
struct BST *tree_Max(struct BST *);
// struct BST *tree_Successor(struct BST *);
int main(){
    int x;
     struct BST *info; 
     int data;
    while(1){
    printf(" \nEnter 1 to Add element in BST \nEnter 2 inorder traversal from BST\nEnter 3 For pre order travesel\nEnter 4 for post order traversel\nEnter 5 if you want to search any value \nEnter 6 for find min value in BST\nEnter 7 to find max value in BST\nEnter 10 for exit :-\nEnter value want to perform with queue:  ");
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
       case 5 :
       printf("Enter value that you want to search");
       scanf("%d",&data);
         info=tree_Search(root,data);
         if(info!=NULL){
          printf("Value is found =%d",info->key);
         }else{
          printf("Element is not found !!");
         }
        break;
       case 6 :
      
         info=tree_Min(root);
         if(info!=NULL){
          printf("The min value is = %d",info->key);
         }
        break;
       case 7 :
       
         info=tree_Max(root);
         if(info!=NULL){
          printf(" The max value is= %d",info->key);
         }
        break;
       case 10:
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
   
    // printf("Pre order traversal:\t");
     if(root!=NULL){
      printf("%d ", root->key);
        InOrderDisplay(root->left);       
        InOrderDisplay(root->right);

     }

}
  void postOrderDisplay(struct BST *root){
      
     if(root!=NULL){
        InOrderDisplay(root->left);       
        InOrderDisplay(root->right);
        printf("%d ", root->key);
     }

}

//Binary Search Tree , Searching program 
struct BST * tree_Search(struct BST *root, int data){
          
     if((root==NULL)||(root->key==data)){
      return root;
     }

     if(data<=root->key){
      return tree_Search(root->left,data);
     }else{
      return tree_Search(root->right,data);
     }
  
}

struct BST *tree_Min(struct BST *p){
  
      while(p->left!=NULL){
         p=p->left;
      }

      return p;

}
struct BST *tree_Max(struct BST *p){
  
      while(p->right!=NULL){
         p=p->right;
      }

      return p;

}