#include <stdio.h>
void swap(int *a,int *b)
{
    int t=*a; *a=*b; *b=t;
}
int part(int a[],int l,int r)
{
    int p=a[r],i=l,j;
    for(j=l;j<r;j++)
        if(a[j]<=p) swap(&a[i++],&a[j]);
    swap(&a[i],&a[r]);
    return i;
}
int select(int a[],int l,int r,int k)
{
    int p;
    if(l==r) return a[l];
    p=part(a,l,r);
    if(k==p) return a[p];
    if(k<p) return select(a,l,p-1,k);
    return select(a,p+1,r,k);
}
int main()
{
    int a[100],n,i,x,y;
    float med;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    if(n%2)
        med=select(a,0,n-1,n/2);
    else
    {
        x=select(a,0,n-1,n/2-1);
        y=select(a,0,n-1,n/2);
        med=(x+y)/2.0;
    }
    printf("Median = %.2f",med);
    return 0;
}


