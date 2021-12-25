#include <bits/stdc++.h>
using namespace std;
class Thread_Node
{
public:
    int data;
    Thread_Node *left;
    Thread_Node *right;
    int lbit;   // left flag
    int rbit;   // right flag
};
class Threaded_BST
{
public:
    Thread_Node *root, *dummy;
    Thread_Node *extreme_leftNode;
    Thread_Node *extreme_rightNode;
    Thread_Node *parent, *child, *current, *val, *pre = NULL, *succ = NULL;

    void Insert();
    void Inorder_Traversal();
    void Preorder_Traversal();
    void Pre_Succ(Thread_Node *root, Thread_Node *&pre, Thread_Node *&succ, int key);
    Thread_Node *leftmost(Thread_Node *root);
    Thread_Node *rightmost(Thread_Node *root);
};
void Threaded_BST::Insert()
{
    root = new Thread_Node;
    cout << "Enter root: ";
    cin >> root->data;
    root->lbit = root->rbit = 0;
    root->left = root->right = NULL;

    // Dummy Node
    dummy = new Thread_Node;
    dummy->data = 0;
    dummy->left = root;
    dummy->right = dummy;

    bool flag = true;
    char ch;

    while (flag)
    {
        child = new Thread_Node;
        cout << "\nEnter the data: ";
        cin >> child->data;
        child->lbit = child->rbit = 0;
        child->left = child->right = NULL;
        parent = root;
        while (true)
        {
            if (child->data == parent->data)
            {
                cout << "Data is already there in Tree !!!";
                break;
            }
            else if (child->data < parent->data)
            {
                if (parent->lbit == 0)
                {
                    parent->left = child;
                    parent->lbit = 1;
                    Pre_Succ(root, pre, succ, child->data);
                    child->right = succ;
                    child->left = pre;
                    if (parent->data == root->data)
                    {
                        root->left = child;
                    }
                    break;
                }
                else
                {
                    parent = parent->left;
                }
            }
            else if (child->data > parent->data)
            {
                if (parent->rbit == 0)
                {
                    parent->right = child;
                    parent->rbit = 1;
                    Pre_Succ(root, pre, succ, child->data);
                    child->right = succ;
                    child->left = pre;
                    if (parent->data == root->data)
                    {
                        root->right = child;
                    }
                    break;
                }
                else
                {
                    parent = parent->right;
                }
            }
        }
        cout << "Enter your choice (y/n): ";
        cin >> ch;
        if (ch == 'n')
        {
            flag = false;
        }
    }

    extreme_leftNode = leftmost(root);
    extreme_leftNode->left = dummy;
    extreme_rightNode = rightmost(root);
    extreme_rightNode->right = dummy;
}
void Threaded_BST::Pre_Succ(Thread_Node *root, Thread_Node *&pre, Thread_Node *&succ, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            if (root->right != NULL)
            {
                succ = root->right;
                while (succ->left)
                {
                    succ = succ->left;
                }
            }
            if (root->left != NULL)
            {
                pre = root->left;
                while (pre->right)
                {
                    pre = pre->right;
                }
            }
            break;
        }
        else if (key < root->data)
        {
            succ = root;
            root = root->left;
        }
        else if (key > root->data)
        {
            pre = root;
            root = root->right;
        }
    }
}
Thread_Node *Threaded_BST::leftmost(Thread_Node *value)
{
    if (value == NULL)
    {
        return NULL;
    }
    while (value->lbit != 0)
    {
        value = value->left;
    }
    return value;
}
Thread_Node *Threaded_BST::rightmost(Thread_Node *value)
{
    if (value == NULL)
    {
        return NULL;
    }
    while (value->rbit != 0)
    {
        value = value->right;
    }
    return value;
}
void Threaded_BST::Inorder_Traversal()
{
    current = leftmost(root);
    while (current != dummy)
    {
        cout << current->data << " ";
        if (current->rbit == 0)
        {
            current = current->right;
        }
        else
        {
            current = leftmost(current->right);
        }
    }
}
void Threaded_BST::Preorder_Traversal()
{
    current = root;
    while (current != dummy)
    {
        cout << current->data << " ";
        if (current->left != dummy && current->lbit == 1)
        {
            current = current->left;
        }
        else if (current->rbit == 1)
        {
            current = current->right;
        }
        else
        {
            while (current->right != dummy && current->rbit == 0)
            {
                current = current->right;
            }
            if (current->right == dummy)
            {
                break;
            }
            else
            {
                current = current->right;
            }
        }
    }
}
int main()
{
    Threaded_BST T;
    int choice;
    char ch;
    bool flag = true;
    while (flag)
    {
        cout << "\n---------------------MENU--------------------" << endl;
        cout << "1] Insert" << endl;
        cout << "2] Inorder Traversal" << endl;
        cout << "3] Preorder Traversal" << endl;
        cout << "4] Extreme Left Data and Extreme Right Data of Tree" << endl;
        cout << "5] Exit" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            T.Insert();
            break;
        case 2:
            cout << "Inorder Traversal : ";
            T.Inorder_Traversal();
            break;
        case 3:
            cout << "Preorder Traversal : ";
            T.Preorder_Traversal();
            break;
        case 4:
            cout << "\nRightmost Thread_Node: " << T.extreme_rightNode->data << "\nLeftmost Thread_Node: " << T.extreme_leftNode->data << endl;
            break;
        case 5:
            cout << "Exiting..." << endl;
            flag = false;
            break;

        default:
            cout << "Invalid Choice..." << endl;
            break;
        }
    }
    return 0;
}
