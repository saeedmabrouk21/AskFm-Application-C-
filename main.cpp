#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define lp(i, n)    for(int i=0;i<(int)(n);++i)
#define lp1(i, n)    for(int i=1;i<(int)(n);++i)
#define it(xx)          for(auto x:xx)
typedef long long ll;

class USER{
  public:
    USER(string user ,string mail,char gender,int id){
        set_user_name(user);
        set_mail(mail);
        set_gender(gender);
        this->id=id;
          //ADMIN admin (user,pass,0);
      }
    int get_ID(){
      return id;
    }

    char get_gender(){
      return gender;
    }
    void set_gender(char gender){
      this->gender=gender;
    }
    string get_user_name(){
      return user_name;
    }
    void set_user_name(string user_name){
      this->user_name=user_name;
    }
    string get_mail(){
      return mail;
    }
    void set_mail(string mail){
      this->mail=mail;
    }
    vector<int> get_answered_questions(){
      return answeredQuestions;
    }
    void add_answered_question(int q){
      answeredQuestions.push_back(q);
    }
    vector<int> get_unanswered_questions(){
      return unAnsweredQuestions;
    }
    void add_unanswered_question(int q){
      unAnsweredQuestions.push_back(q);
    }
    vector<int> get_asked_questions(){
      return askedQuestions;
    }
    void add_asked_question(int q){
      askedQuestions.push_back(q);
    }
    void remove_answered_question(int b){
      vector<int>::iterator it;
      it = find(answeredQuestions.begin(),answeredQuestions.end(),b);
      answeredQuestions.erase(it);
    }
    void remove_unanswered_question(int b){
      vector<int>::iterator it;
      it = find(unAnsweredQuestions.begin(),unAnsweredQuestions.end(),b);
      unAnsweredQuestions.erase(it);
    }
    void remove_asked_question(int b){
      vector<int>::iterator it;
      it = find(askedQuestions.begin(),askedQuestions.end(),b);
      askedQuestions.erase(it);
    }
  private:
    int id ;
    char gender;
    string user_name;
    string mail;
    vector<int> answeredQuestions;
    vector<int> unAnsweredQuestions;
    vector<int> askedQuestions;
    
  
};


class MESSAGE{
  public:
    void answer (int a){
      answers.push_back(a);
    }
    vector<int> get_answers(){
      return answers;
    }
    void set_message(string message){
      this->message=message;
    }
    string get_message(){
      return message;
    }
    void set_label(string label){
      this->label=label;
    }
    string get_label(){
      return label;
    }
    void send_to(int u){
      to=u;
    }
    void send_from(int u){
      from=u;
    }
    int sent_to (){
      return to;
    }
    int sent_from(){
      return from;
    }

  private:
    int from ;
    int to;
    string label;
    string message;
    vector<int> answers;

};

class SYSTEM{
  public:
    void startsystem();
    
    


    SYSTEM() :SYSTEM("admin","admin"){

    }
    SYSTEM(string user ,string pass,char gender='m'){
        users[user]=make_pair(pass,ID);
        USER *a=new USER (user,"admin@admin.com",gender,ID);
        adminUsers[ID]=a;
        IDs.push_back('a');
        ID++;
        users["aliali"]=make_pair("123",ID);
        a=new USER ("aliali","admin@admin.com",gender,ID);
        normalUsers[ID]=a;
        IDs.push_back('n');
        ID++;
        users["maimai"]=make_pair("123",ID);
        a=new USER ("maimai","admin@admin.com",gender,ID);
        normalUsers[ID]=a;
        IDs.push_back('n');
        ID++;
        users["shrouk"]=make_pair("123",ID);
        a=new USER ("shrouk","admin@admin.com",'f',ID);
        normalUsers[ID]=a;
        IDs.push_back('n');
        ID++;
    }
  private:
    unordered_map <string,pair<string,int>>users; //every user name has password and id 
    int ID=0;
    int messageID=0;
    vector<char> IDs;
    unordered_map<int ,USER *>normalUsers;
    unordered_map<int ,USER *>permiumUsers;
    unordered_map<int ,USER *>adminUsers;
    unordered_set<int>blockedUsers;
    stack<int>answeredQuestions;
    unordered_map<int,MESSAGE *>messages;
    int screen1();//signin or sign up
    void screen2();//sign up screen
    void screen3();//sign in screen
    int screen4();//permiun offer
    void screen5(USER*);//normal user home screen
    void screen6(USER*);//permiun  user home screen
    void screen7(USER*);//admin user home screen
    int get_info();
    void printQestionsTo(USER*);
    void printQestionsFrom(USER*);
    
