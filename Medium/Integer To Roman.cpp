#include <iostream>
#include <map>
using namespace std;

string intToRoman(int num) 
{
    int noOfIterations = 0;
    string romanConverted;
        
    map <int, string> conversionMap{{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
        
    for(auto index = conversionMap.rbegin(); index != conversionMap.rend(), num > 0; index++)
    {
        if(num >= index->first)
        {
            noOfIterations = num / index->first;
                
            while(noOfIterations > 0)
            {
                    romanConverted += conversionMap[index->first];
                    noOfIterations--;
            }
                num %= index->first;
        }
    }
    return romanConverted;
}

int main()
{
    int num;
    cin >> num;
    
    cout << intToRoman(num);
    
    return 0;
}