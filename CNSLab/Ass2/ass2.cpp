// W.A.P. to implement Polyalphabetic Cipher
#include<iostream>
#include<map>
using namespace std;

string generateCipherText(string plainText, string keyword, map<int, char> mp) {
    int ind = 0;
    int nk = keyword.size();
    int n = plainText.size();
    string cipherText = "";

    for (int i = 0; i < n; i++) {
        char ch = plainText[i];
        if (ch >= 'a' && ch <= 'z') {
            int p = ch - 'a';
            int k = keyword[ind] - 'a';
            int c = (p + k) % 26;
            cipherText += mp[c];
            ind = (ind + 1) % nk;
        } else if (ch >= 'A' && ch <= 'Z') {
            int p = ch - 'A';
            int k = toupper(keyword[ind]) - 'A';
            int c = (p + k) % 26;
            cipherText += toupper(mp[c]);
            ind = (ind + 1) % nk;
        } else {
            cipherText += ch; 
        }
    }

    return cipherText;
}

string generatePlainText(string cipherText, string keyword, map<int, char> mp) {
    string decryptedText = "";
    int n = cipherText.size();
    int nk = keyword.size();
    int ind = 0;

    for (int i = 0; i < n; i++) {
        char ch = cipherText[i];
        if (ch >= 'a' && ch <= 'z') {
            int c = ch - 'a';
            int k = keyword[ind] - 'a';
            ind = (ind + 1) % nk;
            int p = (c - k + 26) % 26;
            decryptedText += mp[p];
        } else if (ch >= 'A' && ch <= 'Z') {
            int c = ch - 'A';
            int k = toupper(keyword[ind]) - 'A';
            ind = (ind + 1) % nk;
            int p = (c - k + 26) % 26;
            decryptedText += toupper(mp[p]);
        } else {
            decryptedText += ch; 
        }
    }

    return decryptedText;
}


int main(){
  string plainText;
  cout<<"Enter Plain Text : ";
  getline(cin, plainText);
  string keyword;
  cout<<"Enter Keyword : ";
  cin>>keyword;
  map<int, char>mp;
  for(int i=0; i<26; i++){
    char ch=char(i+97);
    mp[i]=ch;
  }
  string cipherText=generateCipherText(plainText, keyword, mp);
  cout<<"Cipher Text : "<<cipherText<<endl;
  string decryptedText=generatePlainText(cipherText, keyword, mp);
  cout<<"Decrypted Text : "<<decryptedText<<endl;
  return 0;
}