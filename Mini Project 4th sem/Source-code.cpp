#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

int arr[100][100], range, error = 0;

//Function to check if the input is valid
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

//Function to input the range and matrix
void Input()
{
    string arrayElements;
    string n;
    try
    {
        cin >> n;
        cout << endl;

        //If input is not numeric
        if (!isNumber(n))
            throw n;

        //If input is numeric but out of bounds
        if (atoi(n.c_str()) < 0 || atoi(n.c_str()) > 100)
            throw atoi(n.c_str());

        //Input is correct, assigning value to range
        range = atoi(n.c_str());
        for (int i = 0; i < range; i++)
        {
            for(int j = 0; j < range; j++)
            {
                cin >> arrayElements;

                //If input is not numeric
                if (!isNumber(arrayElements))
                    throw arrayElements;

                //If input is numeric but out of bounds
                if (atoi(arrayElements.c_str()) < 0 || atoi(arrayElements.c_str()) > 2)
                    throw atoi(arrayElements.c_str());

                //Input is correct, assigning value to array
                arr[i][j] = atoi(arrayElements.c_str());
            }
        }
        cout << endl;
    }

    //Input is not numeric
    catch(string str)
    {
        cin.ignore();
        error = 1;
        cout << endl << str << " is an Invalid Entry" << endl;
    }

    //Input is out of bounds
    catch(int num)
    {
        cin.ignore();
        error = 1;
        cout << endl << num << " is out of bounds" << endl;
    }
}

//Function to check if there is a path of 1s from first row to last.
bool onePath()
{
    int i = 0, j = 0, oneFinder = 0, elementIncrement = 2;
    for (i = 1; i < range; i++)
    {
        for (j = 0; j < range; j++)
        {
            if (arr[i][j] == 1)
            {
                if (j == 0)
                {
                    if (arr[i-1][j] == (i+oneFinder) || arr[i-1][j+1] == (i+oneFinder))
                    {
                        arr[i][j] = arr[i][j] + elementIncrement;
                    }
                }
                else if (j == range-1)
                {
                    if (arr[i-1][j] == (i+oneFinder) || arr[i-1][j-1] == (i+oneFinder))
                    {
                        arr[i][j] = arr[i][j] + elementIncrement;
                    }
                }
                else
                {
                    if (arr[i-1][j] == (i+oneFinder) || arr[i-1][j-1] == (i+oneFinder) || arr[i-1][j+1] == (i+oneFinder))
                    {
                        arr[i][j] = arr[i][j] + elementIncrement;
                    }
                }
            }
        }
        oneFinder++;
        elementIncrement += 2;
    }
    for (i = range-1, j = 0; j < range; j++)
    {
        if (arr[i][j] == (2*(range-1)+1))
        {
            return true;
        }
    }
    return false;
}

//Function to check if there is a path of 2s from first column to last.
bool twoPath()
{
    int i = 0, j = 0, twoFinder = 1, elementIncrement = 2;
    for (j = 1; j < range; j++)
    {
        for (i = 0; i < range; i++)
        {
            if (arr[i][j] == 2)
            {
                if (i == 0)
                {
                    if (arr[i+1][j-1] == (j+twoFinder) || arr[i][j-1] == (j+twoFinder))
                    {
                        arr[i][j] = arr[i][j] + elementIncrement;
                    }
                }
                else if (i == range-1)
                {
                    if (arr[i][j-1] == (j+twoFinder) || arr[i-1][j-1] == (j+twoFinder))
                    {
                        arr[i][j] = arr[i][j] + elementIncrement;
                    }
                }
                else
                {
                    if (arr[i][j-1] == (j+twoFinder) || arr[i-1][j-1] == (j+twoFinder) || arr[i+1][j-1] == (j+twoFinder))
                    {
                        arr[i][j] = arr[i][j] + elementIncrement;
                    }
                }
            }
        }
        twoFinder++;
        elementIncrement += 2;
    }
    for( j = range-1, i = 0; i < range; i++)
    {
        if (arr[i][j] == (2*range))
        {
            return true;
        }
    }
    return false;
}

//Driver Code
int main()
{
    Input();
    if (1 == error)
    {
        cin.ignore();
        cout << endl << "Terminated due to error" << endl;
        cout << "Enter 1 to input again" << endl;
        int inputAgain;
        cin >> inputAgain;
        cout << endl;
        if (inputAgain == 1)
        {
            error = 0;
            Input();
        }
        else
            return 0;
    }
    cout << "\t\t\t\t\t______________OUTPUT_____________" << endl << endl << endl;
    if (onePath() && twoPath())
    {
        cout << "Ambiguous" << endl;
    }
    else if (twoPath())
    {
        cout <<"2" << endl;
    }
    else if (onePath())
    {
        cout << "1" << endl;
    }
    else
    {
        cout << "0" << endl;
    }
    cout << endl << "Press any key to exit";
    getch();
    return 0;
}
