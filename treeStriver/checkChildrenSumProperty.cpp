 int isSumProperty(Node *root)
    {
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return 1;
        int left_val = root->left == NULL ? 0 : root->left->data;
        int right_val = root->right == NULL ? 0 : root->right->data;
        return root->data == (left_val + right_val) && isSumProperty(root->left) && isSumProperty(root->right);
    }

    Convertyt
    void reorder(node * root) {
  if (root == NULL) return;
  int child = 0;
  if (root -> left) {
    child += root -> left -> data;
  }
  if (root -> right) {
    child += root -> right -> data;
  }

  if (child < root -> data) {
    if (root -> left) root -> left -> data = root -> data;
    else if (root -> right) root -> right -> data = root -> data;
  }

  reorder(root -> left);
  reorder(root -> right);

  int tot = 0;
  if (root -> left) tot += root -> left -> data;
  if (root -> right) tot += root -> right -> data;
  if (root -> left || root -> right) root -> data = tot;
}