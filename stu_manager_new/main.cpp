#include "CMD.h"
#include "UIBase.h"

void main()
{
	MainUI* pMain = new MainUI;
	AddUI* pAdd = new AddUI(pMain);
	pMain->AddSubUI(szMainAddStu, pAdd);
	pMain->Show();
	delete pMain;
}
