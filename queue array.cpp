#include<iostream>
using namespace std;
#define MAX 5
class queue
{
    private:
    int a[MAX];
    int front;
    int rear;

    public:
    queue()
    {
    front=-1;
    rear=-1;    
    }
int empty()
{
if(front==-1 && rear==-1)
return(1);
else
return(0);
}
int full(){
if(rear==MAX-1)
return(1);
else
return(0);
}
void enqueue(int x)
{
    if ( front==-1 && rear==-1){
        front++;
        rear++;
    }
    else
    {
        rear++;
    }
    a[rear]=x;
}
int dequeue()
{
    int x=a[front];
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        front++;
    }
return(x);
}
int peak()
{
    return(a[front]);
}
void display(void){
    for(int i=front;i<=rear;i++)
    cout<<"\t"<<a[i];
}
};
int main()
{
    queue q;
    if(!q.full())q.enqueue(10); else cout<<"queue is full"<<endl;
    cout<<" queue contents after enqueue operation: "<<endl;
    q.display();

    if(!q.full())q.enqueue(20); else cout<<"queue is full"<<endl;
    cout<<"queue contents after enqueue operation: "<<endl;
    q.display();

    if(!q.full())q.enqueue(30); else cout<<"queue is full"<<endl;
    cout<<"queue contents after enqueue operation: "<<endl;
    q.display();

    if(!q.full())q.enqueue(40); else cout<<"queue is full"<<endl;
    cout<<"queue contents after enqueue operation: "<<endl;
    q.display();

    if(!q.full())q.enqueue(50); else cout<<"queue is full"<<endl;
    cout<<"queue contents after enqueue operation: "<<endl;
    q.display();

    if(!q.full())q.enqueue(60); else cout<<"queue is full"<<endl;
    cout<<"queue contents after enqueue operation: "<<endl;
    q.display();

    if(q.empty())
    {
        cout<<"queue is empty"<<endl;
    }
    else
    {
    cout<<"dequeue out element is "<<q.dequeue()<<endl;
    }
    cout<<"queue contents after dequeue operation: "<<endl;
    q.display();

    if(q.empty())
    {
        cout<<"queue is empty"<<endl;
    }
    else
    {
    cout<<"dequeue out element is "<<q.dequeue()<<endl;
    }
    cout<<"queue contents after dequeue operation: "<<endl;
    q.display();

    if(q.empty())
    {
        cout<<"queue is empty"<<endl;
    }
    else
    {
    cout<<"dequeue out element is "<<q.dequeue()<<endl;
    }
    cout<<"queue contents after dequeue operation: "<<endl;
    q.display();

    if(q.empty())
    {
        cout<<"queue is empty"<<endl;
    }
    else
    {
    cout<<"dequeue out element is "<<q.dequeue()<<endl;
    }
    cout<<"queue contents after dequeue operation: "<<endl;
    q.display();

    if(q.empty())
    {
        cout<<"queue is empty"<<endl;
    }
    else
    {
    cout<<"dequeue out element is "<<q.dequeue()<<endl;
    }
    cout<<"queue contents after dequeue operation: "<<endl;
    q.display();

    if(q.empty())
    {
        cout<<"queue is empty"<<endl;
    }
    else
    {
    cout<<"dequeue out element is "<<q.dequeue()<<endl;
    }
    cout<<"queue contents after dequeue operation: "<<endl;
    q.display();
    return 0;
};
/*
PS D:\siddhikanhore> cd "d:\siddhikanhore\" ; if ($?) { g++ Queue_using_array.cpp -o Queue_using_array } ; if ($?) { .\Queue_using_array }
 queue contents after enqueue operation:
        10queue contents after enqueue operation:
        10      20queue contents after enqueue operation:
        10      20      30queue contents after enqueue operation:
        10      20      30      40queue contents after enqueue operation:
        10      20      30      40      50queue is full
queue contents after enqueue operation:
        10      20      30      40      50dequeue out element is 10
queue contents after dequeue operation:
        20      30      40      50dequeue out element is 20
queue contents after dequeue operation: 
        30      40      50dequeue out element is 30
queue contents after dequeue operation:
        40      50dequeue out element is 40
queue contents after dequeue operation: 
        50dequeue out element is 50
queue contents after dequeue operation: 
        1973414480queue is empty
queue contents after dequeue operation:
        1973414480
PS D:\siddhikanhore> 
*/
