#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class LeaderboardSystem 
{
//���������㷨
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
			std::cout << "���а�Ϊ��";
			return {};
		}

        if (m <= 0) {
            std::cout << "������Ч";
            return {};
        }
		if (m > scores.size()) {
			std::cout << "���������m�������а��������" << std::endl;
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
        std::cout << "-------------test1���������� ";
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
        std::cout << "-------------test2�����а������������m��";
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
        std::cout << "-------------test3�����а�Ϊ��";
        std::cout << std::endl;
        std::vector<int> emptyScores;
        int m = 3;

        std::vector<int> topScores = leaderboard.GetTopScores(emptyScores, m);

        
        std::cout << std::endl;
        if (topScores.empty()) {
            std::cout << "��������Ϊ�գ�" << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }

    void test4() {
        std::cout << "-------------test4��m = 0 ��";
        std::cout << std::endl;
        std::vector<int> scores = { 10, 20, 30 };
        int m = 0;

        std::vector<int> topScores = leaderboard.GetTopScores(scores, m);

        
        std::cout << std::endl;
        //if (topScores.empty()) {
        //    std::cout << "��������Ϊ��" << std::endl;
        //}
        std::cout << std::endl;
        std::cout << std::endl;
    }

    void test5() {
        std::cout << "-------------test5��mΪ����";
        std::cout << std::endl;
        std::vector<int> scores = { 10, 20, 30 };
        int m = -1;

        std::vector<int> topScores = leaderboard.GetTopScores(scores, m);

        
        std::cout << std::endl;
        //if (topScores.empty()) {
        //    std::cout << "��������Ϊ��" << std::endl;
        //}
    }
};

int main() {
    LeaderboardSystemTests tests;
    tests.RunTests();
    return 0;
}