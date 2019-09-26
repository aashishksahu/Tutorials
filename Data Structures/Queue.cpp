#include <iostream>

using namespace std;

static int head;
static int tail;

class Queue
{

public:

    void push(int x[], int val)
    {
        x[tail] = val;
        ++tail;
    }

    void pop(int x[])
    {
        head++;
    }

    void mid(int a[], int ind, int val)
    {
        for(int n = tail; n>head; n--)
        {
            a[n+1] = a[n];
        }
        a[ind] = val;
        ++tail;
    }
};


int main()
{
    int x[100], i = 0;
    Queue obj;
    for(i = 0; i<10; i++)
    {
        obj.push(x, 1+i);
    }
    obj.pop(x);
    obj.mid(x, 3, 390);
    for(i = head; i<tail; i++)
    {
        cout<<x[i]<<"  ";
    }


    return 0;

}
