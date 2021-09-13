#include "Cell.h"

Node::Node(int value, Node* next, Node* prev)
 :m_val(value),
  m_next(next),
  m_prev(prev) {
  // Empty.
}