#include "MyFsm.h"
#include <conio.h>

void main()
{
	Player p;

	int key;

	cout << "↑ : 대기|↓ : 걷기|← : 공격|→ : 뛰기|ENTER : 종료\n";

	while (1)
	{
		if (_kbhit())
		{
			key = _getch();
			if (key == 224)
			{
				key = _getch();
				switch (key)
				{
				case 72: //위
					p.GetState()->Idle();
					p.ChangeState(m_State::Idle);
					break;
				case 75: //왼쪽
					p.GetState()->Attack();
					p.ChangeState(m_State::Attack);
					break;
				case 77: //오른쪽
					p.GetState()->Run();
					p.ChangeState(m_State::Run);
					break;
				case 80: //아래
					p.GetState()->Walk();
					p.ChangeState(m_State::Walk);
					break;
				}
			}
			else
			{
				if (key == 13) //엔터
				{
					cout << "종료합니다.\n";
					break;
				}
			}
		}
	}
}

