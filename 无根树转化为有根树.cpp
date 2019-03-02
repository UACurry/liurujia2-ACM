#include<cstdio> 
void read_input(){
	int u, v;
	scanf("%d", n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
}

void dfs(int root, int k){ // �ݹ�ת��Ϊ��rootΪ����������root�ĸ��ڵ�Ϊk 
	for(int i = 0; i < G[root].size(); i++ ){ // �ڵ�u�����ڵ���� 
		int v = G[root][i]; // �ڵ�root�� i�����ڵ� 
		if(v != k){ // �ж�V�Ƿ�͸��ڵ���ȣ�������ԣ����������޵ݹ� 
			pa[v] = root;
			dfs(v, root);
		}
	}
}

int main (){
	memset(pa, -1, sizeof(par));
	read_input();
	int m;
	scanf("%d", &m);
	dfs(m, -1);
	
	return 0;
}
