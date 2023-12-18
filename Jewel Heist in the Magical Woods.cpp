#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Node
{

public:
    int data;
    string name;
    Node *left;
    Node *right;
    Node(int l, string n)
    {
        data = l;
        name = n;
        left = NULL;
        right = NULL;
    }
};
class BST
{
private:
    Node *Root;

public:
    BST()
    {
        Root = NULL;
    };
    Node *insert(Node *Curr, int val, string n)

    {
        if (Curr == NULL)
        {
           return Curr = new Node(val, n);
        }
        else if (val < Curr->data)
        {
            Curr->left = insert(Curr->left, val, n);
            return Curr;
        }
        else if (val > Curr->data)
        {
            Curr->right = insert(Curr->right, val, n);
            return Curr;
        }
        else
            return Curr;
    }

    void set_root(Node *curr)
    {
        Root = curr;
    }
    Node *find(Node *curr, int val)
    {
        if (curr == NULL)
        {
            // cout << "Value not found" << endl;
            return NULL;
        }
        if (curr->data == val)
        {
            // cout << "Value found(- _ -)" << endl;
            return curr;
        }
        else if (val < curr->data)
        {
            return find(curr->left, val);
        }
        else if (val > curr->data)
        {
            return find(curr->right, val);
        }
    }
    void inorder(Node *c)
    {
        if (c == NULL)
        {
            return;
        }
        inorder(c->left);
        cout << "[  " << c->name << "  " << c->data << "]"
             << " \t ";
        inorder(c->right);
    }

    void InOrder_Successor(Node *c, Node *&successor, Node *nodeToFind)
    {
        if (c == NULL)
        {
            return;
        }

        InOrder_Successor(c->left, successor, nodeToFind);
        //  cout<<"here 1"<<endl;
        if (successor == NULL && c->data > nodeToFind->data)
        {
            // cout << "successor =" << successor->data << endl;
            successor = c;
        }

        if (c == nodeToFind)
        {
            // cout<<"Here 2"<<endl;
            if (c->right)
            {
                Node *temp = c->right;
                //   cout<<"Here 3"<<endl;
                while (temp->left)
                {
                    //   cout<<"Here 4"<<endl;
                    temp = temp->left;
                }
                successor = temp;
            }
        }
        //   cout<<"here 6"<<endl;
        InOrder_Successor(c->right, successor, nodeToFind);
    }

    void preorder(Node *curr)
    {
        if (curr == NULL)
        {
            return;
        }
        cout << "[  " << curr->name << "  " << curr->data << "]"
             << " \t ";
        preorder(curr->left);
        preorder(curr->right);
    }

    void postorder(Node *curr)
    {
        if (curr == NULL)

        {
            return;
        }
        postorder(curr->left);
        postorder(curr->right);
        cout << "[  " << curr->name << "  " << curr->data << "]"
             << " \t ";
    }

    Node *parent(Node *curr, Node *p, Node *par)
    {
        if (curr == NULL)
        {
            return NULL;
        }
        if (curr == p)
        {
            return par;
        }
        else
        {
            Node *t = NULL;
            t = parent(curr->left, p, curr);
            if (t != NULL)
                return t;
            else
            {
                t = parent(curr->right, p, curr);
                return t;
            }
        }
    }

    Node *get_root()
    {
        return Root;
    }

