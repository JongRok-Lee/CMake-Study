# `variable`
CMake에서는 `set` 함수를 통해 변수를 정의할 수 있다.  
변수는 `set(변수명 값)` 형태로 정의하며, 변수명은 대소문자를 구분한다.  
변수로 설정할 수 있는 타입은 다음과 같다.
### 숫자
``` cmake
set(VARIABLE 1)
```
### 문자열
``` cmake
set(VARIABLE "Hello, World!")
```
### 불리언
``` cmake
set(BOOL_VARIABLE TRUE)
set(BOOL_VARIABLE ON)
set(BOOL_VARIABLE YES)
set(BOOL_VARIABLE 1)

set(BOOL_VARIABLE FALSE)
set(BOOL_VARIABLE OFF)
set(BOOL_VARIABLE NO)
set(BOOL_VARIABLE 0)
```
### 리스트
``` cmake
set(LIST 1 2 3 4 5)
set(STRING_LIST "Hello" "World" "CMake" "Lists")
set(BOOL_LIST TRUE FALSE ON OFF YES NO 1 0)
```