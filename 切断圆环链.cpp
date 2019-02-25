#include<cstdio>
#include<bitset>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 16;
int G[maxn][maxn], n, c[maxn];

// ����ýڵ�Ķ�������ȥ�Ѵ򿪵Ļ��� 
int calcu(int k, bitset<maxn> &open){
	int ans = 0;
	for(int i = 0; i< n; i++){
		if(G[k][i] && !open.test(i)){
			ans++;
		}
	}
	return ans;
} 

// ����ͼ�ж��Ƿ��л� 
int dfs(int k, int pa,  bitset<maxn> &open){
	c[k] = -1; // �������� 
	for(int i = 0; i < n; i++){
		if(G[k][i] && !open.test(i)){ // ���ڱߣ��Ҳ��Ǵ򿪵Ļ� 
			if(c[i]==-1 && pa!=i) return 1; // ���ڻ�
			if(!c[i] && dfs(i, k, open)) return 1; 
		}
	}
	c[k] = 1; //������� 
	return 0;
}


// ����ö�� 
int solve(){
	int ans = n;
	bitset<maxn> open;
	for(int i = 0; i < (1<<n); i++){
		
		//�ȴ洢��Ҫ�򿪵Ļ�() 
		open.reset();
		for(int j = 0; j < n; j++){
			if(i & (1<<j)){
				open.set(j);
			}
		}
		
		int ok = 1;
		// ����û�д򿪻��Ķ�������������<=2
		for(int i = 0; i< n; i++){
			if(open.test(i)) continue;
			if(calcu(i, open) > 2){
				ok = 0;
				break;
			}
		} 
		if(!ok) continue;
		
		// ������ͨ�����������޻� 
		int num = 0;
		memset(c, 0, sizeof(c));
		for(int i = 0; i < n; i++){
			if(open.test(i)) continue;
			if( !c[i]){
				num++;
				if(dfs(i,-1, open)) { // ���ڻ� 
					ok = 0;
					break;
				}
			}
		}
		if(!ok) continue;
		if(num-1  <= open.count()){
			ans = min(ans, (int)open.count());	
		}
	}
	return ans;
}


int main(){
	#ifdef LOCAL
		freopen("1.in","r", stdin);
	#endif
	int kase = 0;
	while(scanf("%d", &n)!=EOF && n){
		memset(G, 0, sizeof(G));
		int from, to;
		while(scanf("%d %d", &from, &to)==2 && (from!=-1 || to!=-1 ) ){
			G[from-1][to-1] = G[to-1][from-1] = 1;
		}
		printf("Set %d: Minimum links to open is %d\n",++kase ,solve());
	}
	return 0;
} 
