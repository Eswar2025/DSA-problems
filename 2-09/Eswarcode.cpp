#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'palindromeIndex' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int palindromeIndex(string s) {
    int k,m=0;
    string w;
    int n= s.size();
   if(n%2==0){
        k=n/2;
    }
    else{
        k=(n-1)/2;
    }
    for(int i=0;i<k;i++){
        if(s[i]==s[n-i-1]){
            m++;
        }
    }
    if(m==k){
        return -1;
    }
    else{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j<i){
                    w[j]=s[j];
                }
                else if(j>i){
                    w[j-1]=s[j]; 
                }
            }
           int h,g=0;
           int l=w.size();
            if(l%2==0){
              h=l/2;
             }
             else{
              h=(l-1)/2;
             }
            for(int a=0;a<h;a++){
                if(w[a]==w[l-a-1]){
                    g++;
                }
            }
            if(g==h){
                return i;
                break;
            }
        } 
    }
   return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
