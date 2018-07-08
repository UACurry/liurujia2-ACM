#include<stdio.h>

#define OFFSET 500000 //ƫ���������ڲ���ʵ�������������±�֮���ƫ��
int hash[1000001]; // hash���飬��¼ÿ�������Ƿ���֣�������Ϊ0�����ֺ󱻱��Ϊ1 
 
int main()
{
	int n,m;
	while(scanf("%d %d", &n, &m)!=EOF){
		for(int i=-500000; i<=500000; i++){
			hash[OFFSET+i]=0; // ��ʼ������ÿ�����ֱ��Ϊδ���� 
		}
		for(int i=0; i<n;i++){
			int x;
			scanf("%d", &x);
			hash[OFFSET+x]=1; // ���ǳ��ֹ������֣�������Ԫ�ؾ������ó�1 
		}
		
		for(int i=500000; i>=-500000; i--){ // ���ǰm���� 
			if(hash[OFFSET+i]==1){
				printf("%d", i);
				m--;
				if(m!=0) printf(" ");
				else {
					printf("\n");
					break; 
				}
			}
		}
	} 
	
	
	
/*
	int n, m;
	int buf[n];
	while(scanf("%d %d", &n, &m)!=EOF && n!=0){
		for(int i=0; i<n;i++){
			int x;
			scanf("%d", &x);
			buf[i]=x;
		}
		for(int i=0;i<m;i++){
			for(int j=0; j<n-1-i;j++){
				if(buf[j]> buf[j+1]){
					int tmp = buf[j];
					buf[j] = buf[j+1];
					buf[j+1] = tmp;
				}
			}
		}
		
		for(int i=0; i< m;i++){
			if(i==0){
				printf("%d", buf[n-i-1]);
			}else{
				printf(" %d", buf[n-i-1]);
			}
		}
		printf("\n");
		
	}
*/
	return 0;
}
