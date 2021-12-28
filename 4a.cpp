#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class tnode
{
public:
    char ch;
    tnode *left;
    tnode *right;
};
class tree
{
public:
    tnode *tree;
    void creat(char *);
    tnode *construct_Postfix(string postfix);
    char *construct_Prefix(tnode **p, char *a);
    bool isOperator(char c);
    void inorder_recursive(tnode *);
    void preorder_recursive(tnode *);
    void postorder_recursive(tnode *);
    void inorder_nonrecursive(tnode *);
    void preorder_nonrecursive(tnode *);
    void postorder_nonrecursive(tnode *);
};
class snode
{
public:
    tnode *ptval;
    snode *nxt;
};
class stack
{
public:
    snode *top;
    stack()
    {
        top = NULL;
    }

    void push(tnode *);
    bool empty();
    snode *pop();
};
bool stack ::empty()
{
    if (top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void stack ::push(tnode *new_data)
{
    snode *new_node = new snode();
    new_node->ptval = new_data;
    new_node->nxt = top;
    top = new_node;
}
snode *stack ::pop()
{
    if (empty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        snode *temp = top;
        top = top->nxt;
        delete (temp);
        return top;
    }
}
bool tree ::isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
tnode *tree ::construct_Postfix(string postfix)
{

    if (postfix.length() == 0)
    {
        return nullptr;
    }
    stack s;
    for (char c : postfix)
    {
        if (isOperator(c))
        {
            tnode *x = s.top->ptval;
            s.pop();
            tnode *y = s.top->ptval;
            s.pop();
            tnode *node = new tnode;
            node->ch = c;
            node->left = y;
            node->right = x;
            s.push(node);
        }
        else
        {
            tnode *node = new tnode;
            node->ch = c;
            node->left = NULL;
            node->right = NULL;
            s.push(node);
        }
    }
    return s.top->ptval;
}
char *tree ::construct_Prefix(tnode **p, char *a)
{
    if (a == '\0')
        return '\0';
    while (1)
    {
        char *q = NULL;

        if (*p == NULL)
        {
            tnode *nn = new tnode();
            nn->ch = *a;
            nn->left = NULL;
            nn->right = NULL;
            *p = nn;
        }
        else
        {
            if (*a >= 'a' && *a <= 'z')
            {
                return a;
            }
            q = construct_Prefix(&(*p)->left, a + 1);
            q = construct_Prefix(&(*p)->right, q + 1);
            return q;
        }
    }
}
void tree::inorder_recursive(tnode *root)
{
    if (root != NULL)
    {
        inorder_recursive(root->left);
        cout << root->ch << " ";
        inorder_recursive(root->right);
    }
}
void tree::preorder_recursive(tnode *root)
{
    if (root != NULL)
    {
        cout << root->ch << " ";
        preorder_recursive(root->left);
        preorder_recursive(root->right);
    }
}
void tree::postorder_recursive(tnode *root)
{
    if (root != NULL)
    {

        postorder_recursive(root->left);
        postorder_recursive(root->right);
        cout << root->ch << " ";
    }
}
void tree::inorder_nonrecursive(tnode *root)
{
    stack s;
    tnode *curr = root;
    while (curr != NULL || s.empty() == false)
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top->ptval;
        s.pop();
        cout << curr->ch << " ";
        curr = curr->right;
    }
}
void tree::preorder_nonrecursive(tnode *root)
{
    if (root == NULL)
        return;
    stack s;
    s.push(root);
    while (s.empty() == false)
    {
        struct tnode *node = s.top->ptval;
        printf("%c ", node->ch);
        s.pop();
        if (node->right)
            s.push(node->right);
        if (node->left)
            s.push(node->left);
    }
}
void tree::postorder_nonrecursive(tnode *root)
{
    if (root == NULL)
        return;
    stack s1, s2;
    s1.push(root);
    tnode *node;
    while (!s1.empty())
    {
        node = s1.top->ptval;
        s1.pop();
        s2.push(node);
        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }
    while (!s2.empty())
    {
        node = s2.top->ptval;
        s2.pop();
        cout << node->ch << " ";
    }
}
int main()
{
    int n;
    cout << "1. Prefix Expression " << endl;
    cout << "2. Postfix Expression " << endl;
    cout << "Enter the type of Expression : ";
    cin >> n;
    tnode *root = NULL;
    tree t;
    if (n == 1)
    {

        cout << "Enter the Prefix Expression : ";
        string prefix;
        cin >> prefix;
        char a[prefix.length()];
        for (int i = 0; i < prefix.length(); i++)
        {
            a[i] = prefix[i];
        }
        t.construct_Prefix(&root, a);
    }
    else if (n == 2)
    {
        cout << "Enter the Postfix Expression : ";
        string postfix;
        cin >> postfix;
        root = t.construct_Postfix(postfix);
    }
    cout << "\nInfix Expression with recursion: ";
    t.inorder_recursive(root);
    cout << "\nPrefix Expression with recursion: ";
    t.preorder_recursive(root);
    cout << "\nPostfix Expression with recursion: ";
    t.postorder_recursive(root);
    cout << "\nInfix Expression with non-recursion: ";
    t.inorder_nonrecursive(root);
    cout << "\nPrefix Expression with non-recursion: ";
    t.preorder_nonrecursive(root);
    cout << "\nPostfix Expression with non-recursion: ";
    t.postorder_nonrecursive(root);
    return 0;
}

