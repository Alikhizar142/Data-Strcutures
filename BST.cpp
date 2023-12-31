#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    };
};

class BST
{
private:
    Node *Root;

public:
    BST()
    {
        Root = NULL;
    }
    Node *insert(Node *curr, int val)
    {
        if (curr == NULL)
        {
            curr = new Node(val);
            return curr;
        }
        else if (val < curr->data)
        {
            curr->left = insert(curr->left, val);
            return curr;
        }
        else if (val > curr->data)
        {
            curr->right = insert(curr->right, val);
            return curr;
        }
        else
            return curr;
    }

    void set_root(Node *Curr)
    {
        Root = Curr;
    }
    Node *find(Node *curr, int val)
    {
        if (curr == NULL)
        {
            return NULL;
        }
        if (curr->data == val)
        {
            return curr;
        }

        if (val > curr->data)
        {
            return find(curr->right, val);
        }
        else if (val < curr->data)
        {
            return find(curr->left, val);
        }
    }

    void inorder(Node *curr)
    {
        if(curr==NULL)
        {
            return;
        }
        inorder(curr->left);
        cout<<curr->data<<" ";
        inorder(curr->right);
    }

    void preorder(Node *curr)
    {
        if(curr==NULL)
        {
            return;
        }
        cout<<curr->data<<" ";
        preorder(curr->left);
        preorder(curr->right);
    }

    void postorder(Node *curr)
    {
        if(curr==NULL)
        {
            return;
        }
        postorder(curr->left);
        postorder(curr->right);
        cout<<curr->data<<" ";
    }

    Node*Parent(Node *curr,Node*p,Node*par)
    {
        if(curr==NULL)
        {
            return NULL;
        }
    
    if(curr==p)
    {
        return par;
    }
    else
    {
        Node *temp=NULL;
        temp=Parent(curr->left,p,curr);
        if(temp!=NULL)
        {
            return temp;
        }
        else{
            temp=Parent(curr->right,p,curr);
            return temp;
        }
    }
    }

    Node* get_root()
    {
        return Root;
    }
    Node *minValueNode(Node *n)
    {
        Node *current = n;

        while (current->left != NULL)
            current = current->left;

        return current;
    }
     Node *deleteNode(Node *root, int key)
    {

        if (root == NULL)
            return root;

        if (key < root->data)
            root->left = deleteNode(root->left, key);

        else if (key > root->data)
            root->right = deleteNode(root->right, key);

        else
        {
            if ((root->left == NULL) || (root->right == NULL))
            {
                Node *temp = NULL;
                if (root->left)
                {
                    temp = root->left;
                }
                else
                    temp = root->right;

                if (temp == NULL)
                {
                    temp = root;
                    root = NULL;
                }
                else
                    *root = *temp;
                delete temp;
            }
            else
            {
                Node *temp = minValueNode(root->right);

                root->data = temp->data;

                root->right = deleteNode(root->right, temp->data);
            }
        }
        if (root == NULL)
            return root;
    }


    Node *findmax(Node*curr)
    {
        if(curr->right!=NULL)
        {
            findmax(curr->right);
        }
        else
        return curr;
    }

    Node *findmin(Node*curr)
    {
        if(curr->left!=NULL)
        {
            findmin(curr->left);
        }
        else
        return curr;
    }

    void  convert(Node *n,vector<int>& v)
    {
        if(n == NULL)
        {
            return;
        }
        v.push_back(n->data);
        convert(n->left,v);
        convert(n->right,v);
    }
    
};

bool check(vector<int>a,int k)
{
    for(int i=0;i<a.size();i++)
    {
        for(int j=i;j<a.size();j++)
        {
            if(a[i]*a[j]==k)
            {
                return true;
            }
        }
    }
    return false;
}


int height(Node *n)
    {
        if (n == NULL)
        {
            return 0;
        }
        return 1 + max(height(n->left), height(n->right));
    }
    int balanceFactor(Node *n)
    {
        if (n == NULL)
        {
            return 0;
        }
        return height(n->left) - height(n->right);
    }
    int countNonbalanceNodes(Node *n)
    {
        if (n == NULL)
        {
            return 0;
        }
        int count = 0;
        int balance = balanceFactor(n);
        if (balance < -1 || balance > 1)
        {
            count = 1;
        }
        return count + countNonbalanceNodes(n->left) + countNonbalanceNodes(n->right);
    }
int main()
{
    BST t;
    t.set_root(t.insert(t.get_root(),5));
    t.insert(t.get_root(),4);
    t.insert(t.get_root(),7);
    // t.inorder(t.get_root());
    cout<<endl;
    // t.postorder(t.get_root());
    cout<<endl;
    // t.preorder(t.get_root());
    vector<int> a;
    t.convert(t.get_root(),a);
    // cout<<"The elements in the tree are : ";
    // for(int i=0;i<a.size();i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    cout<<check(a,20);
}