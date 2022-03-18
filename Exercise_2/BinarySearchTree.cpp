#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* createNode (int input){
    Node* temp = new Node;
    temp -> data = input;
    temp -> left = temp -> right = NULL;
    return temp;
}

struct Node* insert (struct Node* node, int key){
    if (node == NULL)
    return createNode (key);
    
    if (key < node->data)
    node -> left = insert (node -> left, key);
    else node -> right = insert (node -> right, key);
    return node;
}
bool ifNodeExists(struct Node* node, int key)
{
    if (node == NULL)
        return false;
 
    if (node->data == key)
        return true;
 
    /* then recur on left subtree */
    bool res1 = ifNodeExists(node->left, key);
    // node found, no need to look further
    if(res1) return true;
 
    /* node is not found in left,
    so recur on right subtree */
    bool res2 = ifNodeExists(node->right, key);
 
    return res2;
}

int FindMin(Node* root)
{
    while(root->left!=NULL)
        root=root->left; //go to the left until minimum value
    return root->data;
}
struct Node* Delete(struct Node *root, int data)
{
    if(root==NULL) return root; //empty tree
    else if(data<root->data)
        root->left=Delete(root->left,data);
    else if(data>root->data)
        root->right=Delete(root->right,data);
    else
    {
        //C1: No child
        if(root->left==NULL&&root->right==NULL)
            {
            delete root;
            root=NULL;
            return root;
            }

        //C2: 1 child
        else if(root->left==NULL)
        {
            struct Node *temp=root;
            root=root->right; //make right child new root of subtree
            delete temp;
        }
        else if(root->right==NULL)
        {
            struct Node *temp=root;
            root=root->left; //make left child new root of subtree
            delete temp;
        }

        //C3: 2 children
        else
        {
            int temp= FindMin(root->right); //start from right child of root
            root->data=temp;
            root->right=Delete(root->right,temp);
        }
    }
    return root;
};
int main() {
    Node* root = NULL;
    root = insert (root, 13);
    root = insert (root, 6);
    root = insert (root, 15);
    root = insert (root, 17);
    root = insert (root, 20);
    root = insert (root, 9);
    root = insert (root, 4);
    root = insert (root, 3);
    root = insert (root, 7);
    root = insert (root, 2);
    return 0;
}
