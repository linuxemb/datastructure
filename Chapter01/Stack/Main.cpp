
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "Car.h"
#include "Matrix.h"
#include <thread>
#include "Cell.h"

#include "Iterator.h"
# include "linklist.h"
using namespace std;

/* function to split a one dimmension array to 2D array 

input : int* mainArr -> original array
input : int numArr, --> row number, how many rows in 2D array
input : int numElem --> how many element in each row, think as height
output: int** -> pointer to new generated 2D array
notes:  Suppose the 1D array has the size which can be deviced by numElem 
 
*/
int **  splitArr( int mainArr[], int numArr, int numElem )
{
   // malloc and init
   int ** multip = NULL;
   multip = new int*[numArr]; 
   if (multip != nullptr) 
     {
     for (int i =0; i< numArr; i++)
       {
         multip[i] = new int[numElem];
          for (int j= 0; j< numElem; j++)
            { 
           // fill in vals from main arrary
             multip [i][j] = mainArr [i * numElem + j];
             cout << "[i][j]" << i  <<":" << j << endl;
             cout <<  multip[i][j] << endl;
            }
     }
  return multip;
  } 
  else cout << "out of memroy"<<endl;
  return nullptr;
}

void printArray_1 (int (*ptr) [4] ); // 1D array
void printArray_2 ( int (*ptr)[4], int n);

void printArray_1 (int (*ptr) [4])
{
 // prints the elem of a singale 4 elem int array
 //  p is a point to a type int, must type case to make it equt to address in ptr

   int *p ; 
   p = (int *) ptr;  // casting
 for (int i = 0; i < 4; i++)
 {
   cout << *p << endl;
   p++;
 }

}

void printArray_2 ( int (*ptr)[4], int n) 
{
  int *p = (int*) ptr;
   for (int i=0; i< (n *4)  ; i++)
   {
     cout << *p++ <<endl;
   }
}

void printArray_3 ( int (*ptr)[4], int n) 
{
  int *p = (int*) ptr;
   for (int i=0; i< (n *4)  ; i++)
   {
     cout << *p++ <<endl;
   }
}
//===================== string 
  void printMsg( char* p[], int num)  // num of msgs
  {
    for (int i =0; i< num; i++)
    {
      printf ( "%s", *p ++);
    }
  }

 int getLine( char * lines[])

  {
   int n =0;
   char buffer[80 ];
    puts("enter one line blank when done");
  // while ( (gets(buffer) !=0) && (buffer[0] != '\0') )
   while (  (buffer[0] != '\0') )
   { 

     if (( lines [n] = (char *) malloc(strlen(buffer) + 1 ==NULL))
     )
      return -1;
      strcpy ( lines[n++], buffer);
   }

  }
  // compare each pair of string and swap if needed bubble sort
   void sortString( char * p[], int num)
   {
     int i, j;
     char * tmp;
     for (i = 0 ;i < num ; i ++)
      {
        for (j = i; j < num -1; j++ )
            {
              if (strcmp ( p [j]  , p [j+1] ) > 0)
                // swap
               { tmp = p [j];
                p [j] = p [j + 1 ];
                p [ j+ 1 ] = tmp;
               }
            }
      }      
   }

//====== vector
  string pals[] = { "apple","pear", "banana"};
  vector<string> svec(pals,pals+3);
 //=========== testdrive for API above
 // Threads
 struct func
 {
   int & i;
   func (int& i_) : i(i_) {}
   void operator() ()
   {
    //for (int j=0; i<100000; ++j) // i already expired when main thread exits--"got Aborted (core dumped)"
      for (int j=0; i<10; ++j) 
     {
       std::cout<<"hello" << endl;
     }
   }
 };
 void  do_sth()
 {
 std::cout<<"hello1" << endl;
 }
   void    do_sthelse()
   {
 std::cout<<"hello2" << endl;
   }
void my_func3(int a, int b)
{
  cout << a+b<<endl;
}

int main() 
{
   cout <<" Node link list========" <<endl;
   linklist mlist;
   mlist.insertFirst(1);
   mlist.insertFirst(2);
    mlist.insertFirst(3);
     mlist.insertFirst(4);
  // mlist.print(&mlist);
   mlist.myprint();
//---
  linklist mlist2;
     cout <<" Node link list2========" <<endl;
  mlist2.insertLast(1);
 mlist2.insertLast(2); 
  mlist2.insertLast(3);
  mlist2.insertLast(4);
  // mlist2.print(&mlist2);
  mlist2.myprint();


     cout <<" Node link list2===Adding 8 and 10em=====" <<endl;
    Iterator it = mlist2.Ifirst();
    it.next();
    it.next();
    cout << "it next() next() val=" << it.getVal()<<endl;
    bool found = mlist2.find (4, it); 

  cout << "found="<< found << "it.getval==:"<<it.getVal() <<endl;
    mlist2.insert (2,100);
     mlist2.insert (3,300);
      mlist2.insert (5,600);
      mlist2.myprint();
    // del 
    cout<< "===After del 1 and 4 index node"<<endl;
    mlist2.del(4);
    mlist2.del(1);


  //  cout << "insert 8 after 4"<<endl;
  //   mlist2.insert(it, 8);

  //  Iterator iter = mlist2.Ifirst();
  //  cout<<"iter1"<<iter.getVal();
  //  iter.next();
  //     cout<<"iter1"<<iter.getVal();
  //    iter.next();
  // cout<<"iter1"<<iter.getVal();

  mlist2.myprint();

//  

return 1;

} 
// end main
   // thread test ======
