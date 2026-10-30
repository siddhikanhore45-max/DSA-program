#include<iostream>
using namespace std;
class complex{
    private:
    float real;
    float imag;
    public:
    complex(){
        real=0;
        imag=0;

    }
    complex(float r,float i){
        real=r;
        imag=i;
    }
    ~complex(){

    }
    void display(){
        cout<<real<<"+"<<imag<<"i";
    }
    complex operator+(complex c){
        return complex(real+c.real,imag+c.imag);
    }
    complex operator-(complex c){
        return complex(real-c.real,imag-c.imag);
    }
    complex operator*(complex c){
        float r=real*c.real-imag*c.imag;
        float i=real*c.imag+imag*c.real;
        return complex(r,i);

    }
};
int main(){
    complex c1(4,5),c2(2,3);
    cout<<"\nFirst complex Number:";
    c1.display();
    cout<<"second complex Number:";
    c2.display();
    complex sum=c1+c2;
    cout<<"\nsum:";
    sum.display();
    complex diff=c1-c2;
    cout<<"difference:";
    diff.display();
    complex prod=c1*c2;
    cout<<"product:";
    prod.display();
    return 0;
}
/*
PS D:\siddhikanhore> cd "d:\siddhikanhore\" ; if ($?) { g++ complex2.cpp -o complex2 } ; if ($?) { .\complex2 }

First complex Number:4+5isecond complex Number:2+3i
sum:6+8idifference:2+2iproduct:-7+22i
*/
