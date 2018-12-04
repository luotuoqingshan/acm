#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

struct card{
	int col,num;
	card(int col = 0,int num = 0):col(col),num(num){}
	bool operator == (const card & rhs) const{
		return rhs.col == col && num == rhs.num;
	}
	bool operator < (const card & rhs) const{
		return num < rhs.num;
	}
}c[52];

struct poker{
	card a[5];
	int type;
	int Hash;
	poker(){}
	void print(){
		for(int i = 0;i < 5;i++){
			cout << a[i].col << " " << a[i].num << endl;
		}
	}
	bool checkflush(){
		return a[0].col == a[1].col && a[1].col == a[2].col && a[2].col == a[3].col && a[4].col == a[3].col;
	}
	bool checkstraight(){
		if(a[0].num == 2 && a[1].num == 3 && a[2].num == 4 && a[3].num == 5 && a[4].num == 14) return true;
		return a[0].num == a[1].num - 1 && a[1].num == a[2].num - 1 && a[2].num == a[3].num - 1 && a[4].num == a[3].num + 1;
	}
	bool checkfullhouse(){
		int num[15] = {0};
		for(int i = 0;i < 5;i++){
			num[a[i].num]++;
		}
		for(int i = 0;i < 15;i++)
			if(num[i] >= 4) return true;
		return false;
	}
	bool checktriple(){
		int num[15] = {0};
		for(int i = 0;i < 5;i++){
			num[a[i].num]++;
		}
		for(int i = 0;i < 15;i++)
			if(num[i] == 3) return true;
		return false;
	}
	int calpair(){
		int num[15] = {0};
		for(int i = 0;i < 5;i++){
			num[a[i].num]++;
		}
		int res = 0;
		for(int i = 0;i < 15;i++)
			if(num[i] == 2) res++;
		return res;
	}
	int toppair(){
		int num[15] = {0};
		for(int i = 0;i < 5;i++){
			num[a[i].num]++;
		}
		for(int i = 14;i >= 0;i--){
			if(num[i] == 2) return i;
		}	
		return 0;
	}
	int secondpair(){
		int num[15] = {0};
		for(int i = 0;i < 5;i++){
			num[a[i].num]++;
		}
		bool first = false;
		for(int i = 14;i >= 0;i--){
			if(num[i] == 2){
				if(first == 0) first = true;
				else return i;
			}	
		}	
		return 0;
	}
	int morethree(){
		int num[15] = {0};
		for(int i = 0;i < 5;i++){
			num[a[i].num]++;
		}
		for(int i = 14;i >= 0;i--){
			if(num[i] >= 3) return i;
		}	
		return 0;
	}
	int get(){
		int num[15] = {0};
		for(int i = 0;i < 5;i++){
			num[a[i].num]++;
		}
		for(int i = 14;i >= 0;i--){
			if(num[i] == 1 || num[i] == 5) return i;
		}	
		return 0;
	}
	void check(){
		sort(a,a + 5);
		if(checkflush() && checkstraight()){
			type = 9;
			return;
		}
		if(checkflush()){
			type = 6;return;
		}if(checkstraight()){
			type = 5;return;	
		}if(checkfullhouse()){
			type = 8;return;
		}if(checktriple() && calpair() == 1){
			type = 7;return;
		}if(checktriple()){
			type = 4;return;
		}if(calpair() == 2){
			type = 3;return;
		}if(calpair() == 1){
			type = 2;return;
		}
		type = 1;return;
	}
	void cal(){
		check();
		if(type == 1){
			Hash = 0;
			for(int i = 4;i >= 0;i--){
				Hash = Hash * 15 + a[i].num;
			}
		}else if(type == 2){
			int tmp = toppair();
			Hash = toppair();
			for(int i = 4;i >= 0;i--){
				if(a[i].num == tmp) continue;
			   	Hash = Hash * 15 + a[i].num;	
			}	
		}else if(type == 3){
			int tmp = toppair();
			int tmp1 = secondpair();
			Hash = tmp * 15 + tmp1;
			for(int i = 4;i >= 0;i--){
				if(a[i].num == tmp || a[i].num == tmp1) continue;
				Hash = Hash * 15 + a[i].num;
			}
		}else if(type == 4){
			int tmp = morethree();
			Hash = tmp;
			for(int i = 4;i >= 0;i--){
				if(a[i].num == tmp) continue;
				Hash = Hash * 15 + a[i].num;
			}	
		}else if(type == 5 || type == 9){
			if(a[0].num == 2 && a[4].num == 14) Hash = 1;
			else Hash = a[0].num;
		}else if(type == 6){
			Hash = 0;
			for(int i = 4;i >= 0;i--){
				Hash = Hash * 15 + a[i].num;
			}
		}else if(type == 7){
			int tmp = morethree();
			int tmp1 = toppair();
			Hash = tmp * 15 +  tmp1;
		}else if(type == 8){
			Hash = morethree() * 15 + get();
		}
	}
	bool operator < (const poker & rhs) const{
		if(type != rhs.type) return type < rhs.type;
		return Hash < rhs.Hash;
	}	
	bool operator == (const poker & rhs) const{
		return type == rhs.type && Hash == rhs.Hash;
	}
}b[3000000];

int tot;

void pre(){
	for(int i = 0;i < 52;i++){
		c[i].col = i / 13 + 1;
		c[i].num = i % 13 + 1;
		if(c[i].num == 1) c[i].num = 14;
	}
	tot = 0;
	for(int i = 0;i < 52;i++){
		for(int j = i + 1;j < 52;j++){
			for(int k = j + 1;k < 52;k++){
				for(int l = k + 1;l < 52;l++){
					for(int m = l + 1;m < 52;m++){
						++tot;
						b[tot].a[0] = c[i],b[tot].a[1] = c[j],b[tot].a[2] = c[k],b[tot].a[3] = c[l],b[tot].a[4] = c[m];
						b[tot].cal();
					}
				}
			}
		}
	}
	sort(b + 1,b + 1 + tot);
}

char str[4];

int id(char c){
	if(c >= '0' && c <= '9') return c - '0';
	if(c == 'T') return 10;
	if(c == 'J') return 11;
	if(c == 'Q') return 12;
	if(c == 'K') return 13;
	if(c == 'A') return 14;
}
int suit(char c){
	if(c == 'C') return 0;
	if(c == 'D') return 1;
	if(c == 'S') return 2;
	if(c == 'H') return 3;
}

int main(){
	freopen("hands.in","r",stdin);
	freopen("hands.out","w",stdout);
	pre();	
	poker now;
	for(int i = 0;i < 5;i++){
		scanf("%s",str);
		now.a[i] = card(suit(str[1]),id(str[0]));
	}	
	now.cal();
	int same = 0;
	for(int i = 1;i <= tot;i++){
		if(now == b[i]){
			cout << i - same << endl;
			break;
		}	
		if(i > 1 && b[i] == b[i - 1]) same++;
	}
	return 0;
}
