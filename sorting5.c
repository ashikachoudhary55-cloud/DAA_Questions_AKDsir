#include  < stdio.h > 
int  main ()  { 
int  n ; 
printf ( "Enter number of intervals: " ); 
scanf ( "%d" ,  & n ); 
int  start [ n ],  end [ n ]; 
for  ( int  i  =  0 ;  i  <  n ;  i ++)  { 
scanf ( "%d %d" ,  & start [ i ],  & end [ i ]); 
} 
for  ( int  i  =  0 ;  i  <  n  -  1 ;  i ++)  { 
for  ( int  j  =  0 ;  j  <  n  -  i  -  1 ;  j ++)  { 
if  ( start [ j ]  >  start [ j  +  1 ])  { 
int  temp  =  start [ j ]; 
start [ j ]  =  start [ j  +  1 ]; 
start [ j  +  1 ]  =  temp ; 
temp  =  end [ j ]; 
end [ j ]  =  end [ j  +  1 ]; 
end [ j  +  1 ]  =  temp ; 
} 
} 
} 
int  s  =  start [ 0 ]; 
int  e  =  end [ 0 ]; 
printf ( "Merged intervals: " ); 
 for  (  int  i  =  1  ;  i  <  n  ;  i  ++)  { 
 if  (  start  [  i  ]  <=  e  )  { 
 if  (  end  [  i  ]  >  e  ) 
 e  =  end  [  i  ]; 
 } 
 else  { 
 printf  (  "(%d,%d) "  ,  s  ,  e  ); 
 s  =  start  [  i  ]; 
 e  =  end  [  i  ]; 
 } 
 } 
 printf  (  "(%d,%d)\n"  ,  s  ,  e  ); 
 return  0  ; 
 
