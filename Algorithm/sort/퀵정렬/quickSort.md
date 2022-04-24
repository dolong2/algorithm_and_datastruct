# 퀵 정렬

## 시간 복잡도
* 최악의 경우: O(n^2)
* 평균: O(n log n)

## 설명

퀵정렬은 임의의 pivot 값을 기준으로 pivot 의 좌측에는 pivot 보다 작은값을 두고 우측에는 pivot 보다 큰 값을 두고자 한다.

이 행위는 pivot을 기준으로 좌 우로 이분화 된 리스트를 재귀적으로 반복했을 때 결국 정렬이 완성 된다는 방법 론이다.

보다 쉽게 설명하면 pivot보다 큰 값을 pivot index 보다 왼쪽에서 찾고 ( 큰 값 이 나타날 때까지 i index를 증가시키도록 한다.)

pivot 보다 작은 값을 pivot index 보다 오른쪽에서 찾는다 ( 작은 값이 나타날 때까지 j index를 감소시키도록 한다. )

pivot을 기준으로 값 비교가 완료되었다면 index 결과 i , j를 비교 해본다.

i 값이 j 값 보다 작거나 같다면 분명 pivot 을 기준으로 교환을 해야할 값이 있다는 뜻이 된다.

교환한 뒤 i 인덱스는 증가 j 인덱스는 감소 연산을 수행한다.

i 인덱스가 j 인덱스보다 작거나 같다면 계속 반복해서 수행한다.

위 와 같은 과정은 pivot을 기준으로 왼쪽으로 정렬된 list 에서는 최초 Left 값이 감소된 j 보다 작다면 계속 재귀하면되고,

pivot을 기준으로 오른쪽으로 정렬된 list 에서는 최초 Right 값이 증가된 i 값보다 크다면 계속 재귀하면된다.

![Untitled](Sorting_quicksort_anim.gif)

출처([위키백과](https://ko.wikipedia.org/wiki/%ED%80%B5_%EC%A0%95%EB%A0%AC))

## [구현](quickSort.cpp)