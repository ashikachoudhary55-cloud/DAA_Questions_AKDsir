#include  < stdio.h > 
int  main ()  { 
int  n ; 
printf ( "Enter number of items: " ); 
scanf ( "%d" ,  & n ); 
int  num [ n ]; 
char  colour [ n ]; 
int  red [ n ],  blue [ n ],  yellow [ n ]; 
int  r  =  0 ,  b  =  0 ,  y  =  0 ; 
printf ( "Enter number and colour:\n" ); 
for  ( int  i  =  0 ;  i  <  n ;  i ++)  { 
scanf ( "%d %c" ,  & num [ i ],  & colour [ i ]); 
if  ( colour [ i ]  ==  'R' )  { 
red [ r ]  =  num [ i ]; 
r ++; 
} 
else  if  ( colour [ i ]  ==  'B' )  { 
blue [ b ]  =  num [ i ]; 
b ++; 
} 
else  if  ( colour [ i ]  ==  'Y' )  { 
yellow [ y ]  =  num [ i ]; 
y ++; 
} 
} 
printf ( "\nSorted by colour:\n" ); 
for  ( int  i  =  0 ;  i  <  r ;  i ++) 
printf ( "(%d,R) " ,  red [ i ]); 
for  ( int  i  =  0 ;  i  <  b ;  i ++) 
printf ( "(%d,B) " ,  blue [ i ]); 
for  ( int  i  =  0 ;  i  <  y ;  i ++) 
printf ( "(%d,Y) " ,  yellow [ i ]); 
return  0 ; 
} 
