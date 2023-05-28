#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
void cheek(string name,int age,string email,string phone_number,string username,string password);
void suggested_password();
string password_validation();
void main_page_function();
void admin();
void user();
void admin_read();
void user_function();
void login();
void login_id_cheek(string username,string password);
void login_page();
void login_page_function(char ch,string name,string email,int age,string username,string password,string phone_number);
void view_profile(char ch,string name,string email,int age,string username,string password,string phone_number);
void change_password(string phone_number);
void change_password_function(string changePassword,string phone_number);
void logout();
string encrypct(string password);
string decrypt(string password);
void registration();
void wrong_password();
void wrong_password_function();
void forget_password();
void delete_id(string phone_number);
void duplicate_id(string phonenumber);


class Registration{
    string name;
    int age;
    string email;
    string phone_number;
    string username;
    string password;
    public:
    friend void registration();
    friend void save_front();
};
Registration R;


class File{
    public:
    friend void write(string name,int age,string email,string phone_number,string username,string password);
    void read();
    void update();
    void Delete();
};


class Front:public Registration{
    public:
     friend void save_front();
};

void save_front()
{
    cout<<"_____1.Save data_____"<<endl;
    cout<<"_____2.Cancel________"<<endl;
    cout<<"Chosse your option: "<<endl;
   cheek(R.name,R.age,R.email,R.phone_number,R.username,R.password);
}

void main_page()
{
    cout<<"     ******Welcome To Our Security System***** "<<endl<<endl;
    cout<<"__________1.Admin__________"<<endl;
    cout<<"__________2.User___________"<<endl;
    cout<<"Chosse your option: "<<endl;
    main_page_function();
}

void user()
{
  cout<<"____________________"<<endl;
  cout<<"     1.Register     "<<endl;
  cout<<"     2.Login        "<<endl;
  cout<<"____________________"<<endl;
  cout<<"Chosse your option: "<<endl;
  user_function();
}


void login_page(char ch,string name,string email,int age,string username,string password,string phone_number)
{
    cout<<"_______________________"<<endl;
    cout<<"|                     |"<<endl;
    cout<<"|  1.View Profile     |"<<endl;
    cout<<"|  2.Change Password  |"<<endl;
    cout<<"|  3.Log Out          |"<<endl;
    cout<<"|  4.Delete Id        |"<<endl;
    cout<<"|_____________________|"<<endl;
     cout<<"Chosse your option: "<<endl;
    login_page_function(ch,name,email,age,username,password,phone_number);
}

void logout()
{
    cout<<"     *****Thank You So Much***** "<<endl;
    cout<<"     _____Wish You Best Of Luck_____"<<endl;
}

void wrong_password()
{
    cout<<"Incorrect Password!!!!!"<<endl;
    cout<<"_____1.Forget Password_____"<<endl;
   cout<<"__________2.Re Try_________"<<endl;
   cout<<"Chosse your option: "<<endl;
   wrong_password_function();
}

void wrong_password_function()
{
    int x;
    cin>>x;
    switch(x)
    {
        case 1:
        forget_password();
        break;
        case 2:
        login();
        break;
        default:
        cout<<"Invalid number!! Please enter the correct number"<<endl;
        wrong_password();
    }
}


void forget_password()
{
    string phone_number;
   cout<<"Enter your Phone Number: ";
   cin>>phone_number;
   ifstream in;
   in.open("security_file.txt");
   string name,email,username,password,phonenumber;
    int age;
    char ch;
   while(in.eof()==0)
   {
        getline(in,name);
        in>>age>>email>>phonenumber>>username>>password>>ch;
        if(phone_number==phonenumber)
        {
            in.close();
           change_password(phone_number);
           return;
        }
   }
   cout<<"Wrong Phone Number!! Please enter correct Phone Number"<<endl;
   in.close();
   forget_password();
}


void login_page_function(char ch,string name,string email,int age,string username,string password,string phone_number)
{
    int n;
    cin>>n;
    switch(n)
    {
        case 1:
        view_profile(ch,name,email,age,username,password,phone_number);
        cout<<endl;
        login_page(ch,name,email,age,username,password,phone_number);
        break;
        case 2:
        change_password(phone_number);
        cout<<endl;
        user();
        break;
        case 3:
        logout();
        break;
        case 4:
        delete_id(phone_number);
        cout<<endl;
        user();
        break;
        default:
        cout<<"Invalid number!! Please enter the correct number"<<endl;
        login_page(ch,name,email,age,username,password,phone_number);
    }
}


void change_password(string phone_number)
{
    string Password="";
    cout<<"Enter your New Password: ";
    char ch;
    ch=_getch();
    while(ch!=13)
    {
       Password.push_back(ch);
       cout<<"*";
       ch=_getch();
    }
    string passWord=encrypct(Password);
    change_password_function(passWord,phone_number);
}


