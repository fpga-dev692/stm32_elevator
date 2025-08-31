
////////////////////////////////////

[Patch Note]

UART 기능 개선

기존: Emergency Button을 누르면

	Warning!
	
	Select an Option:
	1. Continue
	2. Go to nearest Floor
	3. Go to 1st Floor
	4. Go to 2nd Floor
	5. Go to top Floor

개선안: Emergency Button을 누르면

	Warning!
	
	Select an Option:
	1. Continue
	2. Go to nearest Floor
	3. Go to specific Floor
	
	3->
	1. Go to 1st Floor
	2. Go to 2nd Floor
	3. Go to top Floor
	4. Return
	
	4->
	Select an Option:
	1. Continue
	2. Go to nearest Floor
	3. Go to specific Floor
	
	반복...
	
////////////////////////////////////

////////////////////////////////////

[현재 이슈]

1. Go to nearest floor 기능에서, currentFloor에 targetFloor와 같은 값이 저장되어 있으면 이동하지 못하는 문제
2. Go to specific floor 기능에서, currentFloor에 targetFloor와 같은 값이 저장되어 있으면 이동하지 못하는 문제
3. Go to nearest floor 기능에서, state가 3일 때 2층으로 향하지 못하는 문제(재확인 필요)
4. Go to nearest floor, Go to specific floor 기능에서, PC 터미널에서 uart 메시지가 모터가 회전한 후에 출력되는 문제

[해결 방안]

1, 2의 경우, 센서에 의존하지 않고 스텝 수를 인수로 사용하는 함수를 새로 만들어서, 강제로 보낼 예정
3, 4는 현재 원인을 찾지 못함