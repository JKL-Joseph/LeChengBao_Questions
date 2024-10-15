#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class EnergyFieldSystem {
public:
	float MaxEnergyField(vector<int> heights) {
		float ans = 0;
		if (heights.size() < 2) {
			cout << "数据异常" << endl;
			return 0;
		}
		int i = 0; 
		int j = heights.size() - 1;
		while (i < j) {
			float tmp = (heights[i] + heights[j]) * (j - i) / 2.0;
			ans = max(tmp, ans);
			if (heights[i] < heights[j])
				i++;
			else
				j--;
		}
		return ans;
	}
};

class EnergyFieldSystemTests {
public:
	void RunTest() {
		test1();
		test2();
		test3();
	}
	EnergyFieldSystem EnergyField;

	void test1() {
		cout << "-----------test1:数组数量正常" << endl;
		vector<int> heights = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
		float res = EnergyField.MaxEnergyField(heights);
		cout << std::fixed << std::setprecision(1) << res;
		cout << endl;
		cout << endl;
	}

	void test3() {
		cout << "-----------test3:数组数量正常" << endl;
		vector<int> heights = { 1, 8, 6, 2};
		float res = EnergyField.MaxEnergyField(heights);
		cout << std::fixed << std::setprecision(1) << res;
		cout << endl;
		cout << endl;
	}

	void test2() {
		cout << "-----------test2:数组数量少于2" << endl;
			vector<int> heights = { 1 };
		float res = EnergyField.MaxEnergyField(heights);
		cout << std::fixed << std::setprecision(1) << res;
		cout << endl;
		cout << endl;
	}
};

int main() {
	EnergyFieldSystemTests tests;
	tests.RunTest();
	return 0;
}