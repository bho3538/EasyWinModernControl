#pragma once
#include "CModernControl.h"

namespace EasyWinModernControl {

	typedef BOOL(__stdcall* _TEasyWinModernCtrl_CheckboxCallback)(DWORD id,BOOL isChecked,BOOL Indeterminate);

	class CModernCheckbox : public CModernControl
	{
	public:
		CModernCheckbox(LPCWSTR controlName,DWORD id, LPCWSTR label, BOOL allowIndeterminate);
		~CModernCheckbox();

		BOOL GetStatus(PBOOL isIndeterminate);
		void SetStatus(BOOL isChecked, BOOL isIndeterminate);
		void SetEnableControl(BOOL enable);

		void CallCB(BOOL isChecked, BOOL isIndeterminate);

	protected:
		void SetTemplate();
		void OnAdjustLayout();

	private:
		_TEasyWinModernCtrl_CheckboxCallback _cb = NULL;
		Windows::UI::Xaml::Controls::CheckBox _checkbox;

		DWORD _id = 0;

		PVOID _userData = NULL;
		static LPCWSTR xml;
	};
}
