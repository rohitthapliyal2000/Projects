#include <bits/stdc++.h>
using namespace std;

bool isNumber(string s)
{
    bool result = true;
    string::iterator k = s.begin();
    for (; k != s.end(); k++)
    {
        result = result && isdigit(*k);
    }
    return result;
}

int main()
{
    string h;
    int n;
    cin >> n;
    try
    {
        while (n)
        {
            cin >> h;
            n--;
            if (!isNumber(h))
                throw h;
            if (atoi(h.c_str()) < 0 || atoi(h.c_str()) > 2)
                throw atoi(h.c_str());
        }
    }
    catch(string str)
    {
        cout << str << " is an Invalid Entry" << endl;
    }
    catch(int num)
    {
        cout << num << " is out of bounds" << endl;
    }
}
