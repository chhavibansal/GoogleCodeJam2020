#include<bits/stdc++.h>
using namespace std;
class Activity{
public:
    int start ,end , pos;
    // bool visited;
    Activity(int s , int e , int p){
        start = s;
        end = e;
        pos = p;
        // visited =false;
    }
};
bool cmp(Activity a , Activity b){
    if(a.start == b.start)
    return a.pos < b.pos;

    return a.start < b.start;
}
int main(){
    int t;
    cin >> t;
    int count = 1;
    while(t--){
        int n ;
        cin >> n;
        Activity a(0,0,0);

        vector<Activity> temp ;
        // vector<bool> visited(n, false);
        vector<string> ans(n);
    int  s , e;
        for(int  i = 0  ; i < n ; i++){
            cin >> s >> e ;
            a.start = s , a.end = e , a.pos = i;
            temp.push_back(a);
           
        }

        sort(temp.begin() , temp.end() , cmp);

               
        int women_end_time = temp[0].end;
        int i, man_end_time = 0;
        ans[temp[0].pos] = "C";

        for(i = 1 ; i < n ; i++){
            if (women_end_time <= temp[i].start)
            {
                women_end_time = temp[i].end;
                ans[temp[i].pos]= "C";
            }
            else if (women_end_time > temp[i].start and man_end_time <= temp[i].start)
            {
                man_end_time = temp[i].end;
                ans[temp[i].pos]= "J";
                
            }
            else
            {
                // cout <<"IMPOSSIBLE";
                break;
            }
        }
         cout << "Case #" << count << ": ";
        if (i == n)
        {
            for (string s : ans)
                cout << s;
        }
        else
        {
            cout << "IMPOSSIBLE";
        }
        count += 1;
        cout << endl;
    }
}