#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;
deque <int> d;
int main()
{
//freopen("input.txt", "rt", stdin);
int n,m,i,j,v,cnt=0,find,tmp,left,right,tmp1;

scanf("%d %d",&n,&m);
	
	for(i=1; i<=n; i++)
	{
		d.push_back(i);   // ���� ������� �Է�  
	}
	
	for(i=1; i<=m; i++)
	{
		scanf("%d",&v);   // ã������ �� 
		
		find=0;
		
		if(d.front()==v)    //�Ǿ��� ã������ ���� ������ �ٷ� POP 
			{    
		
				d.pop_front();
			     
			}
		else{
	                for(j=0; j<d.size(); j++)  // ã������ ���� ���� ���°�� �ִ���  
					{
						find++;               
						 
						if(v==d[j])
						{
							break;
						}
					   }
					   tmp1=d.size();      
					   
					  
					   left=abs(1-find);   //���ʿ��� 2�� ������ ����ؾ� �ϴ���    
					   right=abs(tmp1-find)+1;  //�����ʿ��� 3�� ������ ����ؾ� �ϴ���(  �����ʿ��� �Ҷ��� �ش��ϴ� ���� 3�� ������ ���� 
					                                                             // �Ǿ����� ��������ϴ� +1�� ���ش�. 
					
					   if(left<=right)
					   {
					   	while(1)
					   	{
					   		tmp=d.front();
					   		
					   		if(tmp==v)
					   		{  
					   	
							   	   d.pop_front();
					   			break;
							   }
							   
							   else if(tmp!=v)
							   {
							   	   d.pop_front();
							   	   d.push_back(tmp);
							   	   cnt++;
							   	   
							   }
						   }
					   }
					   
					   else if(left>right)
					   {
					   	while(1)
					   	{
					   		tmp=d.back();
					   		d.pop_back();
					   	   d.push_front(tmp);
					   	   cnt++;
					   	   
					   	   if(tmp==v)
					   	   {
					   	   	   d.pop_front();
					   	   	   
					   	   	   break;
							  }		   		
					   }		      
			}	
	}
}
printf("%d",cnt);

return 0;

}
