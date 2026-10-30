# include<iostream>
using namespace std;
class complex
{
    private:
    float real;
     float imag;
public :
complex()
{
    real=0;
    imag=0;
}
complex(float r,float i)
{
    real=r;
    imag=i;
}
~complex()
{}
void display()
{
    cout<<real<<"+"<<imag<<"i"<<endl;
}
complex add(complex c)
{
    return complex(real+c.real,imag+c.imag);
}
complex subtract(complex c)
{
    return complex(real-c.real,imag-c.imag);
}
complex multipy(complex c)
{
   float r=real*c.real-imag*c.imag;
float i=real*c.real+imag*c.imag;
return complex(r,i);
}
};
int main()
{
  complex c1(4,5),c2(2,3);
  cout<<"\n first complex number=";
  c1.display();
  cout<<"\n second complex number=";
  c2.display();
complex sum=c1.add(c2);
cout<<"\n sum =";
sum.display();

complex diff=c1.subtract(c2);
cout<<"\n difference =";
diff.display();

complex prod=c1.multipy(c2);
cout<<"\n product =";
prod.display();

return 0;
}



/*
PS D:\Siddhikanhore> cd "d:\Siddhikanhore\" ; if ($?) { g++ complex_without_overloding.cpp -o complex_without_overloding } ; if ($?) { .\complex_without_overloding }

 first complex number=4+5i

 second complex number=2+3i

 sum =6+8i

 difference =2+2i

 product =-7+23i
 */
