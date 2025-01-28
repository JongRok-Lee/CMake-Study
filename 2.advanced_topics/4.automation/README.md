# 자동화 스크립트
때론 CMake 내에서 다른 스크립트를 통해 자동화할 필요가 있을 수 있다.
cmake에서는 `execute_process` 명령어를 통해 다른 스크립트를 실행할 수 있다.
``` cmake
execute_process(
COMMAND <command1> [args1...]
[COMMAND <command2> [args2...] ...]
[WORKING_DIRECTORY <directory>]
[RESULT_VARIABLE <variable>]
[OUTPUT_VARIABLE <variable>])
```
- `COMMAND`: 실행할 명령어를 나타낸다.
- `WORKING_DIRECTORY`: 명령어를 실행할 디렉토리를 나타낸다.
- `RESULT_VARIABLE`: 결과가 정상적으로 완료되었는지 확인하는 변수를 나타낸다. (0: 정상, 그 외: 오류 코드)
- `OUTPUT_VARIABLE`: 명령어의 출력을 변수에 저장한다.
