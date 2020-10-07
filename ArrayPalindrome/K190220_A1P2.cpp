//Muhammad Ibad Saleem(19K0220 E) Problem 2 : Array Palindrome
#include <iostream>
#include <fstream>
using namespace std;

class Palindrome
{

public:
    Palindrome() {}
    int Reverse(int a)
    {
        int remainder = 0;
        int rev = 0;
        while (a != 0)
        {
            remainder = a % 10;
            rev = rev * 10 + remainder;
            a /= 10;
        }
        return rev;
    }
    void checkpalindrome(int *arr, int elements)
    {
        int flag = 0;
        ofstream fout;
        fout.open("output005.txt");
        for (int j = 0; j <= elements / 2; j++)
        {
            int a = Reverse(arr[elements - j - 1]);
            if (arr[j] == a)
            {
                flag = 1;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        
        if (flag == 1)
        {
            fout << "YES.Array is Palindrome";
        }
        else
        {
            fout << "NO.Array is not Palindrome";
        }
        
        fout.close();
    }
};

int main()
{
    Palindrome P;
    ifstream fin;
    int elements = 0, flag = 0;
    // cout << "Enter Number of Elements: ";
    // cin >> elements;
    fin.open("input005.txt", ios::in);
    fin >> elements;
   
    int *arr = new int[elements];
    // cout << "Enter " << elements << " Elements\n";

    for (int i = 0; i < elements; i++)
    {
        int arrayelement = 0;
        fin >> arrayelement;
        arr[i] = arrayelement;
    }
    P.checkpalindrome(arr, elements);
    fin.close();
}
