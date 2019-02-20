/*
	��֪���������� 
*/ 
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<iostream>
using namespace std;

string str;
const int maxn = 10;
int G[maxn][maxn], n;
map<char, int> mm;
vector<char> vv;
int maxwid;
int vis[10];
int ans[10], A[10];

void dfs (int cur, int bw){
	if(cur == n){
		maxwid = bw;
		memcpy(ans, A, sizeof(int)*n);
	}else{
		for(int i = 0; i < n; i++){
			if(!vis[i]){
				//�����Լ�֦
				int m = 0; // 
				for(int j = 0; j< n; j++){
					if(G[A[j]][i] && !vis[j]) m++; 
				}
				if(m>=maxwid) break;
				
				// �����Լ�֦
				int ok = 1;
				for(int j = 0; j < cur; j++){
					if(G[A[j]][i]){
						int b = cur - j;
						if(b >= maxwid) {
							ok = 0;
							break;
						}
						if(b>bw){ // ��¼��ǰ���������� 
							bw = b;
						}
					}
				}
				// ��������Ŵ���� 
				if(ok){
					A[cur] = i;
					vis[i] = 1;
//					printf("----before %d---\n", bw);
					dfs(cur+1, bw);
//					printf("----after %d---\n", bw);
					vis[i] = 0;
				}else break;
				// curλ���Ѿ���maxwid��֮��������Խ��� 
			}
		} 
	}
}

void init(){
	vv.clear();
	mm.clear();
	memset(vis, 0, sizeof(vis));
	
	for(char i = 'A'; i <= 'Z'; i++){
		if(str.find(i)!=string::npos){
			vv.push_back(i);
			mm[i] = vv.size()-1;
		}
	}
	memset(G, 0, sizeof(G)); // ��ͼ��� 
	str+=';';
	int s = 0, pos;
	
	while((pos = str.find(';', s))!= string::npos){
		char c = str[s];
		for(int i = s+2; i < pos; i++){
			char v = str[i];
			G[mm[v]][mm[c]] = G[mm[c]][mm[v]] = 1;
		}
		s = pos+1;
	}
	maxwid = 8;
	n  = vv.size();
}

int main(){
	while(cin>>str && str!="#"){
		init(); // ��ʼ��
		
		dfs(0, 0); //���� 
		
		for(int i = 0; i<n;i++){
			printf("%c ", vv[ans[i]] );
		}
		printf("-> %d\n", maxwid);
	}
	return 0;
} 

