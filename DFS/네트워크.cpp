#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> graph;
vector<bool> check;

void dfs(int node) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[node][i] == 1 && !check[i]) {
            check[i] = true;
            dfs(i);
        }
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    graph = computers; // 2차원 배열을 전역변수에 복사한다. dfs 함수를 사용하기 위해
    for (int i = 0; i < n; i++) {
        check.push_back(false); //false로 초기화
    }
    for (int i = 0; i < n; i++) {
        if (!check[i]) { //방문을 아직 안했다면 dfs 시작
            dfs(i);
            answer++;
        }
    }
    return answer;
}