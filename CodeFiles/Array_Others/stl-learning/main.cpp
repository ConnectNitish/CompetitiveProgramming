/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

template < typename T > T square (T val)
{
  return val * val;
}



template < typename T > class VectorName
{
private:
  vector < T > content;

public:
  void set (int index, T value)
  {
    if (index >= content.size ())
      {
	content.resize ();
      }
    content[index] = value;
  }

  T get (int index)
  {
    return content[index];
  }

  void push (int value)
  {
    content.push_back (value);
  }

  void print ()
  {
    for (int i = 0; i < content.size (); i++)
      {
	cout << content[i] << " ";
      }
  }

  int size ()
  {
    return content.size ();
  }
};

template<typename T> 
VectorName<T> operator*(VectorName<T> &t1,VectorName<T> &t2)
{
    VectorName<T> obj;
    for(int i=0;i<t1.size();i++)
    {
        obj.push(t1.get(i)*t2.get(i));
    }
    return obj;
}

int
main ()
{

  // cout << square(5) << endl;
  // cout << square(5.5) << endl;

  VectorName < int >IntV;

  IntV.push (1);
  IntV.push (2);
  IntV.push (4);
  IntV.push (7);
  IntV.print ();
  cout << IntV.size () << endl;
  
  IntV = square(IntV);

  IntV.print();

  return 0;
}

