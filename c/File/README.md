# I/O, Stream, FILE

> 프로그램상에서 파일에 저장되어 있는 데이터를 참조/Read하길 원한다면
> 구현한 프로그램과 참조할 데이터가 저장되어 있는 파일 사이에서 데이터가 이동할 수 있는 다리를 놓는 일
> 즉 data 이동의 경로가 되는 다리를 가리켜 '스트림(stream)'

<br/>

`C` 에서 **파일 입출력 스트림**은 입출력 작업을 관리하는 data stream
<br/>

- **Input Stream**

  - data를 외부에서 프로그램으로 가져오는 스트림,
  - 예를 들어, 파일에서 데이터를 읽어와 프로그램 내 변수에 저장하는 경우가 이에 해당
    <br/>

- **Output Stream**
  - data를 프로그램에서 외부로 보내는 스트림
  - 예를 들어, 프로그램 내 데이터를 파일에 쓰거나 화면에 출력하는 경우가 이에 해당
    <br/>

## FILE

> 포인터는 특정 파일을 가리키며, 해당 파일을 스트림으로 제어 가능

- C 언어에서는 표준 라이브러리를 통해 파일 입출력 스트림을 지원
- 이때 스트림은 FILE 구조체로 표현되며, stdio.h 헤더 파일에 정의
  <br/>

## fopen

> 파일을 열고 스트림을 반환하는 함수

```c
FILE * fopen(const char * filename, const char * mode)
```

<br/>

- 파일 이름과 스트림의 종류를 매개변수로 요구
- 성공 시 해당 파일의 FILE 구조체 변수의 주소 값 반환
- 실패 시 NULL 포인터 반환
  <br/>

## 파일 모드

| 파일 모드 | 기능             | 설명                                                                                                                                   |
| --------- | ---------------- | -------------------------------------------------------------------------------------------------------------------------------------- |
| **"r"**   | read(읽기) 전용  | 파일을 읽기 전용으로 open(단, 파일이 반드시 있어야 함)                                                                                 |
| **"w"**   | write(쓰기) 전용 | 새 파일을 생성(만약 파일이 있으면 내용을 덮어씀)                                                                                       |
| **"a"**   | 추가             | 파일을 열어 파일 끝에 값을 이어 씀(만약 파일이 없으면 파일을 생성)                                                                     |
| **"r+"**  | 읽기/쓰기        | 파일을 읽기/쓰기용으로 엽니다. 단, 파일이 반드시 있어야 하며 파일이 없으면 NULL을 반환합니다.                                          |
| **"w+"**  | 읽기/쓰기        | 파일을 읽기/쓰기용으로 open, 파일이 없으면 파일을 생성하고, 파일이 있으면 내용을 덮어씀                                                |
| **"a+"**  | 추가(읽기/쓰기)  | 파일을 열어 파일 끝에 값을 이어 씀 만약 파일이 없으면 파일을 생성, 읽기는 파일의 모든 구간에서 가능하지만, 쓰기는 파일의 끝에서만 가능 |
| **"t"**   | 텍스트 모드      | 파일을 읽거나 쓸 때 개행문자 \n와 \r\n을 서로 변환 ^Z 파일의 끝으로 인식하므로 ^Z까지만 파일을 읽음 (^Z는 Ctrl+Z 입력을 뜻함)          |
| **"b"**   | 바이너리 모드    | 파일의 내용을 그대로 읽고, 값을 그대로 씀                                                                                              |

## 파일명과 파일 경로

- `fopen` 함수 파일명만 지정하면 현재 작업 디렉터리(working directory)에서 파일 open
  <br/>

- window

  - `fopen` 에는 파일이 있는 경로까지 함께 지정가능(경로에 \를 입력할 때는 \\와 같이 입력해야 험)
  - 절대 경로: `fopen("c:\\project\\hello.txt", "w");`
  - 상대 경로: `fopen("..\\hello.txt", "w");` 상대 경로는 작업 디렉터리를 기준으로 파일을 찾아서 open
    <br/>

- linux / OS X
  - `fopen("/home/project/hello.txt", "w");`
    <br/>

## fclose

> 생성한 스트림을 해제하는 함수

```c
int fclose(FILE* stream);
```

<br/>

