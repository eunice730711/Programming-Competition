#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<string,string> ss;
int main()
{
    char input[10005]="",command[10005]="";
    map<ss,bool> on; ///books on shelves
    map<string,string> books;///book and author
    while(gets(input)&&strcmp(input,"END")!=0)
    {
        int len=strlen(input),ind=0,sind=10000000;
        char tmp[10005]="";
        string name="",author="";
        bool check=false,flag=false;
        for(int i=0; i<len; i++)
        {
            if(input[i]=='"'&&check==false) check=true;
            else if(check==true &&input[i]!='"')
            {
                tmp[ind++]=input[i];
            }
            else if(input[i]=='"' && check==true)
            {
                check=false;
                name.assign(tmp);
                memset(tmp,0,sizeof(tmp));
                ind=0;
                sind=i;
            }
            if(i>sind+4)
            {
                tmp[ind++]=input[i];
            }
            if(i==len-1)
            {
                author.assign(tmp);
                memset(tmp,0,sizeof(tmp));
                ind=0;
            }
        }
        ss tmpp(author,name);
        books[name]=author;///store the mapping author of the book
        on[tmpp]=true;///record whether the book is on the shelves
    }

    string book="",instr="";
    deque<ss> rev;
    while(cin>>instr &&instr!="END")
    {
        if(instr=="BORROW")
        {
            getline(cin,book);
            book=book.substr(2,book.size()-3);
            string auu=books[book];
            on[ss(auu,book)]=false;
        }
        else if(instr=="RETURN")
        {
            getline(cin,book);
            book=book.substr(2,book.size()-3);
            string auu=books[book];
            on[ss(auu,book)]=true;
            rev.push_back(ss(auu,book));
        }
        else if(instr=="SHELVE")
        {
            sort(rev.begin(),rev.end());
            while(!rev.empty())
            {
                ss top=rev.front();
                string bau=top.first,bname=top.second;
                rev.pop_front();
                auto it=on.find(top);
                bool first=true;
                for(it;; it--)
                {
                    if(first==true)
                    {
                        if(it==on.begin())
                        {
                            cout<<"Put \""<<bname<<"\" first"<<endl;
                            break;
                        }
                        first=false;
                    }
                    else if(it->second==true)
                    {
                       cout<<"Put \""<<bname<<"\" after \""<<it->first.second<<"\""<<endl;
                       break;

                    }
                    if(it==on.begin())
                    {
                        cout<<"Put \""<<bname<<"\" first"<<endl;
                        break;
                    }
                }
            }
            cout<<"END"<<endl;
        }
    }
    return 0;
}
