#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;


int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<int> bfs;
    vector<bool> check;
    for (int i = 0; i < words.size(); i++) {
        bfs.push_back(0);
        check.push_back(false);
    }
    queue <pair<string, int>> queue;
    queue.push({ begin,-1 });

    while (!queue.empty()) {
        string s = queue.front().first;
        int idx = queue.front().second;
        queue.pop();
        int cnt = 0;
        if (s == target) return bfs[idx];
        if (cnt == 1) {
            return bfs[idx];
        }
        else {
            for (int i = 0; i < words.size(); i++) {
                int cnt = 0;
                for (int j = 0; j < words[i].size(); j++) {
                    if (s[j] != words[i][j]) {
                        cnt++;
                    }
                }
                if (cnt == 1 && !check[i]) {
                    check[i] = true;
                    queue.push({ words[i], i });
                    if (idx == -1) {
                        bfs[i] = 1;
                    }
                    else {
                        bfs[i] = bfs[idx] + 1;
                    }
                }
            }
        }
    }
    return 0;
}