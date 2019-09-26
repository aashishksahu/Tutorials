#include <iostream>

using namespace std;

static int index;


class Stack
{
    int n;
public:
    int bsearch(int a[], int val, int right, int left)
    {
        int mid = (left + right)/2;
    	if(val == a[mid])
    	{
            return mid;
    	}

	else if(val > a[mid])
    	{
            bsearch(a, val, mid, left);
    	}
    	else if(val < a[mid])
    	{
            bsearch(a, val, right, mid);
    	}
    }

    void push(int a[], int val)
    {
        a[index] = val;
        ++index;
    }

    void pop(int a[])
    {
        --index;
    }

    void mid(int a[], int ind, int val)
    {
        for(n = index; n>=ind; n--)
        {
            a[n+1] = a[n];
        }
        a[ind] = val;
        ++index;
    }
};

int main()
{
    int x[100], i = 0;
    Stack obj;
    for(i = 0; i<10; i++)
    {
        obj.push(x, 1+i);
    }
    obj.pop(x);
    obj.mid(x, 3, 390);
    for(i = 0; i<index; i++)
    {
        cout<<x[i]<<"  ";
    }


    return 0;

}