#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, ans=-2147483640;
int number[11]={0};  // �ǿ����ڴ� �ִ� 10��  
int o[10]={0};  // �����ڴ� �ִ� 9��
int check[10]={0};   // ���ո����  



void DFS(int x)
{
	int i,total=number[1],tmp; // total= ������ ���� ��Ÿ�� ��ó�� ���� ���� ������ �ǿ����� ��  



for(i=1; i<=n/2; i++)
{
	printf("%d ",check[i]);
}
printf("\n");


	for(i=1; i<=n/2; i++)  // ���� ���  
	{
		if(check[i]==0&&check[i+1]==0)   //   �� �ڿ� �����ڵ� ��ȣ�� ������ �״�� ���    
		 {
			if(o[i]=='+')   total=total+number[i+1];
			else if(o[i]=='-')  total=total-number[i+1];
			else if(o[i]=='*')  total=total*number[i+1];     
		}  
		
		if(check[i]==1)  // ���� �����ڰ� ��ȣ�� ��������� ���� ��� 
		{
			if(o[i]=='+')   tmp=number[i]+number[i+1];
			else if(o[i]=='-')  tmp=number[i]-number[i+1];
			else if(o[i]=='*')  tmp=number[i]*number[i+1];
			
			if(o[i-1]=='+')   total=total+tmp;   // �� �ڿ� ���� ���� ���  
			else if(o[i-1]=='-')  total=total-tmp;
			else if(o[i-1]=='*')  total=total*tmp;  
			
			
		}
		
		
	}

	if(ans<total)  ans=total;

	 for(i=x; i<=n/2; i++)
	 {
	 	if(check[i-1]==0&&check[i]==0) // ������ �����ڰ� ��ȣ�� ������ ���ٸ� ���� ����, �ț��ٸ� ��������  
	 	{
	 		check[i]=1;
	 		  DFS(i+1);
	 		check[i]=0;
		 }
	 	
	 }
	
}
int main()
{
//freopen("input.txt", "rt", stdin);
int i,p1=1,p2=1; 
char a[20];

scanf("%d",&n);

scanf("%s",a);

for(i=1; i<=n; i++)
{
	if(a[i-1]=='+'||a[i-1]=='-'||a[i-1]=='*')
	{
		o[p1++]=a[i-1];  // ������ ����    i�� �����ڴ� i�� �ǿ����ڿ� i+1�� �ǿ����ڸ� �����ְԲ� ���� 
	}
	else{
		number[p2++]=a[i-1]-48;   // �ǿ����� ���� 
	}
}


DFS(2);  // ù��° �����ڴ� ��ȣ�� �ʿ���� �����ϰ� �ι�° �����ں��� ���ո����  

printf("%d",ans);
return 0;
}
