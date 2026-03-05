#include <stdio.h>
#include <stdlib.h>
struct BST{
  int data;
  struct BST *lchild, *rchild;
};
typedef struct BST *node;

node create(){
  node temp =(node)malloc(sizeof(struct BST));
  printf("Enter the value: ");
  scanf("%d", &temp->data);
  temp->rchild = NULL;
  temp->lchild = NULL;
  return temp;
}

void insert(node root, node newnode){
  if(newnode->data < root->data){
    if(root->lchild==NULL)
      root->lchild = newnode;
    else
      insert(root->lchild, newnode);
  }
  else if(newnode->data > root->data){
    if(root->rchild==NULL)
      root->rchild = newnode;
    else
      insert(root->rchild, newnode);
  }
}

void search(node root){
  int key;
  node cur;
  if(root==NULL){
    printf("BST is Empty");
    return;
  }
  printf("Enter element to be searched: ");
  scanf("%d", &key);
  cur = root;
  while(cur!=NULL){
    if(cur->data==key){
      printf("Key is found in the BST");
      return;
    }
    else if(key< cur->data)
      cur = cur->lchild;
    else
      cur = cur->rchild;
  }
  printf("Element is not found in the BST");
}

void inorder(node root){
  if(root!=NULL){
    inorder(root->lchild);
    printf("%d ", root->data);
    inorder(root->rchild);
  }
}

void preorder(node root){
  if(root!=NULL){
    printf("%d ", root->data);
    preorder(root->lchild);
    preorder(root->rchild);
  }
}

void postorder(node root){
  if(root!=NULL){
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ", root->data);
  }
}

node findMin(node root){
    while(root->lchild != NULL)
        root = root->lchild;
    return root;
}

node deleteNode(node root, int key){
    if(root == NULL){
        printf("Element not found\n");
        return root;
    }

    if(key < root->data)
        root->lchild = deleteNode(root->lchild, key);

    else if(key > root->data)
        root->rchild = deleteNode(root->rchild, key);

    else{
        // Case 1: No child
        if(root->lchild == NULL && root->rchild == NULL){
            free(root);
            return NULL;
        }

        // Case 2: One child
        else if(root->lchild == NULL){
            node temp = root->rchild;
            free(root);
            return temp;
        }

        else if(root->rchild == NULL){
            node temp = root->lchild;
            free(root);
            return temp;
        }

        // Case 3: Two children
        node temp = findMin(root->rchild);
        root->data = temp->data;
        root->rchild = deleteNode(root->rchild, temp->data);
    }

    return root;
}

int main(){
  int ch, val, n;
  node root = NULL, newnode;
  printf("\n\nBST MENU\n\n1.Create a BST\n2.BST Traversal\n3.BST Search\n4.BST Deletion\n5.Exit\n\n");
  while(1){
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    switch(ch){
      case 1:
              printf("Enter number of elements you want to insert: ");
              scanf("%d", &n);
              for(int i=0;i<n;i++){
                newnode = create();
                if(root==NULL)
                  root = newnode;
                else{
                  insert(root, newnode);
                }
              }
              break;
      case 2:
        if(root==NULL)
          printf("BST is Empty");
        else{
          printf("\n\nPostorder: ");
          postorder(root);
          printf("\n\nPreorder: ");
          preorder(root);
          printf("\n\nInorder: ");
          inorder(root);
        }
        break;
      case 3:
        search(root);
        break;
      case 4:
        int key;
        if(root == NULL){
            printf("BST is Empty");
            break;
        }
        printf("Enter element to delete: ");
        scanf("%d", &key);
        root = deleteNode(root, key);
        break;
      case 5:
        printf("Exiting...");
        exit(0);
      default: printf("Invalid Choice");
    }
  }
}
