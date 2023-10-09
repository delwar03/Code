#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s, postFix = ""; cin>>s;
    s = s + ')';
    stack<char> st;
    st.push('(');
    for(auto ch : s) {
        if(ch == '(') st.push(ch);
        else if(ch >= 'a' && ch <= 'z') postFix += ch;
        else if(ch == ')') {
            while(!st.empty()) {
                if(st.top() == '(') {
                    st.pop();
                    break;
                }
                else {postFix += st.top(); st.pop();}
            }
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            if(ch == '+' || ch == '-') {
                while(!st.empty()) {
                    if(st.top() == '*' || st.top() == '/' || st.top() == '^') {
                        postFix += st.top();
                        st.pop();
                    }
                    else break;
                }
                st.push(ch);
            } else if(ch == '*' || ch == '/') {
                while(!st.empty()) {
                    if(st.top() == '^') {postFix += st.top(); st.pop();}
                    else break;
                }
                st.push(ch);
            } else if(ch == '^') st.push(ch);
        }
    }
    cout<<postFix<<endl;
}

/* 
    i/p: ((a+(b/c))*(d^a)-(c-b)^(x-y))
    o/p:  abc/+da^*cb-xy-^-
*/