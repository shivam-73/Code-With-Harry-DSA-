#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int isBST(struct node *root)
{   
    static struct node * prev=NULL;
    if (root != NULL)
    {

        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}
    int main()
    { /*
      struct node *p;
      p=(struct node *)malloc(sizeof(struct node));
      p->data=2;
      p->left=NULL;
      p->right=NULL;

      struct node *p1;
      p1=(struct node *)malloc(sizeof(struct node));
      p1->data=1;
      p1->left=NULL;
      p1->right=NULL;

      struct node *p2;
      p2=(struct node *)malloc(sizeof(struct node));
      p2->data=4;
      p2->left=NULL;
      p2->right=NULL;

      p->left=p1;
      p->right=p2;
      */
        struct node *p = createnode(5);
        struct node *p1 = createnode(3);
        struct node *p2 = createnode(6);
        struct node *p3 = createnode(1);
        struct node *p4 = createnode(4);
        // LInking the node
        p->left = p1;
        p->right = p2;
        p1->left = p3;
        p1->right = p4;
        // preorder(p);
        // cout<<endl;
        // postorder(p);
        // cout<<endl;
        inorder(p);
        cout<<endl;
        cout<<isBST(p);
        return 0;
    }