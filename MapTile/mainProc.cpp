#include"World.h"

void main()
{
	// ���� �ʱ�ȭ (����, ����)
	CWorld world(50,50);
	// ������ ���밴ü(�ʿ�,���,��)�� �������� ����
	world.generateTerrain();
	// �׸�
	world.drawMap();

}