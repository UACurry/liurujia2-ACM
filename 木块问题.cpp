#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

const int maxn = 30;
int n;
vector<int> pile[maxn]; // ÿ��pile[i] ��һ��vector


//��ľ��a���ڵ�pile��height�������õ���ʽ���ظ������� 
void find_block(int a, int &p, int &h){
	for(p = 0; p< n; p++){
		for(h = 0; h < pile[p].size(); h++){
			if(pile[p][h] == a) return;
		}
	}
}

// �ѵ�P�Ѹ߶�Ϊh��ľ��ȫ����λ
void  clear_above(int p, int h){
	for(int i = h+1; i < pile[p].size(); i++){
		int l = pile[p][i];
		pile[l].push_back(l);
	}
	pile[p].resize(h+1);
}

// �ѵ�p�Ѹ߶�Ϊh�����Ϸ���ľ�������ƶ���p2�ѵĶ���
 
void pile_onto(int pa, int ha, int pb){
	for(int i = ha; i< pile[pa].size(); i++){
		pile[pb].push_back(pile[pa][i]);
	}
	pile[pa].resize(ha);
}

void print(){
	for(int i =0; i< n;i++){
		printf("%d:", i);
		for(int j = 0; j < pile[i].size(); j++){
			printf(" %d", pile[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int a,b;
	cin>>n;
	string s1, s2;
	for(int i = 0; i< n; i++) pile[i].push_back(i);
	while(cin>>s1>>a>>s2>>b){
		if(s1=="quit") break;
		int pa, pb, ha, hb;
		find_block(a, pa, ha);
		find_block(b, pb, hb);
		
		if(pa == pb) continue; // �Ƿ�ָ��
		if(s2== "onto") clear_above(pb, hb);
		if(s2 == "move") clear_above(pa, hb);
		pile_onto(pa, ha, pb); 
	}
	print();
	return 0;
}
