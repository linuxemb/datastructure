
#include "Cell.h"
#include "Iterator.h"
#include"linklist.h"

linklist ::linklist()
           :first (nullptr),
           last(nullptr), 
           size(0) {
  cout  <<"==== linklist constructor  -->" <<endl;
  
}

//===============insert

void linklist::insertFirst( int val) {
    Node * node = new Node(val,nullptr, nullptr);
    // if list is empty set first to node
    if (size ==0) 
        {
            first = last = node;
        }
    // insert before first
    else {
        node->m_next = first;
        first  = node;
    }
     size ++;
}


void linklist::insertLast( int val) {
    Node * node = new Node(val, nullptr, nullptr);
    // if list is empty set first to node
    if (size ==0) 
        {
            first = last = node;
        }
// insert after last
    else {
        last->m_next = node;
        last = node;
    }
    size ++;
}

void linklist::insert(int index, int val) {
    // if index out of range
    if (index <0 || index > size) return;
    if (index ==0) { insertFirst (val); return; }
    if (index == size)  { insertLast (val); return;}
    // insert in middle
    Node * node = new Node( val, nullptr, nullptr);
    Node * curr = Ifirst().m_nodeP;
    Node * prev = nullptr;
    for (int i= 0; i< index; i++)
    {
        prev = curr;
       curr = curr->next();        
    }
    // found curr, insert after
       prev->m_next = node;
       node->m_next = curr;
       size ++;
}

//================del ==============
void linklist::del(int index ) {
     // handle head and tail
     // supose del middle
     Node * pre = nullptr;
     Node * curr = Ifirst().m_nodeP;

     for ( int j = 0 ;  j < index  ; j++)
     {
        pre = curr;
        curr = curr->next();    
     }
     // remove the one at curr, next node be the ngighbor of pre : wire up 1st
     Node * nodeDel =  curr;
     pre-> m_next = curr-> m_next;
     delete  nodeDel;
     size --;
}



//====================================print

void  linklist::print( linklist* lst)
{
Node * ptr = lst->first ;
cout  <<"==== linklist  -->" <<endl;
    while(ptr)
    {
        cout<< ptr->m_val;
        cout  <<"-->";
        ptr = ptr->next(); 
    }
    cout <<endl;
}

void  linklist::myprint()
{
Node * ptr = first ;
cout  <<"==== linklist myprint  -->" <<endl;
    while(ptr)
    {
        cout<< ptr->m_val;
        cout  <<"-->";
        ptr = ptr->next(); 
    }
    cout <<endl;
  }

void linklist::write(ostream& outStream) 
{
    outStream <<"[";
    bool firstVal = true;

 Iterator iter = Ifirst();
   while (iter.hasNext()) {
       outStream << (firstVal ? " " : "," ) << iter.getVal();
       firstVal = false;
       iter.next();
   } 
     outStream << "]";
}



//  void linklist::delNode ( int pos) {

bool linklist::find (int val, Iterator& findIterator) 
{

    Iterator it = Ifirst();

   while (it.hasNext()  )
  {
    if( it.getVal() == val) 
        {
        findIterator = it;
        return true;
        }
      it.next();
  }       
      return false;
}





// bad insert from example c++17

bool linklist::insert(const Iterator & insertPos , int val) {
 


// set the pre pointer ot pint at the cell before the pos in the list//
      // if pos is 1st one  it is null
        Node * insertPtr = insertPos.m_nodeP;
        Node * node = new Node (val, insertPtr->getPrev(), insertPtr);
        insertPtr->setPrev(node);
      // if 1st one
        if (insertPtr = node)
        {
            first = node;
          //  node-> next = 
        } else{
           node->getPrev()->next();
  
       }
        ++size;     
}
   
  linklist::~linklist() 
  {
      cout << "delete destricltor ====" <<  endl;
      // 1-- move head,
      // 2--del head
      // 3 --set cur to new head
      // cur always move forward, create once -- iterator
      // tmp created n times deled n times
   Node * cur = first;
   //Node * todel = nullptr;
   while ( cur != nullptr) // != nullptr)
   { 
     Node * tmp = cur;  // each time allocate a new tmp node
     cur = cur->next();  // move 1st to next
     cout << "delete====" << tmp->m_val <<endl;
    delete tmp;  //del 1st node
    
  //  cur = first ; // prepare for next round, cur point to new first
     size --;
   }
  }

ostream& operator <<(ostream& os, const linklist& lst)
{
//     Node * ptr = lst.first ;

//     while(ptr)
//     {
//         os<<ptr->val;
//         os <<"-->";
//         ptr = ptr->next; 
//     }
//     os << "X" << endl;
//     return os;
 }
