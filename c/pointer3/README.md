# Double Pointer

> 포인터 변수를 가리키는 또 다른 포인터 변수

```c
int **pp = &p;
```

> 이중 간접참조를 통해서 다른 포인터 변수가 가르키는 변수에 접근

- `**p` : 포인터를 가르키는 포인터

- `&p` : 변수 `p` 의 주소


`pp` (이중 포인터)는 **`p`가 어디에 있는지 알려주는 화살표 / 메모**

## 포인터를 가르키는 포인터

1. 변수 선언
   
   ```c
   // 코드 선언
   int a = 508;
   int *p = &a;
   int **pp = &p;
   ```

   ```
   # 메모리
   +-----------+
   |   a=10    |   (0061FF1C)
   +-----------+
         ^
         |
   +-----------+
   |   p=&a    |   (0061FF18)
   +-----------+
         ^
         |
   +-----------+
   |   pp=&p   |   (0061FF14)
   +-----------+
   ```
   <br/>

2. 출력

    ```c
    // 값 출력
    printf("값 출력 - 변수 a 값 : %d\n", a);        // 508
    printf("값 출력 - *p 로 a 값 접근 : %d\n", *p); // 508
    printf("값 출력 - **pp 로 a 값 접근 : %d\n", **pp); // 508
    
    // 주소 출력 : 어디를 가리키고 있는지 확인
    printf("주소 출력 - 변수 a 의 주소 : %p\n", &a);  // 0061FF1C
    printf("주소 출력 - 포인터 p 의 값 (a의 주소) : %p\n", p);   // &a 와 같음
    printf("주소 출력 - 이중 포인터 pp 의 값 (p의 주소) : %p\n", pp); // &p 와 같음
    
    // 각자의 주소 : 다 다름
    printf("각자의 주소 - 포인터 p 의 주소 : %p\n", &p);  // 0061FF18
    printf("각자의 주소 - 이중 포인터 pp 의 주소 : %p\n", &pp); // 0061FF14 
    ```

   
   주소   | 변수 | 저장값|
   -------|------|----------|
   0061FF1C  |  `a`   | 508|
   0061FF18  |  `p`   | 0061FF18 (a의 주소)|
   0061FF14  |  `pp`  | 0061FF14 (p의 주소)|

   <br/>

3. 그림으로 표현

   ```
   [변수] <-- [포인터] <-- [이중 포인터]
    a       p (가리킴)    pp (가리킴)
   ```
   <br/>

## 이중 포인터를 쓰는 이유

1. 동적 메모리 배열 (2차원 배열) 할당에 필수적

   **동적 메모리로 2차원 배열 생성** -> 이중 포인터 이용

   ```c
   int row = 2, col = 3;
   int **arr;
   
   // row 메모리 할당
   arr = (int **)malloc(sizeof(int*) * row);
   
   // col 메모리 할당
   for(int i = 0; i < row; i++) {
      arr[i] = (int *)malloc(sizeof(int) * col);
   }
   
   // 값 초기화
   for(int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++) {
            arr[i][j] = (i+1) * 10 + j;
      }
   }
   
   for(int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++)
            printf("%d ", arr[i][j]);
      printf("\n");
   }

   // 메모리 해제
   for(int i = 0; i < row; i++) {
      free(arr[i]);
   }
    
   free(arr);
   ```
   <br/>

2. 포인터를 인자로 전달하여 원본 포인터 변수 자체를 바꾸고 싶을 때

   ```c
   // 포인터 변수를 변경하는 함수
   void change(int **pp) {
      static int b = 999;
      *pp = &b;
   }

   // ...

   printf("변경 전 : %d\n", *p); // 508

   change(pp); // p가 b를 가리키게 변경

   printf("변경 후 : %d\n", *p); // 999
   ```
   <br/>

3. 다차원 구조체 관리를 할 때, ex) 링크드리스트

   ```c
   typedef struct Node {
      int data;
      struct Node *next;
   } Node;

   void insert(Node **head, int data) {
      Node *newNode = (Node*)malloc(sizeof(Node));
      newNode->data = data;
      newNode->next = *head;
      *head = newNode;
   }

   void print(Node *head) {
      while(head) {
            printf("%d -> ", head->data);
            head = head->next;
      }
      printf("NULL\n");
   }
   
   int main(void) {
      Node *head = NULL;

      insert(&head, 10);
      insert(&head, 20);
      insert(&head, 30);

      print(head);  // 30 -> 20 -> 10 -> NULL

      return 0;
   }
   ```
   <br/>

## 참고

- [코딩도장 - 31.6 이중 포인터 사용하기](https://dojang.io/mod/page/view.php?id=1738)

- [wikidocs - 이중 포인터](https://wikidocs.net/258817)

- [블로그 참조 - 지미뉴트론 개발일기(포인터, 이중포인터 개념, 실습 예제 완벽 이해)](https://jimmy-ai.tistory.com/54)

- [블로그 참조 - better-tomorrow(포인터의 포인터에 대한 이해)](https://better-tomorrow.tistory.com/entry/%ED%8F%AC%EC%9D%B8%ED%84%B0%EC%9D%98-%ED%8F%AC%EC%9D%B8%ED%84%B017-1-%ED%8F%AC%EC%9D%B8%ED%84%B0%EC%9D%98-%ED%8F%AC%EC%9D%B8%ED%84%B0%EC%97%90-%EB%8C%80%ED%95%9C-%EC%9D%B4%ED%95%B4)

- [블로그 참조 - 호이돌(2중 포인터와 배열 포인터, 배열 포인터의 원리)](https://blog.naver.com/qkrghdud0/220860847274)

- [블로그 참조 - Wanggo Gyul Story(이중 포인터(double pointer) 이해하기 in C)](https://wanggonya.tistory.com/71)

- [블로그 참조 - 까망 하르망(포인터의 포인터(이중 포인터))](https://zoosso.tistory.com/815)

- [블로그 참조 - operationcoding(C언어 기초#11 이중포인터, 함수포인터, 배열포인터, void포인터)](https://operationcoding.tistory.com/26)

- [블로그 참조 - 알쓸신잡 classic 코딩 로그(포인터 개념 (6): 이중 포인터)](https://classic-griver.tistory.com/29)