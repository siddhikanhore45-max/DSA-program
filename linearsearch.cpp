#include<iostream>
using namespace std;
int linear_search ( int a[],int n, int x )
{
    for (int i=0; i<n; i++)
    {
        if (a[i]==x)
        return(i);

    }
    return (-1);
   
}
int main (){
    int n;
    int a[20];
    cout<<"enter the size of the array:";
    cin >>n;
    cout<<"enter"<<n<<"integers:";
    for (int i=0; i<n; i++){
        cin >>a[i];

    }
    int x;
    cout<<"enter the target element to search for:";
    cin >>x;
int location=linear_search (a,n,x);
if (location!=-1){
    cout<<"element"<<x<<"found at index:"<<location;}
    else{
        cout<<"element"<< x<<"not found in array";
    }
    return 0;
}
/*
PS D:\siddhikanhore> cd "d:\siddhikanhore\" ; if ($?) { g++ linearsearch.cpp -o linearsearch } ; if ($?) { .\linearsearch }
enter the size of the array:5
enter5integers:10
20
30
40
50
enter the target element to search for:40
element40found at index:3
*/
