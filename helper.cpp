#include <iostream>

using namespace std;
string res="";
int count=0;
struct node
{
    char data;
    node *link;
};
struct node *top = 0;

void input(char ans)
{
    struct node *newnode = new (node);
    newnode->data = ans;
    if (top == 0)
    {
        newnode->link = 0;
        top = newnode;
    }
    else
    {
        newnode->link = top;
        top = newnode;
    }
}

void display()
{
    node *temp = top;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->link;
    }
}

void postfix(string s)
{
    cout << endl;
   input(0);
    // let s= A*B+C/D

    // so the answer would be = AB*CD/+

    // associativity
    //() > ^ > /* > +-

    for (int i = 0; i < s.length(); i++)
    {

        if (count==0 && (top->link==NULL && (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*' || s[i]=='(' || s[i]=='^')))
        {
            input(s[i]);
            count=1;
            
        }

        // STARTING FROM THE + OPERATOR
        else if ( top->data == '+' && (s[i] == '*' || s[i]=='/' || s[i]=='(' || s[i]=='^' ) )
        {
            input(s[i]);
        }

        else if ((top->data == '+' && s[i] == '-')  || (top->data == '+' && s[i] == '+') )
        {
            while (top!= NULL)
            {
                if(top->data=='('){
                    break;
                }

                res+=top->data;
                top = top->link;
            }
            input(s[i]);
            count=1;
        }

        // FOR - OPERATOR
        else if ((top->data == '-' && s[i] == '/')  || (top->data == '-' && s[i] == '*') || (top->data=='-' && s[i]=='(' ) || (top->data=='-' && s[i]=='^' ))
        {
            input(s[i]);
        }

        else if (top->data == '-' && (s[i] == '+' || s[i]=='-'))
        {
            while (top != NULL)
            {
                if(top->data=='('){
                    break;
                }

                 res+=top->data;
                top = top->link;
            }
            input(s[i]);
            count=1;
            
        }

        // FOR * OPERATOR

        else if(top->data=='*' && (s[i]=='(' || s[i]=='^' ) ){
            input(s[i]);
        }


        else if ((top->data == '*' && (s[i] == '/' || s[i]=='*'  )))
        {
            while (top != NULL)
            {    
                if(top->data=='-' || top->data=='+')break;
                  if(top->data=='('){
                    break;
                }
                 res+=top->data;
                top = top->link;
            }
            input(s[i]);
            count=1;
        }

              else if ((top->data == '*' && (s[i] == '+' || s[i]=='-' )))
        {
            while (top != NULL)
            {   
                //adding bracket condition  

                  if(top->data=='('){
                // we have to stop the loop here till open bracket
                    break;
                }
                
                 res+=top->data;
                top = top->link;
            }
            input(s[i]);
            count=1;
        }



        //FOR / OPERATOR

             else if(top->data=='/' && (s[i]=='(' || s[i]=='^' )){
            input(s[i]);
        }


            else if ((top->data == '/' && (s[i] == '/' || s[i]=='*' )))
        {
            while (top != NULL)
            {    
                if(top->data=='-' || top->data=='+')break;

                 if(top->data=='('){
                // we have to stop the loop here till open bracket
                    break;
                }
                 res+=top->data;
                top = top->link;
            }
            input(s[i]);
            count=1;
        }


            else if ((top->data == '/' && (s[i] == '-' || s[i]=='+' )))
        {
            while (top != NULL)
            {    
                 if(top->data=='('){
                // we have to stop the loop here till open bracket
                    break;
                }
                 res+=top->data;
                top = top->link;
            }
            input(s[i]);
            count=1;
        }
        //For Bracket ()

        else if(top->data=='(' && (s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='(' || s[i]=='^' ) ){
            input(s[i]);
            
        }


        else if(s[i]==')'){
            while(top!=NULL){

                if(top->data=='('){
                    top=top->link;
                    
                    break;
                }

                res+=top->data;
                top=top->link;
                count=0;
            }
            

            count=0;
        }

        //for Power ^

           else if(top->data=='^' && s[i]=='(' ){
            input(s[i]);
            
        }


            else if ((top->data == '^' && (s[i] == '/' || s[i]=='*' || s[i]=='^')))
        {
            while (top != NULL)
            {    
                if(top->data=='-' || top->data=='+' || top->data=='/' || top->data=='*' )break;

                 res+=top->data;
                top = top->link;
            }
            input(s[i]);
            count=1;
        }


            else if ((top->data == '^' && (s[i] == '-' || s[i]=='+' )))
        {
            while (top != NULL)
            {    
                 res+=top->data;
                top = top->link;
            }
            input(s[i]);
            count=1;
        }


        else
        {
            res+=s[i];
        }
    }
      
      while (top != NULL)
            {
                res+=top->data;
                top = top->link;
            }
            count=0;
    
       


}