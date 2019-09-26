// sorting algorithms (beta)
// work under progress
// author: Aashish Kumar Sahu
// date created: 21/11/2017
// c++ version = c++14 (GNU GCC COMPILER)

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>

using namespace std;

// index holds the maximum number of array elements(here 10), it can be changed
int index = 5;

// algo class is a set of sorting algorithms and includes selection sort, insertion sort, bubble sort
class algo
{
    int di, temp;

public:

    // disp() function to display the array after being sorted
    void disp(vector<int> arr)
    {
        cout<<"\nThe sorted array is\n";
        for(di = 0; di<index; di++)
        {
            cout<<arr[di]<<"  ";
        }
        cout<<endl;
    }

    // function for selection sort, takes a vector as arguments
    vector<int> selection_sort(vector<int>);

    // function for insertion sort, takes a vector as arguments
    vector<int> insertion_sort(vector<int>);

    // function for bubble sort, takes a vector as arguments
    vector<int> bubble_sort(vector<int>);

};

// definition of bubble_sort() function
vector<int> algo::bubble_sort(vector<int> a)
{
    int i, j;
    for(j = 0; j<index; j++)
    {
        for(i=1; i<index; i++)
        {
            if(a[i-1] > a[i])
            {
                temp = a[i-1];
                a[i-1] = a[i];
                a[i] = temp;
            }
        }

    }
    disp(a);
    return a;
}

// definition of insertion_sort() function
vector<int> algo::insertion_sort(vector<int> a)
{
    int i, j, key;
    for(i = 1; i<index; i++)
    {
        j = i;
        key = a[i];
        while(a[j-1]>key && j!=0)
        {
           a[j] = a[j-1];
           j--;
        }
        a[j] = key;

    }
    disp(a);
    return a;
}

// definition of selection_sort() function
vector<int> algo::selection_sort(vector<int> a)
{
    int i, m, j;
    for (i = 0; i<index; i++)
    {
        // m holds the index of the minimum element in an array, in the beginning it is 0
        m = i;
        for (j = i; j<index; j++)
        {
            if(a[m] > a[j])
            {
                m = j;
            }
        }

        // minimum value is swapped with the array[i]
        temp = a[m];
        a[m] = a[i];
        a[i] = temp;

    }
    return a;

}

int main()
{

    srand(time(NULL));
    int c = 0;
    
    vector<int> v;
    int value;

    // c is the number of times you want to add values in the vector
    // using a vector will eliminate size issues

    cout<<"enter values: "<< endl;
    while(c<5)
    {
        cin>>value;
        v.push_back(value);
        c++;
    }
    // declares the maximum index for further use
    ::index = c;

    // object declaration of algo class
    algo  obj;

    // 1. Selection sort
    cout<<endl<<"1. Selection sort";
    obj.disp(obj.selection_sort(v));

    // 2. insertion sort
    cout<<endl<<"2. insertion sort";
    obj.insertion_sort(v);

    cout<<endl<<"3. bubble sort";
    obj.bubble_sort(v);

    return 0;
}
