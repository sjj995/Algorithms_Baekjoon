#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int a, b, n, m,ans;
bool visited[100001];
queue < pair <int, int>> q;


int bfs(int x) {
	q.push(make_pair(0, x));
	visited[x] = 1;

	while (!q.empty()) {
		int cnt = q.front().first;
		int loc = q.front().second;
		q.pop();

		if (loc == m) return cnt;

		if (loc >= 0 && loc + 1 < 100001 && !visited[loc + 1]) {
			visited[loc + 1] = 1;
			q.push(make_pair(cnt + 1, loc + 1));
		}

		if (loc >= 0 && loc - 1 > 0 && !visited[loc - 1]) {
			visited[loc - 1] = 1;
			q.push(make_pair(cnt + 1, loc - 1));
		}

		if (loc >= 0 && loc + a < 100001 && !visited[loc + a]) {
			visited[loc + a] = 1;
			q.push(make_pair(cnt + 1, loc + a));
		}

		if (loc >= 0 && loc - a > 0 && !visited[loc - a]) {
			visited[loc - a] = 1;
			q.push(make_pair(cnt + 1, loc - a));
		}

		if (loc >= 0 && loc + b < 100001 && !visited[loc + b]) {
			visited[loc + b] = 1;
			q.push(make_pair(cnt + 1, loc + b));
		}

		if (loc >= 0 && loc - b > 0 && !visited[loc - b]) {
			visited[loc - b] = 1;
			q.push(make_pair(cnt + 1, loc - b));
		}

		if (loc >= 0 && loc * a < 100001 && !visited[loc * a]) {
			visited[loc * a] = 1;
			q.push(make_pair(cnt + 1, loc * a));
		}

		if (loc >= 0 && loc * b < 100001 && !visited[loc * b]) {
			visited[loc * b] = 1;
			q.push(make_pair(cnt + 1, loc * b));
		}
	}
    return -1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b >> n >> m;

	ans = bfs(n);

	cout << ans;


}