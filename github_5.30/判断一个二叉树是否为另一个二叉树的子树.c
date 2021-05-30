bool compare (struct TreeNode* p1,struct TreeNode* p2)

{

    if(!p1&&!p2) return true;

    if(!p1||!p2) return false;

    if(p1->val!=p2->val) return false;

    return compare(p1->left,p2->left)&&compare(p1->right,p2->right);

}

bool isSubtree(struct TreeNode* s, struct TreeNode* t){

    if(!s) return false;

    return compare(s,t)||isSubtree(s->left,t)||isSubtree(s->right,t);

}