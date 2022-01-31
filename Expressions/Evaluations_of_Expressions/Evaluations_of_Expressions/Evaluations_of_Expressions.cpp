// Evaluations_of_Expressions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//given an infix expression ,evaluate it
//and try to transfer it into another (ex: infix to post fix)


#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <stack>
using namespace std;

class Expression {
private:
    string infix_expression;
    string prefix_expression;
    string postfix_expression;
    map<string, int> isp;
    map<string, int> icp;
public:
    Expression(string expression);
    string& Get_infix();
    string& Get_prefix();
    string& Get_postfix();
    bool infix2postfix();
    bool infix2prefix();
};



inline Expression::Expression(string expression)
{
    this->infix_expression = expression;

    //build isp and icp

    isp.insert(pair<string, int>("--", 1));isp.insert(pair<string, int>("++", 1));isp.insert(pair<string, int>("!", 1));isp.insert(pair<string, int>("&", 1));
    isp.insert(pair<string, int>("*", 2));isp.insert(pair<string, int>("/", 2));isp.insert(pair<string, int>("%", 2));
    isp.insert(pair<string, int>("+", 3));isp.insert(pair<string, int>("-", 3));
    isp.insert(pair<string, int>(">", 4));isp.insert(pair<string, int>("<", 4));isp.insert(pair<string, int>(">=", 4));isp.insert(pair<string, int>("<=", 4));
    isp.insert(pair<string, int>("==", 5));isp.insert(pair<string, int>("!=", 5));
    isp.insert(pair<string, int>("&&", 6));
    isp.insert(pair<string, int>("||", 7));

    icp = isp;
}

inline string& Expression::Get_infix()
{
    return this->infix_expression;
}

inline string& Expression::Get_prefix()
{
    return this->prefix_expression;
}

inline string& Expression::Get_postfix()
{
    return this->postfix_expression;
}

inline bool Expression::infix2postfix()
{
    this->postfix_expression.clear();

    isp.insert(pair<string, int>("(", 8));
    icp.insert(pair<string, int>("(", 0));

    //convert string to char array
    int len = infix_expression.length() + 1;
    char* infix = new char[len];
    strcpy_s(infix,len, infix_expression.c_str());

    //split the expression
    char* pTmp = NULL;
    char* ptr = strtok_s(infix, " ", &pTmp);
    string tmp_ope;
    stack<string> s;

    while (ptr != NULL) {

        tmp_ope = ptr;
        if (isp.find(tmp_ope) == isp.end())
        {
            postfix_expression.append((tmp_ope + " "));
        }
        else if (tmp_ope==")")
        {
            for (; s.top() != "("; s.pop())
                postfix_expression.append((s.top() + " "));
            s.pop();//pop "("
        }
        else {
            if (s.empty()) {
                s.push(tmp_ope);
            }
            else {
                for (;!s.empty() && isp.find(s.top())->second <= icp.find(tmp_ope)->second; s.pop())
                    postfix_expression.append((s.top() + " "));
                s.push(tmp_ope);
            }
        }

        ptr = strtok_s(NULL, " ", &pTmp);
    }

    while (!s.empty()) {
        postfix_expression.append((s.top() + " ")); 
        s.pop();
    }
    
    isp.erase(isp.find("("));
    icp.erase(icp.find("("));

    if (infix_expression.length() != postfix_expression.length())
        return false;

    return true;

}

inline bool Expression::infix2prefix() {

    this->prefix_expression.clear();

    isp.insert(pair<string, int>(")", 8));
    icp.insert(pair<string, int>(")", 0));

    //convert string to char array
    int len = infix_expression.length() + 1;
    char* infix = new char[len];
    strcpy_s(infix, len, infix_expression.c_str());

    //split the expression
    char* pTmp = NULL;
    char* ptr = strtok_s(infix, " ", &pTmp);
    string tmp_ope;
    stack<string> infix_str;
    stack<string> prefix_str;
    stack<string> s;

    while (ptr != NULL) {
        tmp_ope = ptr;
        infix_str.push(tmp_ope);
        ptr = strtok_s(NULL, " ", &pTmp);
    }

    while (!infix_str.empty()) {
        
        if (isp.find(infix_str.top()) == isp.end()) {
            prefix_str.push(infix_str.top());
        }
        else if (infix_str.top() == "(") {
            for (; s.top() != ")"; s.pop())
                prefix_str.push(s.top());
            s.pop();
        }
        else {
            if (s.empty()) {
                s.push(infix_str.top());
            }
            else {
                for (; !s.empty() && isp.find(s.top())->second < icp.find(infix_str.top())->second; s.pop())
                    prefix_str.push(s.top());
                s.push(infix_str.top());
            }
        }

        infix_str.pop();
    }

    while (!s.empty()) {
        prefix_str.push(s.top());
        s.pop();
    }

    while (!prefix_str.empty()) {
        prefix_expression.append(prefix_str.top() + " ");
        prefix_str.pop();
    }

    

    if (infix_expression.length() != prefix_expression.length())
        return false;

    return true;
}

int main()
{
    string ex = "A / B - C + D * E - A * C ";
    Expression E(ex);

    cout << "Infix: " << ex << endl;

    if (E.infix2postfix())
        cout <<"Postfix: " << E.Get_postfix() << endl;

    if (E.infix2prefix())
        cout <<"Prefix: " << E.Get_prefix() << endl;


    return 0;
}