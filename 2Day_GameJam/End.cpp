#include"End.h"

End::End() {
	end_font = CreateFontToHandle("UD デジタル 教科書体 N-B", 70, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8, -1, 8);
	end_time = 3500;
}

End::~End() {
	DeleteFontToHandle(end_font);
}


AbstractScene* End::Update() {
	WaitTimer(end_time);

	return nullptr;
}

void End::Draw() const{
	DrawStringToHandle(GetDrawCenterX("Thank you for playing !!", end_font), 300, "Thank you for playing !!", 0xFF0000, end_font, 0xFFFFFF);
}

//-----------------------------------
// 画面の中心をとる
//-----------------------------------
int End::GetDrawCenterX(const char* string, int font_handle, int margin)const
{

	//画面幅
	const int screenX = 1280;

	if (margin >= screenX || margin <= -screenX)
	{
		margin = 0;
	}

	if (font_handle == 0)
	{
		font_handle = DX_DEFAULT_FONT_HANDLE;
	}


	const int w = screenX / 2 + margin - (GetDrawFormatStringWidthToHandle(font_handle, string) / 2);
	return w;
}