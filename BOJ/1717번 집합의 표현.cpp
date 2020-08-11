#include<iostream>
#include<algorithm>



using namespace std;

int node[1000001]={0};   



int find(int a)  // �θ��� ã��  
{
	if(node[a]==a) return a;  
	
	else return node[a]=find(node[a]);
}

void Union(int a, int b)   // �� ���� ��尡 ���� ���� ��ġ��  
{
	a=find(a);
	b=find(b);
	
	if(a!=b)
	{
		node[a]=b;
	}
	
}

int main()
{
//freopen("input.txt", "rt", stdin);

int n,m,i,a,b,c;
scanf("%d %d",&n,&m);

for(i=0; i<=n; i++)  //�ʱ�ȭ  
{
	node[i]=i;
}


for(i=1; i<=m; i++)
{
	scanf("%d %d %d",&a,&b,&c);
	
	if(a==0)
	{
		Union(b,c);
	}
	
	else
	{
		if(find(b)==find(c))
		  printf("YES\n");
		  
		  
		  else
		   printf("NO\n");
		
		
	}
}




return 0;

}
