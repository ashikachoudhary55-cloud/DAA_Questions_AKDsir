 #include  <  stdio.h  > 
 int  findDefective  (  int  a  [],  int  l  ,  int  r  ,  int  good  )  { 
 int  n  =  r  -  l  +  1  ; 
 if  (  n  ==  1  )  { 
 if  (  a  [  l  ]  <  a  [  good  ]) 
 return  l  ; 
 return  -  1  ; 
 } 
if  ( n  ==  2 )  { 
if  ( a [ l ]  <  a [ r ]) 
return  l ; 
if  ( a [ r ]  <  a [ l ]) 
return  r ; 
return  - 1 ; 
} 
int  size  =  n  /  3 ; 
int  l1  =  l ; 
int  r1  =  l  +  size  -  1 ; 
int  l2  =  r1  +  1 ; 
int  r2  =  l2  +  size  -  1 ; 
int  l3  =  r2  +  1 ; 
int  r3  =  r ; 
int  sum1  =  0 ; 
int  sum2  =  0 ; 
for  ( int  i  =  l1 ;  i  <=  r1 ;  i ++) 
sum1  +=  a [ i ]; 
for  ( int  i  =  l2 ;  i  <=  r2 ;  i ++) 
sum2  +=  a [ i ]; 
if  ( sum1  <  sum2 )  { 
return  findDefective ( a ,  l1 ,  r1 ,  l2 ); 
} 
if  ( sum2  <  sum1 )  { 
return  findDefective ( a ,  l2 ,  r2 ,  l1 ); 
} 
if  ( l3  <=  r3 )  { 
return  findDefective ( a ,  l3 ,  r3 ,  l1 ); 
} 
return  - 1 ; 
} 
int  main ()  { 
int  n ; 
printf ( "Enter number of coins: " ); 
scanf ( "%d" ,  & n ); 
int  a [ n ]; 
printf ( "Enter weights of coins:\n" ); 
for  ( int  i  =  0 ;  i  <  n ;  i ++)  { 
scanf ( "%d" ,  & a [ i ]); 
} 
int  defective  =  findDefective ( a ,  0 ,  n  -  1 ,  - 1 ); 
if  ( defective  ==  - 1 )  { 
printf ( "No defective coin found.\n" ); 
} 
else  { 
printf ( "Defective coin is at position %d.\n" ,  defective  +  1 ); 
} 
return  0 ; 
} 
