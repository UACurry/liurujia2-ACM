#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;


const int maxn = 1000;

int v[maxn],ans[maxn]; 
int maxd;

// ���1/c<=a/b ����С C 
int get_first(int a, int b){
	return b/a+1;
}

// �����ǰ��V��Ŀǰ���Ž�ans���ţ�����
bool better(int d){
	for(int i = d; i>=0; i--){
		if(v[i]!=ans[i] ){
			return ans[i]== -1 || v[i] < ans[i];
		}
	}
	return false;
}


int gcd(int a, int b){
	return b==0? a: gcd(b, a%b);
}

// ��ǰ���Ϊd, ��ĸ����С��from������֮��ǡ��Ϊaa/bb
bool dfs(int d, int from, int aa, int bb){
	if( d== maxd ){
		if(bb % aa) return 0; // aa/bb�����ǰ������� 
		v[d] =  bb / aa;
		if(better(d)){
			memcpy(ans, v, sizeof(int)*(d+1));
		}
		return 1;
	}
	bool ok = 0;
	from = max(from, get_first(aa, bb)); // ö�ٵ����
	for(int i = from; ; i++){
		// ��֦�� ���ʣ�µ�maxd+1-d������ȫ������1/i����������Ȼ������aa/bb,���޽�
		if(bb * (maxd+1-d) <= i*aa )  break;
		v[d] = i;
		// ����aa/bb-1/i,������Ϊa2/b2
		int b2 = bb*i;
		int a2 = aa*i - bb;
		
		int g = gcd(a2, b2); //�Ա�Լ��
		if(dfs(d+1, i+1, a2/g, b2/g)) {
			ok = 1;
		}
	}
	return ok;
}


int main(){
	int a, b, kase = 0;
	while(scanf("%d%d", &a, &b)==2){
		printf("Case %d: ", ++kase);
		
		int ok = 0;
		for(maxd = 1; ; maxd++){
			memset(ans, -1, sizeof(ans));
			if(dfs(0, get_first(a, b), a, b)){
				ok = 1;
				break;
			}
		}
		
		if(ok){
			printf("%d/%d=1/%d", a, b, ans[0]);
			for(int i = 1; i < maxd; i++){
				printf("+1/%d", ans[i]);
			}
			printf("+1/%d\n", ans[maxd]);
		}else{
			printf("No solution\n");
		}
	}
	
	return 0;
}
