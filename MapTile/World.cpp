#include "World.h"


CWorld::~CWorld()
{
}
void CWorld::generateTerrain()
{

	srand((unsigned int)time(NULL));
	// ������ Ǯ�� ����� ä��
	for (int x = 0; x < m_width; x++)
	{
		for (int y = 0; y < m_height; y++)
		{	
			int hill = rand() % 10; // ���
			if (hill == 0)
			{
				// hill�� 0�̸� �̶� ����m_tiles[x][y]�� ���밴ü�� ����� ����Ű���� ��.
				// CTerrain* m_tiles[x][y] == CTerrain m_tiles*[x][y]
				m_tiles[x][y] = &m_hillTerrain;
			}else{
				// Ǯ�� ����Ŵ
				m_tiles[x][y] = &m_grassTerrain;
			}
		}
	}

	// ������ ���� �ϳ� ����
	int x = rand() % m_width;
	for (int y = 0; y < m_height; y++)
	{
		m_tiles[x][y] = &m_riverTerrain;
	}

}
