#include <iostream>
#include <vector>
using namespace std;

vector<int> leftRightDifference(vector<int>& nums, int noOfNums, vector <int>& answer);
void display(vector <int> answer, int noOfNums);

int main()
{
    int noOfNums, i = 0;
    cin >> noOfNums;
    
    vector <int> nums(noOfNums);
    vector <int> answer(noOfNums, 0);
    
    for(; i < noOfNums; i++)
    {
        cin >> nums[i];
    }
    
    leftRightDifference(nums, noOfNums, answer);
    display(answer, noOfNums);

    return 0;
}

vector<int> leftRightDifference(vector<int>& nums, int noOfNums, vector <int>& answer) 
{
    int i = 0, rightSum = 0, leftSum = 0;

    for(; i < noOfNums; i++)
    {
        rightSum += nums[i];
    }    

    for(i = 0; i < noOfNums; i++)
    {
        rightSum -= nums[i];
        answer[i] = abs(leftSum - rightSum);
        leftSum += nums[i];
    }

    return answer;
}

void display(vector <int> answer, int noOfNums)
{
    int i = 0;
    
    for(; i < noOfNums; i++)
    {
        cout << answer[i] << " ";
    }
}