#include "UIBase.h"



UIBase::UIBase()
{
}


UIBase::~UIBase()
{
}


SubUIManager::SubUIManager()
{

}

SubUIManager::~SubUIManager()
{

}

bool SubUIManager::FireCommand(string strCommand)
{
	bool bRet = false;
	do 
	{
		for (map<string, UIBase*>::iterator iter = m_mapSubUI.begin(); iter != m_mapSubUI.end(); iter++)
		{
			if (strCommand == (*iter).first)
			{
				(*iter).second->Show();
				break;
			}
		}
	} while (false);
	return bRet;
}

void SubUIManager::AddSubUI(string strCommand, UIBase* pSubUI)
{
	m_mapSubUI[strCommand] = pSubUI;
}

void SubUIManager::DelSubUI(string strCommand)
{
	for (map<string, UIBase*>::iterator iter = m_mapSubUI.begin(); iter != m_mapSubUI.end(); iter++)
	{
		if (strCommand == (*iter).first)
		{
			m_mapSubUI.erase(iter);
			break;
		}
	}
}

MainUI::MainUI()
{

}

MainUI::~MainUI()
{

}

void MainUI::Show()
{
	cout << "-------------------------------------------------------------" << endl;
	cout << "学生管理系统1.0.0" << endl;
	cout << "help:帮助" << endl;
	cout << "add:增加学生信息" << endl;
	cout << "quit:退出" << endl;
	cout << "请输入命令:" << endl;
	GetUserSelect();
	OnCommand(GetUserCommand());
}

//void MainUI::OnCommand()
//{
//	//m_mapSubUI[]
//
//}

void MainUI::OnCommand(string strCommand)
{
	if ("quit" == strCommand)
	{
		return;
	}

	if (!FireCommand(strCommand))
	{
		Show();
	}
}


void AddUI::Show()
{
	cout << "-------------------------------------------------------------" << endl;
	cout << "学生管理系统1.0.0" << endl;
	cout << szSubParent<< "返回" << endl;
	cout << "add:添加" << endl;
	cout << "quit:退出" << endl;
	cout << "请输入命令:" << endl;
	GetUserSelect();
	OnCommand(GetUserCommand());
}

void AddUI::OnCommand(string strCommand)
{

}

