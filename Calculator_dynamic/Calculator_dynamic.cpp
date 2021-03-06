#include <iostream>
#include <vector>
#include <utility>
#include <limits.h>
using namespace std;

void f(int &i, vector<pair<int, int>> &v) {
	int index = 0, tmp = 0;
	int a = (i % 3 == 0 ? v[i / 3].second : INT_MAX);
	int b = (i % 2 == 0 ? v[i / 2].second : INT_MAX);
	int c = v[i - 1].second;
	if (a < b) {
		tmp = a;
		index = i / 3;
	} else {
		tmp = b;
		index = i / 2;
	}
	if (tmp > c) {
		index = i - 1;
	}
	v[i] = make_pair(index, v[index].second + 1);
}

int main()
{
	int number;
	cin >> number;
	vector<pair<int, int>> v(number + 1); // first = prev, second = steps
	v[1] = make_pair(1, 0);
	for (int i = 1; i <= number; ++i) f(i, v);

	vector <int> answer(1, number);
	int i = number;
	while (i > 1) {
		answer.push_back(v[i].first);
		i = v[i].first;
	}
	cout << answer.size() - 1 << endl;
	for (int i = answer.size() - 1; i >= 0; --i) cout << answer[i] << ' ';
	return 0;
}

