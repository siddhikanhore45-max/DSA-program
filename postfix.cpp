#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node*next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

class queue
{
    private:
    node *front;
    node *rear;

    public:
    queue()
    {
        front = rear = NULL;
    }
    int empty(void)
    {
        if (front == NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int peek(void)
    {
        if (empty())
        {
            cout<<"\nQueue is empty";
            return -1;
        }
        return front->data;
    }
    void enqueue(int x)
    {
        node*p= new node(x);

        if (front == NULL)
            {
                front = p;
                rear = p;
            }
            else
            {
                rear->next = p;
                rear = p;
            }
    }
    int dequeue(void)
    {
        if (empty())
        {
            cout<<"\nQueue is empty";
            return -1;
        }
        int x = front->data;
        node*p= front;

        front = front->next;

        if(front == NULL)
        {
            rear = NULL;
        }
        delete p;
        return x;
    }
    void display(void)
    {
        node*q=front;
        cout<<"\nQueue elements:";
        while(q != NULL)
        {
            cout<<"\t"<<q->data;
            q = q->next;
        }
    }
};

int main()
{
    int x;
    queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    q.display();
    if (!q.empty())
    {
        x=q.dequeue();
        cout<<"\nRemoveed:"<<x;
    }
    q.display();
    cout<<"\nFront element is:"<<x;
    return 0;
}
/*
PS D:\siddhikanhore> cd "d:\siddhikanhore\" ; if ($?) { g++ queue_using_linked_list.cpp -o queue_using_linked_list } ; if ($?) { .\queue_using_linked_list}

Queue elements: 10      20      30      40      50      60
Removeed:10
Queue elements: 20      30      40      50      60
Front element is:10
PS D:\siddhikanhore> 
*/
