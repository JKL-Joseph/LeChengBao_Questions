#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class TreasureHuntSystem {
public:
	//回溯代码
	int MaxTreasureValue_1(vector<int> treasure) {

		function<int(int)> dfs = [&](int i) {
			if (i < 0)
				return 0;
			return max(dfs(i - 2) + treasure[i], dfs(i-1));
			};
		return dfs(treasure.size() - 1);
	}

	//回溯到记忆化搜索
	int MaxTreasureValue_2(vector<int> treasure) {
		int n = treasure.size();
		vector<int> memo(n, -1);
		function<int(int)> dfs = [&](int i) {
			if (i < 0)
				return 0;
			if (memo[i] != -1)
				return memo[i];
			return memo[i] = max(dfs(i - 2) + treasure[i], dfs(i - 1));
			};
		return dfs(treasure.size() - 1);
	}

	//从记忆化搜索到递推：
	//dfs(i) = max(dfs(i-1), dfs(i-2) + tr[i])
	//f[i+2] = max(f[i+1], f[i] + tr[i])
	int MaxTreasureValue_3(vector<int> treasure) {
		int n = treasure.size();
		vector<int> f(n + 2, 0);
		for (int i = 0; i < n; i++) {
			f[i + 2] = max(f[i + 1], f[i] + treasure[i]);
		}
		return f[n + 1];
	}
};

class TreasureHuntSystemTests {
public:
	TreasureHuntSystem treasureHunt;
	void RunTest() {
		test1();
	}

	void test1() {
		cout << "-------------test1:" << endl;
		vector<int> treasure = { 3, 1, 5, 2, 4 };
		int ans = treasureHunt.MaxTreasureValue_3(treasure);
		cout << ans;
	}
};

int main() {
	TreasureHuntSystemTests test;
	test.RunTest();
	return 0;
}