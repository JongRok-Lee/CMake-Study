# C++ 프로젝트 세팅법
cmake에서 기본적으로 project() 함수를 사용하여 프로젝트를 세팅한다.
``` cmake
project(2.setting_cpp_project
    VERSION 1.2.3.4
    LANGUAGES C CXX CUDA
    DESCRIPTION "This is a project for setting up a C++ project in CMake."
    HOMEPAGE_URL "https://github.com/JongRok-Lee/CMake-Study"
)
message(STATUS "PROJECT_IS_TOP_LEVEL: ${PROJECT_IS_TOP_LEVEL}")
```
- `2.setting_cpp_project`: 프로젝트 이름을 나타낸다.
- `VERSION 1.2.3.4`: 프로젝트 버전을 나타낸다.
- `LANGUAGES C CXX CUDA`: 프로젝트에서 사용할 언어를 나타낸다. (CUDA는 옵션)
- `DESCRIPTION "This is a project for setting up a C++ project in CMake."`: 프로젝트 설명을 나타낸다.
- `HOMEPAGE_URL "https://github.com/JongRok-Lee/CMake-Study"`: 프로젝트 홈페이지 주소를 나타낸다.
- `PROJECT_IS_TOP_LEVEL`: 프로젝트가 최상위 레벨인지 나타낸다.
# CMAKE_CXX_SOMETHING variables
cmake 프로젝트들을 살펴보다보면 `CMAKE_CXX_STANDARD` 이런 변수들을 많이 볼 수 있다. 이런 변수들은 C++ 컴파일러 옵션을 설정하는 변수들이다.
- `CMAKE_CXX_STANDARD`: C++ 컴파일러의 버전을 설정하는 변수이다. 만약 `set()`를 통해 설정하지 않으면 컴파일러 기본 버전이 설정된다.
- `CMAKE_CXX_STANDARD_REQUIRED`: 위에서 설정한 C++ 컴파일러의 버전이 지원되는지 확인하는 변수이다. `set(CMAKE_CXX_STANDARD_REQUIRED ON)` 시 지원되지 않으면 오류를 발생시킨다.
- `CMAKE_CXX_EXTENSIONS`: C++ 컴파일러의 확장 기능을 설정하는 변수이다. 예시로, filesystem 라이브러리는 C++17 표준에 포함되지 않았지만, `set(CMAKE_CXX_EXTENSIONS ON)` 시 사용할 수 있다.
``` cmake
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
```
**위의 3가지는 설정해주는 것이 좋다.**
# CMake 내 C++ 소스/헤더 파일 설정하는 법
## add_library() command
`add_library()` 명령어는 소스 파일들을 라이브러리 타켓으로 생성하는 명령어이다. 소스 파일에서 헤더 파일을 포함하는 경우, `target_include_directories()` 명령어를 사용하여 헤더 파일들을 포함해야 한다.
- `add_library(target_name [SHARED|STATIC|MODULE] [source_files])`: 라이브러리 타켓을 생성하는 명령어이다. 주로 모듈은 사용하지 않는다.
    - `target_name`: 라이브러리 타켓의 이름을 나타낸다.
    - `[SHARED|STATIC|MODULE]`: 라이브러리 타켓의 타입을 나타낸다.
        - `SHARED`: 공유 라이브러리
        - `STATIC`: 정적 라이브러리
        - `MODULE`: 모듈 라이브러리
    - `source_files`: 라이브러리 타켓을 구성하는 소스 파일들을 나타낸다.
``` cmake
add_library(UTILS SHARED
    src/utils.cpp
)
```
생성된 파일은 `libXXX.so`(`SHARED`) 또는 `libXXX.a`(`STATIC`) 형식으로 생성된다.
## target_include_directories() command
`target_include_directories()` 명령어는 타켓에 포함될 헤더 파일들을 설정하는 명령어이다. 기존에는 tartget이 없는 `include_directories()` 명령어를 사용하였지만, **모던 CMake에서는 `target_include_directories()` 명령어를 사용해 public, private, interface 범위를 설정하는 것이 권장된다.**
- `target_include_directories(target_name [PUBLIC|PRIVATE|INTERFACE] [include_directories])`: 타켓에 포함될 헤더 파일들을 설정하는 명령어이다.
    - `target_name`: 타켓의 이름을 나타낸다.
    - `[PUBLIC|PRIVATE|INTERFACE]`: 헤더 파일들을 포함할 범위를 나타낸다.
        - `PUBLIC`: 타켓과 타켓에 의존하는 타켓들에게 포함된다. 즉, `add_library(UTILS)` 명령어 내에서 기술한 모든 소스 파일들은 헤더에 접근할 수 있다. (주로 사용)
        - `PRIVATE`: 타켓에만 포함된다.
        - `INTERFACE`: 타켓에 의존하는 타켓들에게만 포함된다.
    - `include_directories`: 헤더 파일들의 경로를 나타낸다.
