#include<cstdio>
#include<cstring>
const int maxn = 8;

int G[maxn][maxn];
int mark[7][8];
int ans[7][8];
int vis[7][8];
int v[30];
int tot, kase = 0, sum;

int dx[] = {0, 1};
int dy[] = {1, 0};


// ��ʼ�� 
void init(){
	memset(G, 0, sizeof(G));
	int t = 1;
	for(int i = 0; i <= 6; i++){
		for(int j = i; j<=6; j++){
			G[i][j] = G[j][i] = t++;
		}
	}
}

// ��ȡ���� 
bool read_input(){
	for(int i = 0; i < 7; i++){
		for(int j = 0; j < 8; j++){
			int n;
			if(scanf("%d", &n)==EOF) return 0;
			mark[i][j] = n;
		}
	}
	return 1;
}

void echo(){
	printf("Layout #%d:\n\n", ++kase);
	for(int i = 0; i<7; i++){
		for(int j = 0; j<8; j++){
			printf("%4d", mark[i][j]);
		}
		printf("\n");
	}
	printf("\nMaps resulting from layout #%d are:\n\n", kase);
}

void out(){
	for(int i = 0; i < 7; i++){
		printf(" ");
		for(int j = 0; j < 8; j++){
			printf("%4d", ans[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


bool check(int x){
	for(int i = 0; i < 8; i++){
		if(!vis[x][i]) return 1;
	}
	return 0;
}

//һ��һ�д���
void dfs(int x, int y, int sum){
	if(sum==28){ // �Ѿ����� ��һ����2���� 
		out();
		tot++;
		return;
	}
	if(x==7) return;
	if(y==8){ // ����Ѿ������һ�� 
		if(check(x)) return;
		dfs(x+1, 0,sum);
		return;
	}
	if(vis[x][y]){
		dfs(x, y+1,sum);
		return;
	}
	for(int i = 0; i < 2; i++){
		if(i==0 && y==7) continue; // �Ѿ���һ�е����ұ� 
		if(i==1 && x==6) continue; // �Ѿ������һ�� 
		int nx = x + dx[i]; //������ڵ����� 
		int ny = y + dy[i];
		
		if(vis[nx][ny]) continue;//�Ѿ�ȷ��ֵ 
		if(v[G[mark[x][y]][mark[nx][ny]]]) continue;//ȷ������Ψһ
		
		if(!G[mark[x][y]][mark[nx][ny]])  continue; //ȷ���ù��ƴ��� 
		
		ans[nx][ny]=ans[x][y]=G[mark[x][y]][mark[nx][ny]]; // ��� 
		
		vis[x][y] = vis[nx][ny] =  v[G[mark[x][y]][mark[nx][ny]]] = 1;
		dfs(x, y+1, sum+1);
		vis[nx][ny]=vis[x][y]=0;
		v[G[mark[x][y]][mark[nx][ny]]] = 0;
	}
}

int main(){
	#ifdef LOCAL
	freopen("1.in", "r",stdin);
	#endif
	
	init();
	while(read_input()){
		tot = 0;
		memset(ans, 0, sizeof(ans));
		memset(v, 0, sizeof(v));
		memset(vis, 0, sizeof(vis));
		
		echo();
		dfs(0, 0, 0);
		printf("There are %d solution(s) for layout #%d.\n\n", tot, kase);
	}
	return 0;
} 
