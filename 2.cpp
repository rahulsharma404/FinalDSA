#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
public:
    Node *top = NULL;
    bool empty();
    void push(int);
    void pop();
};

class Expression
{
public:
    int precedence(char);
    string infixToPrefix(string);
    string infixToPostfix(string);
    double evaluatePrefix(string);
    double evaluatePostfix(string);
};

bool Stack ::empty()
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
void Stack ::push(int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = top;
    top = new_node;
}
void Stack ::pop()
{
    if (empty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        Node *temp = top;
        top = top->next;
        delete (temp);
    }
}

int Expression ::precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string Expression ::infixToPrefix(string infix)
{
    /* 1. Reverse String
       2. Replace ( with ) and vice versa
       3. Get Postfix
       4. Reverse Postfix   
    */

    int l = infix.size();

    reverse(infix.begin(), infix.end());

    for (int i = 0; i < l; i++)
    {

        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }

    infix = '(' + infix + ')';
    Stack st;
    string prefix;
    l = infix.size();

    for (int i = 0; i < l; i++)
    {
        if (isalpha(infix[i]) || isdigit(infix[i]))
            prefix += infix[i];
        else if (infix[i] == '(')
            st.push('(');
        else if (infix[i] == ')')
        {
            while (st.top->data != '(')
            {
                prefix += st.top->data;
                st.pop();
            }
            st.pop();
        }
        else
        {
            if (infix[i] == '^')
            {
                while (precedence(infix[i]) <= precedence(st.top->data))
                {
                    prefix += st.top->data;
                    st.pop();
                }
            }
            else
            {
                while (precedence(infix[i]) < precedence(st.top->data))
                {
                    prefix += st.top->data;
                    st.pop();
                }
            }
            st.push(infix[i]);
        }
    }
    while (!st.empty())
    {
        prefix += st.top->data;
        st.pop();
    }

    reverse(prefix.begin(), prefix.end());

    return prefix;
}

string Expression ::infixToPostfix(string infix)
{

    Stack st;
    string postfix;

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            st.push('(');
        }
        else if (c == ')')
        {
            while (st.top->data != '(')
            {
                postfix += st.top->data;
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && precedence(infix[i]) <= precedence(st.top->data))
            {
                postfix += st.top->data;
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        postfix += st.top->data;
        st.pop();
    }

    return postfix;
}

double Expression ::evaluatePrefix(string prefix)
{
    Stack st;

    for (int j = prefix.size() - 1; j >= 0; j--)
    {
        if (prefix[j] == ' ')
            continue;

        if (isdigit(prefix[j]))
        {

            double num = 0, i = j;
            while (j < prefix.size() && isdigit(prefix[j]))
                j--;
            j++;

            for (int k = j; k <= i; k++)
                num = num * 10 + double(prefix[k] - '0');

            st.push(num);
        }
        else
        {

            double o1 = st.top->data;
            st.pop();
            double o2 = st.top->data;
            st.pop();

            switch (prefix[j])
            {
            case '+':
                st.push(o1 + o2);
                break;
            case '-':
                st.push(o1 - o2);
                break;
            case '*':
                st.push(o1 * o2);
                break;
            case '/':
                st.push(o1 / o2);
                break;
            }
        }
    }

    double result = st.top->data;
    while (!st.empty())
    {
        st.pop();
    }

    return result;
}

double Expression ::evaluatePostfix(string postfix)
{
    Stack st;

    if (!st.empty())
        return -1;

    for (int i = 0; i < postfix.size(); ++i)
    {

        if (postfix[i] == ' ')
            continue;

        if (isdigit(postfix[i]))
        {
            int num = 0;

            while (isdigit(postfix[i]))
            {
                num = num * 10 + (double)(postfix[i] - '0');
                i++;
            }
            i--;
            st.push(num);
        }
        else
        {
            double val1 = st.top->data;
            st.pop();
            double val2 = st.top->data;
            st.pop();

            switch (postfix[i])
            {
            case '+':
                st.push(val2 + val1);
                break;
            case '-':
                st.push(val2 - val1);
                break;
            case '*':
                st.push(val2 * val1);
                break;
            case '/':
                st.push(val2 / val1);
                break;
            }
        }
    }
    double result = st.top->data;
    while (!st.empty())
    {
        st.pop();
    }

    return result;
}

