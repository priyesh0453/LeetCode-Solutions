class MyQueue 
{
    public:

    stack <int> temp1, temp2;

    MyQueue() 
    {    
    }
    
    void push(int x) 
    {    
        temp1.push(x);
    }
    
    int pop() 
    {  
        while(!temp1.empty())
        {
            temp2.push(temp1.top());
            temp1.pop();
        }

        int poppedElement = temp2.top();
        temp2.pop();

        while(!temp2.empty())
        {
            temp1.push(temp2.top());
            temp2.pop();
        }

        return poppedElement;
    }
    
    int peek() 
    {    
        while(!temp1.empty())
        {
            temp2.push(temp1.top());
            temp1.pop();
        }

        int peekElement = temp2.top();

        while(!temp2.empty())
        {
            temp1.push(temp2.top());
            temp2.pop();
        }

        return peekElement;
    }
    
    bool empty()
    {    
        return temp1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */