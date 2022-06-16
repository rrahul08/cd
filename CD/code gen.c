#include<iostream>
#include<string.h>
using namespace std;
int main(){
	int count;
	cout<<"enter the total count:";
	cin>>count;
	string code[count];
	cout<<"enter the three address code:";
	for(int i=0;i<count;i++){
		cin>>code[i];
	}
	cout<<"the equivalent machine code is:"<<endl;
	for(int i=0;i<count;i++){
		cout<<"MOV R"<<i<<","<<code[i][2]<<endl;
		if(code[i][3]=='+'){
			cout<<"ADD";
		}
			if(code[i][3]=='-'){
			cout<<"SUB";
		}
			if(code[i][3]=='*'){
			cout<<"MUL";
		}
			if(code[i][3]=='/'){
			cout<<"DIV";
		}
		cout<<" "<<code[i][4]<<",R"<<i<<endl;
		cout<<"MOV "<<code[i][0]<<",R"<<i<<endl;
	}
	return 0;
}
