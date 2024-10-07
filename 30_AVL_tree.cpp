#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

void preorder(struct node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
int max(int a, int b)
{
    return a > b ? a : b;
}
int getheight(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}
struct node *createnode(int key)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}
int getBalancefactor(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getheight(n->left) - getheight(n->right);
}

struct node *rightrotate(struct node *y)
{
    struct node *x = y->left;
    struct node *t2 = x->right;

    x->right = y;
    y->left = t2;

    x->height = max(getheight(x->left), getheight(x->right)) + 1;
    y->height = max(getheight(y->left), getheight(y->right)) + 1;
    return x;
}

struct node *leftrotate(struct node *x)
{
    struct node *y = x->right;
    struct node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(getheight(x->left), getheight(x->right)) + 1;
    y->height = max(getheight(y->left), getheight(y->right)) + 1;
    return y;
}
struct node *insert(struct node *node, int key)
{
    if (node == NULL)
    {
        return createnode(key);
    }

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    
    node->height = 1 + max(getheight(node->left), getheight(node->right));
    int bf = getBalancefactor(node);

    // Left- left case
    if (bf > 1 && key < node->left->data)
    {
        return rightrotate(node);
    }
    // Right - right case
    if (bf < -1 && key > node->right->data)
    {
        return leftrotate(node);
    }
    // Left - Right case
    if (bf > 1 && key > node->left->data)
    {
        node->left = leftrotate(node ->left);
        return rightrotate(node);
    }
    //Right -left case
    if(bf < -1 && key < node ->right->data)
    {
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }
    return node;
}

int main()
{
    struct node *root=NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,6);
    root=insert(root,3);
    preorder(root);
    return 0;
}