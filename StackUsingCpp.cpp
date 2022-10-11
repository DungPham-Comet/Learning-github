#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
int main(){
    string s[100];
    stack<char> st;
    cout<<" Nhap s: ";
    cin>>s;
    int i,j;
    j=0;
    string s1[100];
    for (i=0;i<s.length();i++){
        if (s[i] >= '0' && s[i] <= '9'){
            s1[j] = s[i];
            j++;
        }
        else if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*'||s[i]=='/'){
            if (s[i] == '+' || s[i] == '-'){
                if (st.top()=='+' || st.top()=='-' || st.top()=='*' || st.top()=='/'){
                    s1[j] == st.top();
                    j++;
                    st.pop();
                    st.push(s[i]);
                }
                else
                    st.push(s[i]);
            }
            else if (s[i] == '*' || s[i] == '/'){
                    if (st.top()=='*' || st.top()=='/'){
                        s1[j] == st.top();
                        j++;
                        st.pop();
                        st.push(s[i]);
                    }
                    else 
                        st.push(s[i]);
            }
        }
        else if (s[i] == ')'){
            while (st.top() != '('){
                s1[j] = st.top();
                j++;
                st.pop();
            }
            st.pop();
        }
    }
    while (!st.empty()){
        s1[j] = st.top();
        j++;
        st.pop();
    }
    cout<<s1[0];
    return 0;
}