# 유클리드 알고리즘
- 두수의 최대공약수를 구하는 알고리즘
  - 두수 a,b와 나머지를 r이라고 하면 a와b의 최대공약수는 b와 r의 최대공약수와 같다
  - 즉 b를 r로 나눈 나머지 r2를 구하고 다시 r을 r2로 나눈 나머지를 구하는 과정을 반복하여 나머지가 0이 되었을 때 나누는 수가 a와 b의 최대공약수이다
    ## 코드     
    반복문을 사용해서 구하는 방법과 재귀 함수를 사용하는 방법이 있다 
    - [반복문을 이용한 구현](euclid_Algorithm(반복).cpp)

    - [재귀 함수를 이용한 구현](euclid_Algorithm(재귀).cpp)