# Data_structure_learned_by_C
Study
<br>
![혼공C](https://book.naver.com/bookdb/book_detail.nhn?bid=15028694)<br>
<img src="https://github.com/ochestra365/StudyAspNet21/blob/main/BasicMVCModel2/MyPortpolioWeb/wwwroot/assets/img/faces/%ED%98%BC%EA%B3%B5C.jpg" width="100%" height="100%" ><br><br>
--------------

## 목차 <br>
1. c언어에 대한 개념적 접근<br>
2. 버퍼<br>
3. 메모리<br>
4. 접근<br>
5. 코드 파일 정리<br>
6. 깨알 용어 정리<br>
------------------
## 1. c언어에 대한 개념적 접근
<br>
C언어란 절차지향 프로그래밍 언어이다. 따라서 코딩의 순서대로 프로그램의 실행 순서를 제어할 수 있다.<br>
이러한 특성을 이용하여 다양한 알고리즘의 구현방법으로 사용된다.<br>
또한 메모리를 상당히 많이 다루는 데, 직접적인 컴퓨터 하드웨어를 제어하는 기능에 특화되어 있다고 볼 수 있다.<br>
기존의 객체지향프로그래밍이 현실 세계를 객체화하여 비즈니스 편의성을 구한다면, C언어는 비즈니스 로직 그 자체를 직접적으로 다룬다고 볼 수 있다.<br>
특히 구현을 잘 하기 위해서는 정수형, 문자형, 포인터 활용, 배열 활용, 포인터 배열 및 배열포인터 활용에 대한 입_출력 함수를 구현하는 것이 가장 기초라고 볼 수 있다.<

--------------
## 2. 버퍼
<br>
가장 중요한 개념이 버퍼이다.<br>
버퍼란 운영체제에서 자동으로 할당한 임시저장 메모리를 의미한다.<br>이 메모리에 사용자가 각 데이터를 할당하면 컴파일러를 통해 데이터 타입의 각 비트 단위를 코드로 enconding한다.<br>
또한 encoding한 각 비트 단위를 decoding하여 필요한 아스키 코드나 데이터 타입의 상수 주소값으로 포인터한다.<br>


## 3. 메모리
----------------
-----------
메모리라는 개념이 가장 중요하다. 변수나 포인터, 배열을 통해서 사용자가 필요한 데이터들을 메모리에 저장하고, 그것들을 Logic을 통해서 연산한 결과 값을 Return하는 것이 주 형식이다.<br>
프로그램에 필요로 하는 주된 메모리는 RAM이며, 필요한 경우 CPU와 가장 가깝고 연산이 빠른 레지스터 메모리도 사용한다. <br>이때, 필요한 변수에 예약어는 Reister이다.<br>
연산은 CPU의 ALU에서 각 변수의 값을 로드해서 스토어란 과정을 통해 Return 값으로 메모리에 돌려준다.<br>
메모리는 크게 Code Segment와 Data Segment로 양분된다. Code Segment에는 코드가 적재되고, Datasegment에는 Stack,Heap,정적 메모리가 할당된다.<br>
Stack은 휘발성이 강한 메모리 영역으로 지역변수같은 연산이 한번 종료되면 사라지는 파트들이 적재된다.<br>
다음으로 Heap은 동적할당을 위한 Data를 위해 사용자가 직접 메모리를 할당하여 사용하는 것이다.<br>마지막으로 정적 메모리는 OS가 자동으로 할당한 메모리를 의미하며 프로그램이 종료될 때까지 할당되어
<br>사용된다.

## 4. 접근
----------------
변수에 값을 할당한다. 그리고 변수가 저장된 상수 주소에 접근하여 간접적으로 값에 영향을 준다. 즉, 값을 저장하는 변수와 주소값을 다루는 포인터가 기초 공리가 되어 확장된 개념성을 가지는 것이<br>
C언어의 특징이다. 사실 이 2가지 개념으로 발견에 발견을 거듭하여 정형화 된 것이 C언이이기 때문에 이거 2개만 잘 알고 있어도 외울 것이 없다.<br> 당연하게 받아들이는 것이다.<br> 그저 생각의 흐름을
빨리 하기만 하면 이전 프로그래머가 생각한 것들을 다수 따라잡을 수 있다.
## 5. 코드 파일 정리
----------------
![Chapter1](https://github.com/ochestra365/StudyAspNet21/tree/main/BasicMVCModel2/MyPortpolioWeb/Models "Model")<br>
![Chapter2](https://github.com/ochestra365/StudyAspNet21/tree/main/BasicMVCModel2/MyPortpolioWeb/Views "View")<br>
![Chapter3](https://github.com/ochestra365/StudyAspNet21/tree/main/BasicMVCModel2/MyPortpolioWeb/Controllers "데이터 읽기 및 저장 생성")<br>
![Chapter4](https://github.com/ochestra365/StudyAspNet21/tree/main/BasicMVCModel2/MyPortpolioWeb/wwwroot "MainApp 구동")<br>

## 6. 깨알 용어 정리
----------------
