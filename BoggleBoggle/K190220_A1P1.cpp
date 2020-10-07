//Muhammad Ibad Saleem(19K0220 E) Problem 1 : Boggle Boggle

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int scores[100] = {0};
class Boggle
{
public:
    Boggle() {}

    //Function Filing
    void inputfile(int &row, int &col, char **boggle, int &no_of_words, string *wordfind)
    {
        ifstream input;
        input.open("input001.txt");
        input >> row;
        input >> col;
        row++;
        col++;

        for (int i = 0; i < row; i++)
        {
            char arr;
            for (int j = 0; j < col; j++)
            {
                input >> arr;
                boggle[i][j] = arr;
            }
        }
        input >> no_of_words;

        // wordfind = new string[nwords];
        for (int i = 0; i < no_of_words; i++)
        {
            string arr;
            input >> arr;
            wordfind[i] = arr;
        }
        input.close();
    }

    //Function to search Word

    int searchWord(int row, int col, char **boggle, int nwords, string wordfind)
    {
        int wordlen = 0;
        int score = 0;

        //horizontal straight search
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {

                if (boggle[i][j] == wordfind[wordlen])
                {
                    wordlen++;
                    if (wordlen == wordfind.length())
                    {
                        score += 1000;
                    }
                }
                else
                {
                    wordlen = 0;
                }
            }
        }

        //horizontal REVERSE search
        for (int i = 0; i < row; i++)
        {
            wordlen = wordfind.length() - 1;

            for (int j = 0; j < col; j++)
            {

                if (boggle[i][j] == wordfind[wordlen])
                {
                    wordlen--;
                    if (wordlen == -1)
                    {
                        score += 1000;
                        break;
                    }
                }
                else
                {
                    wordlen = wordfind.length() - 1;
                }
            }
        }
        //vertical search
        for (int j = 0; j < col; j++)
        {
            wordlen = 0;
            for (int i = 0; i < row; i++)
            {
                if (boggle[i][j] == wordfind[wordlen])
                {
                    wordlen++;
                    if (wordlen == wordfind.length())
                    {
                        score += 1000;
                        break;
                    }
                }
                else
                {
                    wordlen = 0;
                }
            }
        }

        //Reverse vertical search
        for (int j = 0; j < col; j++)
        {
            wordlen = wordfind.length() - 1;
            for (int i = 0; i < row; i++)
            {
                if (boggle[i][j] == wordfind[wordlen])
                {
                    wordlen--;
                    if (wordlen == -1)
                    {
                        score += 1000;
                        break;
                    }
                }
                else
                {
                    wordlen = wordfind.length() - 1;
                }
            }
        }

        // //diagonal search
        int a = -1, b = -1;
        row--;
        col--;
        wordlen = 0;
        while (a < row && b < col)
        {
            a++;
            b++;
            if (boggle[a][b] == wordfind[wordlen])
            {
                wordlen++;
                if (wordlen == wordfind.length())
                {
                    score += 1000;
                    break;
                }
            }
            else
            {
                wordlen = 0;
            }
        }

        //Diagonal Reverse Search
        a = -1;
        b = -1;

        wordlen = wordfind.length() - 1;
        while (a < row && b < col)
        {
            a++;
            b++;
            if (boggle[a][b] == wordfind[wordlen])
            {

                wordlen--;
                if (wordlen == -1)
                {
                    score += 1000;
                    break;
                }
            }
            else
            {
                wordlen = wordfind.length() - 1;
            }
        }

        //left diagonal search

        a = 0;
        b = col;
        wordlen = 0;
        while (a <= row && b >= 0)
        {
            if (boggle[a][b] == wordfind[wordlen])
            {
                wordlen++;
                if (wordlen == wordfind.length())
                {
                    score += 1000;
                    break;
                }
            }
            else
            {
                wordlen = 0;
            }
            a++;
            b--;
        }

        //left REVERSE diagonal search

        a = row;
        b = 0;
        wordlen = 0;
        while (a >= 0 && b <= col)
        {
            if (boggle[a][b] == wordfind[wordlen])
            {
                wordlen++;
                if (wordlen == wordfind.length())
                {
                    score += 1000;
                    break;
                }
            }
            else
            {
                wordlen = 0;
            }
            a--;
            b++;
        }
        return score;
    }
};

int main()
{
    Boggle B;
    int row = 100, col = 100;
    int no_of_words = 0;
    char **boggle = new char *[row];

    for (int i = 0; i < row; i++)
    {
        boggle[i] = new char[col];
    }
    // system("cls");
    string wordfind[100];
    B.inputfile(row, col, boggle, no_of_words, wordfind);
    for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < col; j++)
        {
            // cout << boggle[i][j]<<" ";
        }
    }
    ofstream fout;
    int score;
    fout.open("output001.txt");
    for (int j = 0; j < no_of_words; j++)
    {

        score = B.searchWord(row, col, boggle, no_of_words, wordfind[j]);

        fout << "\n\nWord: " << wordfind[j] << "\nScore is :" << score << endl
             << endl;
    }
    fout.close();
    system("pause");
}
