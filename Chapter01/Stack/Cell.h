// #include <iostream>
// using namespace std;
// class linklist;



#ifndef CELL_H
#define CELL_H
class Node
{
  Node (int value , Node* next, Node * prev );  
  friend class linklist;
  //friend ostream& operator<<(ostream&, const linklist& );

  public:
  
   int getVal() {return  m_val;}
   void setVal(int val) { m_val = val;}
   Node * next() const { return m_next;}
   void setPrev(Node * node) { node = m_prev;}
   
   Node * getPrev() const  { return m_prev ; }

 // Node (int v, Node * pre, Node * m_next)  { }
  private:
      int m_val;
      Node *m_next;
      Node * m_prev;
     // 
};


#endif