# `function`
CMake에서는 `function`을 사용하여 함수를 정의할 수 있다. 하지만, **값을 리턴하는 기능은 없다.**

### 사용법
```cmake
function(my_function [arg1 [arg2 [arg3 ...]]])
    <commands>
endfunction()

my_function(arg1 arg2 arg3)
```
인자의 개수는 제한이 없다.