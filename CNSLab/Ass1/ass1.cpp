// Write a Program to Implement Ceaser Cipher   24-07-25

#include<iostream>
using namespace std;

string generateCipherText(string plainText, int key){
  string cipherText="";
  int n=plainText.size();
  for(int i=0; i<n; i++){
    char ch=plainText[i];
    int num=ch;
    if(ch==' '){
      cipherText+=' ';
    }
    else if(num<=90 && num>=65){
      int asci=ch-65;
      cipherText+=char((asci+key)%26+65);
    } 
    else if(num<=122 && num>=97){
      int asci=ch-97;
      cipherText+=char((asci+key)%26+97);
    }
    else{
      cipherText+=ch;
    }
    
  }
  return cipherText;
}

string generatePlainText(string cipherText, int key){
  string plainText="";
  int n=cipherText.size();
  for(int i=0; i<n; i++){
    char ch=cipherText[i];
    int asci=ch;
    if(ch==' '){
      plainText+=' ';
    }
    else if(asci<=90 && asci>=65){
      int num=asci-65-key;
      if(num<0){
        num = 26 + num;
      }
      plainText+=char(num+65);
    }
    else if(asci<=122 && asci>=97){ 
      int num=asci-97-key;
      if(num<0){
        num = 26 + num;
      }
      plainText+=char(num+97);
    }
    else{
      plainText+=ch;
    }
  }
  return plainText; 
}

int main(){
  string plainText;
  cout<<"Enter Plain Text : ";
  getline(cin, plainText);
  int key;
  cout<<"Enter key : ";
  cin>>key;
  string cipherText=generateCipherText(plainText, key);
  cout<<"Cipher Text : "<<cipherText<<endl;
  string decryptedMessage=generatePlainText(cipherText, key);
  cout<<"Decrypted Message : "<<decryptedMessage<<endl;

  return 0;
}