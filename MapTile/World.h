#pragma once
#include"Terrain.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class CWorld
{
	int m_width;
	int m_height;
	// �� �������� ���� ��ü�� �����.
	CTerrain m_grassTerrain; // Ǯ
	CTerrain m_hillTerrain; // ���
	CTerrain m_riverTerrain; // ��
	CTerrain*** m_tiles; // Ÿ��
	//(�� Ÿ�ϸ��� CTerrain���� Ǯ,���,���� �ϳ��� ��ü �ּҸ� ��´� )
	// CTerrain* m_tiles[][] �̰� �ϳ��� Ǯ, ���, ���߿� �ϳ��� ����Ų��. ����Ű�°� 
	// ����̳Ŀ� ���� ������ �����ȴ�.
	// �� ����Ű�°Ϳ� �������� ����ϴ� �𵨸�,�ؽ��� ������ ����ִ�.
public:
	CWorld(int width, int height):m_width(width), m_height(height), m_grassTerrain(1, false, "="), m_hillTerrain(3, false, "^"), m_riverTerrain(2, true, "~")
	{
		// �ϴ� ���������� �迭�� �ʱ�ȭ(�������� ���� ������)
		m_tiles = new CTerrain**[width];
		for (int y = 0; y < m_height; y++)
		{
			// �� 0 ~ m_height�� ���� ���������͸� �����ͷ� �ʱ�ȭ
			m_tiles[y] = new CTerrain*[height];
			// �̷��� �����μ� ���� X ���� ��� �ּҸ� ���� �� �ִ� �غ� �Ǿ���.
			// CTerrain*[0][0],CTerrain*[1][0],CTerrain*[2][0]
			// CTerrain*[0][1],CTerrain*[1][1],CTerrain*[2][1]
			// �̰͵��� [Ǯ, ���, ��(���� ��ü��)]�߿� �ϳ��� ����Ų��.
		}
	}
	~CWorld();

	void generateTerrain();
	// const�� ����ϴ� ������ �������� ����ϴ� ��ü�� ��ȭ ��Ű�� �ʱ� �����̴�.
	// ���� ��ü�� ��ȭ��Ű�� ���� ������� ������ �㵵 �Բ� ��ȭ�ȴ�.
	const CTerrain& getTile(int x, int y) const 
	{
		return *m_tiles[x][y]; // m_tiles �ϳ��ϳ��� �ּ�(�ʿ�,���,����ü�� �ּ��� �ϳ�)�� �����ϰ� �����Ƿ� *��& ���� �ʿ���� �׳� �����ϸ� ��.
	}

	void drawMap()
	{
		for (int y = 0; y < m_height; y++)
		{
			for (int x = 0; x < m_width; x++)
			{
				// ��ü�� ����Ű���ִ� ������ ��ü�� ������ ���
				cout << getTile(x, y).getTexture();
			}
			cout << endl;
		}
	}

};

