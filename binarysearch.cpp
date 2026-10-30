#include<iostream>
using namespace std;
int binary_search( int a[],int n,int x)
{
    int first,last,mid;
    first=0;
    last=n-1;
    while (first<=last){
        mid=(first+last)/2;
        if(a[mid]==x)
        return (mid);
        else if(a[mid]<x)
        first=mid+1;
        else last=mid-1;

    }
    return(-1);

}
int main()
{
    int n,x;
    int a[10];
    cout<<"how many element";
    cin>>n;
    cout<<"enter"<<n<<"elements";
    for(int i=0;i<n;i++){
        cin>> a[i];
    }
    cout<<"enter the element to be search";
    cin>> x;
    int position=binary_search(a,n,x);
    if(position==-1) cout<<"element not found";
    else cout<<"element found at position"<<position;
    return 0;

}/*
PS D:\siddhikanhore\siddhikanhore> cd "d:\siddhikanhore\siddhikanhore\" ; if ($?) { g++ binarysearch.cpp -o binarysearch } ; if ($?) { .\binarysearch }
how many element 9
enter9elements 10 20 30 40 50 60 70 80 90
enter the element to be search 70
element found at position6
*/
