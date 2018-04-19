#include <bits/stdc++.h>
using namespace std;

const int maxN = 500500;

int tot=0; // Word Count
unordered_map<string, int> mp;
unordered_map<int, string> word; 

bool ca[maxN]; // Has comma after
bool mark[maxN]; // Already use i to update CA before
vector<int> sen[maxN]; int scnt=0; // Sentence Count

vector<int> pword[maxN], nword[maxN];

int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    
    string buf; int lst = 0;
    while (cin >> buf) 
    {
        char last = buf[buf.size()-1];
        if (last == ',' || last == '.') {
            buf.pop_back(); 
        }
        if (!mp[buf]) mp[buf] = ++tot;
        int cur = mp[buf];
        word[cur] = buf;    
        
        sen[scnt].push_back(cur);
        if (lst) {
            nword[lst].push_back(cur);
            pword[cur].push_back(lst);
        }
        
        if (last == ',') {
            ca[cur] = true;
        }
        lst = cur;
        if (last == '.') {
            scnt++; lst = 0;
        }
    }
    
    queue<int> que;
    for (int i=1; i<=tot; ++i) {
        if (ca[i]) que.push(i);
    }
    while (que.size()) {
        int cur = que.front(); que.pop();
        for (unsigned j=0; j<nword[cur].size(); ++j) {
            int now = nword[cur][j];
            if (!mark[now]) {
                mark[now] = true;
                for (unsigned k=0; k<pword[now].size(); ++k) {
                    if (!ca[pword[now][k]]) {
                        ca[pword[now][k]]=true; que.push(pword[now][k]);
                    } 
                }
            }
        }
    }
    
    for (int i=0; i<scnt; ++i) {
        for (unsigned j=0; j<sen[i].size(); ++j) {
            cout << word[sen[i][j]];
            if (j+1==sen[i].size()) {
                cout << '.'; break;
            } 
            cout << (ca[sen[i][j]] ? ", " : " ");
        }
        if (i+1!=scnt) cout << ' ';
    }
} 