    void answerQuestion(USER*);
    void deleteQuestion(USER*);
    void askQuestion(USER* a);
    void changeName(USER* a);
    void deleteUser();
    void showSystemUsers();
    void addAdmin();
    void feed();
};

void SYSTEM::startsystem (void){
  
  while(true){
    system("cls");
    int operation = screen1();
    if(operation==1)
        screen3();
    else if(operation==2)
        screen2();
    else if(operation==4)
      continue;
    else
      return;
  }
}

int SYSTEM::screen1 (void){
    system("cls");
    int operation;
    cout<<"1 : Sign in\n2: Sign up\n3: Close System\noperation : ";
    
    cin >> operation;
    if(operation == 1){
      return 1;
    }else if(operation == 2){
      return 2;
    }else if(operation==3){
      return 3;  
    }else{
      cout<<"\nEnter valid operation . Enter any character to reenter";
      cin.clear();
			cin.ignore(20, '\n');
      while(getchar()!='\n');
      //while(getchar()!='\n');
      system("cls");
      return 4;
    }
}

void SYSTEM::screen2 (void){
    string user,password,mail,gender;
    cout<<"Hint:\"If you want to log in click 0 in USERNAME\""<<endl;
    cout<<"User Name :  ";
    
    cin >> user;
    
    if(user=="0"){
      screen3();
      return;
    }
    cout<<"Password : ";
    cin >> password;
    cout<<"E-mail : ";
    cin >> mail;
    cout<<"Gender : ";
    cin >> gender;
    transform(gender.begin(), gender.end(), gender.begin(), ::tolower);
    if(users.count(user) == 0){
        //check for validation of inputs
        if(user.length()<6){
          cout<<"\nUser name must be atleast 6 characters . Enter any character to reenter";
          while(getchar()!='\n');
          while(getchar()!='\n');
          system("cls");
          screen2();
        }else if(password.length()<8){
          cout<<"\nPassword must be atleast 8 characters . Enter any character to reenter";
          while(getchar()!='\n');
          while(getchar()!='\n');
          system("cls");
          screen2();
        }else if(mail.find("@")==string::npos){
          cout<<"\nEnter Valid E-mail . Enter any character to reenter";
          while(getchar()!='\n');
          while(getchar()!='\n');
          system("cls");
          screen2();
        }else if(gender!="male"&&gender!="female"){
          cout<<"\nEnter Gender . Enter any character to reenter";
          while(getchar()!='\n');
          while(getchar()!='\n');
          system("cls");
          screen2();
        }else{
          int p = screen4();
          if(p==1){
            IDs.push_back('p');
            USER* a = new USER(user,mail,gender=="male"?'m':'f',ID);
            users[user]=make_pair(password,ID);
            permiumUsers[ID]=a;
            ID++;
            screen6(a);
          }else{
            IDs.push_back('n');
            USER* a = new USER (user,mail,gender=="male"?'m':'f',ID);
            users[user]=make_pair(password,ID);
            normalUsers[ID]=a;
            ID++;
            screen5(a);
          }
        }
    }else if(users.count(user) == 1){
      cout<<"There is a user with the same name , Try anything else or log in\nEnter any character to reenter ";
      while(getchar()!='\n');
      while(getchar()!='\n');
      system("cls");
      screen2();
    }
    return;
}

void SYSTEM::screen3 (void){
    string user,password;
    cout<<"User Name : ";
    cin >> user;
    cout<<"Password : ";
    cin >> password;
    if(users.count(user) == 0){
      cout<<"There is no user with this name .";
      while(getchar()!='\n');
      while(getchar()!='\n');
      system("cls");
      screen3();
    }else{
      if(users[user].first==password){
        USER* a;
        switch (IDs[users[user].second])
        {
        case 'n':
          a = normalUsers[users[user].second];
          screen5(a);
          break;
        case 'p':
          a = permiumUsers[users[user].second];
          screen6(a);
          break;
        case 'a':
          a = adminUsers[users[user].second];
          screen7(a);
          break;
        default:
          break;
        }
      }else{
        cout<<"Incorrect Password.";
        while(getchar()!='\n');
        while(getchar()!='\n');
        system("cls");
        screen3();
      }
    }   
}

