#include<iostream>
using namespace std;

class Str{
public:
    Str *next;
    char data;
    Str(){
        next = NULL;
    }
};

class Stack
{
    Str *strTop;

public:
    Stack(){
        strTop = NULL;
    }
    bool isEmptyStr(){
        return strTop == NULL;
    }
    void push(char ch){
        Str *newNode = new Str();
        newNode->data = ch;
        newNode->next = strTop;
        strTop = newNode;
    }
    char popStr(){
        Str *temp = strTop;
        char ch;
        ch = temp->data;
        strTop = strTop->next;
        delete temp;
        return ch;
    }
    void display(){
        Str *temp = strTop;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    bool isValid(string str){
        int i = 0;
        if(str.empty()){
            cout << "String can't be empty!";
            return false;
        }
        while (i < str.length())
        {
            if(str[i] == '{' || str[i] == '(' || str[i] == '['){
                push(str[i]);
            }

            else if(str[i] == '}'){
                if(isEmptyStr() || popStr() != '{'){
                    return false;
                }
            }
            if(str[i] == ')'){
                if(isEmptyStr() || popStr() != '(')
                    return false;
            }
            if(str[i] == ']'){
                if(isEmptyStr() || popStr() != '[')
                    return false;
            }
        i++;
        }
        return isEmptyStr();
    }
};
int main()
{
    Stack stack;
    string str;
    cout << "Enter parenthesis to verify: ";
    cin >> str;
    if(stack.isValid(str))
        cout << "Valid";
    else
        cout << "Not Valid";
    return 0;
}
