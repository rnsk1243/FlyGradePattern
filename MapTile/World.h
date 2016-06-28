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
	// 각 지형마다 공용 객체를 만든다.
	CTerrain m_grassTerrain; // 풀
	CTerrain m_hillTerrain; // 언덕
	CTerrain m_riverTerrain; // 강
	CTerrain*** m_tiles; // 타일
	//(각 타일마다 CTerrain형의 풀,언덕,강중 하나의 객체 주소를 담는다 )
	// CTerrain* m_tiles[][] 이것 하나가 풀, 언덕, 강중에 하나를 가리킨다. 가리키는게 
	// 어떤것이냐에 따라서 지형이 결정된다.
	// 그 가리키는것에 공용으로 사용하는 모델링,텍스쳐 정보가 담겨있다.
public:
	CWorld(int width, int height):m_width(width), m_height(height), m_grassTerrain(1, false, "="), m_hillTerrain(3, false, "^"), m_riverTerrain(2, true, "~")
	{
		// 일단 더블포인터 배열로 초기화(여러개의 더블 포인터)
		m_tiles = new CTerrain**[width];
		for (int y = 0; y < m_height; y++)
		{
			// 이 0 ~ m_height개 까지 더블포인터를 포인터로 초기화
			m_tiles[y] = new CTerrain*[height];
			// 이렇게 함으로서 가로 X 세로 모두 주소를 담을 수 있는 준비가 되었다.
			// CTerrain*[0][0],CTerrain*[1][0],CTerrain*[2][0]
			// CTerrain*[0][1],CTerrain*[1][1],CTerrain*[2][1]
			// 이것들이 [풀, 언덕, 강(공용 객체들)]중에 하나를 가리킨다.
		}
	}
	~CWorld();

	void generateTerrain();
	// const를 사용하는 이유는 공용으로 사용하는 객체를 변화 시키지 않기 위함이다.
	// 만약 객체를 변화시키면 전혀 상관없는 지역의 멥도 함께 변화된다.
	const CTerrain& getTile(int x, int y) const 
	{
		return *m_tiles[x][y]; // m_tiles 하나하나가 주소(초원,언덕,강객체의 주소중 하나)를 보관하고 있으므로 *나& 붙일 필요없이 그냥 리턴하면 됨.
	}

	void drawMap()
	{
		for (int y = 0; y < m_height; y++)
		{
			for (int x = 0; x < m_width; x++)
			{
				// 객체가 가리키고있는 공용의 객체의 지형의 출력
				cout << getTile(x, y).getTexture();
			}
			cout << endl;
		}
	}

};

