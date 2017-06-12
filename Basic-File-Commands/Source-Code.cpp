/*Source file : Basic file commands
  Coder : Rohit Thapliyal*/


#include <bits/stdc++.h>
using namespace std;

map <string, int> files;
map < string, set <int> > vacants;

string file, new_file;

/*Function to create a new file*/
void create()
{
    int position;
    if (vacants[file].size() == 0)
    {
        position = files[file];
        files[file] = position + 1;
    }
    else
    {
        set <int> temp = vacants[file];
        position = * temp.begin();
        temp.erase (temp.begin());
        vacants[file] = temp;
    }
    cout << file;
    if (position != 0)
    {
        cout << "(" << position << ")";
    }
    cout << endl;
}

/*Function to delete the specified file*/
void delete_file()
{
    int position = 0, i = file.size() - 1;
    string real_file = file;
    if (file[i] == ')')
    {
        int pro = 1;
        i--;
        while (file[i] != '(')
        {
            position = position + ( (file[i] - '0') * pro);
            pro *= 10;
            i--;
        }
        real_file = file.substr (0, i);
    }
    set <int> temp = vacants[real_file];
    temp.insert (position);
    vacants[real_file] = temp;
    cout << file;
}

/*Driver Code*/
int main()
{
    int tests;
    cin >> tests;
    while (tests --)
    {
        string command;
        cin >> command >> file;
        if (command == "crt")
        {
            cout << "+ ";
            create();
        }
        else if (command == "del")
        {
            cout << "- ";
            delete_file();
            cout << endl;
        }
        else
        {
            cin >> new_file;
            cout << "r ";
            delete_file();
            cout << " -> ";
            file = new_file;
            create();
        }
    }
}
