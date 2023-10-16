#pragma once
#include <functional>

class Enemy {

public:

	Enemy() = default;
	~Enemy() = default;

	void Update();

private:

	enum class Phase {
		kApproach, // �ڋ߂���
		kFire, // �ˌ�����
		kLeave, // ���E����
		kEnd, // �I���
	};

	void ApproachPhase();
	
	void Fire();
	
	void LeavePhase();

	void EndPhase();

private:

	static void (Enemy::*spFuncTable[])();

	Phase phase_ = Phase::kApproach;
};

