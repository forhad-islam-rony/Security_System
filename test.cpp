#include<bits/stdc++.h>
using namespace std;
#include<time.h>
string decrypt(string password)
{
    char pass[20];
    int x=0;
    int len=password.size();
    int a=1;
    for(int i=0;i<len;i++){
       if(i==1){
        pass[x++]=password[i];
       }
       if(i==a+4){
        pass[x++]=password[i];
        a=a+4;
       }
    }
    pass[x]='\0';
    return pass;
    
}
string encrypct(string password)
{
    srand(time(NULL));
    char pass[40];
    int len=password.size();
    int x=0;
    for(int i=0;i<len;i++){
      pass[x++]=char(rand()%26+'a');
       pass[x++]=password[i];
       pass[x++]=char(rand()%9+'0');
       pass[x++]=char(rand()%26+'a');
    }
    pass[x]='\0';
    return pass;
}
int main()
{
  string s="";
  int age;
  cout<<"Enter your name: ";
  char ch;
  while((ch=getchar())!='\n')
  {
     s.push_back(ch);
  }
  cout<<"Enter your age: ";
  cin>>age;
  cout<<s<<endl;
  cout<<age<<endl;
//  cout<<decrypt(pas)<<endl;
}