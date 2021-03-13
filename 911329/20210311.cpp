#include <iostream>
using namespace std;

int isTwo(int n){ //判斷是否為2的次方
  if(n<2) return 1;
  else if(n%2!=0) return 0;
  else if(n/2>1){
    n/=2;
    return isTwo(n);
  }else return 1;
}

int main(){
  string s;
  cin >> s;
  int slen = s.length();
  int datalen,data2len,sc=0;
  for(int i=0; i<slen; i++){
    if(isTwo(i)){
      slen++;
     continue;
    }
    datalen=i;
    data2len=i;
  }
  int data[datalen+1];
  for(int i=0; i<=datalen; i++)
    data[i]=-1;
    
  int xora,xorb,xorc=0;//XOR
  for(int i=3; i<=datalen; i++){
    if(isTwo(i)){
      datalen++;
     continue;
    }
    data[i]=s[sc]-48;
    sc++;
    //binary
    if(data[i]==1){
      //cout << i << " ";
      if(xorc==0){xora=i; xorc++;}
      else{ //XOR
        xorb=i^xora;
        xora=xorb;
      }
    }
  }
  //for(int i=1; i<=data2len; i++){ //for test
  //cout<<"data["<<i<<"] = "<<data[i]<<endl;
  //}
  
  //cout << "xora = "<< xora << endl; //test
  //接下來：xora轉二進位
  int a=xora, b, ten=1, sum=0;
  while(a>0){
  b=a%2;
  a/=2;
  sum+=b*ten;
  ten*=10;
  }
 // cout << "sum = " << sum << endl;
  string s1="00000";
  string s2=to_string(sum);
  string s3=s1+s2;
  //cout << "s3 = "<<s3<<endl;
  //sum is the answer
  //put back to DATA array
  int s3count=s3.length()-1;
  for(int i=data2len; i>=1; i--){
    if(isTwo(i)){
      data[i]=s3[s3count]-48;
      s3count--;
    }
  }
  for(int i=1; i<=data2len; i++)
  cout<<data[i];
}
