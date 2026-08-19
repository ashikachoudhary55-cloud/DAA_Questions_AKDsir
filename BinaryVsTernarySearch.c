#include  < stdio.h > 
#include  < stdlib.h > 
#include  < time.h > 
int  binarySearch ( int  a [],  int  n ,  int  x ,  int  * count )  { 
int  l  =  0 ,  r  =  n  -  1 ; 
while  ( l  <=  r )  { 
(* count )++; 
int  mid  =  l  +  ( r  -  l )  /  2 ; 
if  ( a [ mid ]  ==  x ) 
return  mid ; 
if  ( x  <  a [ mid ]) 
r  =  mid  -  1 ; 
else 
} 
l  =  mid  +  1 ; 
return  - 1 ; 
} 
int  ternarySearch ( int  a [],  int  n ,  int  x ,  int  * count )  { 
int  l  =  0 ,  r  =  n  -  1 ; 
while  ( l  <=  r )  { 
(* count )++; 
int  mid1  =  l  +  ( r  -  l )  /  3 ; 
int  mid2  =  r  -  ( r  -  l )  /  3 ; 
if  ( a [ mid1 ]  ==  x ) 
return  mid1 ; 
if  ( a [ mid2 ]  ==  x ) 
return  mid2 ; 
if  ( x  <  a [ mid1 ]) 
r  =  mid1  -  1 ; 
else  if  ( x  >  a [ mid2 ]) 
l  =  mid2  +  1 ; 
else  { 
l  =  mid1  +  1 ; 
r  =  mid2  -  1 ; 
} 
} 
return  - 1 ; 
} 
int  main ()  { 
int  sizes []  =  { 100 ,  1000 ,  10000 ,  100000 ,  1000000 }; 
int  m  =  5 ; 
printf ( "n\tBinary\tTernary\n" ); 
printf ( "--------------------------------\n" ); 
for  ( int  k  =  0 ;  k  <  m ;  k ++)  { 
int  n  =  sizes [ k ]; 
int  * a  =  ( int  *) malloc ( n  *  sizeof ( int )); 
for  ( int  i  =  0 ;  i  <  n ;  i ++) 
a [ i ]  =  i  +  1 ; 
int  x  =  n ; 
int  binaryCount  =  0 ,  ternaryCount  =  0 ; 
binarySearch ( a ,  n ,  x ,  & binaryCount ); 
ternarySearch ( a ,  n ,  x ,  & ternaryCount ); 
printf ( "%d\t%d\t%d\n" , 
n ,  binaryCount ,  ternaryCount ); 
free ( a ); 
} 