int SYSTEM::screen4 (void){
    cout<<"\nWe offer you to be perimun user for only 10$ \nEnter 1 : accept   2:refuse";
          int perm ;
          cin>>perm;
          if(perm == 1){
            system("cls");
            return 1;
          }else if(perm == 2){
            system("cls");
            return 2;
          }else{
            cout<<"\nEnter valid operation . Enter any character to reenter";
            return screen4();
            
            //return screen1();
          }
            while(getchar()!='\n');
            while(getchar()!='\n');
            system("cls");
            //return screen1();
    
    
}
//normal user screen
void SYSTEM::screen5 (USER* a){
  while(true){
    while(1){
      system("cls");
      cout <<" 1 : print questions to me\n "
            "2 : print questions from me\n "
            "3 : answer question\n "
            "4 : delete question\n "
            "5 : ask question\n "
            "6 : feed\n "
            "7 : log out\n ";
      int operation ;
      cin >>operation;
      switch (operation)
      {
        case 1:
        printQestionsTo(a);
        break;
      case 2:
        printQestionsFrom(a);
        break;
      case 3:
        answerQuestion(a);
        break;
      case 4:
        deleteQuestion(a);
        break;
      case 5:
        askQuestion(a);
        break;
      case 6:
        feed();
        break;
      case 7:
        return;
        break;
      default:
        break;
      } 
    }
  }
}

void SYSTEM::screen6 (USER* a){
while(true){
  system("cls");
  cout <<" 1 : print questions to me\n "
            " 2 : print questions from me\n "
            " 3 : answer question\n "
            " 4 : delete question\n "
            " 5 : ask question\n "
            " 6 : feed\n "
            " 7 : change user name\n "
            " 8 : print questions to\n "
            " 9 : log out\n ";
      int operation ;
      cin >>operation;
      system("cls");
      vector<int> questions;
      int ab;
      string str;
      USER* uu;
      MESSAGE* mm;
      switch (operation)
      {
      case 1:
        printQestionsTo(a);
        break;
      case 2:
        printQestionsFrom(a);
        break;
      case 3:
        answerQuestion(a);
        break;
      case 4:
        deleteQuestion(a);
        break;
      case 5:
        askQuestion(a);
        break;
      case 6:
        feed();
        break;
      case 7:
        changeName(a);
        break;
      case 8:
        ab=get_info();
        while(ab==-1){
          ab=get_info();
        }
        if(adminUsers.count(ab)!=0){
          cout<<"Can't View admin Questions";
          cout<<"\n Enter any character to continue";
          while(getchar()!='\n');
          while(getchar()!='\n');
        }else if(permiumUsers.count(ab)!=0) {
          printQestionsTo(permiumUsers[ab]);
        }else if(normalUsers.count(ab)!=0) {
          printQestionsTo(normalUsers[ab]);
        }
        break;
      case 9:
        return;
        break;
      default:
        cout<<"No valid Operation";
        cout<<"\n Enter any character to continue";
        while(getchar()!='\n');
        while(getchar()!='\n');
        break;
      }
    } 
}

void SYSTEM::screen7 (USER* a){
  while(1){
    system("cls");
    cout <<"  1 : print questions to me\n "
           " 2 : print questions from me\n "
           " 3 : answer question\n "
           " 4 : delete question\n "
           " 5 : ask question\n "
           " 6 : feed\n "
           " 7 : change user name\n "
           " 8 : print questions to\n "
           " 9 : delete user\n "
           " 10 : show system users\n "
           " 11 : add admin\n "
           " 12 : log out\n ";
    int operation ,ab;
    cin >>operation;
    switch (operation)
    {
    case 1:
      printQestionsTo(a);
      break;
    case 2:
      printQestionsFrom(a);
      break;
    case 3:
      answerQuestion(a);
      break;
    case 4:
      deleteQuestion(a);
      break;
    case 5:
      askQuestion(a);
      break;
    case 6:
      feed();
      break;
    case 7:
      changeName(a);
      break;
    case 8:
      cout<<"Enter The ID : ";
        ab=get_info();
        if(adminUsers.count(ab)!=0){
          cout<<"Can't View admin Questions";
          cout<<"\n Enter any character to continue";
          while(getchar()!='\n');
          while(getchar()!='\n');
        }else if(permiumUsers.count(ab)!=0) {
          printQestionsTo(permiumUsers[ab]);
        }else if(normalUsers.count(ab)!=0) {
          printQestionsTo(normalUsers[ab]);
        }
      break;
    case 9:
      deleteUser();
      break;
    case 10:
      showSystemUsers();
      break;

    case 11:
      addAdmin();
      break;
    case 12:
      return;
      break;
    default:
      break;
    }   
  }
}

