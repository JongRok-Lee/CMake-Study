# `scope`
`CMakeLists.txt`에서 `set`으로 정의한 변수는 해당 `CMakeLists.txt`에서만 유효하다.  
단, `PARENT_SCOPE`를 사용하면 해당 `CMakeLists.txt`가 아닌 상위 `CMakeLists.txt`에서 사용이 가능하다.
```cmake
# child/CMakeLists.txt
set(VAR1 "Hello" PARENT_SCOPE)

# parent/CMakeLists.txt
add_subdirectory(child)
message(STATUS "VAR1: ${VAR1}")
```
모든 `CMakeLists.txt`에서 사용 가능한 전역 변수를 정의하려면 `CACHE`를 사용한다. 마지막에는 변수의 설명을 적어준다.
```cmake
set(VAR2 "World" CACHE STRING "Description")
```