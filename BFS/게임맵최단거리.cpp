#include<vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    queue <pair<int, int>> queue;
    queue.push({ 0,0 }); //로봇의 시작 위치

    vector<vector<bool>> check;
    vector<vector<int>> dis;
    for (int i = 0; i < maps.size(); i++) {
        vector <bool> v;
        vector <int> g;
        for (int j = 0; j < maps[0].size(); j++) {
            v.push_back(false);
            g.push_back(0);
        }
        check.push_back(v);
        dis.push_back(g);
    }
    dis[0][0] = 1;
    check[0][0] = true;
    int n = maps.size() - 1;
    int m = maps[0].size() - 1;

    while (!queue.empty()) {
        int i = queue.front().first; //행
        int j = queue.front().second; //열

        if (i == n && j == m) {
            return dis[n][m];
        }
        if (i + 1 <= n && !check[i + 1][j] && maps[i + 1][j] == 1) {
            queue.push({ i + 1,j });
            dis[i + 1][j] = dis[i][j] + 1;
            check[i + 1][j] = true;
        }
        if (j + 1 <= m && !check[i][j + 1] && maps[i][j + 1] == 1) {
            queue.push({ i,j + 1 });
            dis[i][j + 1] = dis[i][j] + 1;
            check[i][j + 1] = true;
        }
        if (i - 1 >= 0 && !check[i - 1][j] && maps[i - 1][j] == 1) {
            queue.push({ i - 1,j });
            dis[i - 1][j] = dis[i][j] + 1;
            check[i - 1][j] = true;
        }
        if (j - 1 >= 0 && !check[i][j - 1] && maps[i][j - 1] == 1) {
            queue.push({ i,j - 1 });
            dis[i][j - 1] = dis[i][j] + 1;
            check[i][j - 1] = true;
        }
        queue.pop();
    }
    return -1;
}