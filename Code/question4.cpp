#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class TalentAssessmentSystem {
public:
	double FindMedianTalentIndex(vector<int> fireAbility, vector<int> iceAbility) {
		int i = 0, j = 0;
		vector<int> merge(fireAbility.size() + iceAbility.size());

		while (i < fireAbility.size() && j < iceAbility.size()) {
			if (fireAbility[i] < iceAbility[j]) {
				merge[i + j] = fireAbility[i];
				i++;
			}
			else {
				merge[i + j] = iceAbility[j];
				j++;
			}
		}
		while (i < fireAbility.size()) {
			merge[i+j] = fireAbility[i];
			i++;
		}

		while (j < iceAbility.size()) {
			merge[i + j] = iceAbility[j];
			j++;
		}

		int n = merge.size();
		if (n % 2 == 0) {
			return (merge[n / 2] + merge[n / 2 - 1]) / 2;
		}
		else
			return merge[n / 2];
	}
};

class TalentAssessmentSystemTests {
public:
	void RunTest() {
		test1();
	}

	TalentAssessmentSystem TalentAssess;
	void test1() {
		cout << "-----------test1:" << endl;
		vector<int> fireTal = { 1, 3, 7, 9, 11 };
		vector<int> iceTal = { 2, 4, 8, 10, 12, 14 };
		
		double res = TalentAssess.FindMedianTalentIndex(fireTal, iceTal);
		cout << res << endl;
	}
};

int main() {
	TalentAssessmentSystemTests test;
	test.RunTest();
	return 0;
}