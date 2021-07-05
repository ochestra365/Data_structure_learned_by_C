//벡터와 페어만을 이용해서 풀 수 있다. Pair안에 pair가지고 있어서 풀수 있다.
#include <iostrinm>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<string, pair<int, int>>a,// 함수에 대한 불값을 넣어준다.
	pair<string, pair<int, int>>b) {
	if (a.second.first == b.second.first) {// 두번쨰 필드에 속한 첫번쨰 값 성적이 같으면
		return a.second.second > b.second.second;//더 어린학생이 우선순위
	}
	else {
		return a.second.first > b.second.first;
	}
}
int main(void) {
	vector<pair<string, pair<int, int>>> v;// 페어 안에 페어가 들어가 있다.
	v.push_back(par<string, pair<int, int>>("나동빈", pair<int, int>(90, 19961222)));
	v.push_back(par<string, pair<int, int>>("이태일", pair<int, int>(97, 19931518)));
	v.push_back(par<string, pair<int, int>>("박한울", pair<int, int>(95, 19961222)));
	v.push_back(par<string, pair<int, int>>("이상욱", pair<int, int>(90, 19940425)));
	v.push_back(par<string, pair<int, int>>("강종구", pair<int, int>(88, 19990202)));
	sort(v.begin(), v.end(),compare);//한개의 정렬 기준을 알려줘야 한다.
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << '';
	}
	return 0;
}
// 경험상 3개이상 페어 기준이 올라가면 클래스를 정의해서 쓰는 것이 빠르게 프로그래밍을 할 수 있다.