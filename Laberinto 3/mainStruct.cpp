#include<bits/stdc++.h>
using namespace std;
#define maxn 10010
struct dot{
	int x;
	int y;
	int pre;
}temp;
queue<dot>q;
stack<dot>s,s1;
int dir[4][2]={-1,0,0,-1,1,0,0,1};
int main()
{
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int ma[111][111]={// Establecer la matriz del laberinto
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,1,0,0,0,1,0,1},
		{1,0,0,1,0,0,0,1,0,1},
		{1,0,0,0,0,1,1,0,0,1},
		{1,0,1,1,1,0,0,0,0,1},
		{1,0,0,0,1,0,0,0,0,1},
		{1,0,1,0,0,0,1,0,0,1},
		{1,0,1,1,1,0,1,1,0,1},
		{1,1,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1},
	};
	dot start,t; 
	int xe=8;
	int ye=8; 
	start.x=1;
	start.y=1;
	start.pre=1;
	ma[start.x][start.y]=-1;
	q.push(start);
	while(q.back().x!=xe||q.back().y!=ye){
		start=q.front();
		s.push(start);
		q.pop();
		for( int i=0; i<4; i++ ){
			dot ans;
			ans.x=start.x+dir[i][0];
			ans.y=start.y+dir[i][1];
			if(ma[ans.x][ans.y]==0){
				ans.pre=start.pre+1;
				q.push(ans);
				ma[ans.x][ans.y]=-1;
			}
		}
	}
	while(!q.empty()){
		start=q.front();
		q.pop();
		s.push(start);
	}
//	temp.x=8;temp.y=8;temp.pre=0;
//	s1.push(temp);
	int ansx=8,ansy=8,cnt=s.top().pre-1;
	while(cnt!=1){
		temp=s.top();
		if(temp.pre!=cnt) s.pop();
		else if(temp.pre==cnt&&(temp.x==ansx&&abs(temp.y-ansy)==1||temp.y==ansy&&abs(temp.x-ansx)==1)){
			s1.push(temp);
			cnt=temp.pre-1;
			ansx=temp.x;ansy=temp.y;
		}
		else s.pop();
	}
//	temp.x=1;temp.y=1;temp.pre=0;
//	s1.push(temp);
	while(!s1.empty()){
		temp=s1.top();
		s1.pop();
		cout<<temp.x<<' '<<temp.y<<'\n';
	}
	return 0;
}
