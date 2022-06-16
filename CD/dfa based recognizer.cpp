#include <iostream>
#include<sstream>
using namespace std;
 
int dfa;
 
// the starting state (zeroth) of DFA
void start(char c)
{
    if (isalpha(c))
        dfa = 1;
    else
        dfa = -1;
}
 
// This function is for the first state of DFA
void state1(char c)
{
    if (isalnum(c))
        dfa = 1;
    else
        dfa = -1;
}
 
bool DFA_for_ID(string token)
{
    dfa = 0;
    int i, len = token.length();
    for (i = 0; i < len; i++) {
        if (dfa == 0)
            start(token[i]);
        else if (dfa == 1)
            state1(token[i]);
        else
            return 0;
    }
    if (dfa == 1)
        return 1;
    else
        return 0;
}

bool isDigit(string s){
    for(int i=0;i<s.length();i++)
        if(!isdigit(s[i])) return false;
    return true;
    
}

bool isValidKeyword(string str) {
   if (str== "auto" || str=="break" || str=="case"
       || str=="char" || str=="const" || str=="continue"
       || str=="default" || str=="do"
       || str=="double"
|| str=="else"
|| str=="enum"
|| str=="extern"
|| str=="float"
|| str=="for"
|| str=="goto"
|| str=="if"
|| str=="int"
|| str=="long"
|| str=="register"
|| str=="return"
|| str=="short"
|| str=="signed"
|| str=="sizeof"
|| str=="static"
|| str=="struct"
       || str=="switch"
|| str=="typedef"
|| str=="union"
|| str=="unsigned"
       || str=="void"
|| str=="volatile"
|| str=="while"
       )
   return (true);
   return (false);
}
 
int main()
{
    string input = "int a = 98 ";
 
// to separate all the tokens by space in the string
// and checking for each token
    stringstream ss(input);
    string token;
    while (ss >> token) {
        bool isValid = DFA_for_ID(token);
        if (isValid)
        {            
            if(isValidKeyword(token))
            
            cout << token << " : " << "Keywords" << endl;

            else
            cout << token << " : " << "Identifier" << endl;
        }
        
        else
            if(isDigit(token))
            cout << token << " : "
                 << "Constant" << endl;
           
    }
    return 0;
}
