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
		cout << "�̹� ������Դϴ�. \n";
	}
	void Attack()
	{
		cout << "������ �ǽ��մϴ�. \n";
	}
	void Walk()
	{
		cout << "�ȱ� �����մϴ�. \n";
	}
	void Run()
	{
		cout << "�ٱ� �����մϴ�. \n";
	}
};

class AttackState : IState
{
public:
	void Idle()
	{
		cout << "������ ������ ����մϴ�. \n";
	}
	void Attack()
	{
		cout << "�̹� �������Դϴ�. \n";
	}
	void Walk()
	{
		cout << "���� �� �ȱ� �����մϴ�. \n";
	}
	void Run()
	{
		cout << "���� �� �ٱ� �����մϴ�. \n";
	}
};

class WalkState : IState
{
public:
	void Idle()
	{
		cout << "�ȴ� ���� ���߰� ����մϴ�. \n";
	}
	void Attack()
	{
		cout << "�ȴ� ���� ���߰� �����մϴ�. \n";
	}
	void Walk()
	{
		cout << "�̹� �ȴ� ���Դϴ�. \n";
	}
	void Run()
	{
		cout << "�ȴٰ� �ٱ� �����մϴ�. \n";
	}
};

class RunState : IState
{
public:
	void Idle()
	{
		cout << "�ٴ� ���� ���߰� ����մϴ�. \n";
	}
	void Attack()
	{
		cout << "�ٴ� ���� ���߰� �����մϴ�. \n";
	}
	void Walk()
	{
		cout << "�ٴٰ� �ȱ� �����մϴ�. \n";
	}
	void Run()
	{
		cout << "�̹� �ٴ� ���Դϴ�. \n";
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