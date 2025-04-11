# Pointer

> 변수의 메모리 공간 주소를 가리키는 변수

> 변수의 메모리 주소를 저장하는 변수

- 일반적인 변수들과 달리, Pointer는 어떤 값이 저장된 메모리 위치(주소)를 가리키며, 이를 통해 간접적으로 data Read / Write
  <br/>

- 간접 참조 연산자(=**포인트 연산자**, **역참조**) `*` 이용
  <br/>

## 주소(Address)

> 메모리 주소는 컴퓨터 메모리의 물리 위치를 파악하며, data가 저장되는 위치를 가리킴

<div style="text-align: center;">

![위키피디아](https://upload.wikimedia.org/wikipedia/commons/thumb/3/32/Virtual_address_space_and_physical_address_space_relationship.svg/1280px-Virtual_address_space_and_physical_address_space_relationship.svg.png)
<br/>
이미지 출처: 위키피디아
</div>

- 변수가 할당된 메모리 공간의 시작 주소
  <br/>

- 변수가 선언되면 그 변수타입 크기만큼 메모리 할당
  <br/>

- 주소 연산자 `&` 으로 출력시 시작 주소가 나옴
  <br/>

<div style="text-align: center;">

| 구분      | Address                            | Pointer                                                |
| --------- | ---------------------------------- | ------------------------------------------------------ |
| 정의      | 메모리 내 특정 위치를 나타내는 값  | 주소를 저장하는 변수                                   |
| 역할      | 데이터의 위치를 나타냄             | 데이터에 간접적으로 접근할 수 있도록 주소를 가리킴     |
| 형태      | 16진수 값으로 표현되는 경우가 많음 | 특정 주소를 가리키며 해당 위치의 값을 읽거나 수정 가능 |
| 사용 예시 | `&a`로 주소를 확인 가능            | `int *p = &a;`를 통해 주소 저장 후 간접 접근           |

</div>

## in Code

1. 선언과 초기화

   ```c
   int a = 10;
   int *p = &a;
   // p는 a가 저장된 메모리 주소를 가리키게 됌
   ```

   <br/>

2. 사용

   ```c
   int *p = &a;        // a의 주소를 저장하는 포인터 p 선언
   printf("%p\n", &a); // 변수 a의 메모리 주소
   printf("%d\n", *p); // 포인터 p가 가리키는 위치의 값 10

   // ...

   printf("%p\n", (void *)p); // 변수 a의 메모리 주소
   ```

   <br/>

3. 정리

   - `p` -> 포인터 변수 자체의 값, 즉 메모리 주소
   - `*p` -> 포인터가 가리키는 메모리 주소에 저장된 값
     <br/>

4. 전체 코드
   ```c
   int main(void)
   {
       int a = 10;
       int *p = &a;        // a의 주소를 저장하는 포인터 p 선언
       printf("%p\n", &a); // 변수 a의 메모리 주소
       printf("%d\n", *p); // 포인터 p가 가리키는 위치의 값 10
       return 0;
   }
   ```
   <br/>

## Pointer 대입의 차이

> `*p` 에 `&` 을 대입할 떄, `*` 포인터를 대입할 때 아무것도 쓰지 않고 대입할때 어떤차이가 있을 려나

```
포인터 = &변수     -> 가리킨다
*포인터 = 값        -> 값 넣는다
포인터1 = 포인터2  -> 따라간다
*포인터1 = *포인터2 -> 값 복붙
```

1. 포인터 변수 = '&'

   ```c
   int *q = &n2;
   ```

   포인터 변수가 **주소 값** 을 기억함
   <br/>

2. 포인터 변수 = 값

   ```c
   *p = 20;                   // 포인터 p가 가리키는 주소에 20 저장
   printf("%d\n", a); // 20 출력
   ```

   실제 메모리 값 변경
   <br/>

3. 포인터 1 = 포인터 2

   ```c
   p = q;
   printf("*p : %d , *q : %d\n", *p, *q);
   printf("n1 : %d, n2 : %d\n", n1, n2);
   printf("p : %p, q : %p\n", (void *)p, (void *)q); // 주소는 같음
   ```

   ```
   *p : 20 , *q : 20
   n1 : 10, n2 : 20
   p : 0061FF0C, q : 0061FF0C
   ```

   포인터 값은 변경되나 원본은 변경 X
   <br/>

4. *포인터 1 = *포인터 2

   ```c
   *p = *q;
   printf("*p : %d , *q : %d\n", *p, *q);
   printf("n1 : %d, n2 : %d\n", n1, n2);
   printf("p : %p, q : %p\n", (void *)p, (void *)q); // 주소는 다름
   ```

   ```
   *p : 20 , *q : 20
   n1 : 10, n2 : 20
   p : 0061FF10, q : 0061FF0C
   ```

   `p` 가 가리키는 곳에 `q` 가 가리키는 값 복사

   주소는 다름


## 참고

- [위키피디아-주소공간](https://ko.wikipedia.org/wiki/%EC%A3%BC%EC%86%8C_%EA%B3%B5%EA%B0%84)

- [세종대학교 학술정보원 연구학습지원서비스-C언어 기초 가이드 STEP 2: 포인터](https://sejong-kr.libguides.com/c.php?g=942235&p=6822366)

- [블로그-쭌의 개발기록(C언어 문법 - 포인터(Pointer))](https://velog.io/@dev_tmb/C%EC%96%B8%EC%96%B4-%EB%AC%B8%EB%B2%95-%ED%8F%AC%EC%9D%B8%ED%84%B0Pointer)

- [블로그-seoltang(C언어 | 포인터(Pointer))](https://velog.io/@seoltang/c-pointer)

- [코딩도장-포인터](https://dojang.io/mod/page/view.php?id=1733)

- [TCP shcool- 포인터의 개념](https://tcpschool.com/c/c_pointer_intro)

- [혼공-c언어 포인터를 사용하는 이유](https://hongong.hanbit.co.kr/c%EC%96%B8%EC%96%B4-%ED%8F%AC%EC%9D%B8%ED%84%B0%EB%A5%BC-%EC%82%AC%EC%9A%A9%ED%95%98%EB%8A%94-%EC%9D%B4%EC%9C%A0/)

- [블로그 참조-엔츄핀([C언어] 포인터 (단일, 다중포인터, 주소값, 참조와 역참조, 포인터배열))](https://enchupin.tistory.com/63)

- [블로그 참조 - Agile 방식의 삶([C언어] 포인터를 사용하는 진짜 쉬운 이유)](https://masterpiece-programming.tistory.com/144)
