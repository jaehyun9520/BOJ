#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int map[2188][2188];
int a[3]={0};
	

void func(int n, int x, int y)
{
	int i,j,val,flag=0;
	if(n==1)   
	{
		
				if(map[x][y]==-1)
				  {
				
				             a[2]++;
			      }
				             else
				             {
							 
				               a[map[x][y]]++;
				           }
		
	}
	
	else{
		
	          val=map[x][y];  // Ȯ���ҷ��� �ϴ� ������ ù��° ��  
	         
	          
	          
	          
	          for(i=x; i<x+n; i++)
	          {
	          	for(j=y; j<y+n; j++)
	          	{
	          		if(val!=map[i][j])  // ���� �ٸ��� ���� 9���  
					  {
					  flag=1;
					  break;
				}
				  }
			  }
			  
			  if(flag==0)   //  ���� ���� ���� �� ���� ���� ä�������  
			  {
			  	if(val==-1)   a[2]++;
			  	
			  	
			  	else
			  	   a[val]++;
			  }
			  
			  
			  else if(flag==1)  // 9���  
			  {
			  	
			  	func(n/3,x,y);     
			  	func(n/3,x,y+n/3);   
			  	func(n/3,x,y+2*n/3);     
			  	func(n/3,x+n/3,y);     
			  	func(n/3,x+n/3,y+n/3);  
			  	func(n/3,x+n/3,y+2*n/3);
			  	func(n/3,x+2*n/3,y);
			  	func(n/3,x+2*n/3,y+n/3);
			  	func(n/3,x+2*n/3,y+2*n/3);
			  	
			  }
		
	}

	
	}	


int main()
{
//freopen("input.txt", "rt", stdin);
int n,i,j,val;
scanf("%d",&n); 

for(i=1; i<=n; i++)
{
	for(j=1; j<=n; j++)
	{
		scanf("%d",&map[i][j]);
		
	}
}

func(n,1,1);   

printf("%d\n%d\n%d",a[2],a[0],a[1]);
return 0;

}
