#pragma once
// ��������(��������)
// �� ��ü�� ��������(��: �ʿ�)�� ��� ��ü�� �����ؼ� ����� �ؽ��� ������ ������ �ִ�.
// �������� ����ϴ� ��ü (������ ������)
class CTerrain
{
	// �縷, ��, ���, �ʿ� �� �������� �̵������ �ٸ� �� �����Ƿ� �̶��� �� �������� ���밴ü�� �����.
	int m_movementCost; // �� ���������� �̵� ���
	bool m_isWater; // �� �����ΰ�?
	char* m_texture; // ���� �ؽ���
public:
	CTerrain(int movementCost, bool isWater, char* texture):m_movementCost(movementCost), m_isWater(isWater), m_texture(texture) {};
	~CTerrain() {};
	
	int getMovementCost() const { return m_movementCost; }
	bool isWater() const { return m_isWater; }
	const char* getTexture() const { return m_texture; }
};

