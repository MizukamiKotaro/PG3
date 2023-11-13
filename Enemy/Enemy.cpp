#include "Enemy.h"
#include <chrono>
#include <thread>

void Enemy::Update() 
{
	(this->*spFuncTable[static_cast<size_t>(phase_)])();
}

void Enemy::ApproachPhase()
{
	printf("敵が接近\n");

	std::this_thread::sleep_for(std::chrono::milliseconds(4 * 1000));

	phase_ = Phase::kFire;
}

void Enemy::Fire()
{
	printf("敵が射撃\n");
	std::this_thread::sleep_for(std::chrono::milliseconds(4 * 1000));
	phase_ = Phase::kLeave;
}

void Enemy::LeavePhase()
{
	printf("敵が離脱\n");
	std::this_thread::sleep_for(std::chrono::milliseconds(4 * 1000));
	phase_ = Phase::kEnd;
}

void Enemy::EndPhase()
{
	printf("終わり\n");

	std::this_thread::sleep_for(std::chrono::milliseconds(10 * 1000));
}

void (Enemy::* Enemy::spFuncTable[])() = {
	&Enemy::ApproachPhase,
	&Enemy::Fire,
	&Enemy::LeavePhase,
	&Enemy::EndPhase,
};