#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class LeaderboardSystem 
{
//快速排序算法
public:
	int partition(vector<int>& score, int low, int high) {
		int pivot = score[high];
		int i = low - 1;

		for (int j = low; j < high; j++) {
			if (score[j] > pivot) {
				i++;
				std::swap(score[i], score[j]);
			}
		}

		std::swap(score[i + 1], score[high]);
		return i + 1;
	}

	void quickSort(vector<int>& score, int low, int high) {
		if (low < high)
		{
			int pi = partition(score, low, high);
			quickSort(score, low, pi - 1);
			quickSort(score, pi + 1, high);
		}
	}

	vector<int> GetTopScores(vector<int>& scores, int m) {
		if (scores.empty()) {
			std::cout << "排行榜为空";
			return {};
		}

        if (m <= 0) {
            std::cout << "请求无效";
            return {};
        }
		if (m > scores.size()) {
			std::cout << "请求的数量m大于排行榜玩家数量" << std::endl;
            m = scores.size();
		}
        quickSort(scores, 0, scores.size() - 1);
		return vector<int>(scores.begin(), scores.begin() + m);
	}
		
};


class LeaderboardSystemTests {
public:
    void RunTests() {
        test1();
        test2();
        test3();
        test4();
        test5();
    }

    LeaderboardSystem leaderboard;

    void test1() {
        std::cout << "-------------test1：正常排序： ";
        std::cout << std::endl;
        std::vector<int> scores = { 10, 20, 30, 40, 50 };
        int m = 3;

        std::vector<int> topScores = leaderboard.GetTopScores(scores, m);

        
        for (int score : topScores) {
            std::cout << score << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }

    void test2() {
        std::cout << "-------------test2：排行榜玩家数量少于m：";
        std::cout << std::endl;
        std::vector<int> scores = { 10, 20, 30 };
        int m = 5;

        std::vector<int> topScores = leaderboard.GetTopScores(scores, m);

        
        for (int score : topScores) {
            std::cout << score << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }

    void test3() {
        std::cout << "-------------test3：排行榜为空";
        std::cout << std::endl;
        std::vector<int> emptyScores;
        int m = 3;

        std::vector<int> topScores = leaderboard.GetTopScores(emptyScores, m);

        
        std::cout << std::endl;
        if (topScores.empty()) {
            std::cout << "返回数组为空：" << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }

    void test4() {
        std::cout << "-------------test4：m = 0 ：";
        std::cout << std::endl;
        std::vector<int> scores = { 10, 20, 30 };
        int m = 0;

        std::vector<int> topScores = leaderboard.GetTopScores(scores, m);

        
        std::cout << std::endl;
        //if (topScores.empty()) {
        //    std::cout << "返回数组为空" << std::endl;
        //}
        std::cout << std::endl;
        std::cout << std::endl;
    }

    void test5() {
        std::cout << "-------------test5：m为负数";
        std::cout << std::endl;
        std::vector<int> scores = { 10, 20, 30 };
        int m = -1;

        std::vector<int> topScores = leaderboard.GetTopScores(scores, m);

        
        std::cout << std::endl;
        //if (topScores.empty()) {
        //    std::cout << "返回数组为空" << std::endl;
        //}
    }
};

int main() {
    LeaderboardSystemTests tests;
    tests.RunTests();
    return 0;
}