#include  < stdio.h > 
int  main ()  { 
int  n ; 
printf ( "Enter number of intervals: " ); 
scanf ( "%d" ,  & n ); 
int  point [ 2  *  n ]; 
int  type [ 2  *  n ]; 
// Store endpoints 
for  ( int  i  =  0 ;  i  <  n ;  i ++)  { 
int  l ,  r ; 
scanf ( "%d %d" ,  & l ,  & r ); 
point [ 2  *  i ]  =  l ; 
type [ 2  *  i ]  =  1 ;  
point [ 2  *  i  +  1 ]  =  r ; 
// start 
type [ 2  *  i  +  1 ]  =  - 1 ;  // end 
} 
// Sort events 
for  ( int  i  =  0 ;  i  <  2  *  n  -  1 ;  i ++)  { 
for  ( int  j  =  0 ;  j  <  2  *  n  -  i  -  1 ;  j ++)  { 
if  ( point [ j ]  >  point [ j  +  1 ])  { 
int  temp  =  point [ j ]; 
point [ j ]  =  point [ j  +  1 ]; 
point [ j  +  1 ]  =  temp ; 
temp  =  type [ j ]; 
type [ j ]  =  type [ j  +  1 ]; 
type [ j  +  1 ]  =  temp ; 
} 
} 
} 
int  count  =  0 ; 
int  max  =  0 ; 
int  answer  =  0 ; 
// Scan events 
for  ( int  i  =  0 ;  i  <  2  *  n ;  i ++)  { 
count  =  count  +  type [ i ]; 
if  ( count  >  max )  { 
max  =  count ; 
answer  =  point [ i ]; 
} 
} 
printf ( "Point = %d\n" ,  answer ); 
printf ( "Maximum intervals = %d\n" ,  max ); 
return  0 ; 
}
