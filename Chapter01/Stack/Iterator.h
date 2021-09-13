//#include "Cell.h"
#ifndef ITERATOR_H
#define ITERATOR_H
class Iterator {
    

  // private:
  //   Iterator(Node* nodePtr);


  public:
   Iterator(Node* nodePtr);
    Iterator(); //:m_nodeP (nullptr) {}
   // Iterator( Node * nodeptr) :nodeP (nodeptr) {} 
    Iterator (const Iterator& iterator) ; //: m_nodeP(iterator.m_nodeP) { }

    //Node * getNext();
    void setNext(Node * n) { m_nodeP = n;}
     bool hasNext() { return ( m_nodeP != nullptr);} 
    
     bool hasNext() const { return (m_nodeP != nullptr); }
     void next() { m_nodeP = m_nodeP->next(); }

    
     int getVal() { return  m_nodeP->getVal();}
     void setVal(int value) { m_nodeP->setVal( value );}
    
       
    friend class linklist;
  
  private:
    Node * m_nodeP;
  //  Iterator(Node * node) : nodeP(node) { }

};
#endif