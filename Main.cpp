#include "MyFsm.h"
#include <conio.h>

void main()
{
	Player p;

	int key;

	cout << "�� : ���|�� : �ȱ�|�� : ����|�� : �ٱ�|ENTER : ����\n";

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
				case 72: //��
					p.GetState()->Idle();
					p.ChangeState(m_State::Idle);
					break;
				case 75: //����
					p.GetState()->Attack();
					p.ChangeState(m_State::Attack);
					break;
				case 77: //������
					p.GetState()->Run();
					p.ChangeState(m_State::Run);
					break;
				case 80: //�Ʒ�
					p.GetState()->Walk();
					p.ChangeState(m_State::Walk);
					break;
				}
			}
			else
			{
				if (key == 13) //����
				{
					cout << "�����մϴ�.\n";
					break;
				}
			}
		}
	}
}

