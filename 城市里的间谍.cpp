#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define INF 1<<30
const int maxn = 1000;
int n,T, has_edge[maxn][maxn][2]; // ��Tʱ��
int time[maxn];

int dp[maxn][maxn];

int main(){
	#ifdef LOCAL
		freopen("1.in", "r", stdin);	
	#endif
	int kase = 0;
	while(scanf("%d", &n)==1 && n){
		memset(has_edge, 0, sizeof(has_edge));
		
		
		scanf("%d", &T); // ���ڳ�վ 
		for(int i = 1;i < n; i++){
			scanf("%d", &time[i]);
		}
		int num; // ��վ�ĳ��� ,������ 
		scanf("%d", &num);
		
		for(int i = 0; i < num; i++){
			int g;
			scanf("%d", &g);
			for(int j = 1; j <= n; j++){
				has_edge[g][j][0] = 1;
				g += time[j];
			}
		}
		
		scanf("%d", &num); // ������ 
		for(int i = 0; i < num; i++){
			int g;
			scanf("%d", &g);
			for(int j = n; j>=1; j--){
				has_edge[g][j][1] = 1;
				g+= time[j-1];
			}
		}
		
		// dp
		// ��ʼ���߽� 
		dp[T][n] = 0; // ��Ŀ������ٵȴ�ʱ�� 
		for(int i = 1; i <= n-1; i++){
			dp[T][i] = INF;
		}
		
		for(int t = T-1; t>=0; t--){
			for(int i = 1; i<=n; i++){
				dp[t][i] = dp[t+1][i] + 1; // �ȴ�һ����λ
				if( has_edge[t][i][0] && i<n && t + time[i] <= T ) // ������ 
					dp[t][i] = min(dp[t][i], dp[t+time[i]][i+1]);
				if( has_edge[t][i][1] && i>1 && t + time[i-1] <= T)
					dp[t][i] = min(dp[t][i], dp[t+time[i-1]][i-1] ); // �� 
			}
		}
		
		printf("Case Number %d: ", ++kase);
		if(dp[0][1]>=INF) printf("impossible\n");
		else printf("%d\n", dp[0][1]);
	}
	return 0;
}
