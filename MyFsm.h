#pragma once
#include <iostream>
using namespace std;
#include <list>

enum m_State
{
	Idle,
	Attack,
	Walk,
	Run
};

class IState
{
public:
	virtual void Idle() = 0;
	virtual void Attack() = 0;
	virtual void Walk() = 0;
	virtual void Run() = 0;
};

class IdleState : IState
{
public:
	void Idle()
	{
		cout << "이미 대기중입니다. \n";
	}
	void Attack()
	{
		cout << "공격을 실시합니다. \n";
	}
	void Walk()
	{
		cout << "걷기 시작합니다. \n";
	}
	void Run()
	{
		cout << "뛰기 시작합니다. \n";
	}
};

class AttackState : IState
{
public:
	void Idle()
	{
		cout << "공격을 끝내고 대기합니다. \n";
	}
	void Attack()
	{
		cout << "이미 공격중입니다. \n";
	}
	void Walk()
	{
		cout << "공격 후 걷기 시작합니다. \n";
	}
	void Run()
	{
		cout << "공격 후 뛰기 시작합니다. \n";
	}
};

class WalkState : IState
{
public:
	void Idle()
	{
		cout << "걷는 것을 멈추고 대기합니다. \n";
	}
	void Attack()
	{
		cout << "걷는 것을 멈추고 공격합니다. \n";
	}
	void Walk()
	{
		cout << "이미 걷는 중입니다. \n";
	}
	void Run()
	{
		cout << "걷다가 뛰기 시작합니다. \n";
	}
};

class RunState : IState
{
public:
	void Idle()
	{
		cout << "뛰는 것을 멈추고 대기합니다. \n";
	}
	void Attack()
	{
		cout << "뛰는 것을 멈추고 공격합니다. \n";
	}
	void Walk()
	{
		cout << "뛰다가 걷기 시작합니다. \n";
	}
	void Run()
	{
		cout << "이미 뛰는 중입니다. \n";
	}
};

class Player
{
private:
	IState* states[4];
	IState* currentstate;
public:
	Player()
	{
		states[0] = (IState*) new IdleState();
		states[1] = (IState*) new AttackState();
		states[2] = (IState*) new WalkState();
		states[3] = (IState*) new RunState();
		currentstate = states[0];
	}
	~Player()
	{
		for (int i = 0; i < sizeof(states) / 4; i++)
		{
			delete states[i];
		}
		currentstate = nullptr;
	}
	void ChangeState(m_State state)
	{
		currentstate = states[(int)state];
	}
	IState* GetState()
	{
		return currentstate;
	}

};