``` cmake
target_include_directories(UTILS PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
```
## add_executable() command
`add_executable()` 명령어는 소스 파일들을 실행 파일 타켓으로 생성하는 명령어이다. 소스 파일에서 라이브러리를 사용할 경우 `target_link_libraries()` 명령어를 사용하여 라이브러리를 연결해야 한다. 실헹 함수인 `main()` 함수가 있는 소스 파일을 포함해야 한다.
- `add_executable(target_name [source_files])`: 실행 파일 타켓을 생성하는 명령어이다.
    - `target_name`: 실행 파일 타켓의 이름을 나타낸다.
    - `source_files`: 실행 파일 타켓을 구성하는 소스 파일들을 나타낸다.
``` cmake
add_executable(PRINTING_MESSAGE
    src/printing_message.cpp
)
```
## target_link_libraries() command
`target_link_libraries()` 명령어는 타켓에 연결될 라이브러리들을 설정하는 명령어이다.
- `target_link_libraries(target_name [PUBLIC|PRIVATE|INTERFACE] [libraries])`: 타켓에 연결될 라이브러리들을 설정하는 명령어이다.
    - `target_name`: 타켓의 이름을 나타낸다.
    - `[PUBLIC|PRIVATE|INTERFACE]`: 라이브러리들을 연결할 범위를 나타낸다.
        - `PUBLIC`: 타켓과 타켓에 의존하는 타켓들에게 연결된다.
        - `PRIVATE`: 타켓에만 연결된다. (주로 사용)
        - `INTERFACE`: 타켓에 의존하는 타켓들에게만 연결된다.
    - `libraries`: 연결될 라이브러리들을 나타낸다.
``` cmake
target_link_libraries(PRINTING_MESSAGE PRIVATE
    UTILS
)
```
## target_compile_options() command
`target_compile_options()` 명령어는 타켓에 컴파일 옵션을 설정하는 명령어이다.
- `target_compile_options(target_name [PUBLIC|PRIVATE|INTERFACE] [options])`: 타켓에 컴파일 옵션을 설정하는 명령어이다.
    - `target_name`: 타켓의 이름을 나타낸다.
    - `[PUBLIC|PRIVATE|INTERFACE]`: 컴파일 옵션을 설정할 범위를 나타낸다. (주로 `PRIVATE` 사용)
    - `options`: 컴파일 옵션들을 나타낸다.
주로 `-Wall`, `-Wextra`, `-Werror` 등의 옵션을 설정하는 것을 권장한다. 위 옵션들은 컴파일러의 경고 메시지를 출력하는 옵션들로 빌드 시 디버깅을 용이하게 해준다.
``` cmake
target_compile_options(UTILS PRIVATE
    -Wall
    -Wextra
    -Werror
)
```
## add_dependencies() command
`add_dependencies()` 명령어는 타켓에 의존하는 타켓들을 설정하는 명령어이다. 예를 들어, `PRINTING_MESSAGE` 타켓이 `UTILS` 타켓에 의존하는 경우, `PRINTING_MESSAGE` 타켓을 빌드하기 전에 `UTILS` 타켓을 먼저 빌드해야 한다. 프로젝트가 소규모일 경우 에러가 발생하지 않지만, 프로젝트가 규모가 클 경우 에러가 발생할 수 있다.
- `add_dependencies(target_name [dependencies])`: 타켓에 의존하는 타켓들을 설정하는 명령어이다.
    - `target_name`: 타켓의 이름을 나타낸다.
    - `dependencies`: 타켓에 의존하는 타켓들을 나타낸다.
``` cmake
add_dependencies(PRINTING_MESSAGE
    UTILS
)
```