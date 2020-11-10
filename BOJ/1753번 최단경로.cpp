#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


struct edge{
	
	int node;
	int val;
	
	    edge(int a, int b)
	    {
	    	node=a; val=b;
		}
		
		bool operator<(const edge &b) const
		{
			return val>b.val;
		}
};
vector <edge>  list[20000]; //�� ��忡 ����� ����  ���� ����ġ�� �������ִ� ��������Ʈ 
bool check[20001]={0}; 

vector <int> dis(20001,2147000000);  // ������������ �� ����������� ����ġ ����ϴ� �迭  
priority_queue <edge> PQ;   

int main()
{
//freopen("input.txt", "rt", stdin);	
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

int v,e,k,i,n1,n2,val,node; 
cin>>v>>e;

cin>>k;

PQ.push(edge(k,0));

for(i=1; i<=e; i++)
{
	cin>>n1>>n2>>val;
	
	list[n1].push_back(edge(n2,val)); 
}

dis[k]=0;  	  //��ó���� �ڱ��ڽ��̹Ƿ� ���Ѵ뿡�� 0���� ����

while(!PQ.empty())
{
	node=PQ.top().node;
	val=PQ.top().val;
	PQ.pop();
	if(check[node]==0)
	{
		check[node]=1;

		
		
		 for(i=0; i<list[node].size(); i++)
		 {
		 	if(dis[list[node][i].node]>dis[node]+list[node][i].val) //���� ��ϵ� ����ġ ������ �۴ٸ�? 
		 	{
		 		dis[list[node][i].node]=dis[node]+list[node][i].val; //�� ���������� ���� 
		 		PQ.push(edge(list[node][i].node,list[node][i].val+dis[node]));  // ���� ����ġ�� ť�� �־���  
			 }
		 	
		 	
		  } 
	}
}

for(i=1; i<=v; i++)
{
	if(dis[i]!=2147000000)
	cout<<dis[i]<<"\n";
	else
	cout<<"INF"<<"\n";
}


return 0;
}
