How to processing this project.
Process
교수님께서 조별문제 제공( 2일전)
ex) 조별문제
C = A - 1 - 3 + B 구현하고, C를 출력하라
A값: 0100(메모리주소: 0111)
B값: 0011(메모리주소: 0101)
C값: 0000(메모리주소: 0001)
조별 문제
C = A + B - 3 + 1
A값: 0100 (메모리주소: 1100)4
B값: 0001 (메모리주소 0111)1
C값: 1111(메모리주소 1111)7
E = A + B - C - D - 1 + 6
A값: 1110 (메모리주소 1100)
B값: 0001 (메모리주소 1110)
C값: 0001(메모리주소 0100)
D값: 1100(메모리주소 0101)
E값: 1111 (메모리주소 0011)
조별문제를 input.pl로 작성
structure: OPCODE/ OPERAND/ OPERAND/ OPERAND
ex)input.pl
WRITE A, 0111, 0001
WRITE B, 0101, 0010
WRITE C, 0001, 0000
ADD A, B
STORE C
PRINT C
Module 2
Goal
input.pl을 opcode로 변환하여 output.bl 로 작성
function
[0000] LOAD Num: Num 값을 DR에 저장
[0001] LOAD[A]: 메모리 주소 A의 값을 DR에 저장
[0010] STORE [A]: DR의 값을 메모리 A 주소에 저장
[0011] PUSH Num: Stack에 Num값 추가
[0100] PUSH: Stack에 DR값 추가
[0101] POP: Stack에서 제거 및 DR에 값 저장
[0110] ADD: Stack에 Stack + DR 저장
[0111] SUB: Stack에 Stack - DR 저장
[1000] WRITE Address: 메모리주소 Address에 Stack의 값을 저장
[1001] PRINT Address: 메모리주소 Address에 있는 값을 출력
ex)output.bl
0011 0001 
1000 0111
0101
0011 0010
1000 0101
0101
0011 0000
1000 0001
0101
0001 0111
0100
0001 0101
0110
0101
0010 0001
1001 0001
Module 1
Goal
reading output.dl and compile
function
instruction
[0000] LOAD Num: Num 값을 DR에 저장
[0001] LOAD[A]: 메모리 주소 A의 값을 DR에 저장
[0010] STORE [A]: DR의 값을 메모리 A 주소에 저장
[0011] PUSH Num: Stack에 Num값 추가
[0100] PUSH: Stack에 DR값 추가
[0101] POP: Stack에서 제거 및 DR에 값 저장
[0110] ADD: Stack에 Stack + DR 저장
[0111] SUB: Stack에 Stack - DR 저장
[1000] WRITE Address: 메모리주소 Address에 Stack의 값을 저장
[1001] PRINT Address: 메모리주소 Address에 있는 값을 출력
manage memory
manage stack
