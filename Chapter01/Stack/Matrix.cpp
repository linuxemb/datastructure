
#include "Matrix.h"
#include <cstdlib>
#include <assert.h>  
void Matrix::initData (int r, int c)
{
    rows = r;
    cols = c;
    im = new int *[rows];   // row 
    for (int i =0 ;i <rows; i++)
    {
        im[i] = new int[cols] ;
    }
}

void Matrix::initMatrix ( int ** array )
{
    
    initMatrix(array); 

}
void Matrix::initMatrix (int *array)
{
    for  (int  i=0; i<rows; ++i)
    {
        for (int j=0; j<cols; ++j)
        {
          if (array)
            im[i][j] = *array++;  // copy array val to im
          else
            im [i][j] =0;
        }   
    }
}

// constructor
 Matrix::Matrix(int r, int c)
 {
    initData (r,c);
    initMatrix(static_cast <int *>(0));    // set all pointer to nullptr
  }  

  // 2nd constructor

  Matrix::Matrix(int r, int c, int *array )
 {
    initData (r,c);
    initMatrix(array);  
  }  

  // destructor

  Matrix::~Matrix()
  {
      for (int i=0; i<rows; i++)
      {
          delete [] im[i];
      }
      delete [] im;
  }

  int & Matrix::operator()(int r, int c)
  {
      assert (r>=0 && r<rows && c>= 0 && c< cols);
      
      return im[r][c];
  }