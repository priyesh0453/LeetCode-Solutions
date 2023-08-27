#include <iostream>
#include <unordered_map>
using namespace std;

int furthestDistanceFromOrigin(string moves) ;

int main()
{
    string moves;
    cin >> moves;
    
    cout << furthestDistanceFromOrigin(moves);

    return 0;
}

int furthestDistanceFromOrigin(string moves) 
{
    int noOfMoves = moves.length(), i = 0;
    unordered_map <char, int> temp;

    for(; i < noOfMoves; i++)
    {
        temp[moves[i]]++;
    }

    return (max(temp['L'], temp['R']) + temp['_'] - min(temp['L'], temp['R']));
}