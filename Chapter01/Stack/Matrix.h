#include <ostream>
#include <iosfwd>
using namespace std;

//====== Matrix class ======
class Matrix {

public:

  Matrix(int row,int col) ;
 

  Matrix (int, int, int  * array);
  //Matrix (const Matrix &); // copy conto
   ~Matrix();
  int & operator() (int r, int c);  
friend ostream &operator <<(ostream &, const Matrix &);

private:
int rows, cols;
static const int defaultRowSize =5;
void initData(int r, int c); // set up memory
void initMatrix( int**);  // set up data
void initMatrix (int *array);
int ** im;
};
