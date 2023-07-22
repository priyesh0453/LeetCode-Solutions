#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

double checkInBoardMoves(int row, int column, int n, int k, vector <vector <vector <double>>>& possibleMoves);
double knightProbability(int n, int k, int row, int column);

int xCardinals[8] = {-2, -1, 1, 2, 2, 1, -1 , -2}, yCardinals[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main()
{
    int n, k, row, column;
    cin >> n >> k >> row >> column;
    
    cout << knightProbability(n, k, row, column);

    return 0;
}

double knightProbability(int n, int k, int row, int column)
{
    if(!k) return 1;

    vector <vector <vector <double>>> possibleMoves(26, vector <vector <double>> (26, vector <double> (101, -1)));
    double inBoardMoves = checkInBoardMoves(row, column, n, k, possibleMoves), totalNoOfMoves = pow(8, k);

    return inBoardMoves / totalNoOfMoves;   
}

double checkInBoardMoves(int row, int column, int n, int k, vector <vector <vector <double>>>& possibleMoves)
{
    if(row < 0 || row >= n || column < 0 || column >= n) return 0;
    if(!k) return 1;
    if(possibleMoves[row][column][k] != -1) return possibleMoves[row][column][k];

    int i = 0;
    double tempMoves = 0;

    for(; i < 8; i++)
    {
        tempMoves += checkInBoardMoves(row + xCardinals[i], column + yCardinals[i], n, (k - 1), possibleMoves);
    }

    return possibleMoves[row][column][k] = tempMoves;
}