void change_password_function(string changePassword,string phone_number)
{
    ifstream in;
    in.open("security_file.txt");
    ofstream out;
    out.open("temp_file.txt",ios::app);
    string name,email,username,password,phonenumber;
    int age;
    char ch;
    int i=0;
    while(in.eof()==0)
    {
        getline(in,name);
        in>>age>>email>>phonenumber>>username>>password;
        if(i!=0){
            out<<ch;
        }
        out<<name<<endl;
        if(phone_number==phonenumber)
        {

            out<<age<<endl<<email<<endl<<phonenumber<<endl<<username<<endl<<changePassword<<endl;
        }
        else{
              out<<age<<endl<<email<<endl<<phonenumber<<endl<<username<<endl<<password<<endl;
        }
        in>>ch;
        i++;
    }
    in.close();
    out.close();
    remove("security_file.txt");
    rename("temp_file.txt","security_file.txt");
}

void delete_id(string phone_number)
{
    ifstream in;
    in.open("security_file.txt");
    ofstream out;
    out.open("temp_file.txt",ios::app);
    string name,email,username,password,phonenumber;
    int age;
    char ch;
    int i=0;
    while(in.eof()==0)
    {
        getline(in,name);
        in>>age>>email>>phonenumber>>username>>password;
       if(phone_number!=phonenumber)
       {
        if(i!=0){
            out<<ch;
        }
           out<<name<<endl<<age<<endl<<email<<endl<<phonenumber<<endl<<username<<endl<<password<<endl;
       }
       in>>ch;
       i++;
    }
    in.close();
    out.close();
    remove("security_file.txt");
    rename("temp_file.txt","security_file.txt");
}


void view_profile(char ch,string name,string email,int age,string username,string password,string phone_number)
{
    cout<<"          *****Welcome Profile Page*****"<<endl<<endl;
    cout<<"Name         : ";
    name.push_back('\n');
    int i=0;
    ifstream in;
    in.open("security_file.txt");
    string firstname,firstemail,firstphonenumber;
    int firstage;
    in>>firstname>>firstage>>firstemail>>firstphonenumber;
    in.close();
    if(phone_number!=firstphonenumber){
        cout<<ch;
    }
    while(name[i]!='\n')
    {
        cout<<name[i];
        i++;
    }
    cout<<endl;
    cout<<"Age          : "<<age<<endl;
    cout<<"Email        : "<<email<<endl;
    cout<<"Phone_number : "<<phone_number<<endl;
    cout<<"Username     : "<<username<<endl;
    cout<<"Password     : ";
    for(int i=0;i<password.size()/4;i++){
        cout<<"*";
    }
    cout<<endl;
}


void login()
{
    string username,password="";
    cout<<"Enter your Username: ";
    cin>>username;
    cout<<"Enter your Password: ";
     char ch;
    ch=_getch();
    while(ch!=13)
    {
       password.push_back(ch);
       cout<<"*";
       ch=_getch();
    }
    login_id_cheek(username,password);
}
void login_id_cheek(string userName,string passWord)
{
    ifstream in("security_file.txt");
    string name,email,username,password,phone_number;
    int age;
    char ch;
    while(in.eof()==0)
    {
        getline(in,name);
        in>>age>>email>>phone_number>>username>>password;
        string real_password=decrypt(password);
        if(userName==username && passWord==real_password){
            in.close();
            cout<<endl;
            login_page(ch,name,email,age,username,password,phone_number);
            return;
        }
        in>>ch;
    }
    in.close();
    wrong_password();
}


void user_function()
{
     int n;
    cin>>n;
    switch(n)
    {
        case 1:
        registration();
        cout<<endl;
        user();
        break;
        case 2:
        login();
        break;
        default:
        cout<<"Invalid number!! Please enter the correct number"<<endl;
        user();
        
    }
}

void admin()
{
    cout<<"Enter Admin Secret Password: ";
    string password="";
     char ch;
    ch=_getch();
    while(ch!=13)
    {
       password.push_back(ch);
       cout<<"*";
       ch=_getch();
    }
    cout<<endl;
    if(password=="rony2007065"){
     cout<<"     *****Welcome Admin Page*****"<<endl<<endl;
    cout<<"ID     Name           Age       Email             Phone_Number    Password"<<endl;
    admin_read();
    }
    else{
        cout<<"Hey!! You're a Hacker** "<<endl;
        cout<<"This is highly secure..So,please don't waste your time to try hack..."<<endl;
        cout<<"     *****Bye Bye*****"<<endl;
    }
}

void admin_read()
{
    ifstream in;
    in.open("security_file.txt");
    int x=1;
    string name,email,username,password,phone_number;
    int age;
    char ch;
    while(!in.eof())
    {
        getline(in,name);
        in>>age;
        in>>email;
        in>>phone_number;
        in>>username;
        in>>password;
      cout<<x<<"  "<<ch<<name<<"  "<<age<<"  "<<email<<"  "<<phone_number<<"  ";
      for(int i=0;i<password.size()/4;i++){
        cout<<"*";
      }
      cout<<endl;
      x++;
      in>>ch;
    }
    in.close();
}


