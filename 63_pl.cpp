#include <iostream>
#include <cstring>
#include <math.h>
#define max 10
using namespace std;

class stack
{
public:
    string st[max];
    int top;

    stack()
    {
        top = -1;
    }

    bool isEmpty();
    bool isFull();
    void push(string s1);
    string pop();
};

class expression
{
public:
    stack s;
    bool isOperator(char x)
    {
        if (x == '+' || x == '-' || x == '*' || x == '/')
        {
            return true;
        }
        else
            return false;
    }

    int operand(string x)
    {
        if (x == "+" || x == "-")
            return 1;
        else if (x == "*" || x == "/")
            return 2;
        else if (x == "^")
            return 3;
        else
            return 0;
    }

    void prefix_to_infix()
    {
        stack s;
        string prefix;
        cout << "Enter the prefix-statement" << endl;
        cin >> prefix;
        int len = prefix.length();

        for (int i = len - 1; i >= 0; i--)
        {
            if (isOperator(prefix[i]) == true)
            {
                string x = s.pop();
                string y = s.pop();
                string temp = "(" + x + prefix[i] + y + ")";
                s.push(temp);
            }
            else
            {
                s.push(string(1, prefix[i]));
            }
        }
        cout << "Infix -expression" << endl;
        cout << s.pop() << endl;
    }

    void infix_to_postfix()
    {
        stack s;
        string infix, postfix;
        cout << "Enter the infix Expression" << endl;
        cin >> infix;

        int len = infix.length();

        for (int i = 0; i < len; i++)
        {
            if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z')
            {
                postfix = postfix + infix[i];
            }
            else if (infix[i] == '(')
            {
                s.push("(");
            }
            else if (infix[i] == ')')
            {
                while ((!s.isEmpty()) && (s.st[s.top] != "("))
                {
                    string t = s.st[s.top];
                    s.pop();
                    postfix = postfix + t;
                }

                if (s.st[s.top] == "(")
                {
                    s.pop();
                }
            }
            // if scanned have the less precedence than stack element then pop all the lements having greater or
            else
            {
                while ((!s.isEmpty()) && operand(string(1, infix[i])) <= operand(s.st[s.top]))
                {
                    string t = s.st[s.top];
                    s.pop();
                    postfix = postfix + t;
                }
                s.push(string(1, infix[i]));
            }
        }
        while ((!s.isEmpty()))
        {
            string t = s.st[s.top];
            s.pop();
            postfix = postfix + t;
        }
        cout << "Infix :" << endl;
        cout << infix << endl;

        cout << "Postfix :" << endl;
        cout << postfix << endl;
    }

    void postfixEva()
    {
        stack s;
        string postfix;
        int result,A,B;
        cout << "Enter the postfix exp :" << endl;
        cin >> postfix;

        for (int i = 0; i < postfix.length(); i++)
        {
            if ((isOperator(postfix[i])) == true)
            {
                 A = stoi(s.pop());
                 B = stoi(s.pop());

                if (postfix[i] == '+')
                {
                    result = B + A;
                }
                else if (postfix[i] == '-')
                {
                    result = B - A;
                }
                else if (postfix[i] == '*')
                {
                    result = B * A;
                }
                else if (postfix[i] == '/')
                {
                    result = B / A;
                }
                else if (postfix[i] == '^')
                {
                    result = pow(B, A);
                }
               
                string r=to_string(result);

                s.push(r);
            }
            else{
                if(isdigit(postfix[i]))
                {
                    s.push(string(1,postfix[i]));

                }
            }
              
        
        }
        cout<<"result :"<<endl;
        string ans=s.pop();
        cout<<ans<<endl;

    }
};

bool stack ::isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    else
        return false;
}

bool stack ::isFull()
{
    if (top == max - 1)
    {
        return true;
    }
    else
        return false;
}

void stack ::push(string s1)
{
    if (isFull() == true)
    {
        cout << "Stack is overflow" << endl;
    }
    else
    {
        top++;
        st[top] = s1;
    }
}

string stack ::pop()
{
    if (isEmpty() == true)
    {
        return "empty";
    }
    else
    {
        string s1 = st[top];
        top--;
        return s1;
    }
}

int main()
{
    expression E;
    int c;
   

    while(true){

    cout<<"Enter your choice"<<endl;
    cout<<"1.prefix to infix"<<endl;
    cout<<"2.infix to postfix"<<endl;
    cout<<"3.postfix-Evaluation"<<endl;
    cin>>c;
     
     switch(c){
        case 1:
        E.prefix_to_infix();
        break;

        case 2:
        E.infix_to_postfix();
        break;

        case 3:
        E.postfixEva();
        break;

        default:
        cout<<"Invalid input"<<endl;

     }
}
   

    return 0;
}
