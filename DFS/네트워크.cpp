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
    graph = computers; // 2���� �迭�� ���������� �����Ѵ�. dfs �Լ��� ����ϱ� ����
    for (int i = 0; i < n; i++) {
        check.push_back(false); //false�� �ʱ�ȭ
    }
    for (int i = 0; i < n; i++) {
        if (!check[i]) { //�湮�� ���� ���ߴٸ� dfs ����
            dfs(i);
            answer++;
        }
    }
    return answer;
}