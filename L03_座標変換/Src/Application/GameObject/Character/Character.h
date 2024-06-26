﻿#pragma once

class Character : public KdGameObject
{
public:
	Character() {}
	virtual ~Character()	override {}

	void Init()				override;
	void Update()			override;
	void DrawLit()			override;
	void DrawSprite()		override;

	//POINT GetMousePos();

	void SetCamera(std::weak_ptr<KdCamera>camera)
	{
		m_wpCamera = camera;
	}

	void SetTerrain(std::weak_ptr<KdGameObject>terrain)
	{
		m_wpTerrain = terrain;
	}

	void SetClickPos(POINT cPos) { m_clickPos = cPos; }

private:
	std::shared_ptr<KdSquarePolygon> m_spPoly = nullptr;
	Math::Vector3 nowPos = m_mWorld.Translation();
	KdTexture m_tex;
	std::weak_ptr<KdCamera>		m_wpCamera;
	//マウス
	POINT m_mousePos;
	POINT m_clickPos;
	POINT GetMousePos();
	float moveSpd;
	Math::Vector3 result;
	//2d.3d変換用
	std::weak_ptr<KdGameObject>m_wpTerrain;

	Math::Vector3 m_TargetPos;
};