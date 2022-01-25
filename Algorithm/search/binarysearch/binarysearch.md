# 이진서치
**정렬된 배열에서** 아주 빠르게 찾을 수 있는 알고리즘

(오름차순일때)배열의 중간에 있는 값과 찾을 값을 비교해서 찾는 값이 더 큰지 작은지 비교 후 범위를 줄임 다시 그 범위의 절반을 찾아서 비교 계속 반복해서 찾는 값을 찾을때까지 반복

O(logN)의 시간 복잡도를 가짐

데이터가 많고 원하는 데이터가 배열의 끝 부분에 저장되어 있는 경우 제일 효율적으로 찾을 수 있다

## 그림

![https://blog.kakaocdn.net/dn/bpv9gL/btqEChu74lV/Fuil3yXTuDmv2us2tPOoT1/img.gif](https://blog.kakaocdn.net/dn/bpv9gL/btqEChu74lV/Fuil3yXTuDmv2us2tPOoT1/img.gif)

### [ 구현 ](binarysearch.c++) 