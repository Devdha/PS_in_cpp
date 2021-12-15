# 배열

링크: https://blog.encrypted.gg/927?category=773649  
목차: STL vector, 기능과 구현, 연습 문제, 정의와 성질  
순서: 0x02  
스터디 날짜: 2021년 12월 16일  
정리일: 2021년 12월 15일  

# 목차

## 정의와 성질

### 배열

메모리 상에 원소를 연속하게 배치한 자료구조

### 배열의 성질

1. $O(1)$에 k번째 원소를 확인/변경 가능
    
    배열은 메모리 상에 원소를 연속하게 배치한 자료구조라, k번째 원소의 위치를 바로 계산 가능
    
2. 추가적으로 소모되는 메모리(=overhead)가 거의 없음
    
    배열은 다른 자료구조와 달리 추가적으로 소모되는 메모리가 거의 없음
    
3. Cache hit rate가 높음(왜?)
    
    메모리 상에 데이터들이 붙어있으니까(연속되니까) Cache hit rate가 높음
    
4. 메모리 상에 연속한 구간을 잡아야 해서 할당에 제약이 걸림

## 기능과 구현

### 기능

1. 임의의 위치에 있는 원소를 확인/변경 = $O(1)$
2. 원소를 끝에 추가 = $O(1)$
3. 마지막 원소를 제거 = $O(1)$
4. 임의의 위치에 원소를 추가, 임의의 위치의 원소를 제거 = $O(N)$

### 구현

4번 기능 외에는 어려운 점이 없으므로, 4번 기능만 구현해본다.

- 임의의 위치에 원소를 추가, 임의의 위치의 원소를 제거
    
    ```cpp
    #include <iostream>
    using namespace std;
    
    void insert(int idx, int num, int arr[], int& len){
    	for (int i = len; i >= idx; i--)
    		arr[i + 1] = arr[i];
    	// 추가할 공간부터 요소들을 한칸씩 뒤로 밀고
    	arr[idx] = num;
    	// 새로운 요소를 idx에 추가한다.
    	len++;
    }
    
    void erase(int idx, int arr[], int& len){
    	for (int i = idx; i < len; i++)
    		arr[i] = arr[i + 1];
    	// 제거할 공간부터 뒤의 요소들을 한칸씩 앞으로 당긴다.
    	len--;
    }
    ```
    

### 사용 팁

전체를 특정 값으로 초기화시킬 때 어떻게 하면 효율적으로 할 수 있을까?

1. memset
    
    제일 짧은 방법으로는 cstring 헤더에 있는 memset 함수를 사용하는 방식이다.
    
    하지만 memset 함수는 실수할 여지가 굉장히 많기 때문에, 비추천
    
2. `for` 문을 돌면서 값 하나하나를 다 바꾸는 방식
    
    코드가 투박하긴 하지만, 실수할 여지가 없기에 무난하고 좋다.
    
3. fill
    
    algorithm 헤더의 fill 함수를 이용한다.
    
    fill 함수는 실수할 여지도 없고 코드도 짧으니, 익숙해진다면 가장 추천하는 방식
    
    ```cpp
    // fill 함수 원형
    #include <algorithm>
    
    void fill(ForwardIterator first, ForwardIterator last, const T& val);
    // first: 채우고자 하는 자료구조의 시작위치 iterator
    // last: 채우고자 하는 자료구조의 끝 위치 iterator / last는 미포함
    // val: first부터 last전까지 채우고자 하는 값 / 어떤 객체나 자료형을 넘겨도 템플릿 T에 의해 가능하다.
    ```
    

예시)

```cpp
int a[21];
int b[21][21];

// 1. memset
memset(a, 0, sizeof a);
memset(b, 0, sizeof b);

// 2. for
for (int i = 0; i < 21; i++)
	a[i] = 0;
for (int i = 0; i < 21; i++)
	for(int j = 0; j < 21; j++)
		a[i][j] = 0;

// 3. fill
fill(a, a + 21, 0);
for (int i = 0; i < 21; i++)
	fill(b[i], b[i] + 21, 0);
```

## STL vector

### 개념

vector는 배열과 거의 통일한 기능을 수행하는 자료구조로, 배열과 마찬가지로 원소가 메모리에 연속하게 저장되기 때문에, $O(1)$에 인덱스를 가지고 각 원소로 접근할 수 있다.

배열과의 차이점은 vector은 크기를 자유자재로 늘이거나 줄일 수 있다.

(그래프의 인접 리스트를 저장하기 전까지 굳이 배열 대신 vector을 써야하는 상황은 없다.)

### 예시

- 벡터 사용 함수
    
    ```cpp
    int main(void) {
      vector<int> v1(3, 5); // {5,5,5};
      cout << v1.size() << '\n'; // 3
      v1.push_back(7); // {5,5,5,7};
    
      vector<int> v2(2); // {0,0};
      v2.insert(v2.begin()+1, 3); // {0,3,0};
    
      vector<int> v3 = {1,2,3,4}; // {1,2,3,4}
      v3.erase(v3.begin()+2); // {1,2,4};
    
      vector<int> v4; // {}
      v4 = v3; // {1,2,4}
      cout << v4[0] << v4[1] << v4[2] << '\n';
      v4.pop_back(); // {1,2}
      v4.clear(); // {}
    }
    vector.size() // 벡터의 사이즈를 반환
    vector.push_back() // 벡터의 마지막에 요소를 추가
    vector.insert() // 특정 인덱스에 요소를 추가
    vector.erase() // 특정 인덱스의 요소를 제거
    vector.pop_back() // 마지막 요소를 제거
    vector.clear() // 벡터를 비움
    ```
    
- range-based for loop
    
    ```cpp
    vector<int> v1 = {1, 2, 3, 4, 5, 6};
    
    for (int e : v1)
    	cout << e << ' ';
    // 위와 같이 사용하면, e에 v1 원소들이 하나씩 들어가는 for문이 된다.
    
    for (int &e : v1)
    	e = 1;
    // 참조자를 사용하면 값을 복사해오지 않고, 원본을 가져오기 때문에 수정될 수 있다.
    
    for (int i = 0; i < v1.size(); i++)
    	cout << v1[i] << ' ';
    // not bad - 인덱스 별로 순환하게 만들어도 상관없다.
    
    for (int i = 0; i <= v1.size() - 1; i++)
    	cout << v1[i] << ' ';
    // wrong - size가 0일 때, 언더플로우가 발생하여 문제가 생길 수 있기 때문에,
    // 이런한 코드는 쓰지 말자
    ```
    

## 연습문제

[BOJ](https://www.notion.so/7e0131db10b548a0a9342d8e8ce8a7e3)
