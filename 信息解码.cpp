#include<stdio.h>
#include<string.h>

int code[8][1<<8];

int readchar(){
	while(1){
		int c = getchar();
		if(c != '\n' && c != '\r') return c; // һֱ�����ǻ��з�Ϊֹ 
	}
}
int readcodes(){
	memset(code, 0, sizeof(code));
	code[1][0] = readchar(); // ֱ�� 
	
	for(int len = 2; len<=7; len++){
		for(int i =0; i<(1<<len)-1; i++){
			int c = getchar();
			if(c == EOF) return 0;
			if(c == '\n' || c == '\r') return 1;
			code[len][i] = c;
		}
	}
	return 1;
}

int readint(int c){
	int v = 0;
	while(c--){
		v = v *2 + (readchar() - '0');
	}
	return v;
}
int main(){
	while(readcodes()){ //��ȡ����ͷ 
		while(1){
			int len = readint(3); // ��ȡ�����ı� 
			if(len==0) break;
			while(1){
				int v = readint(len);
				if(v == (1<<len )-1) break;
				putchar(code[len][v]);
			}
		}
		putchar('\n');	
	}
	return 0; 
}
