#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,ans=0;
void DFS(int s, int d[], int w[])  // s: ���� ����ִ� ����� ��ȣ , �Ű������� �������� ���Թ迭�� �Ѱܹ���  
{
	int flag=0,tmp=0,i,j,cnt=0; 
	int d1[n+1];
	int w1[n+1];
	
	for(i=1; i<=n; i++)
	{
		d1[i]=d[i];   // ���纻�� �� ����  
		w1[i]=w[i];
	
		
	}

	
	for(i=1; i<=n; i++)
	{
		
		if(i!=s&&d1[i]>=1)  // �������ִ� ����� ��ȣ�� �����ϰ� �������� �����ִ� ����� ����  
		{
		   flag=1;	
		   d1[s]=d1[s]-w1[i];   // ������� ��� ����  
		   d1[i]=d1[i]-w1[s];
			
			tmp=s+1;     
			
			while(1)   
			{
				if(d1[tmp]>=1&&tmp<=n)   // ���� �������� n�� ����̴� n�������̸鼭 �������� ������ ����ִ�. 
				{
					DFS(tmp,d1,w1);  // ������ ��츦 Ȯ��  
					break;
				}
				
				else{
					
					if(tmp==n+1)   // n+1�̸� ������ ������ �°Ŵ� ���� ����� ��ִ��� Ȯ�� �� ���簪���� �������� ����  
					{   cnt=0;
				     	for(j=1; j<=n; j++)
				     	{
				     		if(d1[j]<=0) cnt++;
						 }
						 
						 if(ans<cnt)  ans=cnt;
					   break;
				}
				
				tmp++;  
				}
	
				
			}
			 
		 d1[s]=d1[s]+w1[i];   // �ٸ� ��쵵 Ȯ���ؾ��ϴ� �������·� �ǵ�����  
		   d1[i]=d1[i]+w1[s];	
		}
	}
	
	if(flag==0)   // ����� �� ���¿��� �ѹ��� �ٸ� ����� ġ�� ���Ѱ�� ���̻� �����Ҽ������� ��� �����ִ��� Ȯ��  
	{
		cnt=0;
				     	for(j=1; j<=n; j++)
				     	{
				     		if(d1[j]<=0) cnt++;
						 }
						 
						 if(ans<cnt)  ans=cnt;
					
		
	}
	
	
}


int main()
{
//freopen("input.txt", "rt", stdin);
int i,a,b;
scanf("%d",&n);

int d[n+1];    // ����� �������� ��Ÿ���� �迭 
int w[n+1];    // ����� ���Ը� ��Ÿ���� �迭  
for(i=1; i<=n; i++) 
{
	scanf("%d %d",&a,&b);
	d[i]=a;  
	w[i]=b; 
}

DFS(1,d,w);  
printf("%d",ans);
return 0;
}
