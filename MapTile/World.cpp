#include "World.h"


CWorld::~CWorld()
{
}
void CWorld::generateTerrain()
{

	srand((unsigned int)time(NULL));
	// 지형에 풀과 언덕을 채움
	for (int x = 0; x < m_width; x++)
	{
		for (int y = 0; y < m_height; y++)
		{	
			int hill = rand() % 10; // 언덕
			if (hill == 0)
			{
				// hill이 0이면 이때 지형m_tiles[x][y]는 공용객체인 언덕을 가리키도록 함.
				// CTerrain* m_tiles[x][y] == CTerrain m_tiles*[x][y]
				m_tiles[x][y] = &m_hillTerrain;
			}else{
				// 풀을 가리킴
				m_tiles[x][y] = &m_grassTerrain;
			}
		}
	}

	// 지형에 강도 하나 넣자
	int x = rand() % m_width;
	for (int y = 0; y < m_height; y++)
	{
		m_tiles[x][y] = &m_riverTerrain;
	}

}
