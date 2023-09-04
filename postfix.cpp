#include <iostream>
#include"helper.cpp"
using namespace std;
int main()
{
    //bracket () hasnt added so it can only solve 3 operands operaton

    string s ;
    cout<<"Enter express to convert it into postfix e.g(a+b, a+-b etc): "<<endl;
    cin>>s;


    postfix(s);
    display();
  cout<<"The postfix expression is: "<<res<<endl;
  
cout<<endl;
    return 0;
}