int SYSTEM::get_info(){
  string str;int ab;
  cout<<"Write User name or ID : ";
  cin >>str;
  if (str.length()<6){
    ab=stoi(str);
  }else{
    if(users.count(str)==0){
      cout<<"No user with following input . Enter any character to reenter";
      while(getchar()!='\n');
      while(getchar()!='\n');
      system("cls");
      return -1;
    }else{
      ab=users[str].second;
    }
  }
  if(permiumUsers.count(ab)==0&&normalUsers.count(ab)==0&&adminUsers.count(ab)==0){
      cout<<"No user with following input . Enter any character to reenter";
      while(getchar()!='\n');
      while(getchar()!='\n');
      system("cls");
      return -1;
  }
  return ab;
}

void SYSTEM::printQestionsTo(USER* a){
  vector<int>questions;
  cout<<"Unanswered Qeustions :"<<endl;
      questions = a->get_unanswered_questions();
      for(auto x : questions)
        cout <<x<<" : "<<"Label : "<<messages[x]->get_label()<<" Qestion : "<<messages[x]->get_message()<<endl;
       cout<<"answered Qeustions :"<<endl;
      questions = a->get_answered_questions();
      for(auto x : questions){
        cout <<x<<" : "<<"Label : "<<messages[x]->get_label()<<" Qestion : "<<messages[x]->get_message()<<endl;
        vector<int>cc;
        cc= messages[x]->get_answers();
        cout <<"\tANSWER : "<<messages[cc[0]]->get_message()<<endl;
        for(int i =1 ; i < cc.size();i++){
            cout <<"\t\tThread : "<<messages[cc[i]]->get_message()<<endl;
        }

      }
      cout<<"\n Enter any character to continue"<<endl;
      while(getchar()!='\n');
      while(getchar()!='\n');
      return;
}

void SYSTEM::printQestionsFrom(USER* a){
  vector<int>questions;
  questions = a->get_asked_questions();
  for(auto x : questions){
    cout <<x<<" : "<<"Label : "<<messages[x]->get_label()<<" Qestion : "<<messages[x]->get_message()<<endl;
    vector<int>cc;
    cc= messages[x]->get_answers();
    if(cc.size()==0){
      continue;
    }
    cout <<"\tANSWER : "<<messages[cc[0]]->get_message()<<endl;
    for(int i =1 ; i < cc.size();i++){
        cout <<"\t\tThread : "<<messages[cc[i]]->get_message()<<endl;
    }
  }
  cout<<"\n Enter any character to continue";
  while(getchar()!='\n');
  while(getchar()!='\n');
}

void SYSTEM::answerQuestion(USER* a){
  int ab;
  cout<<"Write the Id of question to answer "<<endl;
  cin >> ab;
  if(messages.count(ab)==0){
    cout<<"No Question with this ID";
    cout<<"\n Enter any character to continue";
    while(getchar()!='\n');
    while(getchar()!='\n');
  }else if(messages[ab]->sent_to()==a->get_ID() || messages[ab]->get_answers().size()>=1 ){
    cout<<"Enter Answer : ";
    string str;
    while(getchar()!='\n');
    getline(cin,str);
    MESSAGE * mm=new MESSAGE;
    mm->set_message(str);
    mm->send_from(a->get_ID());
    mm->send_to(messages[ab]->sent_from());
    mm->set_label(messages[ab]->get_label());
    messages[ab]->answer(messageID);
    messages[messageID]=mm;
    messageID++;
    if(messages[ab]->get_answers().size()==1){ 
      answeredQuestions.push(ab);
      a->remove_unanswered_question(ab);
      a->add_answered_question(ab);
    }
  }
  else{
    cout<<"No Question with this ID";
  }
  cout<<"\n Enter any character to continue";
  while(getchar()!='\n');
  while(getchar()!='\n');
  
}

