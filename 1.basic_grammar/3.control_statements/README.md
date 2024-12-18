# `Control Statements`
CMake에서는 `if`, `elseif`, `else`, `endif`를 사용하여 조건문을 사용할 수 있다.  

### `if`, `elseif`, `else`
`if` 명령어는 항상 `endif` 명령어와 함께 사용되어야 한다.  
변수가 `BOOL` 타입인 경우에는 `${}`로 감싸지 않아도 되지만, 그 외의 경우에는 반드시 `${}`로 감싸야하기 때문에 `${}`로 통일해서 감싸는 것이 좋다.  
```cmake
set(BOOL_VARIABLE1 FALSE)
set(BOOL_VARIABLE2 BOOL_VARIABLE1)
if(BOOL_VARIABLE2)
    message(STATUS "BOOL_VARIABLE2 is TRUE")
endif()
```
`BOOL_VARIABLE1`가 `FALSE`이기 때문에 `BOOL_VARIABLE2`도 `FALSE`이길 기대 하지만, 위와 같이 작성하면 `BOOL_VARIABLE2`는 `BOOL_VARIABLE1`의 값을 그대로 가져오기 때문에 `TRUE`로 인식하기 때문에 아래와 같이 작성해야 한다.  
```cmake
if(${BOOL_VARIABLE2})
    message(STATUS "BOOL_VARIABLE2 is TRUE")
else()
    message(STATUS "BOOL_VARIABLE2 is FALSE")
endif()
```
### `NOT`, `AND`, `OR`
`if` 명령어에서 `NOT`, `AND`, `OR`를 사용하여 조건을 더 복잡하게 만들 수 있다.  
```cmake
if(NOT ${BOOL_VARIABLE1})
    message(STATUS "BOOL_VARIABLE1 is FALSE")
endif()
if(${BOOL_VARIABLE1} AND ${BOOL_VARIABLE2})
    message(STATUS "BOOL_VARIABLE1 and BOOL_VARIABLE2 are TRUE")
endif()
if(${BOOL_VARIABLE1} OR ${BOOL_VARIABLE2})
    message(STATUS "BOOL_VARIABLE1 or BOOL_VARIABLE2 is TRUE")
endif()
```
### `EQUAL`, `LESS`, `GREATER`, `LESS_EQUAL`, `GREATER_EQUAL`
`EQUAL`, `LESS`, `GREATER`, `LESS_EQUAL`, `GREATER_EQUAL`를 사용하여 숫자를 비교할 수 있다.  
```cmake
if(${NUMBER1} EQUAL ${NUMBER2})
    message(STATUS "NUMBER1 == NUMBER2")
elseif(NOT(${NUMBER1}  EQUAL ${NUMBER2}))
    message(STATUS "NUMBER1 != NUMBER2")
endif()

if(${NUMBER1} LESS ${NUMBER2})
    message(STATUS "NUMBER1 < NUMBER2")
elseif(NOT(${NUMBER1} LESS ${NUMBER2}))
    message(STATUS "NUMBER1 >= NUMBER2")
endif()

if(${NUMBER1} GREATER ${NUMBER2})
    message(STATUS "NUMBER1 > NUMBER2")
elseif(NOT(${NUMBER1} GREATER ${NUMBER2}))
    message(STATUS "NUMBER1 <= NUMBER2")
endif()

if(${NUMBER1} LESS_EQUAL ${NUMBER2})
    message(STATUS "NUMBER1 <= NUMBER2")
elseif(NOT(${NUMBER1} LESS_EQUAL ${NUMBER2}))
    message(STATUS "NUMBER1 > NUMBER2")
endif()

if(${NUMBER1} GREATER_EQUAL ${NUMBER2})
    message(STATUS "NUMBER1 >= NUMBER2")
elseif(NOT(${NUMBER1} GREATER_EQUAL ${NUMBER2}))
    message(STATUS "NUMBER1 < NUMBER2")
endif()
```
### String Compare
`STREQUAL`, `MATCHES`를 사용하여 문자열을 비교할 수 있다.  
`MATCHES`는 정규표현식을 사용할 수 있다.
```cmake
if(${STRING1} STREQUAL ${STRING2})
    message(STATUS "STRING1 == STRING2")
elseif(NOT(${STRING1} STREQUAL ${STRING2}))
    message(STATUS "STRING1 != STRING2")
endif()

if(${STRING1} MATCHES "^abc")
    message(STATUS "STRING1 starts with 'abc'")
endif()

if(${STRING1} MATCHES "txt$")
    message(STATUS "STRING1 ends with 'txt'")
endif()

if(${STRING1} MATCHES "c1")
    message(STATUS "STRING1 contains 'c1'")
else()
    message(STATUS "STRING1 does not contain 'c1'")
endif()

if(${STRING1} MATCHES "^[a-z][3].txt")
    message(STATUS "STRING1 included in '^[a-z][3].txt'")
else()
    message(STATUS "STRING1 does not included in '^[a-z][3].txt'")
endif()
```
### `IN_LIST`
`IN_LIST`를 사용하여 리스트에 포함되어 있는지 확인할 수 있다.
```cmake
if(${STRING1} IN_LIST STRING_LIST)
    message(STATUS "STRING1 in STRING_LIST")
else()
    message(STATUS "STRING1 not in STRING_LIST")
endif()

if(NOT(${STRING2} IN_LIST STRING_LIST))
    message(STATUS "STRING2 not in STRING_LIST")
endif()
```
### `DEFINED`
`DEFINED`를 사용하여 변수가 정의되어 있는지 확인할 수 있다.
```cmake
if(DEFINED STRING3)
    message(STATUS "STRING3 defined")
else()
    message(STATUS "STRING3 not defined")
endif()
```
### `COMMAND`, `TARGET`
`COMMAND`, `TARGET`를 사용하여 명령어, 타겟이 존재하는지 확인할 수 있다.
```cmake
if(COMMAND project)
    message(STATUS "COMMAND project exists")
else()
    message(STATUS "COMMAND project does not exist")
endif()

if(NOT COMMAND project2)
    message(STATUS "COMMAND project2 does not exist")
endif()

if(TARGET project)
    message(STATUS "TARGET project exists")
else()
    message(STATUS "TARGET project does not exist")
endif()

if(NOT(TARGET project2))
    message(STATUS "TARGET project2 does not exist")
endif()
```
### `foreach`, `while`
`foreach`, `while` 명령어를 사용하여 반복문을 사용할 수 있다.  
`foreach` 명령어는 `RANGE`를 사용하여 반복 횟수를 지정할 수 있다. 특히, `RANGE`를 사용할 때는 `RANGE` 다음에 시작, 끝, 증가값을 지정할 수 있다.
```cmake
foreach(NUM RANGE 5)
    message(STATUS "NUMBER: ${NUM}")
endforeach()

foreach(NUM RANGE 2 6 2)
    message(STATUS "NUMBER: ${NUM}")
endforeach()

set(INDEX 0)
while(${INDEX} LESS 5)
    message(STATUS "INDEX: ${INDEX}")
    math(EXPR INDEX "${INDEX} + 1")
endwhile()
```