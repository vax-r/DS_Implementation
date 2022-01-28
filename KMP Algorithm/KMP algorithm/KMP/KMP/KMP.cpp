// KMP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class KMP {
private:
    string s;
    string pattern;
    int* failure_function;
public:
    KMP(string str,string pat);
    ~KMP();
    void Fail_func();
    int Fast_found();
};

inline KMP::KMP(string str, string pat)
{
    this->s = str;
    this->pattern = pat;
}

inline KMP::~KMP()
{
    delete[] failure_function;
}

inline void KMP::Fail_func()
{
    int len = this->pattern.length();
    this->failure_function = new int[len];
    failure_function[0] = -1;
    int j;
    for (int i = 1; i < len; i++) {
        j = failure_function[i - 1];
        while (pattern[i] != pattern[j + 1] && j >= 0)
            j = failure_function[j];
        if (pattern[i] == pattern[j + 1])
            failure_function[i] = j + 1;
        else
            failure_function[i] = -1;
    }
}

inline int KMP::Fast_found()
{
    int posS = 0, posP = 0, lenS = this->s.length(), lenP = this->pattern.length();
    while (posS < lenS && posP < lenP) {
        if (s[posS] == pattern[posP]) {
            posS++; posP++;
        }
        else{
            if (posP == 0)
                posS++;
            else
                posP = failure_function[posP - 1]+1;
        }
    }

    if (posP != lenP)
        return -1;
    else
        return posS - lenP;

}

int main()
{

    string s = "abcdabca";
    string pat = "abca";
    
    KMP game1(s, pat);
    game1.Fail_func();
    
    if (game1.Fast_found() == -1) {
        cout << "Couldn't find the pattern in the test string.\n";
    }
    else
    {
        cout << "the pattern appear in the test string of position " << game1.Fast_found() << endl;
    }



    return 0;
}