//   int local_state=0;
//   func m_func(local_state);
//   //std::thread my_thread(m_func);
//   // lamda func
//   std::thread my_thread1(  [] ( ) {   
//       do_sth();
//       do_sthelse();
//    }
//  );
      
//   //my_thread.join();  // fix for core abort
//   my_thread1.join();  // fix for core abort
//  // my_thread.detach();

// // ==== pass augment to thread
// int a =2;
// int  b=3;
// std::thread t(my_func3, a, b);
  



//   string pals[] = { "apple","pear", "banana"};
//   int ia[10] = {32,4,5,2,5,6,8,1} ;

//   vector<string> svec(pals,pals+3);
//   vector<int> vec(ia, ia+ 8 );

//   sort(vec.begin(), vec.end());
//   sort(svec.begin(), svec.end());
//   cout<<"svec" <<svec[0]<<svec.at(1)<<endl;
//   cout<<" \n vec==" <<vec[0]<<vec.at(5)<<endl;

//   vector<int>::iterator iter = vec.begin();
//   vector<string>::iterator iterS=svec.begin();

//   vector<string>::iterator found = svec.begin();
//   // locate banana
//   found =  find(svec.begin(),svec.end(),"banana");
//   if (found != svec.end())
//   cout <<"\n Found "<<*found<<endl;
//   for ( iter ; iter!=vec.end(); iter++)
//   {
//     cout << *iter << endl;
//   } 

//     for ( iterS ; iterS!=svec.end(); iterS++)
//   {
//     cout << *iterS << endl;
//   } 

//   // split a vector to size of 2 element each
//   // change vec to vec2d
//   int rows =3; int elem =2;
//   vector<int>::iterator iter2d = vec.begin();
//   vector<int> vec2d [rows][elem]; 
//   int i;
//   // for (iter2d , i=0; iter2d != vec.end(); iter2d ++, i++ )  // traval whole vec
//   // {
//   //   for (int j = 0; j < elem; j ++)
//   //   //  vec2d [i][j]  vec.at(j);
//   // }

//   // char pointer array
//    char   * msg[5] = { "zb", "ab", "bc"};
  
//   //char * p
//   printMsg  ( msg, 5);
//   sortString ( msg , 3 );
//   printMsg ( msg , 3);

// // Class dependency injection test=========================
// GasolineSource *stationService = new GasStation();
// GasolineSource * canService = new FuelCan();

// // race car is independe form implemnation of fuel service
// // a gass station service is injected

// Car racecar (stationService);
// racecar.getGasoline();

// Car truckcar (canService);
// truckcar.getGasoline();

// delete stationService;
// delete canService;


// //========  template test
// Ex2< vector<int> *>  ex1; 

// cout << "TTTT"<<ex1._val <<endl;



//   int main2D[3][4] = { {1,2,3,4},
//                         {5,6,7,8},
//                         {9,10,11,12} };

// ===== Class Matrix =====test

//Matrix * mtrix = new Matrix(3,4);
// int arr[10] = {0,1,2,3,4,5,6,7,8,9};
// Matrix m = Matrix(2,5, (int *)arr);
// cout << "MATRIX+++"<<endl;
// cout << m(1,1) << endl;

// // test 0 padding
// Matrix m0 = Matrix(2,9, (int* ) arr);

// cout << "MATRIX0+++"<<endl;

// cout << m(1,0) << endl;
// cout << m(1,1) << endl;
// cout << m(1,2) << endl;

// cout << m(1,3) << endl;
// cout << m(1,4) << endl;

// cout << m(1,5) << endl;

// cout << m(1,6) << endl;

// cout << m(1,7) << endl;
// cout << m(1,8) << endl;


// for (int i =0; i<2;i++)
//   for ( int j = 0; j <6; j++    )
//       cout << m0(i)(j) << "->" ;
//       cout << endl;
// cout << "MATRIX0+++"<<endl;
//========CONST============const test
// int ival =1.01;

// int &rval2= ival;
// //const int &rval1 = 1.01;
// int *pi = &ival; 
// int &rval5 = *pi;

// const int &rval1 = 1.01;
// int * const &rval3 = &ival;


// // a pointer to reference is illigle
//  // int &*prval1 = pi;   //error: cannot declare pointer to ‘int&’  int &*prval1 = pi;
// // fix

// int * &prval1 = pi;  //cast &prval1 ro int * 

// //const int &*prval2 = &ival; // pointer to ref is wrong
// //fixed
// int * const &prval2 = &ival; 
// cout << "&prval2=" << &prval2<<endl;

// ptr is a pointer to a arts
 //     printArray_1( p++ );
  //}

// call 2nd way

 // printArray_2 (main2D, 3);

//   int mainArr[50];
//       cout << "mainAra=";
//       for (int i = 0; i < 50; i++)
//       {
//          mainArr [i] = i;
//          cout<< "  "<< mainArr[i] ; 
//       }
//        cout  << endl;

// // how many sub arrary ?  5 * 10  
//   int total = 50;
//   int subElem = 5;
//   int numSubArr = total / subElem;
//   cout << "numSubArr = " << numSubArr <<endl;

//    int ** matrix;
// // callApi to   test :split to int pointer point to  arr  5 array each has 10 element
//   matrix = splitArr( mainArr, numSubArr, subElem );

// // testing result
// cout <<matrix[0][0]<<endl;  // row 0, col 0
// cout <<matrix[1][1]<<endl;  // row1, col 1
// cout <<matrix[9][0]<<endl;  // row1, col 1
// // ????? printArray_2(matrix, numSubArr );

//  // free memory
// if (matrix)
//    delete matrix;
// return 1;
// }