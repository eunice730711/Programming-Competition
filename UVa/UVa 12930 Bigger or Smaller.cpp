#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<map>
#include<vector>
#include<string>
using namespace std;
//int compute(string str)
//{
//
//    int len=str.size(),num=0;
//
//    for(int i=0; i<len; i++)
//    {
//
//        num=num*10+(str[i]-'0');
//    }
//
//    return num;
//
//}
int main()
{
    string a,b;
    int cas=1;
    while(cin>>a>>b)
    {
        int lena=a.size(),lenb=b.size();
        auto it=find(a.begin(),a.end(),'.');
        auto it1=find(b.begin(),b.end(),'.');
        int ind1=it-a.begin(),ind2=it1-b.begin();
        //cout<<ind1<<endl<<ind2<<endl;


        string i1,f1,i2,f2;
        i1=a.substr(0,ind1);
        f1=a.substr(ind1+1,lena-ind1-1);
        i2=b.substr(0,ind2);
        f2=b.substr(ind2+1,lenb-ind2-1);

        // cout<<'a'<<i1<<' '<<f1<<' '<<i2<<' '<<f2<<endl;
        //int n1=0,ff1=0,n2=0,ff2=0;
      //  n1=compute(i1),ff1=compute(f1),n2=compute(i2),ff2=compute(f2);
        //cout<<n1<<' '<<ff1<<' '<<n2<<' '<<ff2<<endl;
        if(i1>i2)  printf("Case %d: Bigger\n",cas++);
        else if(i1<i2) printf("Case %d: Smaller\n",cas++);
        else
        {

            int s1=f1.size(),s2=f2.size(),idx1=-1,idx2=-1;
            for(int i=s1-1; i>=0; i--)
            {
                if(f1[i]!='0')
                {
                    idx1=i;
                    break;
                }
            }
            for(int i=s2-1; i>=0; i--)
            {
                if(f2[i]!='0')
                {
                    idx2=i;
                    break;
                }
            }
            string tmp1="",tmp2="";
           // cout<<idx1<<' '<<idx2<<endl;
            if(idx1==-1) tmp1=f1.substr(0,1);
            else tmp1=f1.substr(0,idx1+1);
            if(idx2==-1) tmp2=f2.substr(0,1);
            else tmp2=f2.substr(0,idx2+1);
            //cout<<tmp1<<' '<<tmp2<<endl;
            tmp1+='\0';
            tmp2+='\0';
//cout<<tmp1.compare(tmp2)<<endl;
            if(tmp1.compare(tmp2)>0) printf("Case %d: Bigger\n",cas++);
            else if(tmp1.compare(tmp2)<0) printf("Case %d: Smaller\n",cas++);
            else if(tmp1.compare(tmp2)==0) {printf("Case %d: Same\n",cas++);}
            //cout<<"aa"<<endl;


        }




    }
    return 0;

}
