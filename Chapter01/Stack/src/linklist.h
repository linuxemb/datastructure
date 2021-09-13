

class linklist
{
  friend ostream& operator<<(ostream&,  linklist& );
public:
    linklist();
    ~linklist();
    void insertFirst(int);
    void insertLast(int);
     void linklist::delNode (int pos) ;
    void print(linklist* lst);
    void myprint();

    //Iterator first() const { return Iterator(first);}

private:
  int size;
  Node * next;

  //Node *first, *last;
};