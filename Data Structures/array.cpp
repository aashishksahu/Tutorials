#include<iostream>
#include<ctime>

using namespace std;


class array
{
 private:
	int l[100], i, j, size, loc;
 public:

	int insert()
	{	
		srand(time(0));
		// assign 10 random numbers to array
		for (i = 0; i<10; i++)
		{
			l[i] = rand()%10;
			size = i;
		}

		disp(size);
		return (size);
	}
	   

	// to delete an array element
	int del(int, int);

	// outputs array on screen
	void disp(int);
	
	// function to add value at a given location
	int mid(int);
};


// function to add value at a given location
int array::mid(int loc)
{
	int val, n = 10;
	cout<<"\nenter value: ";
	cin>> val;
	for (i = n; i>=0; i--)
	{

		if(i > loc)
		{
			l[i] = l[i-1];
		}

	}
	l[loc] = val;
	size = n;
	disp(size);
	return (size);
}


// outputs array on screen
void array::disp(int s)
{
	// display
	for (i = 0; i<s; i++)
	{
		cout<<l[i]<<"  ";
	}
}

// to delete an array element
int array::del(int loc, int size)
{
	
	for(j = 0; j<size-1; j++)
	{
		if(j >= loc)
		{
			l[j] = l[j+1];
		}
	}
	disp(size-1);
	return (size-1);
}


int main()
{
	array one;
	int size = one.insert();

	cout<<endl;

	one.mid(5);

	int v;
	cout<<"\nenter location: ";
	cin>>v;

	one.del(v, 10);

	return 0;

}
