#include <iostream>
using namespace std;
int N, score[5], num[5][5], maxnum, maxi, check;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int first, second, third;
		cin >> first >> second >> third;
		score[1] += first;
		num[1][first]++;
		score[2] += second;
		num[2][second]++;
		score[3] += third;
		num[3][third]++;
	}
	for (int i = 1; i <= 3; i++) {
		if (maxnum < score[i]) {
			maxnum = score[i];
			maxi = i;
			check = 0;
		}
		else if (maxnum == score[i]) {
			if (num[maxi][3] < num[i][3]) {
				maxi = i;
				check = 0;
			}
			else if (num[maxi][3] == num[i][3]) {
				if (num[maxi][2] < num[i][2]) {
					maxi = i;
					check = 0;
				}
				else if (num[maxi][2] == num[i][2]) {
					if (num[maxi][1] < num[i][1]) {
						maxi = i;
						check = 0;
					}
					else if (num[maxi][1] == num[i][1])
						check = 1;
				}
			}
		}
	}
	if (check)
		cout << "0 " << maxnum;
	else
		cout << maxi << " " << maxnum;
	return 0;
}
