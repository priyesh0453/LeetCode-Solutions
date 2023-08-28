class MyStack 
{
    public:

    queue <int> temp;

    MyStack() 
    {    
    }
    
    void push(int x) 
    {
        temp.push(x);

        int i = 0, noOfElements = temp.size() -1;

        for(; i < noOfElements; i++)
        {
            temp.push(temp.front());
            temp.pop();
        }     
    }
    
    int pop() 
    { 
        int poppedElement = temp.front();
        temp.pop();

        return poppedElement;   
    }
    
    int top() 
    {    
        return temp.front();
    }
    
    bool empty() 
    { 
        return temp.empty();   
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */