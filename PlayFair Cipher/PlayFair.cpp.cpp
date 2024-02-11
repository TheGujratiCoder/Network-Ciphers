#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> playfair(5,vector<char>(5,'-'));
map<char,pair<int,int>> storeIndex;

void Initialise_Matrix(string a,string b)
{
	map<char,bool> m;
	string temp;
	int index=0;
	for(auto it:b){
		it=tolower(it);
		if(it=='j')
			it='i';
		if(m.find(it)==m.end()){
			temp+=it;
			m[it]=1;
		}
	}

	for(auto it:a){
		it=tolower(it);
		if(it=='j')
			it='i';
		if(m.find(it)==m.end()){
			temp+=it;
			m[it]=1;
		}
	}

	for(char ch='a';ch<='z';++ch)
		if(m.find(ch)==m.end() && ch!='j')
			temp+=ch;
	// cout<<temp.size()<<" "<<temp<<endl;

	for(int i=0;i<5;++i){
		for(int j=0;j<5;++j){
			playfair[i][j]=temp[index++];
		}
	}

	cout<<"Matrix used for Encryption is : "<<endl;
	for(int i=0;i<5;++i){
		for(int j=0;j<5;++j){
			storeIndex[playfair[i][j]]={i,j};
			cout<<playfair[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

string convert(string s)
{
	string s1="";
	for(int i=0;i<s.size();i++){
        if(i+1==s.size()){
            s1.push_back(tolower(s[i]));
            s1.push_back('x');
            continue;
        }
        if(s[i]!=s[i+1]){
            s1.push_back(tolower(s[i]));
            s1.push_back(tolower(s[i+1]));
            i++;
        }if(s[i]==s[i+1]){
            s1.push_back(tolower(s[i]));
            s1.push_back('x');
        }
    }
	return s1;
}

string encrypt(string s,string k)
{
	string s1=convert(s);
	cout<<"Original String : "<<s1<<endl;
	string s2="";
	for(int i=0;i<s1.size();++i){
		pair<int,int> a=storeIndex[s1[i]];
		pair<int,int> b=storeIndex[s1[i+1]];
		if(a.first==b.first){
			s2+=playfair[(a.first+1)%5][(a.second)];
			s2+=playfair[(b.first+1)%5][(b.second)];
			i++;
		}else if(a.second==b.second){
			s2+=playfair[(a.first)][(a.second+1)%5];
			s2+=playfair[(b.first)][(b.second+1)%5];
			i++;
		}else{
			s2+=playfair[b.first][a.second];
			s2+=playfair[a.first][b.second];
			i++;
		}
	}
	// cout<<"String After Conversion : "<<s2<<endl;
	return s2;
}

string decrypt(string s,string k)
{
	// string s1=convert(s);
	// cout<<"Original String : "<<s1<<endl;
	string s1=s;
	string s2="";
	for(int i=0;i<s1.size();++i){
		pair<int,int> a=storeIndex[s1[i]];
		pair<int,int> b=storeIndex[s1[i+1]];
		if(a.first==b.first){
			s2+=playfair[(a.first+4)%5][(a.second)];
			s2+=playfair[(b.first+4)%5][(b.second)];
			i++;
		}else if(a.second==b.second){
			s2+=playfair[(a.first)][(a.second+4)%5];
			s2+=playfair[(b.first)][(b.second+4)%5];
			i++;
		}else{
			s2+=playfair[b.first][a.second];
			s2+=playfair[a.first][b.second];
			i++;
		}
	}
	// cout<<"String After Conversion : "<<s2<<endl;
	return s2;
}

int main()
{
	string s,k;
	// cout<<"Enter string : ";
	// cin>>s;
	ifstream f1("./input2a.txt");
	ofstream f2("./output2a.txt");
	f1>>s;
	cout<<"String is : "<<s<<endl;
	cout<<"Enter key : ";
	cin>>k;
	Initialise_Matrix(s,k);
	string s1=encrypt(s,k);
	f2<<"String After Encryption : "<<s1<<endl;
	string s2=decrypt(s1,k);
	f2<<"String after decryption : "<<s2<<endl;
	return 0;
}