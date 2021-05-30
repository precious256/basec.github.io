#include<stdio.h>

#include<stdlib.h>

#include<stdbool.h>

typedef char datatype;

struct Binarytree

{

  datatype val;

  struct Binarytree *left;

  struct Binarytree*right;

};

struct Binarytree*my_malloc(datatype val)

{

  struct Binarytree*newnode=(struct Binarytree*)malloc(sizeof(struct Binarytree));

  if(newnode==NULL)

  {

    return NULL;

  }

  newnode->left=newnode->right=NULL;

  newnode->val=val;

  return newnode;

}



struct Binarytree*create(const char str[],int size,int *index)

{

  struct Binarytree*root=NULL;

  if(str[*index]!='#'&&str[*index]!='\0')

  {

    root=my_malloc(str[*index]);

    (*index)++;

    root->left=create(str,size,index);

    (*index)++;

    root->right=create(str,size,index);

  }

  return root;

}

void inorder(struct Binarytree*root)

{

  if(root==NULL)

  {

    return;

  }

  inorder(root->left);

  printf("%c ",root->val);

  inorder(root->right);

}











void destory(struct Binarytree* root)

{

if (root == NULL)

{

return;

}

destory(root->left);

destory(root->right);

free(root);

}



int main()

{

  char s[100];

  int index=0;

  while(scanf("%s",&s)!=EOF)

  {

    struct Binarytree*root= create(s,strlen(s),&index);

    if(root==NULL)

    {

      continue;

    }

    inorder(root);

    destory(root);

  }

  return 0;

}