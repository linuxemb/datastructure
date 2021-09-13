#include "Cell.h"
#include "Iterator.h"

Iterator::Iterator(Node* nodePtr)
 :m_nodeP(nodePtr) {
  // Empty.
} 

Iterator::Iterator()
 :m_nodeP(nullptr) {
  // Empty.
}

Iterator::Iterator(const Iterator& iterator)
 :m_nodeP(iterator.m_nodeP) {
  // Empty.
}