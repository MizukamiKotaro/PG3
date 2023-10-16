#pragma once
#include <functional>

class Enemy {

public:

	Enemy() = default;
	~Enemy() = default;

	void Update();

private:

	enum class Phase {
		kApproach, // Ú‹ß‚·‚é
		kFire, // ËŒ‚‚·‚é
		kLeave, // —£’E‚·‚é
		kEnd, // I‚í‚è
	};

	void ApproachPhase();
	
	void Fire();
	
	void LeavePhase();

	void EndPhase();

private:

	static void (Enemy::*spFuncTable[])();

	Phase phase_ = Phase::kApproach;
};

