/*
	�����б����򣬼ǵ�iС�ı�Ϊe[i] (1<=i<m)
	��ʼ��MSTΪ��
	��ʼ����ͨ��������ÿһ�����Գ�һ����������ͨ����
	for(int i = 0; i < m; i++)
		if(e[i].u��e[i].v����ͬһ����ͨ����){
			�ѱ�e[i]����MST 
			�ϲ�e[i].u��e[i].v���ڵ���ͨ���� 
		}
*/

int cmp(const int i, const int j) return w[i] < w[j];  // ��������� 
int find(int x) { return p[x]==x? x: p[x] = find(x); } // ���鼯��find 

int kruskal(){
	int ans = 0;
	for(int i = 0; i < n; i++) p[i] = i; // ��ʼ�����鼯
	for(int i = 0; i < m; i++) r[i] = i; // ��ʼ������� 
	
	sort(r, r+m, cmp); // ��������
	for(int i = 0; i < m; i++){
		int e = r[i];
		int x = find(u[e]), y = find(v[e]); // �ҳ���ǰ�������˵����ڵļ��ϱ�� 
		if(x!=y) {
			ans += w[i];
			p[x] = y; // ����ڲ�ͬ���ϣ��ϲ� 
		}
	}
	return ans;
}


