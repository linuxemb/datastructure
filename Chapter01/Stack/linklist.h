#include <iostream>
#include "Iterator.h"
#include "Cell.h"
using namespace std;

class linklist
{
  friend ostream& operator<<(ostream&,  linklist& );
public:
    linklist();
    ~linklist();
    void insertFirst(int);
    void insertLast(int);
    void insert(int index, int val) ;

     void del (int index) ;
     template <typename T>
     void Tdel<T> (int index) ;
    void print(linklist* lst);
    void myprint();
    
    void write(ostream& outStream) ;

    

    bool find(int val, Iterator & findIterator) ;
    bool equal ( const linklist& list ) const ;
    bool insert(const Iterator & insertPos , int val);
    Iterator Ifirst()  { return Iterator(first); }
    Iterator Ilast()  { return Iterator(last); }
  
private:
  int size;
  Node * first; 
  Node * last;
};