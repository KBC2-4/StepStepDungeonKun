#include "Result.h"
#include "PadInput.h"
#include"Title.h"
#include"End.h"

Result::Result(short score) {
	background_image = LoadGraph("Resource/images/Title&Result/background_images2.png");
	select_image = LoadGraph("Resource/images/Title&Result/select_images.png");
	background_music = LoadSoundMem("Resource/Sounds/BGM/リザルト.mp3");
	result_font = CreateFontToHandle("UD デジタル 教科書体 N-B", 120, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8, -1, 8);
	text_font = CreateFontToHandle("UD デジタル 教科書体 N-B", 60, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8, -1, 8);

	flash_number = 0;
	select = 0;
	this->score = score;
	input_margin = 0;
	

	PlaySoundMem(background_music, DX_PLAYTYPE_LOOP, TRUE);
}

Result::~Result() {
	DeleteFontToHandle(result_font);
	StopSoundMem(background_music);
	DeleteSoundMem(background_music);
}

AbstractScene* Result::Update() {

	if (input_margin < 30)
	{
		input_margin++;
	}

	//メニューカーソル移動処理
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_DPAD_DOWN && PAD_INPUT::GetPadState() == PAD_STATE::ON) {
		if (++select > 1)select = 0;
	}
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_DPAD_UP && PAD_INPUT::GetPadState() == PAD_STATE::ON) {
		if (--select < 0)select = 1;
	}
	if (select == 0)MenuNo = RESULT_MENU::TITLE;
	if (select == 1)MenuNo = RESULT_MENU::END;
	

	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_A && PAD_INPUT::GetPadState() == PAD_STATE::ON && input_margin >= 30) {
		PlaySoundMem(select_se, DX_PLAYTYPE_BACK, TRUE);
		if (RESULT_MENU::TITLE == MenuNo) {
			return new Title();
		}
		if (RESULT_MENU::END == MenuNo) {
			return new End();
		}
	}

	return this;
}

void Result::Draw() const{
	DrawGraph(0, 0, background_image, FALSE);
	DrawStringToHandle(GetDrawCenterX("RESULT", result_font), 100, "RESULT", 0x56F590, result_font, 0xFFFFFF);
	DrawStringToHandle(GetDrawCenterX("TITLE", text_font), 380, "TITLE", 0xFFFFFF, text_font, 0xFF0000);
	DrawStringToHandle(GetDrawCenterX("TITLE", text_font), 460, "END", 0xFFFFFF, text_font, 0xFF0000);
	DrawGraph(GetDrawCenterX("TITLE", text_font) - 80, 380 + select * 80, select_image, TRUE);

	DrawFormatStringToHandle(570, 270, 0xFFFFFF, text_font, "%2dm",score);
}

//-----------------------------------
// 画面の中心をとる
//-----------------------------------
int Result::GetDrawCenterX(const char* string, int font_handle, int margin)const
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