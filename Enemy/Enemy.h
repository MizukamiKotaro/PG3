#pragma once
#include <functional>

class Enemy {

public:

	Enemy() = default;
	~Enemy() = default;

	void Update();

private:

	enum class Phase {
		kApproach, // 接近する
		kFire, // 射撃する
		kLeave, // 離脱する
		kEnd, // 終わり
	};

	void ApproachPhase();
	
	void Fire();
	
	void LeavePhase();

	void EndPhase();

private:

	static void (Enemy::*spFuncTable[])();

	Phase phase_ = Phase::kApproach;
};

