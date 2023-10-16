#include "Enemy.h"
#include <chrono>
#include <thread>

void Enemy::Update() 
{
	(this->*spFuncTable[static_cast<size_t>(phase_)])();
}

void Enemy::ApproachPhase()
{
	printf("�G���ڋ�\n");

	std::this_thread::sleep_for(std::chrono::milliseconds(4 * 1000));

	phase_ = Phase::kFire;
}

void Enemy::Fire()
{
	printf("�G���ˌ�\n");
	std::this_thread::sleep_for(std::chrono::milliseconds(4 * 1000));
	phase_ = Phase::kLeave;
}

void Enemy::LeavePhase()
{
	printf("�G�����E\n");
	std::this_thread::sleep_for(std::chrono::milliseconds(4 * 1000));
	phase_ = Phase::kEnd;
}

void Enemy::EndPhase()
{
	printf("�I���\n");

	std::this_thread::sleep_for(std::chrono::milliseconds(10 * 1000));
}

void (Enemy::* Enemy::spFuncTable[])() = {
	&Enemy::ApproachPhase,
	&Enemy::Fire,
	&Enemy::LeavePhase,
	&Enemy::EndPhase,
};