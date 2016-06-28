#pragma once
// 고유상태(자유문맥)
// 이 객체는 같은지형(예: 초원)의 모든 객체가 공유해서 사용할 텍스쳐 정보를 가지고 있다.
// 공용으로 사용하는 객체 (지형의 공통점)
class CTerrain
{
	// 사막, 물, 언덕, 초원 각 지형마다 이동비용이 다를 수 있으므로 이때는 각 지형마다 공용객체를 만든다.
	int m_movementCost; // 각 지형마다의 이동 비용
	bool m_isWater; // 물 지역인가?
	char* m_texture; // 지형 텍스쳐
public:
	CTerrain(int movementCost, bool isWater, char* texture):m_movementCost(movementCost), m_isWater(isWater), m_texture(texture) {};
	~CTerrain() {};
	
	int getMovementCost() const { return m_movementCost; }
	bool isWater() const { return m_isWater; }
	const char* getTexture() const { return m_texture; }
};

