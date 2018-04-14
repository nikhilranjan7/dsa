#include "tree.h"

tree createTree(int v)
{
  tree t = (tree)malloc(sizeof(struct tree_node));
  t->value = v;
  t->left = NULL;
  t->right = NULL;
  t->h_info = 0;

  return t;
}



tree add(tree t, int v)
{
    tree a = t;
    if(t->value > v)
    {
      if(t->left == NULL)
        t->left = createTree(v);
      else
        t = add(t->left, v);
    }
    else
    {
      if(t->right == NULL)
        t->right = createTree(v);
      else
        t = add(t->right, v);
    }

    return a;
}

tree find(tree t, int v)
{
  if (t == NULL)
    return NULL;
  if (t->value == v)
    return t;
  else
  {
    if(t->value > v)
      return find(t->left, v);
    else
      return find(t->right, v);
  }
}

tree deleteNode(tree root, int key)
{
    // base case
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->value)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->value)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            tree temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            tree temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        tree temp = minValue(root->right);

        // Copy the inorder successor's content to this node
        root->value = temp->value;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}

void print_dfs(tree t)
{
  int i = 0;
  if (t != NULL)
  {
    print_dfs(t->left);
    printf("%d->",t->value);
    print_dfs(t->right);
  }
}

int isleaf(tree t)
{
  if (t->left == NULL && t->right == NULL) return 0;
  if (t->left != NULL && t->right == NULL) return -1;
  if (t->left == NULL && t->right != NULL) return 1;
  return 2;
}

tree return_parent(tree root, tree child)
{
  tree a = root;
  if(a == child) return a;
  if (a != NULL)
  {
    if (a->left == child || a->right == child) return a;
    // if(a->left != NULL && a->left->value == child->value) return a;
    // if(a->right != NULL && a->right->value == child->value) return a;
    if(a->value > child->value) return return_parent(a->left, child);
    if(a->value <= child->value) return return_parent(a->right, child);
  }
  return NULL;
}

tree inOrderSuccessor(tree root, tree n)
{
  // step 1 of the above algorithm
  if( n->right != NULL )
    return minValue(n->right);

  // step 2 of the above algorithm
  tree p = return_parent(root, n);
  while(p != NULL && n == p->right)
  {
     n = p;
     p = return_parent(root, p);
  }
  return p;
}

/* Given a non-empty binary search tree, return the minimum data
    value found in that tree. Note that the entire tree does not need
    to be searched. */
tree minValue(tree node) {
  tree current = node;

  /* loop down to find the leftmost leaf */
  while (current->left != NULL) {
    current = current->left;
  }
  return current;
}

void print2DUtil(Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->value);

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(Node *root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}
