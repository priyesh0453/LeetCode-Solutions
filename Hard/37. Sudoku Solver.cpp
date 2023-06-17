#include <iostream>
#include <vector>
using namespace std;

void display(vector<vector<char>>& board);
bool checkValidity(vector<vector<char>>& board, int row, int col, char ch);
bool solveSudoko(vector<vector<char>>& board);

int main()
{
    int i = 0, j;
    
    vector <vector<char>> board (9, vector <char> (9));
    
    for(; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }
    cout << endl;
    
    solveSudoko(board);
    display(board);

    return 0;
}

bool solveSudoko(vector<vector<char>>& board)
{
    int i = 0, j;
    char ch;

    for(; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            if(board[i][j] == '.')
            {
                for(ch = '1'; ch <= '9'; ch++)
                {
                    if(checkValidity(board, i, j, ch))
                    {
                        board[i][j] = ch;

                        if(solveSudoko(board)) return true;
                        else board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool checkValidity(vector<vector<char>>& board, int row, int col, char ch)
{
    int i = 0;

    for(; i < 9; i++)
    {
        if(board[row][i] == ch || board[i][col] == ch || board[((3 * (row / 3)) + (i / 3))][((3 * (col / 3)) + (i % 3))] == ch) return false;
    }

    return true;
}

void display(vector<vector<char>>& board)
{
    int i = 0, j;
    
    for(; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}