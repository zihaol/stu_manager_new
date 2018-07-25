#pragma once
#include "CMD.h"
#include <string>
#include <map>
#include <iostream>
using namespace std;


class UIBase;
class SubUIManager
{
public:
	SubUIManager();
	~SubUIManager();
	void AddSubUI(string strCommand, UIBase* pSubUI);
	void DelSubUI(string strCommand);
	bool FireCommand(string strCommand);
private:
	map<string, UIBase*> m_mapSubUI;
};


class UIBase
{
public:
	UIBase();
	~UIBase();
	virtual void GetUserSelect() { cin >> m_strCommand; }
	virtual string GetUserCommand() { return m_strCommand; }
	virtual void Show() = 0;
	//virtual void OnCommand() = 0;
	virtual void OnCommand(string strCommand) = 0;
private:
	string m_strCommand;
};

class MainUI : public UIBase, public SubUIManager
{
public:
	MainUI();
	~MainUI();
	virtual void Show();
	virtual void OnCommand(string strCommand);
private:

};

class AddUI : public UIBase, public SubUIManager
{
public:
	AddUI(UIBase* pParent) { AddSubUI(szSubParent, pParent); }
	~AddUI() {}
	virtual void Show();
	virtual void OnCommand(string strCommand);
};