void SYSTEM::deleteQuestion(USER* a){
  cout <<"Enter Question ID you want to delete : " ;
  int ab;
  cin >>ab;
  //cout <<messages[ab]->sent_from()<<"   "<<a->get_ID()<<" "<<adminUsers.count(a->get_ID());

  if(messages.count(ab)==0||messages[ab]->get_answers().size()==0 ||(adminUsers.count(a->get_ID())==0 && messages[ab]->sent_from()!=a->get_ID())){
    cout<<"Unfortunatly . You don't have rights to delete ."<<endl;
    cout<<"\n Enter any character to continue";
    while(getchar()!='\n');
    while(getchar()!='\n');
    return;
  }
  //remove question message from asked questions from sender
  a->remove_asked_question(ab);
  vector<int> aa;
  aa=messages[ab]->get_answers();

  //remove thread messages
  for(auto x:aa){
    messages.erase(x);
  }
  //remove question message from receiver as answered question
  int sentTo=messages[ab]->sent_to();
    if(IDs[sentTo]=='a'){
      adminUsers[sentTo]->remove_answered_question(ab);
    }else if(IDs[sentTo]=='p'){
      permiumUsers[sentTo]->remove_answered_question(ab);
    }else{
      normalUsers[sentTo]->remove_answered_question(ab);
    }
  messages.erase(ab);
  cout<<"Enter any character to continue";
  while(getchar()!='\n');
  while(getchar()!='\n');
  return;

}

void SYSTEM::askQuestion(USER* a){
  int ab;
  string str;
  USER* uu;
  MESSAGE* mm;
  ab =get_info();
  while(ab==-1){
    ab=get_info();
  }
    switch (IDs[ab])
    {
    case 'a':
      uu=adminUsers[ab];
      break;
    case 'p':
      uu=permiumUsers[ab];
      break;
    case 'n':
      uu=normalUsers[ab];
      break;
    default:
      break;
    }
    cout<<"Enter the label of question \"sport reading ...etc"<<endl;
    cin>>str;
    mm=new MESSAGE;
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    mm->set_label(str);
    if(uu->get_gender()=='m'){
      cout<<"ask him"<<endl;
    }else
      cout<<"ask her"<<endl;
    while(getchar()!='\n');
    getline(cin,str);
    
    mm->set_message(str);
    //mm->set_id(messageID);
    a->add_asked_question(messageID);
    
    uu->add_unanswered_question(messageID);
    mm->send_from(a->get_ID());
    mm->send_to(uu->get_ID());
    messages[messageID]=mm;
    messageID++;
    cout<<"Enter any character to continue";
    while(getchar()!='\n');
    //while(getchar()!='\n');
}
  

void SYSTEM::feed(){
  stack<int> x;
  x=answeredQuestions;
  while(!x.empty()){
    if(messages.count(x.top())==0){
      x.pop();
      continue;
    }
    cout <<x.top()<<" : "<<"Label : "<<messages[x.top()]->get_label()<<" Qestion : "<<messages[x.top()]->get_message()<<endl;
    vector<int>cc;
    cc= messages[x.top()]->get_answers();
    cout <<"\tANSWER : "<<messages[cc[0]]->get_message()<<endl;
    for(int i =1 ; i < cc.size();i++){
        cout <<"\t\tThread : "<<messages[cc[i]]->get_message()<<endl;
    }
    x.pop();
  }
  //cout<<"This feature is not available, yet :("<<endl;
  cout<<"\n Enter any character to continue";
  while(getchar()!='\n');
  while(getchar()!='\n');
}

void SYSTEM::changeName(USER* a){
  //detect usur tpye 
  //if(adminUsers.count(a->get_ID())!=0)
  string str;
  cout << "Enter new user name : ";
  cin >>str;
  if(str.size()<6){
    cout<<"User name must be more than 6 characters"<<endl;
    cout<<"\n Enter any character to continue";
    while(getchar()!='\n');
    while(getchar()!='\n');
    return;
  }
  users[str]=users[a->get_user_name()];
  users.erase(a->get_user_name());
  a->set_user_name(str);
  return;

}

