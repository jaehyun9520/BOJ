#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int map[65][65]={0};


void func(int n, int x, int y)   
{
	int val,flag=0;
	  val=map[x][y];
	if(n==1) 
         {
         	printf("%d",map[x][y]);
		 }
     
     else{
     	
     	for(int i=x; i<n+x; i++)     //  ������ ��� ���� ���� �̷�����ִ���  
     	{
     		for(int j=y; j<n+y; j++)
     		{
     			if(val!=map[i][j])
     			{
     				flag=1;
     				break;
				 }
			 }
		 }
		 
		 if(flag==1)  // �ƴ϶�� 4��� 
		 {
		 	printf("(");
		 	
		 	func(n/2,x,y);  // ���� ��  
		 	func(n/2,x,y+n/2);   //������ �� 
		 	func(n/2,x+n/2,y);   // ���� �Ʒ�  
		 	func(n/2,x+n/2,y+n/2);  // ������ �Ʒ�  
		 	
		 	printf(")");
		 }
		 else if(flag==0)
		 {
		 	printf("%d",val);
		 }
	 }

   
}


int main()
{
//freopen("input.txt", "rt", stdin);
int n,i,j;
scanf("%d",&n);  
char a[65];

for(i=1; i<=n; i++)
{
	scanf("%s",a);
	for(j=1; j<=n; j++)
	{
		map[i][j]=a[j-1]-48;
		
	}
	
}

func(n,1,1); 

return 0;


}
