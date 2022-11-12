#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int N, dx[8] = { 1,1,1,0,0,-1,-1,-1 }, dy[8] = { -1,0,1,-1,1,-1,0,1 };
string king, stone;
pair<int, int> k, s;
char shift[5];

int main() {
	cin >> king >> stone >> N;
	int kx, ky, sx, sy;
	ky = king[0] - 'A', kx = king[1] - '1';
	k.first = kx, k.second = ky;
	sy = stone[0] - 'A', sx = stone[1] - '1';
	s.first = sx, s.second = sy;
	while (N--) {
		int n = 0;
		cin >> shift;
		if (!strcmp(shift, "R"))
			n = 4;
		else if (!strcmp(shift, "L"))
			n = 3;
		else if (!strcmp(shift, "B"))
			n = 6;
		else if (!strcmp(shift, "T"))
			n = 1;
		else if (!strcmp(shift, "RT"))
			n = 2;
		else if (!strcmp(shift, "RB"))
			n = 7;
		else if (!strcmp(shift, "LB"))
			n = 5;
		kx = k.first + dx[n], ky = k.second + dy[n];
		sx = s.first + dx[n], sy = s.second + dy[n];
		if (kx < 0 || kx > 7 || ky < 0 || ky > 7)
			continue;
		if (kx == s.first && ky == s.second) {
			if (sx < 0 || sx > 7 || sy < 0 || sy > 7)
				continue;
			k.first = kx;
			k.second = ky;
			s.first = sx;
			s.second = sy;
		}
		else {
			k.first = kx;
			k.second = ky;
		}
	}
	char c;
	c = k.second + 'A';
	cout << c;
	c = k.first + '1';
	cout << c << "\n";
	c = s.second + 'A';
	cout << c;
	c = s.first + '1';
	cout << c;
	return 0;
}