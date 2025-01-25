# Pre-defined Global Variables
cmake는 크로스 빌드 시스템이다. 따라서 크로스 빌드 시스템에서 사용되는 타겟 시스템을 위한 전역 변수들이 있다.
### 타겟 시스템
- `CMAKE_SYSTEM_NAME`: 타켓 시스템의 이름을 나타낸다.
- `CMAKE_SYSTEM_VERSION`: 타켓 시스템의 버전을 나타낸다.
- `CMAKE_SYSTEM`: 타켓 시스템의 이름과 버전을 동시에 나타낸다.
- `CMAKE_SYSTEM_PROCESSOR`: 타켓 시스템의 CPU 아키텍처를 나타낸다.
### 호스트 시스템
크로시 컴파일 시 타겟 시스템이 아닌 호스트 시스템을 위한 전역 변수들이 있다.
- `CMAKE_HOST_SYSTEM_NAME`: 호스트 시스템의 이름을 나타낸다.
- `CMAKE_HOST_SYSTEM_VERSION`: 호스트 시스템의 버전을 나타낸다.
- `CMAKE_HOST_SYSTEM`: 호스트 시스템의 이름과 버전을 동시에 나타낸다.
- `CMAKE_HOST_SYSTEM_PROCESSOR`: 호스트 시스템의 CPU 아키텍처를 나타낸다.
### 컴파일러 변수
- `CMAKE_C_COMPILER`: C 컴파일러의 절대 경로를 나타낸다.
- `CMAKE_C_COMPILER_ID`: C 컴파일러의 타입을 나타낸다.
- `CMAKE_C_COMPILER_VERSION`: C 컴파일러의 버전을 나타낸다.
- `CMAKE_CXX_COMPILER`: C++ 컴파일러의 절대 경로를 나타낸다.
- `CMAKE_CXX_COMPILER_ID`: C++ 컴파일러의 타입을 나타낸다.
- `CMAKE_CXX_COMPILER_VERSION`: C++ 컴파일러의 버전을 나타낸다.
- `CMAKE_CUDA_COMPILER`: CUDA 컴파일러의 절대 경로를 나타낸다.
- `CUDAToolkit_VERSION`: CUDA 컴파일러의 버전을 나타낸다.
### 빌드를 위한 전역 변수
- `CMAKE_BUILD_TYPE`: 어떤 빌드 타입을 사용하고 있는지 나타낸다.
    - `Debug`: 디버그 모드
    - `Release`: 릴리즈 모드
    - `RelWithDebInfo`: 디버그 정보를 포함한 릴리즈 모드
    - `MinSizeRel`: `Release`는 속도에 최적화하지만, `MinSizeRel`은 크기에 최적화한다.
- `CMAKE_CXX_COMPILE_FEATURES`: 어떤 컴파일러 기능을 사용하고 있는지 나타낸다.
### 프로젝트를 위한 전역 변수
- `CMAKE_PROJECT_NAME`: 프로젝트의 이름을 나타낸다.
- `CMAKE_PROJECT_VERSION`: 프로젝트의 버전을 나타낸다.
- `CMAKE_PROJECT_VERSION_MAJOR`: 프로젝트의 메이저 버전을 나타낸다.
- `CMAKE_PROJECT_VERSION_MINOR`: 프로젝트의 마이너 버전을 나타낸다.
- `CMAKE_PROJECT_VERSION_PATCH`: 프로젝트의 패치 버전을 나타낸다.
- `CMAKE_PROJECT_VERSION_TWEAK`: 프로젝트의 트윅 버전을 나타낸다.
- `CMAKE_PROJECT_DESCRIPTION`: 프로젝트의 설명을 나타낸다.
- `CMAKE_PROJECT_HOMEPAGE_URL`: 프로젝트의 홈페이지 주소를 나타낸다.
