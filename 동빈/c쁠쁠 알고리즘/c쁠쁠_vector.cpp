#include <iostream>//cpp헤더
#include <vector>//벡터 헤더 단순한 배열을 사용할 것인가? 아니면 벡터를 사용할 것이냐 상황에 따라 다르다.(연결리스트는 벡터다.)
#include <algorithm>//

using namespace std;//c++문법

int main(void) {//pair는 만든 이후 어떤 배열값이 연결적으로 만들어 지고 있는 것이다.
	vector<int, string> v;//벡터를 사용할떄는 걍 대가리 값에 정수를 넣는 것이 가장 편함
	v.push_back(pair<int, string>(90, "박한울"));//pair는 한쌍의 데이터를 배열로써 사용하는 것이다. 걍 지금은 데이터만 때려박는 것이다.
	v.push_back(pair<int, string>(85, "이태일"));
	v.push_back(pair<int, string>(82, "나동빈"));
	v.push_back(pair<int, string>(98, "강종구"));
	v.push_back(pair<int, string>(79, "이상욱"));

	sort(v.begin(), v.end());//성적순으로 정렬이 된다. 벡터의 첫번쨰 값부터 마지막 값까지 정렬이 되게 한다.-->학생들의 이름이 나온다.
	for (int i = 0; i < v.size(); i++) {//벡터의 크기를 가져온다.-->벡터의 크기는 5이다.0~4까지 반복을 한다.
		cout << v[i].second << '';//세컨드로 뽑아온다. 필드의 두 번쨰 값을 가져온다.-->이 경우는 이름이 되겠지
	}
	return 0;
}

//push_back-->리스트의 마지막에 삽입을 하겠다.
//short coding이다. 알고리즘의 효율성이 좋다면 알고리즘 대회에서는 소스코드가 짧은 것이 좋다.