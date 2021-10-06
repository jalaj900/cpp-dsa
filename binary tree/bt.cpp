//max depth
//check balanced bt
//diameter of bt

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;

    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// maximun depth of  binary tree
//t(n)=O(n)

int max_depth(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = max_depth(root->left);
    int rh = max_depth(root->right);

    return 1 + max(lh, rh); // +1 to add the count of the root where the pointer is
}

//balanced binary tree

int depth(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = depth(root->left);

    if (lh == -1)
    {
        return -1;
    }

    int rh = depth(root->right);

    if (rh == -1)
    {
        return -1;
    }

    if (abs(lh - rh) > 1) //if the diff of lh and rh of node below is > 1 then it return -1
    {
        return -1;
    }

    return max(lh, rh) + 1;
}

bool bbt(node *root) // function to check balance
{
    return depth(root) != -1; //returns -1 if the tree is not balanced and if balanced returns its height
}


