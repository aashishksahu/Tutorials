#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

class node
{
    int key;
    node* next;
    node* pre;

    public:
    node* create_node(int val)
    {
        node* t;
        t = (node*)calloc(1, sizeof(node));
        t -> key = val;
        t ->next = t->pre = NULL;
        return t;
    }
    node* pushback(int);
    node* pushfront(int);
    void  disp(node*);
    node* popback();
    node* popfront();
    void  pushmid(node*, int);
    void  popmid(node*);

};

node* head = NULL;
node* tail = NULL;
node* pre_pnt = NULL;

node* node::pushfront(int val)
{
    node* tmp = NULL;
    tmp = create_node(val);
    if(head == NULL)
    {
        head = tail = NULL;
    }
    else
    {
        head->pre = tmp;
        tmp->next = head;
        head = head->pre;
    }

    return head;
}

node* node::pushback(int val)
{
    node* temp = NULL;
    temp = create_node(val);
    if(head == NULL)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->pre = tail;
        tail = tail->next;
    }

    return head;
}

void node::pushmid(node* p, int val)
{
    int loc, i = 0;
    cout<<endl<<"enter location: ";
    cin>>loc;
    while(p->next!=NULL && loc != i)
    {
        p = p->next;
        i++;
    }
    node* tp = NULL;
    tp = create_node(val);
    tp->next = tail->next;
    tail->next->pre = tp;
    tail->next = tp;
    tp->pre = tail;
}

void node::popmid(node* po)
{
    int l, j = 0;
    cout<<"\nenter index: ";
    cin>>l;
    while(po->next != NULL && l != j)
    {
        pre_pnt = po;
        po = po->next;
        j++;
    }
    pre_pnt->next = po->next;
    free(po);
}

node* node::popback()
{
    node* pointer;
    pointer = head->next;
    free (head);
    head = pointer;
    return head;
}
node* node::popfront()
{
    node* ktm;
    while(tail->next != NULL)
    {
        tail = tail->next;
    }
    ktm = tail->pre;
    free(tail);
    tail = ktm;
    return tail;
}
void node::disp(node* p)
{
    cout<<"\nlink list:\n";
    while(p != NULL)
    {
        cout<<p->key<<"  ";
        p = p->next;
    }
    cout<<endl;
}
int main()
{
    srand(time(NULL));
    node* ptr = NULL;
    node one;
    for (int i = 0;i<10; i++)
    {
        ptr = one.pushback(rand()%100);
    }
    one.disp(ptr);
    ptr = one.popback();
    one.disp(ptr);
    return 0;
}
