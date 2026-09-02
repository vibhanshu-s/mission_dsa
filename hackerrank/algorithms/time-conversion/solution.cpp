#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    int n = s.size();
    string ans(s.begin(),s.end()-2);
    if(s[n-2]=='P' && s[0]=='1' && s[1]=='2')
        return ans;
    else if(s[n-2]=='A'&& s[0]!=1 && s[1]!='2')
        return ans;
    else if(s[n-2]=='A'){
        ans[1]='0';
        ans[0]='0';
        return ans;
   }
    else {
        string hr(s.begin(),s.begin()+2);
        int k = stoi(hr);
        k+=12;
        hr = to_string(k);
        ans[0]=hr[0];
        ans[1]=hr[1];
        return ans;
   }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
