#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,k,val,sp=0,ep=0,cnt=0,ans=0,i;   
vector <pair <int , int > > conveyer; // first�� ������ second�� �κ�����  
queue <int> reuse;
queue <int> robot;
void p1()
{
	sp--; ep--; // �������� �������� ��ĭ�� �ڷ�  
	

	if(sp<0)  sp=2*n-1;
	if(ep<0)  ep=2*n-1;

}

void p2()
{
	int x,tmp;
	while(!robot.empty())  // �κ��� ��ġ�� ���ʺ��� ������  
	{
		x=robot.front();
		robot.pop();

		if(x==ep) conveyer[x].second=0; // ���� p1�� ���� �������� �����ߴٸ� �״�� �����ֱ�  
		
		else {
		   tmp=x+1;	  if(tmp>2*n-1) tmp=0;  // ����ĭ tmp 
		   
		   if(conveyer[tmp].first>0&&tmp==ep)   //����ĭ�� �������̰� �������� ������ �ٷ� �����ֱ�  
		   {
		   	conveyer[tmp].first--;  if(conveyer[tmp].first==0) cnt++;
		   	conveyer[x].second=0;
		   	
		   }
		   
		   else if(conveyer[tmp].first>0&&conveyer[tmp].second==0) // ����ĭ�� �������� �ְ� �κ��� ������  
		   {
		   	conveyer[tmp].first--;  if(conveyer[tmp].first==0) cnt++;
		   	conveyer[tmp].second=1;  conveyer[x].second=0;
		   	reuse.push(tmp);
		   }
		   
		   
		   else {  // ������ ������ �ٽ� �־��ֱ�  
		   	reuse.push(x);
		   }
		}
	}
	
	while(!reuse.empty())
	{
		robot.push(reuse.front());  
		reuse.pop();
	}
	 
	
}
void p3()
{

	if(conveyer[sp].first>0&&conveyer[sp].second==0)
	{
		
		conveyer[sp].first--;
		if(conveyer[sp].first==0) {
		cnt++;}
		
		robot.push(sp);
		conveyer[sp].second=1;
	
		
			}
}


int main()
{	
//freopen("input.txt", "rt", stdin);



scanf("%d %d",&n,&k);
ep=n-1;

for(i=1; i<=2*n; i++)
{
	scanf("%d",&val);
	conveyer.push_back(make_pair(val,0));
 }
while(cnt<k)
{
	
	ans++;
	p1();
	p2();
	p3();
	
	
}
  printf("%d",ans);
return 0;
}
