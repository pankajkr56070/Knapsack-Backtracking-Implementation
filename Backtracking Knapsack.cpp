

/* knapsack  problem using backtracking*/
/* Variable Description….
n   – Total no. of items available
w[] – Weight of each item
p[] – Profit of each item
m   – Maximum Capacity of the Sack
unit[] – Profit of each item per Unit p[]/w[]
x[] – Final list of items put into the Sack
y[] – Intermediate list of selected items
fp  – Final Profit
fw  – Final Weight
cp  – Current Profit
cw  – Current Weight
*/
#include<bits/stdc++.h>
using namespace std;
int w[9]={0,1,11,21,23,33,43,45,55};
int p[9]={0,11,21,31,33,43,53,55,65};
int y[9],x[9],fp=-1,fw;
int m=110;
int n=8;
void show()
{
float s=0.0;
cout<<"\n\tItem\tWeight\tCost\tSelected";
for(int i=1;i<9;i++)
printf("\n\t%d\t%d\t%d\t%d",i+1,w[i],p[i],x[i]);
printf("\n\n The Sack now holds following items : ");
for(int i=1;i<9;i++){
if(x[i]==1)
{
cout<<i+1<<"     ";
s += (float) p[i] * (float) x[i];
}
}
printf("\n Maximum Profit: %f ",s);
}
/*Arrange the item based on high profit per Unit*/
float bound(float cp,float cw,int k)
{
float b = cp;
float c = cw;
for(int i=k+1;i<=n;i++)
{
c = c+w[i];
if( c < m)
b = b +p[i];
else
return (b+(1-(c-m)/ (float)w[i])*p[i]);
}
return b;
}
void knapsack(int k,float cp,float cw)
{
if(cw+w[k] <= m)
{
y[k] = 1;
if(k < n)
knapsack(k+1,cp+p[k],cw+w[k]);
if(((cp+p[k]) > fp) && ( k == n))
{
fp = cp+p[k];
fw = cw+w[k];
for(int j=1;j<=k;j++)
x[j] = y[j];
}
}
if(bound(cp,cw,k) >= fp)
{
y[k] = 0;
if( k < n)
knapsack(k+1,cp,cw);
if((cp > fp) && (k == n))
{
fp = cp;
fw = cw;
for(int j=1;j<=k;j++)
x[j] = y[j];
}
}
}
int main()
{
printf("\n\n\n\t\t    *******************************************************");
     cout<<"\n\t\t    *                                                     *" ;
     cout<<"\n\t\t    *           0/1 KNAPSACK USING BACKTRACKING           *";
for(int i=0;i<2;i++)
     cout<<"\n\t\t    *                                                     *";
    printf("\n\t\t    *******************************************************");
printf("\n The Sack is arranged in the order - -\n");
knapsack(1,0.0,0.0);
show();
return 0;
}
