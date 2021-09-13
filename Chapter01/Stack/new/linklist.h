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
    void insert(const Iterator & insertPos, int val);

    // remove
    void del(int index );
    void erase (const Iterator& rmPos);
    void remove (const Iterator &removePos, const Iterator& lastPosition=(nullptr));

    
    void delNode (int pos) ;
    void print(linklist* lst);
    void myprint();

    



    bool find(int val, Iterator & findIterator) ;
    bool equal ( const linklist& list ) const ;
    bool insert(const Iterator & iter , int val);
    Iterator Ifirst() const { return Iterator(first); }
    Iterator Ilast()  const { return Iterator(last); }
  
private:
  int size;
  Node *first, *last;
};