void SYSTEM::deleteUser(){
  int id,sentFrom;
  id=get_info();
  while(id==-1){
    id=get_info();
  }
  USER* a;
  if(IDs[id]=='a')
    a=adminUsers[id];
  else if (IDs[id]=='p')
    a=permiumUsers[id];
  else
    a=normalUsers[id];
  vector<int> aa;


  aa=a->get_unanswered_questions();
  for(auto x:aa){
    sentFrom=messages[x]->sent_from();
    if(IDs[sentFrom]=='a')
      adminUsers[sentFrom]->remove_asked_question(x);
    else if (IDs[id]=='p')
      permiumUsers[sentFrom]->remove_asked_question(x);
    else
      normalUsers[sentFrom]->remove_asked_question(x);
  }


  aa=a->get_answered_questions();
  for(auto x:aa){
    sentFrom=messages[x]->sent_from();
    if(IDs[sentFrom]=='a')
      adminUsers[sentFrom]->remove_asked_question(x);
    else if (IDs[id]=='p')
      permiumUsers[sentFrom]->remove_asked_question(x);
    else
      normalUsers[sentFrom]->remove_asked_question(x);

    vector<int>cc;
    cc=messages[x]->get_answers();
    for(auto y:cc){
      messages.erase(y);
    }
    
  }
  int sentTo;
  aa=a->get_asked_questions();
  for(auto x:aa){
    vector<int> cc=messages[x]->get_answers();
    sentTo=messages[x]->sent_to();
    messages.erase(x);
    if(cc.size()==0){
        if(IDs[sentTo]=='a')
        adminUsers[sentTo]->remove_unanswered_question(x);
      else if (IDs[sentTo]=='p')
        permiumUsers[sentTo]->remove_unanswered_question(x);
      else
        normalUsers[sentTo]->remove_unanswered_question(x);
    } 
    else{
      if(IDs[sentTo]=='a')
        adminUsers[sentTo]->remove_answered_question(x);
      else if (IDs[sentTo]=='p')
        permiumUsers[sentTo]->remove_answered_question(x);
      else
        normalUsers[sentTo]->remove_answered_question(x);
      for(auto y:cc){
        messages.erase(y);
      }
    }
  }
  users.erase(a->get_user_name());
  if(IDs[id]=='a')
    adminUsers.erase(id);
  else if (IDs[id]=='p')
    permiumUsers.erase(id);
  else
    normalUsers.erase(id);
  
  
  cout<<"\n Enter any character to continue";
  while(getchar()!='\n');
  while(getchar()!='\n');
  return;
}

void SYSTEM::showSystemUsers(){
  for(int i = 0 ; i < IDs.size();i++){
    if(IDs[i]=='a'){
      if(adminUsers.count(i)==0){
        continue;
      }
      cout <<"User name : "<<left<<setw(15)<<adminUsers[i]->get_user_name()<<" ID : "<<left<<setw(5)<<i
      <<"Password : "<<left<<setw(15)<<users[adminUsers[i]->get_user_name()].first<<endl;
    }
    else if(IDs[i]=='p'){
      if(permiumUsers.count(i)==0){
        continue;
      }
      cout <<"User name : "<<left<<setw(15)<<permiumUsers[i]->get_user_name()<<" ID : "<<left<<setw(5)<<i
      <<"Password : "<<left<<setw(15)<<users[permiumUsers[i]->get_user_name()].first<<endl;
    }
    else{
      if(normalUsers.count(i)==0){
        continue;
      }
      cout <<"User name : "<<left<<setw(15)<<normalUsers[i]->get_user_name()<<" ID : "<<left<<setw(5)<<i
      <<"Password : "<<left<<setw(15)<<users[normalUsers[i]->get_user_name()].first<<endl;
    }
  }
  cout<<"Enter any character to continue";
  while(getchar()!='\n');
  while(getchar()!='\n');
}

void SYSTEM::addAdmin(){
  string user,password,mail,gender;
    cout<<"User : ";
    cin >> user;
    cout<<"Password : ";
    cin >> password;
    cout<<"E-mail : ";
    cin >> mail;
    cout<<"Gender : ";
    cin >> gender;
    transform(gender.begin(), gender.end(), gender.begin(), ::tolower);
    if(users.count(user) == 0){
        //check for validation of inputs
        if(user.length()<6){
          cout<<"\nUser name must be atleast 6 characters . Enter any character to reenter";
          while(getchar()!='\n');
          while(getchar()!='\n');
        }else if(password.length()<8){
          cout<<"\nPassword must be atleast 8 characters . Enter any character to reenter";
          while(getchar()!='\n');
          while(getchar()!='\n');
        }else if(mail.find("@")==string::npos){
          cout<<"\nEnter Valid E-mail . Enter any character to reenter";
          while(getchar()!='\n');
          while(getchar()!='\n');
        }else if(gender!="male"&&gender!="female"){
          cout<<"\nEnter Gender . Enter any character to reenter";
          while(getchar()!='\n');
          while(getchar()!='\n');
        }else{
            users[user]=make_pair(password,ID);
            USER *a=new USER (user,mail,gender=="male"?'m':'f',ID);
            adminUsers[ID]=a;
            IDs.push_back('a');
            ID++;
        }
    }else if(users.count(user) == 1){
      cout<<"There is a user with the same name , Try anything else or log in\nEnter any character to reenter ";
      while(getchar()!='\n');
      while(getchar()!='\n');
      system("cls");
    }
    return;
}



int main()
{
  SYSTEM askFM("saeedfares","123");
  askFM.startsystem();
  return 0;
}
