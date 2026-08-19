#include  < stdio.h > 
int  min ,  max ,  comparisons  =  0 ; 
void  maxMin ( int  a [],  int  l ,  int  r )  { 
if  ( l  ==  r )  { 
min  =  max  =  a [ l ]; 
return ; 
} 
if  ( r  ==  l  +  1 )  { 
comparisons ++; 
if  ( a [ l ]  <  a [ r ])  { 
min  =  a [ l ]; 
max  =  a [ r ]; 
} 
else  { 
min  =  a [ r ]; 
max  =  a [ l ]; 
} 
} 
return ; 
int  mid  =  ( l  +  r )  /  2 ; 
int  oldMin  =  min ; 
int  oldMax  =  max ; 
maxMin ( a ,  l ,  mid ); 
int  leftMin  =  min ; 
int  leftMax  =  max ; 
maxMin ( a ,  mid  +  1 ,  r ); 
int  rightMin  =  min ; 
int  rightMax  =  max ; 
comparisons ++; 
if  ( leftMax  >  rightMax ) 
max  =  leftMax ; 
else 
max  =  rightMax ; 
comparisons ++; 
if  ( leftMin  <  rightMin ) 
min  =  leftMin ; 
else 
} 
min  =  rightMin ; 
int  main ()  { 
int  n ; 
printf ( "Enter size of array: " ); 
scanf ( "%d" ,  & n ); 
int  a [ n ]; 
printf ( "Enter array elements:\n" ); 
for  ( int  i  =  0 ;  i  <  n ;  i ++) 
scanf ( "%d" ,  & a [ i ]); 
maxMin ( a ,  0 ,  n  -  1 ); 
printf ( "Minimum = %d\n" ,  min ); 
printf ( "Maximum = %d\n" ,  max ); 
printf ( "Number of comparisons = %d\n" ,  comparisons ); 
printf ( "3n/2 = %.0f\n" ,  1.5  *  n ); 
return  0 ; 
} 
