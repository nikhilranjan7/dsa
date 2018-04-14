#include "tree.h"

tree createTree(int v)
{
  tree t = (tree)malloc(sizeof(struct tree_node));
  t->value = v;
  t->left = NULL;
  t->right = NULL;
  t->height = 0;

  return t;
}



tree add(tree root, tree t, int v)
{
    tree a = t;
    tree x, y, z;
    if(t->value > v)
    {
      if(t->left == NULL)
      {
        t->left = createTree(v);

        y = t;
        x = t->left;
        z = return_parent(root,y);
        if(z->value != y->value)
        {
          if(getBalance(z) > 1 || getBalance(z) < -1)
            {printf("\n\nInsideL\n\n");
            root = rotate(root, x, y, z);}
        }
      }
      else
        t = add(root, t->left, v);
    }
    else
    {
      if(t->right == NULL)
      {
        t->right = createTree(v);

        y = t;
        x = t->right;
        z = return_parent(root,y);
        printf("X= %d Y=%d Z=%d\n", x->value, y->value, z->value);
        if(z->value != y->value)
        {
          if(getBalance(z) > 1 || getBalance(z) < -1)
            {printf("\n\nInsideR & Point of imbalance is %d\n\n",z->value);
            print2D(z);
            root = rotate(root, x, y, z);}
        }
      }
      else
        t = add(root, t->right, v);
    }

    return root;
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
    t->height = height(t);
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

tree rotate(tree root, tree X, tree Y, tree Z)
{
    tree a, b, c, T0, T1, T2, T3;
    if(Z->left == Y)
	  {
  		if(Y->left == X) // X=a, Y=b, Z=c
  		{
  			a = X;
  			b = Y;
  			c = Z;
  			T0 = X->left;
  			T1 = X->right;
  			T2 = Y->right;
  			T3 = Z->right;

  		}
  		else // X=b, Y=a, Z=c
  		{
  			a = Y;
  			b = X;
  			c = Z;
  			T0 = Y->left;
  			T1 = X->left;
  			T2 = X->right;
  			T3 = Z->right;
  		}
	  }
	else
	{
		if(Y->right == X) // X=c, Y=b, Z=a
		{
			a = Z;
			b = Y;
			c = X;
			T0 = Z->left;
			T1 = Y->left;
			T2 = X->left;
			T3 = X->right;
		}
		else // X=b, Y=c, Z=a
		{
			a = Z;
			b = X;
			c = Y;
			T0 = Z->left;
			T1 = X->left;
			T2 = X->right;
			T3 = Y->right;
		}
	}

  tree p = return_parent(root,Z);
  if(p->value == Z->value)
  {
    root = b;
  }
  else
  {
    if(p->left == Z)  p->left = b;
    else  p->right = b;
  }
  b->left = a;
  a->left = T0;
  a->right = T1;
  b->right = c;
  c->left = T2;
  c->right = T3;

  return root;
}

int height(tree root)
{
  if (root==NULL)
       return 0;
   else
   {
       /* compute the depth of each subtree */
       int lDepth = height(root->left);
       int rDepth = height(root->right);

       /* use the larger one */
       if (lDepth > rDepth)
           return(lDepth+1);
       else return(rDepth+1);
   }
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

int getBalance(tree t)
{
    return(height(t->right)-height(t->left));
}
