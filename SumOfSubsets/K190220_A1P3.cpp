//Muhammad Ibad Saleem(19K0220 E) Problem 3 : Sum of subsets
#include <iostream>
#include <fstream>
using namespace std;


class SumSubset{
public:
SumSubset(){}
bool subsetadd(int *arr, int n, int sum)
{
    if (sum == 0)
    {
        return true;
    }
    if (n < 0 || sum < 0)
    {

        return false;
    }

    bool rec1 = subsetadd(arr, n - 1, sum - arr[n]);
    bool rec2 = subsetadd(arr, n - 1, sum);
    return rec1 || rec2;
}

};




int main()
{
    SumSubset S;
    int elements = 0, sumfind = 0;
    ifstream fin;
    ofstream fout;
    fin.open("input001.txt");
    fin >> elements;
    int *arr = new int[elements];

    for (int i = 0; i < elements; i++)
    {
        int arrayelement;
        fin >> arrayelement;
        arr[i] = arrayelement;
    }
    
    fin >> sumfind;
    fin.close();
    fout.open("output001.txt");
    bool a = S.subsetadd(arr, elements - 1, sumfind);
    if (a == true)
    {
        fout << "YES";
    }
    else
    {
        fout << "NO";
    }
}