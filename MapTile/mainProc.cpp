#include"World.h"

void main()
{
	// 지형 초기화 (가로, 세로)
	CWorld world(50,50);
	// 지형과 공용객체(초원,언덕,강)를 랜덤으로 연결
	world.generateTerrain();
	// 그림
	world.drawMap();

}