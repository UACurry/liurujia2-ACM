#include<cstdio>
#include<cstring>

typedef int State[9]; // ���� ��״̬������ 
const int maxstate = 1000000;
State st[maxstate], goal; // ״̬���飬����״̬������������

int dist[maxstate]; // ��������
// �����Ҫ��ӡ���������Լ�һ�������ױ�š����� int fa[maxstate]

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

//BFS ����Ŀ��״̬��st�����±�

const int hashsize = 1000003;
int head[hashsize], next[maxstate];

void init_lookup_table(){
	memset(head, 0, sizeof(head));
}

int hash(State &s){
	int v = 0;
	for(int i = 0; i < 9; i++) v = v*10+s[i]; // ��9��������ϳ�9λ�� 
	return v % hashsize; //ȷ��hash����ֵ�ǲ�����hash��Ĵ�С�ķǸ����� 
}

int try_to_insert(int s){
	int h = hash(st[s]);
	int u = head[h]; // �ӱ�ͷ��ʼ��������
	while(u){
		if(memcmp(st[u], st[s], sizeof(st[s])) == 0) return 0;
		u = next[u];
	}
	next[s] = head[h];
	head[h] = s;
	return 1;
}


int bfs(){
	init_lookup_table(); // ��ʼ�����ұ� 
	int front = 1, rear = 2; //��ʹ���±�0����Ϊ0����Ϊ
	while(front < rear){
		State &s = st[front]; //�����ü򻯴���
		if(memcmp(s, goal, sizeof(s))==0) return front; // �ҵ�Ŀ��״̬���ɹ�����
		int z;
		for(z = 0; z < 9; z++) if(!s[z]) break;
		int x = z / 3, y = z % 3; // ��ȡ���б��
		for(int d = 0; d < 4; d++){
			int newx = x + dx[d], newy = y + dy[d];
			if(newx>=0 && newx < 3 && newy>=0 && newy<3) {
				State &t = st[rear];
				memcpy(&t, &s, sizeof(t));
				t[3 * newx + newy] = s[z];
				t[z] = s[3 * newx + newy];
				dist[rear] = dist[front] +1;
				if(try_to_insert(rear)) {
					rear++;
				}
			}
		} 
		front++;
	} 
	return 0;
} 


int main(){
	
	#ifdef LOCAL
		freopen("1.in","r",stdin);
	#endif
	
	for(int i = 0; i<9; i++) scanf("%d", &st[1][i]); // ��ʼ״̬
	for(int i = 0; i<9; i++) scanf("%d", &goal[i]); // Ŀ��״̬
	
	int ans = bfs();
	if(ans>0) printf("%d\n", dist[ans]);
	else printf("-1\n");
	
	return 0;
}
