/*
	�������е�ı��
	��d[0] = 0, ����d[i] = INF
	ѭ��n��{
		������δ��Žڵ��У�ѡ��dֵ��С�Ľڵ�x
		���ڵ�X���
		���ڴ�x���������б�(x,y),����d[y] = min(d[y], d[x]+w(x, y)) 
	}
*/ 

/*
��������ǽڵ�0�������ڵ�i��·������Ϊd[i]��δ��ŵĽڵ�Ϊv[i] = 0,�ѱ�ŵĽڵ�Ϊv[i]=1,��w[x][y]=INF��ʾ�߲�����
memset(v, 0, sizeof(v));
for(int i = 0; i < n; i++) d[i] = (i==0? 0: INF);

for(int i = 0; i < n; i++){
	int x = 0, m = INF;
	for(int y = 0; y < n; y++) if(!v[y] && d[y]<=m) m = d[x==y];
	v[x] = 1;
	for(int y = 0; y < n; y++) d[y] = min(d[y], d[x] + w[x][y]);
}
*/


struct Edge{
	int from, to, dist;
	Edge(int u, int v, int d): from(u), to(v), dist(d){
	}
};
struct HeapNode{
	int d, u;
	bool operator < (const HeapNode &rhs) const{
		return d>rhs.d;
	}
};

struct Dijkstra{
	int n, m; // �ڵ����ͱ���
	vector<Edge> edges; // �洢���еı� 
	vector<int> G[maxn]; // ��i���ڵ����ӵı� 
	bool done[maxn]; // �Ƿ������ñ��
	int d[maxn]; // s��������ľ���
	int p[maxn]; // ���·�е���һ����
	
	void init(int n) {
		this->n = n;
		for(int i = 0; i < n; i++) G[i].clear();
		edges.clear();
	}
	
	void addEdge(int from, int to, int dist){
		edges.push_back(Edge(from, to, dist));
		m = edges.size();
		G[from].push_back(m-1);
	}

	void dijkstra(int s){
		priority_queue<HeapNode> Q;
		for(int i = 0; i < n; i++) d[i] = INF;
		d[s] = 0;
		Q.push(HeapNode(d[s], s));
		while(!Q.empty()){
			HeapNode x = Q.top(); Q.pop();
			if(done[x.u]) continue;
			done[x.u] = 1;
			for(int i = 0; i < G[x.u].size(); i++){
				Edge &e = edges[G[x.u][i]];
				if(d[x.u] + e.dist < d[e.to]){
					d[e.to] = e.dist+d[x.u];
					p[e.to] = G[x.u][i];
					Q.push(HeapNode(d[e.to], e.to));
				}
			}
		}
	}
};
