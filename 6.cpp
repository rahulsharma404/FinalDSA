#include <iostream>
#include <string.h>
using namespace std;
class threaded //class for node creation
{
public:
    int d;          //store value
    threaded *l;    //pointer of left node
    threaded *r;    //pointer of right node
    int left_flag;  //to determine normal pointer or thread
    int right_flag; //to determine normal pointer or thread
};
class tbt
{
public:
    threaded *dummy, *root, *parent, *child, *curr, *val, *pre = NULL, *succ = NULL;
    void insert_node(); //insert number
    void inordertra();  //inorder tree traversal
    void preordertra(); //preorder tree traversal
    void pre_succ(threaded *root, threaded *&pre, threaded *&suc, int no);
    threaded *leftmost(threaded *root);  //find leftmost node in tree
    threaded *rightmost(threaded *root); //find rightmost node in tree
};
void tbt ::insert_node()
{
    int cont;
    threaded *rn, *ln; //store rightmost and leftmost node respectively
    root = new threaded;
    cout << "Enter root node: ";
    cin >> root->d;
    root->left_flag = root->right_flag = 0;
    root->l = root->r = NULL;
    dummy = new threaded;
    dummy->d = 0;
    dummy->l = root; //left node of dummy pointer points to root dummy->r=dummy; //right node of dummy pointer points to itself

    do
    {
        cout << endl;
        child = new threaded;
        cout << "Enter number: ";
        cin >> child->d;
        child->left_flag = child->right_flag = 0;
        child->r = child->l = NULL;
        parent = root;
        while (true)
        {
            if (child->d == parent->d) //number present in tree is entered
            {
                cout << "Number present in tree" << endl;
                break;
            }
            else if (child->d < parent->d) //child<parent
            {
                if (parent->left_flag == 0)
                {
                    parent->l = child;
                    parent->left_flag = 1;
                    pre_succ(root, pre, succ, child->d);
                    child->r = succ; //right pointer of child node
                    child->l = pre;  //left pointer of child node
                    if (parent->d == root->d)
                        root->l = child; //parent is root node break;
                }
                else
                    parent = parent->l;
            }
            else if (child->d > parent->d) //child>parent
            {
                if (parent->right_flag == 0)
                {
                    parent->r = child;
                    parent->right_flag = 1;
                    pre_succ(root, pre, succ, child->d);
                    child->r = succ;
                    child->l = pre;
                    if (parent->d == root->d)
                        root->r = child; //parent=root node
                    break;
                }
                else
                    parent = parent->r;
            }
        }
        cout << endl
             << "Enter 1 to continue otherwise enter 0";
        cout << endl
             << "Do you want to continue? (1/0) :";
        cin >> cont;
    } while (cont != 0);
    ln = leftmost(root);
    ln->l = dummy;
    rn = rightmost(root);
    rn->r = dummy;
    cout << endl
         << "Display Rightmost and Leftmost node :";
    cout << endl
         << "Rightmost Node= " << rn->d << " Leftmost Node= " << ln->d << endl;
}
void tbt::pre_succ(threaded *root, threaded *&pre, threaded *&suc, int no)
{
    while (root != NULL)
    {
        if (root->d == no)
        {
            if (root->r != NULL)
            {
                succ = root->r;
                while (succ->l)
                    succ = succ->l;
            }
            if (root->l != NULL) //leftmost no in left subtree=predecessor.
            {
                pre = root->l; //first no in left subtree
                while (pre->r)
                    pre = pre->r;
            }
            break;
        }
        else if (no < root->d)
        {
            succ = root;
            root = root->l;
        }
        else if (no > root->d)
        {
            pre = root;
            root = root->r;
        }
    }
}
threaded *tbt::leftmost(threaded *val)
{
    if (val == NULL)
        return NULL;
    while (val->left_flag != 0)
        val = val->l;
    return val;
}
threaded *tbt::rightmost(threaded *val)
{
    if (val == NULL)
        return NULL;
    while (val->right_flag != 0)
        val = val->r;
    return val;
}
void tbt ::inordertra()
{
    curr = leftmost(root); // leftmost node
    while (curr != dummy)
    {
        cout << curr->d << " ";
        if (curr->right_flag == 0)
            curr = curr->r;
        else
            curr = leftmost(curr->r);
    }
}
void tbt ::preordertra()
{
    curr = root;
    while (curr != dummy)
    {
        cout << curr->d << " ";
        if (curr->l != dummy && curr->left_flag == 1)
            curr = curr->l;
        else if (curr->right_flag == 1)
            curr = curr->r;
        else
        {
            while (curr->r != dummy && curr->right_flag == 0)
                curr = curr->r;
            if (curr->r == dummy)
                break; //rightmost node
            else
                curr = curr->r;
        }
    }
}
int main()
{
    int choice;
    int cont;
    tbt t;
    do
    {
        cout << endl
             << "Enter 1 to insert no in tree";
        cout << endl
             << "Enter 2 ti display inorder traversal";
        cout << endl
             << "Enter 3 to display preorder traversal";
        cout << endl
             << endl
             << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            t.insert_node();
            break;
        case 2:
            cout << "INORDER TREE TRAVERSAL: ";
            t.inordertra();
            break;
        case 3:
            cout << "PREORDER TREE TRAVERSAL: ";
            t.preordertra();
            break;
        default:
            cout << "Enter valid choice" << endl;
        }
        cout << endl
             << endl
             << "To Continue enter 1 otherwise enter 0" << endl;
        cout << "Do you want to continue? (1/0): ";
        cin >> cont;
    } while (cont != 0);
    return 0;
}
/*
Enter 1 to insert no in tree
Enter 2 ti display inorder traversal 
Enter 3 to display preorder traversal

Enter your choice: 1

Enter root node: 7

Enter number: 4
Number present in tree

Enter 1 to continue otherwise enter 0
Do you want to continue? (1/0) :1    

Enter number: 4
Number present in tree

Enter 1 to continue otherwise enter 0
Do you want to continue? (1/0) :1    

Enter number: 8

Enter 1 to continue otherwise enter 0
Do you want to continue? (1/0) :1

Enter number: 2
Number present in tree

Enter 1 to continue otherwise enter 0
Do you want to continue? (1/0) :1

Enter number: 9

Enter 1 to continue otherwise enter 0
Do you want to continue? (1/0) :0

Display Rightmost and Leftmost node :
Rightmost Node= 9 Leftmost Node= 2


To Continue enter 1 otherwise enter 0
Do you want to continue? (1/0): 1

Enter 1 to insert no in tree
Enter 2 ti display inorder traversal
Enter 3 to display preorder traversal

Enter your choice: 2

INORDER TREE TRAVERSAL: 2 4 7 8 9

To Continue enter 1 otherwise enter 0
Do you want to continue? (1/0): 1

Enter 1 to insert no in tree
Enter 2 ti display inorder traversal
Enter 3 to display preorder traversal

Enter your choice: 3

PREORDER TREE TRAVERSAL: 7 4 2 8 9

*/
