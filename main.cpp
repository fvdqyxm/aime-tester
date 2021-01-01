#include <bits/stdc++.h>
int year;
char type;
using namespace std;
void case_two();
void case_one();
int main () {
    cout << "enter year: ";
    cin >> year;
    if(year < 2000) {
        case_one();
    }
    else case_two();
}
void case_two() {
    cout << "enter I or II: ";
    cin >> type;
    cout << "enter number: ";
    int number;
    cin >> number;
    cout << "reading from: " << to_string(year) + type + "_answers.txt" << endl;
    /* return; */
    ifstream read(to_string(year) + type + "_answers.txt");
    vector<string> answers;
    string k;
    while (read >> k) answers.push_back(k);
    /* for(auto i : answers) { */
        /* cout << i << "\n"; */
    /* } */
    /* return; */
    --number;
    for(int i = 0; i < 5; i++) {
        cout << "your answer: ";
        string guess;
        cin >> guess;
        if(answers[number] == guess) {
            cout << "correct!\n";
            cout << "anymore? (y/n): ";
            char c;
            cin >> c;
            if(c == 'y') main();
            else exit(0);
        }
        else cout << "wrong, try again\n";
    }
    cout << "Do you want the answer: (y/n): ";
    char c;
    cin >> c;
    if(c == 'y') {
        cout << answers[number] << '\n';
    }
    cout << "anymore? (y/n): ";
    cin >> c;
    if(c == 'y') main(); 
    else exit(0);

}
void case_one() {
    cout << "enter problem #: ";
    int number;
    cin >> number;
    vector<string> answers;
    ifstream read(to_string(year) + "_answers.txt");
    /* string N = year + "answers.txt"; */
    /* cout << "N: " << N << endl; */
    /* return; */
    string k;
    while (read >> k) answers.push_back(k);
    --number;
    /* for(int i = 0; i < answers.size(); i++) { */
        /* cout << i + 1 << " " << answers[i] << "\n"; */
    /* } */
    /* cout << endl << "\n"; */
    /* return; */
    for(int i = 0; i < 5; i++) {
        cout << "your answer: ";
        string guess;
        cin >> guess;
        if(answers[number] == guess) {
            cout << "correct!\n";
            cout << "anymore? (y/n): ";
            char c;
            cin >> c;
            if(c == 'y') main();
            else exit(0);
        }
        else cout << "wrong, try again\n";
    }
    cout << "Do you want the answer: (y/n): ";
    char c;
    cin >> c;
    if(c == 'y') {
        cout << answers[number] << '\n';
    }
    cout << "anymore? (y/n): ";
    cin >> c;
    if(c == 'y') main(); 
    else exit(0);
}