    void Delete_node(Node *curr, int val)
    {
        if (curr == Root)
        {
            curr = find(Root, val);
        }
        if (curr->left != NULL && curr->right != NULL)
        {
            Node *Succ = NULL;
            // cout << "here" << endl;
            InOrder_Successor(curr, Succ, curr);
            // cout << "Succ data=" << Succ->data << endl;
            curr->data = Succ->data;
            Delete_node(Succ, Succ->data);
        }
        else if (curr->left == NULL && curr->right == NULL)
        {
            Node *par = parent(Root, curr, NULL);
            if (par->left == curr)
            {
                // cout << "In left" << endl;

                delete curr;
                par->left = NULL;
            }
            else if (par->right == curr)
            {
                // cout << "In right" << endl;
                delete curr;
                par->right = NULL;
            }
        }
        else if (curr->left != NULL || curr->right != NULL)
        {
            if(curr==Root)
            {
            if (curr->left != NULL && curr->right == NULL)
            {
                Node *temp = curr->left;
                Root = temp;
                delete curr;
            }
            else if (curr->left == NULL && curr->right != NULL)
            {
                Node *temp = curr->right;
                Root = temp;
                delete curr;
            }
            }
            else
            {
                Node *par = parent(Root, curr, NULL);
                if (par->left == curr)
                {

                    if (curr->left != NULL)
                    {
                        par->left = curr->left;
                        delete curr;
                    }
                    else
                    {
                        par->left = curr->right;
                        delete curr;
                    }
                }

                if (par->right == curr)
                {

                    if (curr->right != NULL)
                    {
                        par->right = curr->right;
                        delete curr;
                    }
                    else
                    {
                        par->right = curr->left;
                        delete curr;
                    }
                }
            }
        }
    }

    Node *findmax(Node *curr)
    {
        if (curr->right != NULL)
        {
            findmax(curr->right);
        }
        else
        return curr;
    }
};
int main()
{
    BST t;
    t.set_root(t.insert(t.get_root(), 50, "Diamond"));
    t.insert(t.get_root(), 30, "Ruby");
    t.insert(t.get_root(), 70, "Sapphire");
    t.insert(t.get_root(), 40, "Pearl");
    t.insert(t.get_root(), 10, "Opal");
    t.insert(t.get_root(), 60, "Garnet");
    t.insert(t.get_root(), 20, "Zircon");
    t.insert(t.get_root(), 5, "Jade");
    int power=0;
    int input=0;
    while (1)
    {
        cout<<endl;
        cout << "1.Display the magical tree." << endl;
        cout << "2.Search a gem by its power" << endl;
        cout << "3.Find the gem with the highest magical power." << endl;
        cout << "4.Pluck (remove) a gem from the BST, and put it in your bag." << endl;
        cout << "Enter your option" << endl;
        cin >> input;
        if (input == 1)
        {
            cout << "1.pre Order " << endl;
            cout << "2.In Order " << endl;
            cout << "3.Post Order " << endl;
            int a;
            cin >> a;
            if (a == 1)
            {
                cout << "Magical Tree (Pre Order)" << endl;
                t.preorder(t.get_root());
            }
            else if (a == 2)
            {
                cout << "Magical Tree (In Order)" << endl;

                t.inorder(t.get_root());
            }
            else if (a == 3)
            {
                cout << "Magical Tree (post Order)" << endl;

                t.postorder(t.get_root());
            }
        }
        else if (input == 2)
        {
            cout << "Enter the power of which gem u want to search" << endl;
            int n;
            cin >> n;
            Node *temp = t.find(t.get_root(), n);
            if(temp!=NULL)
            cout << "[  " << temp->name << "  " << temp->data << "]";
            else
            cout<<"Value Not Found"<<endl;
        }
        else if (input == 3)
        {
            Node *temp = t.findmax(t.get_root());
            cout << "Max power gem is [" << temp->name << "  " << temp->data << "]";
        }
        else if (input == 4)
        {
            cout << "Magical Tree (In Order)" << endl;

            t.inorder(t.get_root());

            cout << "Selcet the gems you want to pluck : Enter Power " << endl;
            int pow;
            cin >> pow;
            Node *temp = t.find(t.get_root(), pow);
            cout << "You plucked   ";
            cout << "[  " << temp->name << "  " << temp->data << "]";
            power = power + temp->data;
            t.Delete_node(t.get_root(), pow);
            cout<<"power="<<power<<endl;
            if (power >= 100)
            {
                if (power == 100)
                {
                    cout << "You Won ( - ___ - )  "<<endl;
                    cout<<"Now run from the Shafeen" << endl;
                    break;
                }
                else
                {
                    cout << "Bag Busted!!!!!!Now run from the Shafeen.He is Coming to Catch You" << endl;
                    break;
                }
            }
            else
                continue;
        }
        else
            break;
    }
}