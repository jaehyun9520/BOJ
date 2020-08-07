#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int n,i,j,a,val,x=0,y=0,result=9999;
int color[11]={0};
int map[11]={0};
int check[11]={0};
vector <int> node[10];


void dfs2(int x)  // ���ű��� ���� �������� ����Ǿ��ִ��� Ȯ�� X=  ������ȣ  
{
	int tmp,j;
	check[x]=1;   
	

	for(j=0; j<node[x].size(); j++)
	{
		 tmp=node[x][j];
		 if(check[tmp]==0&&color[x]==color[tmp])   
		 {
		 	dfs2(tmp);
		 }
	}
}

void dfs(int cnt, int node)  // cnt= A���ű��� �̴� ������ ���� , node= ��� ��������  
{
	int flag=0,a=0,b=0,j,i;   
   
   for(j=1; j<=n; j++)
   {
   	check[j]=0;          
   }

	if(cnt<=(n/2))    // ������ ������ 10�����  A������ 1������ 5������ �̴°���� ���� �ϸ� �ߺ��Ǵ°� ����  
	{

	
	
	for(i=node; i<=n; i++)  // A���ű��� ���� �̱�    
	{	 
		if(color[i]==0)  
		{      
	
			color[i]=1;   // A���ű��� ���� ������ 1�� ǥ��  
			
			
			
			 
			dfs2(i); // A���ű��� ���� �������� ���� ����Ǿ��ִ��� Ȯ��  
			
			
			
			for( j=1; j<=n; j++)     //  A���ű��� ���������� �� B���ű��� ���� �������� ���� ����Ǿ��ִ��� Ȯ��  
			{
				if(color[j]==0&&check[j]==0)
				{
					dfs2(j);
					break;
				}
						}			
		
		
			for(j=1; j<=n; j++)   
			{
				if(check[j]==0)
				{
					flag=1;   //    ���� ���ű��� �������� ���� ��������� ����   
				}
		}		
		if(flag==0)  // �� ���ű��� �������� ����Ǿ����� 
			{
				for(j=1; j<=n; j++)
				{
					if(color[j]==1)
					{
						a=a+map[j];     //   A���ű��� �α��� ����  
					}
					else if(color[j]==0)
					{
						b=b+map[j];  // B���ű��� �α��� ����  
					}
				}
				if(result>abs(a-b))   // �ּҰ� ã��  
			{
				
				result=abs(a-b);
			}
			
			}
			dfs(cnt+1,i+1);
			
			

			   color[i]=0;
               a=0; b=0; flag=0;  
			   for(j=1; j<=n; j++)    
			   {
			   	check[j]=0;
						   }			
			
		
		}
		
	}
}
	
	
}
 

int main()
{//freopen("input.txt", "rt", stdin);

scanf("%d",&n);


for(i=1; i<=n; i++)    // �� ������ �α��� �ޱ�  
{
	scanf("%d",&map[i]);
}


for(i=1; i<=n; i++)  // �� ������� ����� ������ ����    ���� ��������Ʈ �̿�   
{
	scanf("%d",&a);
	
	for(j=1; j<=a; j++)
	{
		scanf("%d",&val);
		node[i].push_back(val);
	}
	
}


dfs(1,1);  //  N���� ������ A���ű��� �̴� ����� �� ���ϱ� �̶�    1~N/2���� �̱�  (����) 

  
if(result==9999)    
{
	printf("-1");   
}
else{

printf("%d",result);
}
return 0;

}

