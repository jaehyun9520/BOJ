#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
int s[100001]={0};
int group[100001]={0}; // �׷쿡 �����ִ���  
int check[100001]={0}; // 
vector <int> use; 
queue <int> Q;
int main()
{
//freopen("input.txt", "rt", stdin);
int t,n,i,j,now,cnt;
scanf("%d",&t); 
for(i=1; i<=t; i++)
{
	scanf("%d",&n);
	 
	for(j=1; j<=n; j++)
	{
	
		scanf("%d",&s[j]);   
		group[j]=0;
	
	}
	
	cnt=0;
	

	
	

	for(j=1; j<=n; j++)
	{
	   if(group[j]==0)    // ��� ������ ������ ���� ���  
		{
		   Q.push(j);
		   
		   
		   while(!Q.empty())
		   {
		   	   now=Q.front();  // ���� �л� ��ȣ  
		   	   Q.pop();
		   	   
		   	   if(check[now]==0&&group[now]==0)  // ��  ����⸦ ������ ���°��  
		   	   {
		   	   	    use.push_back(now);  
		   	   	   check[now]=1;     
		   	   	   
		   	   	   Q.push(s[now]);
		   	   	   
		   	   	   
				  }
				  
				  else if(check[now]==1)   // ���� �л���ȣ�� �� ���°�� ���� ���������  
				  {
				  	while(1)
				  	{
				  		if(now==use.back())  // �ߺ��� �л���ȣ�� �ٽ� �������� ����  
				  		{
				  			group[now]=1; // 1�� ���� ���Ѱ����� ǥ��  
				  			check[now]=0; // 
				  			use.pop_back();
				  			break;
						  }
						  
						  else if(now!=use.back()){ // ���� �л����� ���� �� 
						  	   group[use.back()]=1; // ���� ���ߴٰ� 1 ǥ��  
						  	   check[use.back()]=0;
						  	   use.pop_back();
						  	
						  }
					  }
				  }
		   }
		   
		   
		   while(!use.empty())  // ���� ������ ���� �л���  
		   {
		   	     cnt++;// ���� ������ ���� �л� �� ī��Ʈ  
		   	     
		   	     group[use.back()]=-1; 
		   	     check[use.back()]=0;
		   	     use.pop_back();
		   }
		}
	
}
printf("%d\n",cnt);

}

return 0;

}
