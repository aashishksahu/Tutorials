#include<iostream>
#include<ctime>

using namespace std;

class Node
{
	int key;;
	Node * Left;
	Node * Right;
public:
	Node * push(int);
	void InsertNode(Node*,Node*);
	void traversal(Node*);
	
};

Node * Head = NULL;

Node * Node::push(int val)
{
	Node * temp = (Node*)calloc(1, sizeof(Node));
	temp->key= val

	if (Head == NULL)
	{
		Head = temp;
	}
	else
	{
		InsertNode(ptr, temp);
	}
	cout << endl;
	return Head;
}


void Node::InsertNode(Node* ptr, Node* temp)
{
	if (ptr->key > temp->key)
	{
        	while(ptr->left != NULL)
		{
            `		InsertNode(Node* ptr->left, Node* temp)
        	}
	}
	if (ptr->key < temp->key)
	{
        	while(ptr->right != NULL)
		{
            		InsertNode(Node* ptr->right, Node* temp)
        	}
	}
}



int main()
{
	Node * ptr = NULL;
	Node obj;
	srand(time(NULL));
	int i = 0;
	while (i < 10)
	{
		ptr = obj.push(rand()%10);
		i++;
	}

    return 0;
}
