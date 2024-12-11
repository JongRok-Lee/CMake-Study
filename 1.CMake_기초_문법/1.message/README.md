# `message`
CMake에서는 `message` 함수를 통해 터미널에 메시지를 출력할 수 있다.  
`message` 함수는 인자 내에 2가지가 필요하다.  
1. 메시지의 타입
2. 메시지의 내용

## 메시지의 타입
- `STATUS`: 일반적인 메시지 타입으로, cmake의 프로세스에 영향을 미치지 않는다.
- `WARNING`: 경고 메시지 타입으로, 주로 사용자에게 경고를 주는 용도로 사용되며 몇 번째 라인에서 경고가 발생했는지도 알려준다.
    ```text
    CMake Warning at CMakeLists.txt:17 (message):
      This warning is for all!
    ```
- `AUTHOR_WARNING`: `WARNING`과 거의 동일한 기능을 수행하지만, `WARNING`과는 다르게 `AUTHOR_WARNING`은 개발자들을 위한 경고 메시지이다. 일반적으로 거의 사용되지 않는다.
    ```text
    CMake Warning (dev) at CMakeLists.txt:23 (message):
      This warning is for developers only!
    This warning is for project developers.  Use -Wno-dev to suppress it.
    ```
    - `set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS ON CACHE INTERNAL "Suppress developer warnings")`을 사용하면 해당 경고 메시지를 무시할 수 있다.
- `SEND_ERROR`: 에러 메시지 타입으로, cmake의 프로세스에 영향을 미치며 에러가 발생하면 **cmake Configure 과정은 진행되지만 Generate 과정은 진행되지 않는다.**
    ```text
    CMake Error at CMakeLists.txt:30 (message):
      But it will stop the generation process.
    ```
- `FATAL_ERROR`: 치명적인 에러 메시지 타입으로, cmake의 프로세스에 영향을 미치며 에러가 발생하면 **cmake Configure 과정도 진행되지 않는다.**
    ```text
    CMake Error at CMakeLists.txt:36 (message):
      Fatal error during configuration!
    ```
- `DEPRECATION`: 미래에 사용되지 않을 기능을 사용했을 때 발생하는 **일종의 경고 메시지 타입**이다.
    ```text
    CMake Deprecation Warning at CMakeLists.txt:42 (message):
      This is deprecated.
    ```
## 메시지의 내용
메시지의 내용은 사용자가 원하는 내용을 입력하면 된다.  
