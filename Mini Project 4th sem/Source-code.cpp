#include <bits/stdc++.h>
using namespace std;

int arr[100][100];


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

void input()
{
    string arrayElements;
    string n;
    int range;
    try
    {
        cin >> n;
        if (!isNumber(n))
            throw n;
        if (atoi(n.c_str()) < 0 || atoi(n.c_str()) > 100)
            throw atoi(n.c_str());
        range = atoi(n.c_str());
        for (int i = 0; i < range; i++)
        {
            for(int j = 0; j < range; j++)
            {
                cin >> arrayElements;
                if (!isNumber(arrayElements))
                    throw arrayElements;
                if (atoi(arrayElements.c_str()) < 0 || atoi(arrayElements.c_str()) > 2)
                    throw atoi(arrayElements.c_str());
                arr[i][j] = atoi(arrayElements.c_str());
            }
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

//Driver Code
int main()
{
    input();
}
