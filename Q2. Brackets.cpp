#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int sample  =1;
    while (t--)
    {
        string s;
        cin >> s;

        string ans;
        int i = s.size() - 1, rem = 0, prev = 0, count, brackets= 0 ;
        while (i >= 0)
        {
            rem = s[i] - '0';
            count = prev - rem;
            // cout << count << " ";
            while (count < 0)
            {
                ans = ")" + ans;
                count += 1;
                brackets+=1;
            }
            while (count > 0)
            {
                ans = "(" + ans;
                count -= 1;
                brackets-=1;
            }
            ans = s[i] + ans;
            prev = rem;
            i--;
        }
        // cout << endl;
    while(brackets){
        ans= "("+ ans;
        brackets-=1;
    }
        cout <<"Case #"<<sample <<": "<< ans << endl;
        sample+=1;
    }
}