int main()
{
    bool flag = true;
    int choice;
    string str;
    string str1;
    string str2;

    string st1;
    string st2;

    Expression E;

    while (flag)
    {
        cout << "-----------------------------------------" << endl;
        cout << "1. INFIX to PREFIX CONVERSION  & PREFIX EVALUATION" << endl;
        cout << "2. INFIX to POSTFIX CONVERSION  & POSTFIX EVALUATION" << endl;
        cout << "0. FOR EXIT " << endl;
        cout << "-----------------------------------------" << endl;

        cout << "Enter the choice  : ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 0:
            flag = false;
            cout << "EXITING..." << endl;
            cout << "-----------------------------------------" << endl;
            break;

        case 1:
            cout << "Enter the infix expression  :  ";
            cin >> str;
            cout << "Prefix Expression  :  ";
            cout << E.infixToPrefix(str) << endl;
            str = E.infixToPrefix(str);
            for(int i = 0 ; i < str.length() ; i++)
            {
                if(str[i] >= 'a' && str[i] <= 'z')
                {
                    int num1;
                    cout<<str[i]<<" =>  ";
                    cin>>num1;
                    st1 = st1 + to_string(num1) + " ";
                }
                else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
                {
                    st1 = st1 + str[i] + " "; 
                }
            }
            cout << "Prefix Evaluation  :  " << st1 << " => " << E.evaluatePrefix(st1) << endl;
            
            cout << "-----------------------------------------" << endl;
            break;

        case 2:
            cout << "Enter the infix expression  :  ";
            cin >> str;
            cout << "Postfix Expression  :  ";
            cout << E.infixToPostfix(str) << endl;
            str = E.infixToPostfix(str);
            for(int i = 0 ; i < str.length() ; i++)
            {
                if(str[i] >= 'a' && str[i] <= 'z')
                {
                    int num1;
                    cout<<str[i]<<" =>  ";
                    cin>>num1;
                    st2 = st2 + to_string(num1) + " ";
                }
                else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
                {
                    st2 = st2 + str[i] + " "; 
                }
            }
            cout << "Postfix Evaluation  :  " << st2 << " => " << E.evaluatePostfix(st2) << endl;
            cout << "-----------------------------------------" << endl;
            break;
        default:
            cout << "Wrong Choice" << endl;
            cout << "-----------------------------------------" << endl;
            break;
        }
    }
    return 0;
}

/*
-----------------------------------------
1. INFIX to PREFIX CONVERSION  & PREFIX EVALUATION  
2. INFIX to POSTFIX CONVERSION  & POSTFIX EVALUATION
0. FOR EXIT 
-----------------------------------------
Enter the choice  : 1

Enter the infix expression  :  x+y*z/w+u
Prefix Expression  :  ++x/*yzwu
x =>  1
y =>  4
z =>  2
w =>  1
u =>  3
Prefix Evaluation  :  + + 1 / * 4 2 1 3  => 12
-----------------------------------------
-----------------------------------------
1. INFIX to PREFIX CONVERSION  & PREFIX EVALUATION
2. INFIX to POSTFIX CONVERSION  & POSTFIX EVALUATION
0. FOR EXIT
-----------------------------------------
Enter the choice  : 2

Enter the infix expression  :  a*b+c*d
Postfix Expression  :  ab*cd*+
a =>  2
b =>  3
c =>  4
d =>  5
Postfix Evaluation  :  2 3 * 4 5 * +  => 26
-----------------------------------------
-----------------------------------------
1. INFIX to PREFIX CONVERSION  & PREFIX EVALUATION
2. INFIX to POSTFIX CONVERSION  & POSTFIX EVALUATION
0. FOR EXIT
-----------------------------------------
Enter the choice  : 0

EXITING...
-----------------------------------------
*/
