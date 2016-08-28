#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
struct card
{
    char flower=' ',num=' ';
    friend bool operator == (card a,card b);
};
bool operator == (card a,card b)
{
    if(a.flower==b.flower||a.num==b.num) return true;
    return false;
}
int main()
{
    char first=' ';
    while(cin>>first&&first!='#')
    {
        card cards[55];
        vector <stack<card> > pile;
        card tmpc;
        cin>>tmpc.flower;
        tmpc.num=first;
        cards[0]=tmpc;
        for(int i=1; i<52; i++)
        {
            cin>>tmpc.num>>tmpc.flower;
            cards[i]=tmpc;
        }
        for(int i=0; i<52; i++)
        {
            stack <card> c;
            c.push(cards[i]);
            pile.push_back(c);
            for(int j=pile.size()-1; j<pile.size(); j++)
            {
                card tmp=pile[j].top();
                if(j>=3)
                {
                    if(tmp==pile[j-3].top())
                    {
                        pile[j-3].push(tmp);
                        pile[j].pop();
                        if(pile[j].empty()) pile.erase(pile.begin()+j);
                        j-=4;
                    }
                    else if(tmp==pile[j-1].top())
                    {
                        pile[j-1].push(tmp);
                        pile[j].pop();
                        if(pile[j].empty()) pile.erase(pile.begin()+j);
                        j-=2;

                    }
                }
                else if(j>0&&j<3)
                {
                    if(tmp==pile[j-1].top())
                    {
                        pile[j-1].push(tmp);
                        pile[j].pop();
                        if(pile[j].empty()) pile.erase(pile.begin()+j);
                        j-=2;
                    }

                }
            }
        }
        int ans=pile.size();
        if(ans==1)  cout<<ans<<" pile remaining:";
        else cout<<ans<<" piles remaining:";
        for(vector<stack<card> >::iterator it=pile.begin();it!=pile.end();it++)
        {
            cout<<' '<<it->size();
        }
        cout<<endl;
    }
    return 0;
}
