#include <iostream>
using namespace std;

bool canPlaceFlowers(int flowerbed[], int noOfPlots, int n);

int main(void)
{
    int noOfPlots, n, i = 0;
    cin >> noOfPlots;
    cin >> n;
    
    int flowerbed[noOfPlots];
    
    for(; i < noOfPlots; i++)
    {
        cin >> flowerbed[i];
    }
    
    cout << canPlaceFlowers(flowerbed, noOfPlots, n);

    return 0;
}

bool canPlaceFlowers(int flowerbed[], int noOfPlots, int n) 
{
    int i = 0, count = 0, previous, next;

    for(; i < noOfPlots; i++)
    {
        if(n == 0) return true;

        if(flowerbed[i] == 0)
        {
            previous = (i == 0) ? 0 : flowerbed[(i - 1)];
            next = (i == (noOfPlots - 1)) ? 0 : flowerbed[(i + 1)];

            if(previous == 0 && next == 0)
            {
                flowerbed[i] = 1;
                n--;
            }
        }
    }

    return (n == 0);
}