void main_page_function()
{
    int n;
    cin>>n;
    switch(n)
    {
        case 1:
        admin();
        break;
        case 2:
        user();
        break;
        default:
        cout<<"Invalid number!! Please enter the correct number"<<endl;
        main_page();
        
    }
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


void write(string name,int age,string email,string phone_number,string username,string password)
{
    string passWord = encrypct(password);
    ofstream out;
    out.open("security_file.txt",ios::app);
    int i=0;
    while(name[i]!='\n')
    {
        out<<name[i];
        i++;
    }
    out<<endl;
    out<<age<<endl;
    out<<email<<endl;
    out<<phone_number<<endl;
    out<<username<<endl;
    out<<passWord<<endl;
    out.close();
}


void registration()
{
    cout<<"Enter your name: ";
    char c;
    cin>>c;
    R.name="";
    char ch;
    (R.name).push_back(c);
  while((ch=getchar())!='\n')
  {
     (R.name).push_back(ch);
  }
  (R.name).push_back('\n');
    cout<<"Enter your Age: ";
    cin>>R.age;
    cout<<"Enter your Email: ";
    cin>>R.email;
    cout<<"Enter your Phone Number: ";
    cin>>R.phone_number;
    duplicate_id(R.phone_number);
    cout<<"Enter your Username: ";
    cin>>R.username;
    cout<<"Enter your Password: ";
    R.password=password_validation();
    cout<<endl<<endl;
    save_front();
}
void duplicate_id(string phone_number)
{
    ifstream in("security_file.txt");
    string name,email,username,password,phoneNumber;
    int age;
    char ch;
    while(in.eof()==0)
    {
        getline(in,name);
        in>>age>>email>>phoneNumber>>username>>password>>ch;
        if(phone_number==phoneNumber){
            cout<<"This phone number is already Registered!!"<<endl;
            cout<<"Please enter another Phone Number: ";
            string phonenumber;
            cin>>phonenumber;
            duplicate_id(phonenumber);
        }
    }
    in.close();
}

string password_validation()
{
    string password="";
    while(1)
    {
      char ch;
    ch=_getch();
    while(ch!=13)
    {
       password.push_back(ch);
       cout<<"*";
       ch=_getch();
    }
    int s=0,c=0,d=0,e=0;
    if(password.size()>=6 && password.size()<=10){
    for(int i=0;i<password.size();i++){
        if(password[i]>='a' && password[i]<='z'){
              s=1;
        }
        else if(password[i]>='A' && password[i]<='Z'){
            c=1;
        }
        else if(password[i]>='0' && password[i]<='9'){
            d=1;
        }
        else{
            e=1;
        }
    }
    if(s+c+d+e==4){
        return password;
    }
    else{
        cout<<endl;
        cout<<"Weak Password!!!!"<<endl;
        cout<<"Please follow the rules to make strong Password: "<<endl;
        cout<<"1.Must be contain atlest a small alphabet."<<endl;
        cout<<"1.Must be contain atlest a capital alphabet."<<endl;
        cout<<"1.Must be contain atlest a digit."<<endl;
        cout<<"1.Must be contain atlest a spacial character."<<endl<<endl;
        cout<<"Suggested Password: ";
        suggested_password();
        cout<<endl<<endl;
        cout<<"Enter your Password Again: "<<endl;
        password_validation();
        break;
    }
    }
    else{
        cout<<endl;
       if(password.size()<6){
        cout<<"Password is too small!!!"<<endl;
        cout<<"Suggested Password: ";
        suggested_password();
        cout<<endl<<endl;
        cout<<"Enter your Password Again: "<<endl;
        password_validation();
        break;
       }
       else{
         cout<<"Password is too Big!!!"<<endl;
         cout<<"Suggested Password: ";
        suggested_password();
        cout<<endl<<endl;
        cout<<"Enter your Password Again: "<<endl;
        password_validation();
        break;
       }
    }
}
}

void suggested_password()
{
   srand(time(NULL));
    cout<<char(rand()%26+'A')<<char(rand()%26+'A')<<int(rand()%9)<<int(rand()%9)<<char(rand()%15+33)<<char(rand()%15+33)<<char(rand()%26+'a')<<char(rand()%26+'a'); 
}


void cheek(string name,int age,string email,string phone_number,string username,string password)
{
    int n;
    cin>>n;
    switch(n)
    {
        case 1: 
        write(name,age,email,phone_number,username,password);
        break;
        case 2:
        user();
        break;;
        default:
        cout<<"You pressed a wrong Number!!  Please enter the valid number"<<endl;
        save_front();
    }
}


int main()
{
   main_page();
}