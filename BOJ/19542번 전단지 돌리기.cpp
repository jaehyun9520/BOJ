#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
int n,s,d,y=0;
vector <int> node[100001];
int check[100001]={0};
queue <int> Q;


void DFS(int x, int cnt)  // x: ����ȣ  cnt: ����  
{
    
	int next;
	
if(cnt>d)
   {

	y=1;   
	}	
	
else if(cnt<=d&&y==0)
	{
		for(int i=0; i<node[x].size(); i++)
		{
			next=node[x][i];
			
			if(check[next]==0&&y==0)
			{
				
			
				check[next]=1;
				DFS(next,cnt+1);
				check[next]=0;
			}
		}
}
 
		
		}	
		
	
	
	 




int main()
{
//freopen("input.txt", "rt", stdin);

int i,a,b,now,next,dis=0;
scanf("%d %d %d ",&n,&s,&d);



check[s]=1; // ������ġ  
Q.push(s);

for(i=2; i<=n; i++) // ��� ����  
{
	scanf("%d %d",&a,&b);
	
	node[a].push_back(b);
	node[b].push_back(a);
}




while(!Q.empty())  // ���� ���� ����Ǿ��ִ� ��� Ž��  
{
	now=Q.front();
	if(now!=s)
	{
		
		dis++;
		
	}
	Q.pop();

	
	
	for(i=0; i<node[now].size(); i++)
	{
		next=node[now][i];
		if(check[next]==0)  // �湮�ߴ���  
		{
			
		
			check[next]=1;
			y=0;
		
			DFS(next,1);  // ��������� ���̰� ������  
	
		if(y==1)  // ���̰� D(��)���� ũ�� ���� �̵�  
		{
		
		
			Q.push(next);
			
		}
			
		}
		
		
	}
	
}

printf("%d",dis*2);  // ���ư��°ͱ��� �̵��Ÿ��� ����ؾ��ϴ� *2  


return 0;

}

