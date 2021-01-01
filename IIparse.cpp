#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    /* std::ios_base::sync_with_stdio(false);cin.tie(nullptr); */
    string year;
    cin >> year;
    ifstream get(year + "_II.txt");
    string res = "";
    getline(get, res);
    string looking = "( " + year + " AIME II Problems )";
    auto loc = res.find(looking);
    cout << "searching for " << looking << "\n";
    cout << "searching over: " << res << endl;
    if(loc == string::npos) {
        cout << "ENDED HERE\n";
        return 0;
    }
    vector<int> answers;
    loc += looking.size() - 1;
    /* cout << "index: " << loc << "\n"; */
    /* cout << "res.size(): " << res.size() << endl; */
    /* cout << "1464: " << res[1465]<< "\n"; */
    for(int j = loc; j < int(res.size()); j++) {
        if(isdigit(res[j])) {
            int cur = 0;
            int k = j;
            for(k = j; true; k++) {
                if(!isdigit(res[k])) break;
                cur = (cur * 10 + res[k]-'0');
            }
            if(cur == stoi(year)) {
                cout << "ENDING HERE 2\n";
                break;
                /* return 0;; */
            }
            answers.push_back(cur);
            j = k;
        }
    }
    ofstream OUT(year + "II_answers.txt");
    cout << "answer: \n";
    for(auto i : answers) {
        OUT << i << "\n";
    }
}





