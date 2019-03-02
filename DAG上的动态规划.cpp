#include<cstdio>

/*
	�·�����ֵ���Ƕ�׾������⣻
		�����DAG�в��̶������·���أ�����d(i)��ʾ�ӽڵ�i�������·���ȣ���һ��ֻ���ߵ� �������ڽڵ�
		��ˣ�d(i) = 1 + max(d(j)) ,(i,j)����E�����У�EΪ�߼������մ�������d(i)�е����ֵ����������д���仯��������
		(����ǰ���ʼ��d���������ֵΪ0)
		int dp(int k){
			int &ans = d[k];
			if(ans>0) return ans;
			ans = 1;
			for(int i = 0; i < n; i++){
				if(G[k][i]) ans  = max(ans, 1 + dp(i));
			}
			return ans;
		}
		void print_ans(int i){
			printf("%d ", i);
			for(int j = 1; j <= n; j++){
				if(G[i][j] && d[i] == d[j]+1){
					print_ans();
					break;
				}
			}
		}
	�̶��յ���·�����·:
		int dp(int S){
			int &ans = d[S];
			if(ans!=-1) return ans;
			ans = -(1<<30);
			for(int i = 1; i <= n; i++){
				if(S>= v[i]){
					ans = max(ans, 1 + dp(S-v[i]));
				}
			}
			return ans;
		}
	���Ʒ�����
		minv[0] = maxv[0] = 0;
		for(int i = 1; i<=S; i++){
			minv[i] = INF; maxv[i] = -INF;
		}
		
		for(int i = 1; i<=S; i++){
			for(int j = 1; j<= n; j++){
				if(i >= V[j]){
					minv[i] = min(minv[i], minv[i- v[j]]+1);
					maxv[i] = max(maxv[i], maxv[i- v[j]]+1);
				}
			}
		}
		printf("%d %d\n", minv[S], maxv[S]);
	
		����ֵ�����С�ķ�����
			void print_ans(int *d, int s){
				for(int i = 1; i <= n; i++){
					if(s>=v[i] && d[s]==d[s-v[i]]+1){
						print_ans(d, i);
						break;
					}
				}
			}
*/
