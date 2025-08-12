// Write a program to implement play fair cipher

#include<bits/stdc++.h>
using namespace std;

string generateCipherText(string plainText, vector<vector<char>> keyMatrix, map<char, int> rmp, map<char, int> cmp){
	string s="";
	int n=plainText.size();
	for(int i=0; i<n; i++){
		plainText[i]=toupper(plainText[i]);
	}
	cout<<"Plain Text : "<<plainText<<endl;
	
	for(int i=0; i<n; i++){
		if(plainText[i]==' '){
			continue;
		}
		if(plainText[i]=='I' || plainText[i]=='J'){
			s+='I';
		}
		else{
			s+=plainText[i];
		}
		if(i<n-1 && plainText[i]==plainText[i+1]){
			s+='X'; 
		}
	}
	if(s.size()%2!=0){
		s+='Z';
	}

	cout<<"Processed String : "<<s<<endl;
	string cipherText="";
	
	for(int j=0; j<s.size()-1; j+=2){
		if(rmp[s[j]]==rmp[s[j+1]]){
			cipherText+=keyMatrix[rmp[s[j]]][(cmp[s[j]]+1)%5];
			cipherText+=keyMatrix[rmp[s[j]]][(cmp[s[j+1]]+1)%5];
		}
		else if(cmp[s[j]]==cmp[s[j+1]]){
			cipherText+=keyMatrix[(rmp[s[j]]+1)%5][cmp[s[j]]];
			cipherText+=keyMatrix[(rmp[s[j+1]]+1)%5][cmp[s[j]]];
		}
		else{
			int x=cmp[s[j]];
			int y=cmp[s[j+1]];
			cipherText+=keyMatrix[rmp[s[j]]][y];
			cipherText+=keyMatrix[rmp[s[j+1]]][x];
			
		}
	}
	
	return cipherText;
	
}

void constructKeyMatrix(string keyword, vector<vector<char>>& keyMatrix){
	int ind=0;
	int nk=keyword.size();
	int cind=65;
	map<char, int> mp;
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			if(ind<nk && mp[keyword[ind]]==0){
				keyMatrix[i][j]=keyword[ind];
				if(keyword[ind]=='I' || keyword[ind]=='J'){
					mp['I']++;
					mp['J']++;
				}
				else{
					mp[keyword[ind]]++;
				}
				ind++;
			}
			else{
				while(mp[char(cind)]!=0){
					cind++;
				}
				keyMatrix[i][j]=char(cind);
				if(char(cind)=='I'){
					mp['I']++;
					mp['J']++;
					cind+=2;
				}
				else{
					mp[char(cind)]++;
					cind+=1;
				}
				
			}
		}
	}	
}

int main(){
	string plainText;
	cout<<"Enter plain Text : ";
	getline(cin, plainText);
	
	cout<<plainText<<endl;
	
	string keyword;
	cout<<"Enter keyword : ";
	cin>>keyword;
	
	vector<vector<char>>keyMatrix(5, vector<char>(5));
	
	constructKeyMatrix(keyword, keyMatrix);
	
	map<char, int> rmp;
	map<char, int> cmp;
	
	cout<<"KeyMatrix : "<<endl;
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			cout<<keyMatrix[i][j]<<" ";
			if(keyMatrix[i][j]=='I' || keyMatrix[i][j]=='J'){
				rmp['I']=i;
				cmp['I']=j;
				rmp['J']=i;
				cmp['J']=j;
			}
			else{
				rmp[keyMatrix[i][j]]=i;
				cmp[keyMatrix[i][j]]=j;
			}
		}
		cout<<endl;
	}
	
	string cipherText=generateCipherText(plainText, keyMatrix, rmp, cmp);
	
	cout<<"Cipher Text : "<<cipherText<<endl;
	return 0;
}
