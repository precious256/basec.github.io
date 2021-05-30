int by_high(struct TreeNode*root)

{

    if(root==NULL)

    {

        return 0;

    }

    int high1=by_high(root->left);

    int high2=by_high(root->right);

    return high1>high2?high1+1:high2+1;

}





bool isBalanced(struct TreeNode* root){



    if(root==NULL)

   {

      return true;



   }

   int h1=by_high(root->left);

   int h2=by_high(root->right);

   if(fabs(h1-h2)>1)

   {

       return false;

   }

   return isBalanced(root->left)&&isBalanced(root->right);





}