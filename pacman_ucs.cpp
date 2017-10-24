#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
using namespace std;

int px,py;
int fx,fy;
int n,m;
char arr[40][40];

struct node {
	struct node* par;
	int fn,hn,gn;
	int cur_row, cur_col;
	//struct node* next;
}*head;

struct node *initialize(struct node*par, int i,int j){
	struct node* p = (struct node*) malloc(sizeof(struct node));
	p->cur_row = i;
	p->cur_col = j;
	p->par = par;
	p->fn = p->gn = p->hn = 0;
	return p;
}

vector <struct node*> closedlist;
vector<struct node* > openlist;
vector<struct node* > generated;

bool move_up(int a,int b){
	return (a-1 >= 0 && arr[a-1][b] != '%');
}
bool move_left(int a,int b){
	return (b-1 >=0 && arr[a][b-1] != '%');
}
bool move_right(int a,int b){
	return (b+1 < m && arr[a][b+1] != '%');
}
bool move_down(int a,int b){
	return (a+1 <n && arr[a+1][b] != '%');
}

bool check_goal(struct node* p){
	if(p != NULL && p->cur_row == fx && p->cur_col == fy)
		return true;
	return false;
}
void printans(struct node *p){
    	
    	int len;
    	stack<struct node *> ss;
    	while(p && p->par){
         	ss.push(p);
         	p = p->par;
    	}
    	ss.push(p);
    	len = ss.size()-1;
        cout <<len<<endl;
    	while(!ss.empty()){
        	struct node * w = ss.top();
        	ss.pop();
        	cout << w->cur_row <<" "<<w->cur_col<<endl;
    	}
   // cout <<"solution found at depth (from root or packman to food) "<< len<<endl;
}


bool visited(struct node* p) {
	int i, c = generated.size();
	for(i =0; i<c; i++){
		if(generated[i]->cur_row == p->cur_row && generated[i]->cur_col == p->cur_col )
			return true;
	}
	return false;
}

int bfs_pacman(){
	closedlist.clear();
	openlist.clear();
	generated.clear();
	head = initialize(NULL, px,py);
	openlist.push_back(head);
	generated.push_back(head);
	while(! openlist.empty()){
		struct node * p = openlist.front();
		openlist.erase(openlist.begin());
		int a =p->cur_row;
		int b = p->cur_col;
		//cout <<a << " ," <<b <<endl;
		closedlist.push_back(p);
		if(check_goal(p)){
			cout<< "found ans\n";
			printans(p);
			return 1;
		}
		if(move_up(a, b) ){
			struct node * q = initialize(p, a-1, b);
			if(visited(q) ==false ) {
				openlist.push_back(q);
				generated.push_back(q);
			}
		}
		if(move_left(a, b)  ){
			struct node * q = initialize(p, a, b-1);
			if(visited(q) ==false ) {
				openlist.push_back(q);
				generated.push_back(q);
			}
		}
		if(move_right(a, b)  ){
			struct node * q = initialize(p, a, b+1);
			if(visited(q) ==false ) {
				openlist.push_back(q);
				generated.push_back(q);
			}
		}
		if(move_down(a, b)  ){
			struct node * q = initialize(p, a+1, b);
			if(visited(q) ==false ) {
				openlist.push_back(q);
				generated.push_back(q);
			}
		}
	}

	return 0;
}

int dfs_pacman(){
	closedlist.clear();
	openlist.clear();
	generated.clear();
	head = initialize(NULL, px,py);
	openlist.push_back(head);
	generated.push_back(head);
	while(! openlist.empty()){
		struct node * p = openlist.back();
		openlist.pop_back();
		int a =p->cur_row;
		int b = p->cur_col;
		//cout <<a << " ," <<b <<endl;
		closedlist.push_back(p);
		if(check_goal(p)){
			//cout<< "found ans\n";
			printans(p);
			return 1;
		}
		if(move_up(a, b) ){
			struct node * q = initialize(p, a-1, b);
			if(visited(q) ==false ) {
				openlist.push_back(q);
				generated.push_back(q);
			}
		}
		if(move_left(a, b)  ){
			struct node * q = initialize(p, a, b-1);
			if(visited(q) ==false ) {
				openlist.push_back(q);
				generated.push_back(q);
			}
		}
		if(move_right(a, b)  ){
			struct node * q = initialize(p, a, b+1);
			if(visited(q) ==false ) {
				openlist.push_back(q);
				generated.push_back(q);
			}
		}
		if(move_down(a, b)  ){
			struct node * q = initialize(p, a+1, b);
			if(visited(q) ==false ) {
				openlist.push_back(q);
				generated.push_back(q);
			}
		}
	}

	return 0;
}
bool cmp(const struct node* a, const struct node* b) 
{   
	return a->fn < b->fn;
}   
int hn_func(struct node* p){
	return abs(p->cur_row - fx )+ abs(p->cur_col -fy);
}
int gn_func(struct node* p){
	int c=0;
    	while(p ){
         	p = p->par;
		c++;
    	}
    	return c;
}
int fn_func(struct node* p){
	p->hn = hn_func(p);
	p->gn = 0;
	p->fn = p->hn +p->gn;
	return p->fn;
}

int astar_pacman(){
	closedlist.clear();
	openlist.clear();
	generated.clear();
	head = initialize(NULL, px,py);
	fn_func(head);
	openlist.push_back(head);
	generated.push_back(head);
	while(! openlist.empty()){
		sort(openlist.begin(), openlist.end(), cmp);
		struct node * p = openlist.front();
		openlist.erase(openlist.begin());
		int a =p->cur_row;
		int b = p->cur_col;
		//cout <<a << " ," <<b <<endl;
		closedlist.push_back(p);
		if(check_goal(p)){
			//cout<< "found ans\n";
			printans(p);
			return 1;
		}
		if(move_up(a, b) ){
			struct node * q = initialize(p, a-1, b);
			fn_func(q);
			if(visited(q) ==false ) {
				openlist.push_back(q);
				generated.push_back(q);
			}
		}
		if(move_left(a, b)  ){
			struct node * q = initialize(p, a, b-1);
			fn_func(q);
			if(visited(q) ==false ) {
				openlist.push_back(q);
				generated.push_back(q);
			}
		}
		if(move_right(a, b)  ){
			struct node * q = initialize(p, a, b+1);
			fn_func(q);
			if(visited(q) ==false ) {
				openlist.push_back(q);
				generated.push_back(q);
			}
		}
		if(move_down(a, b)  ){
			struct node * q = initialize(p, a+1, b);
			fn_func(q);
			if(visited(q) ==false ) {
				openlist.push_back(q);
				generated.push_back(q);
			}
		}
	}

	return 0;
}
int main(){
	cin >> px >> py;
	cin >> fx >>fy;
	cin >>n >>m;
	int i,j;
	string str;
	getchar();
	//getline(cin,str);
	for(i =0; i<n; i++){
		//getchar();
		getline(cin,str);
		//cout<<str<<endl;
		for(j =0; j<m && j<str.size(); j++){
			arr[i][j] = str[j];
		}
		//getchar();
		
	}
	/*cout <<endl;
	for(i =0; i<n; i++){
		//cout <<i<<" " << arr[i][0]<<"RR" <<endl;
		for(j =0; j<m; j++){
			printf("%c",arr[i][j]);
		}
		cout<<endl; 
	}*/
	i = astar_pacman();

	return 0;
}