- `malloc`으로 메모리 할당했을 때 `free` 통해 해제하는 것과 마찬가지

- 성공 시 `0` 반환
- 실패 시 `EOF` 반환

## fprintf

> printf의 파일 버전인 fprintf를 사용

<br/>

```c
#include <stdio.h>  // C++ 에서는 <cstdio>
int fprintf(FILE* stream, const char* format, ...);
```

- **parameter**

  - `stream`: 작업을 수행할 스트림의 `FILE` 객체
  - `format`: C 문자열로 스트림에 써질 텍스트를 포함

  <br/>

- **예시**

  ```c
  #define _CRT_SECURE_NO_WARNINGS
  #include <stdio.h>

  int main(void)
  {
      FILE *fp = fopen("hello.txt", "w"); // 1

      fprintf(fp, "%s %d\n", "Hello", 100); // 2

      fclose(fp); // 3
      return 0;
  }
  ```

  1. `hello.txt` 파일을 쓰기 모드(`w`)로 연 후 파일 포인터를 반환
  2. 서식을 지정하여 문자열을 파일에 저장
  3. 파일 포인터 닫기
  4. `hello.txt` 파일에 **Hello 100** 문구가 생기고 파일이 생성
     <br/>

_cf_ . **stdout** : `fprintf` 으로 출력 가능

```c
fprintf(stdout, "%s %d\n", "Hello", 100);
```

```
Hello 100
```

<br/>

## fscanf

> sacnf의 파일 버전인 fscanf를 사용

```C
#include <stdio.h>  // C++ 에서는 <cstdio>
int fscanf(FILE * const _Stream, char const * const _Format, ...);
```

- **parameter**

  - `stream`: 작업을 수행할 스트림의 `FILE` 포인터
  - `format`: C 문자열로 스트림에 써질 텍스트를 포함

    - _공백 문자 (Whitespace character 이라 부르며, 개행 문자(\n), 탭 문자, 띄어쓰기(' '))_
      `fscanf` 함수는 비-공백 문자를 읽어들이기 전까지 읽혀지는 모든 공백 문자들을 무시
      <br/>
    - _비-공백 문자 (Non whitespcae character, 단 % 를 제외)_

      - 공백 문자가 아니거나 형식 지정자에 포함되지 않는 것들은 함수로 하여금 다음 문자를 스트림에서 읽어 들이고 이와 이 비-공백 문자와 비교하여 같다면 버리고 다음 문자와 형식으로 진행
      - 만일 다르다면 함수가 종료되고, 스트림에서 읽혀지지 않은 다른 문자들은 모두 남아있게 됌
        <br/>

    - 형식 지정자 이는 % 로 지정되는 것들로 스트림에서 어떠한 형식으로 데이터를 읽어오고, 또 각각의 형식 지정자에 대응되는 인자에 어떠한 형식으로 저장할 지에 대해 결정
      <br/>

- **예시**

  ```c
  int main(void)
  {
      char s1[10];
      int num1;
      FILE *fp = fopen("hello.txt", "r");

      fscanf(fp, "%s %d", s1, &num1);
      printf("%s %d\n", s1, num1); // Hello 100
      fclose(fp);

      return 0;
  }
  ```

  <br/>

_cf_ . **stdin** : `fsacnf` 으로 입력 가능

```c
fscanf(stdin, "%s %d", s1, &num1);
```

```
sss 10 // 입력
sss 10 // 출력
```

## 참고

- [코딩도장-서식을 지정하여 파일에 문자열 쓰기](https://dojang.io/mod/page/view.php?id=607)
- [블로그 참조-better(파일과 스트림(Stream), 그리고 기본적인 파일의 입출력)](https://better-tomorrow.tistory.com/entry/%ED%8C%8C%EC%9D%BC-%EC%9E%85%EC%B6%9C%EB%A0%A524-1-%ED%8C%8C%EC%9D%BC%EA%B3%BC-%EC%8A%A4%ED%8A%B8%EB%A6%BCStream-%EA%B7%B8%EB%A6%AC%EA%B3%A0-%EA%B8%B0%EB%B3%B8%EC%A0%81%EC%9D%B8-%ED%8C%8C%EC%9D%BC%EC%9D%98-%EC%9E%85%EC%B6%9C%EB%A0%A5)
