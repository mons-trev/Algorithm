#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector <bool> check;
vector<string> answer;
int n;

bool cmp(vector<string> a, vector <string> b) {
    return a < b;
}

bool dfs(vector<vector<string>> tickets, vector<string> a, int count) {
    if (count == n - 1) {
        int j = -1;
        for (int i = 0; i < check.size(); i++) {
            if (!check[i]) {
                j = i;
                break;
            }
        }
        if (a[1] == tickets[j][0]) {
            answer.push_back(tickets[j][1]);
            return true;
        }
        else return false;
    }
    for (int i = 0; i < tickets.size(); i++) {
        if (a[1] == tickets[i][0] && !check[i]) {
            check[i] = true;
            if (dfs(tickets, tickets[i], count + 1)) {

                answer.insert(answer.begin(), tickets[i][1]);
                return true;
            }
            else {
                check[i] = false;
            }
        }

    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    n = tickets.size();
    sort(tickets.begin(), tickets.end(), cmp); // 방법이 두가지 있을 때를 방지하여 알파벳순으로 정렬을 먼저한다.
    for (auto it : tickets) {
        check.push_back(false); // false로 초기화
    }
    cout << "\n";
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == "ICN") {
            check[i] = true;
            if (dfs(tickets, tickets[i], 1)) {
                answer.insert(answer.begin(), tickets[i][1]);
                answer.insert(answer.begin(), tickets[i][0]);
                return answer;
            }
        }
        answer.clear();
        for (int j = 0; j < tickets.size(); j++) {
            check[j] = false;
        }

    }
}