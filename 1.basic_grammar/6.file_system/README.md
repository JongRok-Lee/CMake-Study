# `file_system`
### 파일 시스템을 위한 사전에 정의된 변수들이 존재한다.
- `CMAKE_SOURCE_DIR`: 최상위 `CMakeLists.txt` 파일이 있는 디렉토리의 절대 경로
- `CMAKE_CURRENT_SOURCE_DIR`: 현재 처리 중인 `CMakeLists.txt` 파일이 있는 디렉토리의 절대 경로
- `CMAKE_BINARY_DIR`: 최상위 `CMakeLists.txt`가 빌드한 결과 파일들이 있는 디렉토리의 절대 경로
- `CMAKE_CURRENT_BINARY_DIR`: 현재 처리 중인 `CMakeLists.txt`가 빌드한 결과 파일들이 있는 디렉토리의 절대 경로
- `CMAKE_CURRENT_LIST_DIR`: `CMAKE_CURRENT_BINARY_DIR`와 비슷하지만, `include()` 명령어를 사용할 경우 `*.cmake` 파일이 있는 디렉토리의 절대 경로를 표시한다.
- `include()`: 현재 처리 중인 `CMakeLists.txt` 파일에 다른 `*.cmake` 파일을 포함시키는 명령어

### 파일 시스템을 위한 `file()`함수가 존재한다.
- `file(WRITE )`: 파일을 생성한다.
    ``` cmake
    file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/file.txt "Hello, World!\n")
    ```
- `file(READ )`: 파일을 읽고 읽은 내용을 변수에 저장한다.
    ``` cmake
    file(READ ${CMAKE_CURRENT_SOURCE_DIR}/file.txt CONTENT)
    ```
- `file(remove )`: 파일을 제거한다.
    ``` cmake
    file(REMOVE ${CMAKE_CURRENT_SOURCE_DIR}/file.txt)
    ```
### 심볼릭 링크가 존재한다.
심볼릭 링크란 파일을 직접 사용하지 않고 링크를 걸어서 파일을 참조하는 개념이다.
- `file(CREATE_LINK )`: 심볼릭 링크를 생성한다.
    ``` cmake
    file(CREATE_LINK ${CMAKE_CURRENT_SOURCE_DIR}/file.txt ${CMAKE_CURRENT_SOURCE_DIR}/file_link.txt SYMBOLIC)
    ```
- `file(READ_SYMLINK )`: 심볼릭 링크가 걸린 파일이 가리키는 파일의 경로를 읽어온다.
    ``` cmake
    file(READ_SYMLINK ${CMAKE_CURRENT_SOURCE_DIR}/file_link.txt CONTENT)
    ```
- `file(REMOVE )`: 심볼릭 링크를 제거한다.
    ``` cmake
    file(REMOVE ${CMAKE_CURRENT_SOURCE_DIR}/file_link.txt)
    ```
### 디렉토리를 생성하거나 제거하는 함수가 존재한다.
- `file(MAKE_DIRECTORY )`: 디렉토리를 생성한다.
    ``` cmake
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/dir)
    ```
- `file(REMOVE_RECURSE )`: 디렉토리를 제거한다.
    ``` cmake
    file(REMOVE_RECURSE ${CMAKE_CURRENT_SOURCE_DIR}/dir)
    ```
### Copy
- `file(COPY )`: 파일 또는 디렉토리를 복사한다. 파일과 디렉토리 모두 동일한 파일/폴더 명으로 복사되므로 폴더를 새로 생성한 후 그 안에 복사한다.
    ``` cmake
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/file.txt DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/destination)
    ```
### glob
특정 패턴을 가진 파일 또는 디렉토리들을 찾아 리스트로 반환한다.
```
file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/file1.txt "Hello, World!\n")
file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/file2.txt "Hello, World!\n")
file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/file3.txt "Hello, World!\n")
file(GLOB FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.txt)
```
### rename
- `file(RENAME )`: 파일 또는 디렉토리의 이름을 변경한다.
    ``` cmake
    file(RENAME ${CMAKE_CURRENT_SOURCE_DIR}/file.txt ${CMAKE_CURRENT_SOURCE_DIR}/file_renamed.txt)
    ```
### type check
- `file(IS_DIRECTORY )`: 디렉토리인지 확인한다. 단, 상대 경로는 사용할 수 없다.
- `file(IS_SYMLINK )`: 심볼릭 링크인지 확인한다.
- `file(IS_ABSOLUTE )`: 절대 경로인지 확인한다.
``` cmake
if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/dir)
    message("dir is directory")
endif()
if(IS_SYMLINK ${CMAKE_CURRENT_SOURCE_DIR}/file_link.txt)
    message("file_link.txt is symbolic link")
endif()
if(IS_ABSOLUTE ${CMAKE_CURRENT_SOURCE_DIR})
    message("CMAKE_CURRENT_SOURCE_DIR is absolute path")
endif()
```