#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int check[9];
int a[9];
int n,m,cnt=0;

void DFS(int x)
{
   if(cnt==m)    // �������� �־��� �ʿ��� ������ ������ ���õ� ������ ���� �� 
   {
   	for(int j=1; j<=m; j++)
   	{
   		printf("%d ",a[j]);
	   }
	   printf("\n"); 
   }
   
  
   
 else   
 { 
   for(int i=1; i<=n; i++)
   {
   	  if(check[i]==0)
   	  {
   	  	check[i]=1; 
   	  	a[++cnt]=i;
   	  	DFS(i);
   	  	check[i]=0; 
   	  	cnt--;
		 }
   	
   }
}
   
}
int main(){
//freopen("input.txt", "rt", stdin);
int i;
	scanf("%d %d",&n,&m);
	DFS(0);
	return 0;
}
