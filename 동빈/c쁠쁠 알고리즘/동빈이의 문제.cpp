//���Ϳ� ���� �̿��ؼ� Ǯ �� �ִ�. Pair�ȿ� pair������ �־ Ǯ�� �ִ�.
#include <iostrinm>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<string, pair<int, int>>a,// �Լ��� ���� �Ұ��� �־��ش�.
	pair<string, pair<int, int>>b) {
	if (a.second.first == b.second.first) {// �ι��� �ʵ忡 ���� ù���� �� ������ ������
		return a.second.second > b.second.second;//�� ��л��� �켱����
	}
	else {
		return a.second.first > b.second.first;
	}
}
int main(void) {
	vector<pair<string, pair<int, int>>> v;// ��� �ȿ� �� �� �ִ�.
	v.push_back(par<string, pair<int, int>>("������", pair<int, int>(90, 19961222)));
	v.push_back(par<string, pair<int, int>>("������", pair<int, int>(97, 19931518)));
	v.push_back(par<string, pair<int, int>>("���ѿ�", pair<int, int>(95, 19961222)));
	v.push_back(par<string, pair<int, int>>("�̻��", pair<int, int>(90, 19940425)));
	v.push_back(par<string, pair<int, int>>("������", pair<int, int>(88, 19990202)));
	sort(v.begin(), v.end(),compare);//�Ѱ��� ���� ������ �˷���� �Ѵ�.
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << '';
	}
	return 0;
}
// ����� 3���̻� ��� ������ �ö󰡸� Ŭ������ �����ؼ� ���� ���� ������ ���α׷����� �� �� �ִ�.