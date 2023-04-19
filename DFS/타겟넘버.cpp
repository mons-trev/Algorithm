#include <string>
#include <vector>

using namespace std;

vector<int> list;
int answer = 0;
void dfs(int idx, int value, int target) {
    if (idx == list.size()) {
        if (value == target) {
            answer++;
            return;
        }
        else {
            return;
        }
    }
    dfs(idx + 1, value + list[idx], target);
    dfs(idx + 1, value - list[idx], target);
    return;
}
int solution(vector<int> numbers, int target) {

    list = numbers;

    dfs(1, list[0], target);
    dfs(1, -list[0], target);
    return answer;
}