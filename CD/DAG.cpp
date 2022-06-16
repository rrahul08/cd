#include<iostream>
#include<map>
#include<string.h>
using namespace std;

int main(){
	int temp_count, var_count;
	cout<<"Enter number of twmp var: ";
	cin>>temp_count;
	cout<<"\nEnter the no. of variables: ";
	cin>>var_count;
	int vertex=temp_count+var_count;
	string aj_matrix[vertex][vertex];
	string t;
	string varname[vertex];
	char RL[vertex][vertex];
	map<string,int>var;
	cout<<"Enter temp and variables: ";
	for(int i=0;i<vertex;i++){
		cin>>t;
		var.insert(pair<string,int>(t,i));
		varname[i]=t;
	}
	for(int i=0;i<vertex;i++)
	{
		for(int j=0;j<vertex;j++){
			aj_matrix[i][j]="0";
			RL[i][j]=0;
		}
	}
	string code[4];
	for(int i=0;i<temp_count;i++){
		cout<<"Enter tem var: ";
		cin>>code[0];
		cout<<"\nEnter left: ";
		cin>>code[1];
		cout<<"\n Enter operator: ";
		cin>>code[2];
		cout<<"\nEnter right: ";
		cin>>code[3];
		int x=var[code[1]];
		int y=var[code[3]];
		int z=var[code[0]];
		aj_matrix[x][z]=code[2];
		aj_matrix[y][z]=code[2];
		RL[x][z]='L';
		RL[y][z]='R';
		cout<<endl;
	}
	for(int i=0;i<vertex;i++){
		for(int j=0;j<vertex;j++){
			cout<<aj_matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"\n\n";
	cout<<"PTR \t LEFT \t RIGHT \t LABEL"<<endl;
	for(int i=0;i<temp_count;i++){
		string left;
		string right;
		string operand;
		for(int j=0;j<vertex;j++){
			if(aj_matrix[j][i]!="0"){
				if(RL[j][i]=='L'){
					left=varname[j];
				}
				if(RL[j][i]=='R'){
					right=varname[j];
				}
			    operand =aj_matrix[j][i];
			}}
			cout<<operand<<"\t"<<left<<"\t"<<right<<"\t"<<varname[i]<<"\n";
		
	}
}
