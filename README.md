# Data_structure_learned_by_C
Study
<br>
![혼공C](https://book.naver.com/bookdb/book_detail.nhn?bid=15028694)<br>
<img src="https://github.com/ochestra365/StudyAspNet21/blob/main/BasicMVCModel2/MyPortpolioWeb/wwwroot/assets/img/faces/%ED%98%BC%EA%B3%B5C.jpg" width="100%" height="100%" ><br><br>
--------------



-----------------
너무 길다. 간결하게 표현하자
주석은 최대한 핵심만
알고리즘의 이해 절차 일반화
~~~
1. 구하고자 하는 것이 무엇인가
2. 조건이 무엇인가
3. 코드로 정리할 수 있는가
4. 그림으로 이해할 수 있는가

구조정리
~~~

## 목차 <br>
1. 알고리즘에 대한 접근(초기화, 반환)--> 가장 중요한 개념이다.-->일반식을 찾아야 한다.
~~~
짧고 간결한 것이 좋은 코드고 좋은 생각이다.
어차피 다 기억하지도 못하는 거 핵심만 기억해라.
주석 달지말라 코드만 보고 이해해라 주석을 단다면 핵심만 
엄청 고민하고 다른 사람의 코드를 보는 게 훨씬 도움이 된다.
하나의 알고리즘은 하나의 단위다.(연결 자료구조는 하나의 리스트)
~~~
##공부법
------------------
1. 백준 답지 받아적기
2. 책 코드 받아적기
3. 훈련생들 코드 받아적기
4. 코드 해독하기
5.  필요한 스킬 체화하기
6. 군더더기들을 덜어내고 정제하면 된다.
7. 동적할당을 배열대신 즐겨 쓰는 버릇 하고, 다른 사람의 코드 작성 노하우를 내걸로 만들면 된다.(논리적이든, 물리적이든 1차원 순차 혹은 연결자료구조면 배열 개념 버리고 그냥 동적할당써라)
8. 그리고 동적할당 식별자를 for문으로 각 요소 출력하면 배열 처럼 쓸수있다. 
9. ex int *num=(int*)malloc(sizeof(int)); for문 num[j]
10. 이건 수학이다. 수학이 수를 이용하여 어떤 현상의 규칙성 혹은 논리적 배합이나 결과값을 도출하듯이, 알고리즘도 메모리와 버퍼, 그리고 언어를 통해서 논리적 배합이나 결과값을 도출하기 때문이다.

##선택문, 반복문
-----------------
1. if 경우의 수를 제어할 때 사용한다.
2. while for i++이나  cnt++기억하기 sum+=1->초기화 해서 누계 값구하기
3. NULL  다음 정보의 존재가 버퍼상에서 확인할 수 없으면 반복문 탈출
4. 메모리에 정보가 있는 지 없는 지 확인할 수 없기 때문에 선택 분기를 못내림
5. 정보가 없다 라는 것은 정보가 없는 상태를 확인할 수 있기 때문에  NULL 값이 아님.
