#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

int n,result=0,out=0;

int runner[4]={0};  //  1�� 2�� 3�翡 ���ڰ� �����ִ���  
int t[10]={0};   // 1��~9��Ÿ�ڰ� ��� ������ �������ִ���  
int check[10]={0};  // �ߺ������� �����ϱ� ���� �̹� Ÿ�ڷ� ���� ������ ���̵���  
int map[51][10]={0}; // �� ������ �� �̴׿��� ��� ��� ����  


void play(int x)  // �߱����� �ùķ��̼�   x�� �� �̴����� ����Ǵ���  
{
	int i,j;
	 
	int number=1; //1�� Ÿ�ں��� ����  
	int k=0;   
	int score=0;  

	for(i=1; i<=x; i++)   //1�̴׺��� x�̴ױ��� 
	{
	   out=0;   //�� �̴��� �����Ҷ����� out Ƚ�� �ʱ�ȭ 
	   for(j=1; j<=3; j++)  // �� �̴� �����Ҷ����� ���� �ʱ�ȭ  
	   {
	   	runner[j]=0;  
	   }
	   
	    
	   while(1)   
	{

		   k=map[i][t[number]];  // ���� �����ִ� Ÿ�ڰ� 1~9�� ���� �� ��� �������� �׸��� ���� ���� �̴׿� � ����� ����� ����  

		    if(k==0)  // �ƿ��̸�  
		      {
		      	number++;   // ���� ��ȣ�� Ÿ��  
		      	if(number>9)  // 9�� Ÿ�ڱ��� ������ �ٽ� 1��Ÿ��  
		      	{
		      		number=1;
				  }
		      	out++;  // �ƿ� Ƚ�� �߰�  
		      	if(out==3)  // 3�ƿ��̸� �̴� ����  
		      	break;
		    
			  }
			  
			  else if(k!=0)   // �ƿ��� �ƴ϶� 1�� 2�� 3�� Ȩ�� �̸�? 
			  {
			  	number++;   
			  	if(number>9)
			  	{
			  		number=1;
				  }
			  	for(j=3; j>=1; j--)   // 3����� 1����� ���ڰ� �����ִ���? 
			  	{
			  		if(runner[j]==1)
			  		{
			  			if(j+k>=4)   // 3�翡 ���ڰ� �ִµ�   1��Ÿ�� ������ 3�翡 �ִ� ���ڴ� Ȩ���� ���� ���� +1        
			  			{
			  				runner[j]=0;
			  				score++;
						  }
						  
						else if(j+k<=3)  // 1�翡 ���ڰ� �����ִµ� Ÿ�ڰ� 1��Ÿ�� �������   1�翡 �ִ� ���ڴ� 2���  Ÿ�ڴ� 1���  
						{
							runner[j+k]=1;
							runner[j]=0;
						  }  
					  }
				  }
				if(k==4)   // Ȩ���� ���  Ÿ�ڵ� Ȩ���� ���� ����  
				{
					score++;
				  }
				else if(k<=3)  // 1��Ÿ~3��Ÿ �� �ϳ��� ��� Ÿ�ڸ� �ű�  
				{
					runner[k]=1;
				  }  
				    
				  
			  	
			  	
	           }   	
	}	
 } 
 
 if(result<score)
 {
 	result=score;
 }
}

void team(int number)   // ���� Ÿ�ڷ� ���� ���� ��    9���� �� ������ ���� ����  
{
	int i;
	if(number==9)  
	{
		
				for(int j=1; j<=9; j++)
		{
			printf("%d",t[j]);
		}
		
		printf("\n");
		play(n);   
	}
	
	else if(number==3)      //  4��Ÿ�ڴ� 1�� ����  
	{
		team(number+1);
	}
	
	
	else 
	{
		for(i=2; i<=9; i++)   // �������� Ÿ�� ���ϱ� (����)  
		{
			if(check[i]==0)
			{
				check[i]=1;
				t[number+1]=i;
				
		
				
				team(number+1);
				check[i]=0;
			}
		}
		
	 } 
	
	
 } 

int main()
{
//freopen("input.txt", "rt", stdin);
int i,j;

scanf("%d",&n);

for(i=1; i<=n; i++)
{
	for(j=1; j<=9; j++)
	{
		scanf("%d",&map[i][j]);
	}
}
t[4]=1;


for(i=2; i<=9; i++)  // 2~9�� ���� Ÿ���� ������ ¥��  
{
	check[i]=1;
	t[1]=i;
	team(1);  
	check[i]=0;
}


printf("%d",result);
return 0;

}

