#include <stdlib.h>
#include <string.h>


#define MAXLINE 20

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
// here do malloc 
   int n =0;
   char buffer[80 ];
    puts("enter one line blank when done");
    while (  ( n <MAXLINE) && (gets(buffer) !=0) && (buffer[0] != '\0') )
  // while (  (buffer[0] != '\0') )
   { 
	 // set line [n] char pointer 1st then verify if itis null	   


     lines [n] = (char *) malloc(strlen(buffer) + 1); //) ==NULL);
     if ( lines[n]  == NULL ) 
	  {printf ("melloc faiul\n");
	  	return -1;
	  }
     strcpy ( lines[n++], buffer); // copy buffer to nth line and move index 
   }
   return n;
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



//=========== testdrive for API above
//



char * lines[MAXLINE];


int main() 

{
const int a = 100;
int *p;
p=&a;
(*p)++;

printf("a=%d\n(*p)=%d\n", a,*p);

printf("ai%d\n(*p)++=%d\n", a ,(*p)++);
printf("ai%d\n ++(*p)=%d\n", a ,++(*p));
  
// dont not chage a va twice in one expressing
int i =7;
printf("\n%d\n", i++ * i++);

// char pointer array
   char   * msg[5] = { "zb", "ab", "bc"};
  int numline =  getLine( lines); 
  //char * p
  sortString (lines, numline);

 printMsg  ( lines,numline);
//  sortString ( msg , 3 );
 // printMsg ( msg , 3);
return 0;
 }
