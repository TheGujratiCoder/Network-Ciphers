#include<bits/stdc++.h>
using namespace std;

vector<int> multiply(int n,vector<int> A,vector<vector<int>> B)
{
    vector<int> C(n,0);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            C[i]+=(A[j]*B[i][j]);
        }
        C[i]%=26;
    }
    return C;
}

string encrypt(int n,vector<int> s,vector<vector<int>> v)
{
    vector<int> V=multiply(n,s,v);
    string res;
    for(auto it : V)
        res+=char('A'+it);
    return res;
}

int modInverse(int a,int m)
{
    a=a%m;
    for(int x=1;x<m;x++)
        if((a*x)%m==1)
            return x;
    return 1;
}

int determinant(int a,int b,int c,int d)
{
    return ((a*d)-(b*c))%26;
}

vector<vector<int>> modInverseMatrix(vector<vector<int>> key)
{
    int det=(key[0][0]*key[1][1]-key[0][1]*key[1][0])%26;
    int invDet=modInverse(det,26);
    vector<vector<int>> invMatrix(2,vector<int>(2));
    invMatrix[0][0]=key[1][1]*invDet%26;
    invMatrix[0][1]=(-key[0][1]*invDet)%26;
    invMatrix[1][0]=(-key[1][0]*invDet)%26;
    invMatrix[1][1]=key[0][0]*invDet%26;
    return invMatrix;
}

string decrypt(int n,vector<int> s,vector<vector<int>> key)
{
    vector<vector<int>> invKey=modInverseMatrix(key);
    vector<int> decrypted=multiply(n,s,invKey);
    string res;
    for(auto it : decrypted)
        res+=char('A'+it%26);
    return res;
}

int main()
{
    string s,k;
    ifstream f1("./input2b.txt");
    ofstream f2("./output2b.txt");
    f1>>s;
    vector<int> s1;
    int n=s.size();
    for (auto it : s)
        s1.push_back(toupper(it) - 'A');
    cout<<"Enter key : ";
    cin>>k;

    int keySize=ceil(sqrt(k.size())),index=0;;
    while(k.size()<keySize*keySize)
        k+='A';
    vector<vector<int>> v(keySize,vector<int>(keySize));
    for(int i=0;i<keySize;++i)
        for(int j=0;j<keySize;++j)
            v[i][j]=toupper(k[index++])-'A';

    string res=encrypt(n,s1,v);
    f2<<res<<endl;
    
    vector<int> resvec;
    for(auto it:res)
        resvec.push_back(it+'A');
    string original=decrypt(n,resvec,v);
    f2<<original<<endl;

    return 0;
}
