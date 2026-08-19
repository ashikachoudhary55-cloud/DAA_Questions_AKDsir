#include  < stdio.h > 
#define  MAX  100 
void  multiply ( int  A [ MAX ][ MAX ],  int  B [ MAX ][ MAX ], 
int  C [ MAX ][ MAX ],  int  n )  { 
if  ( n  ==  1 )  { 
C [ 0 ][ 0 ]  =  A [ 0 ][ 0 ]  *  B [ 0 ][ 0 ]; 
return ; 
} 
int  k  =  n  /  2 ; 
int  A1 [ MAX ][ MAX ],  A2 [ MAX ][ MAX ]; 
int  B1 [ MAX ][ MAX ],  B2 [ MAX ][ MAX ]; 
int  X [ MAX ][ MAX ],  Y [ MAX ][ MAX ]; 
int  P [ MAX ][ MAX ],  Q [ MAX ][ MAX ]; 
for  ( int  i  =  0 ;  i  <  k ;  i ++)  { 
for  ( int  j  =  0 ;  j  <  k ;  j ++)  { 
A1 [ i ][ j ]  =  A [ i ][ j ]; 
A2 [ i ][ j ]  =  A [ i ][ j  +  k ]; 
B1 [ i ][ j ]  =  B [ i ][ j ]; 
B2 [ i ][ j ]  =  B [ i ][ j  +  k ]; 
} 
} 
for  ( int  i  =  0 ;  i  <  k ;  i ++)  { 
for  ( int  j  =  0 ;  j  <  k ;  j ++)  { 
X [ i ][ j ]  =  A1 [ i ][ j ]  +  A2 [ i ][ j ]; 
Y [ i ][ j ]  =  B1 [ i ][ j ]  +  B2 [ i ][ j ]; 
} 
} 
multiply ( X ,  Y ,  P ,  k ); 
for  ( int  i  =  0 ;  i  <  k ;  i ++)  { 
for  ( int  j  =  0 ;  j  <  k ;  j ++)  { 
X [ i ][ j ]  =  A1 [ i ][ j ]  -  A2 [ i ][ j ]; 
Y [ i ][ j ]  =  B1 [ i ][ j ]  -  B2 [ i ][ j ]; 
} 
} 
multiply ( X ,  Y ,  Q ,  k ); 
for  ( int  i  =  0 ;  i  <  k ;  i ++)  { 
for  ( int  j  =  0 ;  j  <  k ;  j ++)  { 
int  P1  =  ( P [ i ][ j ]  +  Q [ i ][ j ])  /  2 ; 
int  P2  =  ( P [ i ][ j ]  -  Q [ i ][ j ])  /  2 ; 
C [ i ][ j ]  =  P1 ; 
C [ i ][ j  +  k ]  =  P2 ; 
C [ i  +  k ][ j ]  =  P2 ; 
C [ i  +  k ][ j  +  k ]  =  P1 ; 
} 
} 
} 
int  main ()  { 
int  n ; 
int  A [ MAX ][ MAX ],  B [ MAX ][ MAX ],  C [ MAX ][ MAX ]; 
printf ( "Enter size of matrix: " ); 
scanf ( "%d" ,  & n ); 
printf ( "Enter first matrix:\n" ); 
for  ( int  i  =  0 ;  i  <  n ;  i ++) 
for  ( int  j  =  0 ;  j  <  n ;  j ++) 
scanf ( "%d" ,  & A [ i ][ j ]); 
printf ( "Enter second matrix:\n" ); 
for  ( int  i  =  0 ;  i  <  n ;  i ++) 
for  ( int  j  =  0 ;  j  <  n ;  j ++) 
scanf ( "%d" ,  & B [ i ][ j ]); 
multiply ( A ,  B ,  C ,  n ); 
printf ( "\nResult matrix:\n" ); 
for  ( int  i  =  0 ;  i  <  n ;  i ++)  { 
for  ( int  j  =  0 ;  j  <  n ;  j ++) 
printf ( "%d " ,  C [ i ][ j ]); 
printf ( "\n" ); 
} 
return  0 ; 
}
