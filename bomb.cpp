#include<iostream>
#include<iomanip> 
#include<cstdlib>
#include<ctime>
using namespace std;

char board[10][10];
char userboard[10][10];
bool win=false; 


void init(int bomb){
	
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
		{	
			board[i][j]=' ';
			userboard[i][j]='@';
		} 
	srand(time(NULL));	
	
	for(int n=0;n<bomb;)
	{
		int x=rand()%100;
		if(board[x/10][x%10]!='x')
		{
			board[x/10][x%10]='x';
			n++;
		}
	}
	
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			int countbomb=0;
			if(board[i][j]=='x')
			continue;
			 
			if(i!=0&&j!=0&&board[i-1][j-1]=='x')
			countbomb+=1;
			if(i!=0&&board[i-1][j]=='x')
			countbomb+=1;
			if(i!=0&&j!=9&&board[i-1][j+1]=='x')
			countbomb+=1;
			if(j!=0&&board[i][j-1]=='x')
			countbomb+=1;
			if(j!=9&&board[i][j+1]=='x')
			countbomb+=1;
			if(i!=9&&j!=0&&board[i+1][j-1]=='x')
			countbomb+=1;
			if(i!=9&&board[i+1][j]=='x')
			countbomb+=1;
			if(i!=9&&j!=9&&board[i+1][j+1]=='x')
			countbomb+=1;
			
			if(countbomb!=0)
			board[i][j]=countbomb+48;
		}
	}
}

bool play(int bomb){
	int x,y;
	bool end=false;
	cout<<"Please tell me where you want to check?(row,col)"<<endl; 
	cin>>x>>y;
	userboard[x-1][y-1]=board[x-1][y-1]; 
	if(board[x-1][y-1]=='x')
		end=true;
		
	for(int i=0;i<=10;i++)
	{
		for(int j=0;j<=10;j++)
		{ 
			if(i==0)
			{
				cout<<' '<<j;
				continue;
			}
			if(j==0)
			{
				cout<<setw(2)<<i<<' ';
				continue;
			}
			if(userboard[i-1][j-1]==' ')
			cout<<'o'<<' ';
			else 
			cout<<userboard[i-1][j-1]<<' ';
		}
		cout<<endl;
	}
	int countbomb=0; 
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
	 		if(userboard[i][j]=='@')
			 	countbomb+=1;
	if(countbomb==bomb)
	{
		end=true;
		win=true; 
	} 
	
	return end;
	
}

int main()
{
	int bomb;
	cout<<"the game is 10x10 bomb games."<<endl; 
	cout<<"Please give the number of bombs:";
	cin>>bomb;
	init(bomb);
	bool end=false;
	while(!end)
	{
		end=play(bomb);
	}
	if(win)
	cout<<"Congratulation!!!"<<endl;
	else
	cout<<"Maybe you can try again."<<endl; 
}
