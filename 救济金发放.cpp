#include<stdio.h>
#define maxn 25

int n, k, m, a[maxn];
// ��ʱ����t����������d(-1��ʾ˳ʱ����)��������λ��


int  go(int p, int d, int t){
	while(t--){
		do{
			p = (p + d + n -1) % n +1;
		}while(a[p]==0);
	}
	return p;
} 


int main(){
	while(scanf("%d%d%d", &n, &k, &m)==3 && n){
		for(int i = 1; i<=n; i++) a[i] = i;
		int left = n; //��ʣ�µ� ����
		int p1 = n, p2 = 1;
		while(left){
			p1 = go(p1, 1, k);
			p2 = go(p2, -1, m);
			printf("%3d", p1);
			left--;
			if(p2!=p1) {
				printf("%3d", p2);
				left--;
			}
			a[p1] = a[p2] = 0;
			if(left) printf(",");
		}
		printf("\n");
	}
}



int main2(){
	int n, k, m;
	while(scanf("%d %d %d", &n, &k, &m)==3 && n){
		int count = 0;
		int person[n+1] = {0};
		int first = 1;
		
		for(int i = 1; i<= n; i++){
			person[i] = i;
		}
		
		int A = 1, B = n;
		
		while(count<n){
			// A����
			int step = 0;
			while(step< k){
				if(person[A]==0) {
					A++;
					if(A==n+1){
					A=1;
				}
					continue;
				}
				step++;
				if(step==k){
					break;
				}
				A++;
				if(A==n+1){
					A=1;
				}
			}
			
			// B����
			step = 0;
			while(step<m){
				if(person[B]==0){
					B--;
					if(B==-1) B = n;
					continue; 
				}
				step++;
				if(step == m){
					break;
				}
				B--;
				if(B==-1) B = n;
			}
			if(A!=B){
				person[A] = 0;
				person[B] = 0;
				count+=2;
				first ? printf("%3d%3d", A, B): printf(",%3d%3d", A, B);
				first = 0;
			}else{
				person[A] = 0;
				count+=1;
				first ? printf("%3d", A): printf(",%3d", A);
				first = 0;
			}
			
			if(count == n) break;
			// �ƶ�A
			while(1){
				A++;
				if(A==n+1) A=1;
				if(person[A]!=0) break;
			} 
			// �ƶ�B
			while(1){
				B--;
				if(B==-1) B=n;
				if(person[B]!=0) break;
			}
//			printf("   241\n");
		}
		printf("\n");
	}
	return 0;
}
