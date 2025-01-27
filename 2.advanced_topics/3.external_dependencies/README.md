# 외부 의존성 관리
C++ 오픈 소스들 중, Eigen이나 OpenCV 같이 외부 라이브러리가 필요한 경우를 많이 보았을 것이다.  
보통 이런 경우, README에 외부 라이브러리 설치법을 따로따로 기입해서 사용하는 경우가 많다.(하수다)  
하지만, CMake에서는 이런 외부 라이브러리를 쉽게 관리할 수 있는 방법을 제공하고 있다.  
이 포스트에서는 외부 라이브러리를 쉽게 관리할 수 있는 방법을 알아보도록 하자.
### ExternalProject_Add
ExternalProject_Add는 외부 프로젝트를 다운로드하고 빌드하는 명령어이다.  
이 명령어를 사용하면, 외부 프로젝트를 다운로드하고 빌드하는 과정을 자동으로 처리할 수 있다.  
- `include(ExternalProject)`: ExternalProject 모듈을 포함한다.
- `ExternalProject_Add(target_name)`: 외부 프로젝트를 다운로드하고 빌드하는 명령어이다.
    - `target_name`: 외부 프로젝트의 이름을 나타낸다.
    - `GIT_REPOSITORY`: 외부 프로젝트의 깃 저장소 주소를 나타낸다.
    - `GIT_TAG`: 외부 프로젝트의 깃 태그를 나타낸다.
    - `PREFIX`: 외부 프로젝트를 다운로드하고 빌드하는 경로를 나타낸다. (소스 파일 경로)
    - `CMAKE_ARGS`: 외부 프로젝트를 빌드하는 명령어를 나타낸다.
``` cmake
include(ExternalProject)
ExternalProject_Add(
    GTEST #target name
    GIT_REPOSITORY "https://github.com/google/googletest.git" #git repository
    GIT_TAG "release-1.12.1" #git tag
    PREFIX ${CMAKE_BINARY_DIR}/GTEST-prefix #source file path
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/thirdparty/install/GTEST/${CMAKE_BUILD_TYPE} -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
)
```
### find_package
find_package는 외부 프로젝트를 찾는 명령어이다.  
이 명령어를 사용하면, 외부 프로젝트를 찾아서 사용할 수 있다.
- `find_package(target_name [version] [EXACT] [QUIET] or [REQUIRED] [HINTS] PATH)`: 외부 프로젝트를 찾는 명령어
  - `target_name`: 외부 프로젝트의 이름을 나타낸다.
  - `version`: 외부 프로젝트의 버전을 나타낸다.
  - `EXACT`: 버전을 정확하게 찾는다.
  - `QUIET` or `REQUIRED`: 외부 프로젝트를 찾는 과정을 출력하지 않는다. (`QUIET`: 오류 출력 X, `REQUIRED`: 오류 출력 O)
  - `HINTS PATH`: 외부 프로젝트를 찾는 경로를 나타낸다.
``` cmake
find_package(GTest QUIET HINTS ${CMAKE_SOURCE_DIR}/thirdparty/install/GTEST/lib/cmake/GTest)
```