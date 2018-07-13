#include<cstring>
#include<iostream>
#include<string>
#include<queue>
using namespace std;

 string maze_name;
 int r0, c0, r1, c1, dir, r2, c2;
 
 const char *dirs = "NESW";
 const char *turns = "FLR";
 
 struct Node{
 	int r,c,dir;
 	Node(int r = 0, int c = 0, int dir = 0):r(r), c(c),dir(dir){
 		
	}
 };
 
int dir_id(char c){
	return strchr(dirs,c) - dirs;
}

int turn_id(char c){
	return strchr(turns, c) - turns;
}

const int dr[]= {-1, 0 ,1, 0};
const int dc[]= {0,1,0,-1};

const int maxn = 20;
int has_edge[maxn][maxn][maxn][maxn];
int d[maxn][maxn][maxn];
Node p[maxn][maxn][maxn];

void read_edge(){
	memset(has_edge, 0, sizeof(has_edge));
	int  pr, pc, pdir,pturn;
	string temp;
	while(cin>>pr){
		if(pr==0) break;
		cin>>pc;
		while(cin>>temp){
			if(temp=="*") break;
			pdir = dir_id(temp[0]);
			
			for(int i =1; i < temp.size(); i++){
				pturn = turn_id(temp[i]);
				has_edge[pr][pc][pdir][pturn] = 1;
			}
		}
	}
}
bool read_list(){
	cin>>maze_name;
	if(maze_name == "END") return false;
	char dir0;
	cin>>r0>>c0>>dir0>>r2>>c2;
	dir = dir_id(dir0);
	r1 = r0 + dr[dir];
	c1 = c0 + dc[dir];
	read_edge();
	return true;
}
Node walk(const Node &u, int turn){
	int dir = u.dir; //�ı䷽��
	if(turn == 1) dir = (dir + 3) % 4;
	if(turn == 2) dir = (dir + 1) % 4;
	return Node(u.r + dr[dir], u.c+dc[dir], dir);
}

bool inside(int r, int c){
	if(r >= 1 && r<=9 && c>=1 && c<=9)
		return true;
	return false;
}
void print_ans(Node u){
	// ��Ŀ��ڵ�����׷˷����ʼ�ڵ�
	 vector<Node> v;
	 while(1){
	 	v.push_back(u);
	 	if(d[u.r][u.c][u.dir]==0) break;
	 	u = p[u.r][u.c][u.dir];
	 }
	 v.push_back(Node(r0, c0, dir));
	 
	 cout<<maze_name<<endl;
	 // ��ӡ��
	 int cnt = 0;
	 for(int i = v.size()-1; i>=0; i--){
	 	if(cnt % 10 ==0) cout << " ";
	 	cout<<" (" << v[i].r <<","<<v[i].c<<")";
	 	if(++cnt % 10 ==0) cout<<endl;
	 } 
	 if(v.size()%10 !=0) cout<<endl;
}

void solve(){
	queue<Node> q;
	memset(d, -1, sizeof(d));
	Node n1(r1, c1, dir);
	q.push(n1);
	d[r1][c1][dir] = 0;
	
	while(!q.empty()){
		Node u = q.front(); q.pop();
		if(u.r== r2 && u.c == c2){
			print_ans(u);
			return;
		}
		for(int i = 0; i<3;i++){
			Node v = walk(u, i);
			if(has_edge[u.r][u.c][u.dir][i] && inside(v.r, v.c) && d[v.r][v.c][v.dir]<0){
				d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] +1;
				p[v.r][v.c][v.dir] = u;
				q.push(v);
			}
		}
	}
	
	cout<<maze_name<<endl;
	cout<<"  No Solution Possible"<<endl;
}

int main(){
	while(read_list()){
		solve();
	}
	return 0;
}
