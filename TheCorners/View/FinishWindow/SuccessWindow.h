// ****************************************************************************
//  SuccessWindow.h
//  TODO краткое описание класса
// ****************************************************************************

#pragma once
#include "BaseWindow.h"

namespace View
{

	class SuccessWindow final : public BaseWindow
	{
	public:

		void Init() override;
		void UpdateFinishWindow(bool isSuccess) override;
	};
}
