#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

string reorganizeString(string s);

int main()
{
    string s;
    cin >> s;
    
    cout << reorganizeString(s);

    return 0;
}

string reorganizeString(string s) 
{
    unordered_map <char, int> freq;
    priority_queue <pair <int, char>> maxHeap;
    int i = 0, length = s.length(), currentF, nextF;
    char current, next;
    string reorgStr;

    for(; i < length; i++)
    {
        freq[s[i]]++;
    }

    for(auto [ch, f] : freq)
    {
        maxHeap.push({f, ch});
    }

    while(maxHeap.size() > 1)
    {
        currentF = maxHeap.top().first;
        current = maxHeap.top().second;

        maxHeap.pop();

        next = maxHeap.top().second;
        nextF = maxHeap.top().first;

        maxHeap.pop();

        reorgStr += current;
        reorgStr += next;

        if(currentF > 1) maxHeap.push({currentF - 1, current});

        if(nextF > 1) maxHeap.push({nextF - 1, next});
    }

    if(!maxHeap.empty())
    {
        currentF = maxHeap.top().first;

        if(currentF > 1) return "";

        reorgStr += maxHeap.top().second;
    }

    return reorgStr;
}