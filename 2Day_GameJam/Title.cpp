#include "Title.h"
#include "DxLib.h"
#include "PadInput.h"
#include"GameMain.h"

//-----------------------------------
// コンストラクタ
//-----------------------------------
Title::Title()
{
	background_image = LoadGraph("images/background_images2.png");
	select_image = LoadGraph("images/select_images.png");

	title_font = CreateFontToHandle("UD デジタル 教科書体 N-B", 90, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8, -1, 8);
	text_font = CreateFontToHandle("UD デジタル 教科書体 N-B", 60, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8, -1, 8);
	
	select_se = 0;

	select = 0;

	bgm = 0;
	select_se = 0;
	decision_se = 0;

	input_margin = 0;
}

//-----------------------------------
// デストラクタ
//-----------------------------------
Title::~Title()
{
	DeleteFontToHandle(title_font);
	DeleteFontToHandle(text_font);
	DeleteGraph(background_image);
}

//-----------------------------------
// 更新
//-----------------------------------
AbstractScene* Title::Update()
{
	//シーン切り替えテスト		デバック
	/*if (PAD_INPUT::GetNowKey(XINPUT_BUTTON_DPAD_RIGHT) && input_margin >= 30)
	{
		input_margin = 0;
		return new GameMain();
	}*/
	

	if (input_margin < 30)
	{
		input_margin++;

		
	}
	//メニューカーソル移動処理
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_DPAD_DOWN && PAD_INPUT::GetPadState() == PAD_STATE::ON) {
		if (++select > 2)select = 0;
	}
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_DPAD_UP && PAD_INPUT::GetPadState() == PAD_STATE::ON) {
		if (--select < 0)select = 2;
	}
	if (select == 0)MenuNo = TITLE_MENU::PLAY;
	if (select == 1)MenuNo = TITLE_MENU::RANKING;
	if (select == 2)MenuNo = TITLE_MENU::END;

	//カーソル決定ボタン
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_A && PAD_INPUT::GetPadState() == PAD_STATE::ON && input_margin >= 30) {
		PlaySoundMem(select_se, DX_PLAYTYPE_BACK, TRUE);
		if (TITLE_MENU::PLAY == MenuNo) {
			return new GameMain();
		}
		if (TITLE_MENU::RANKING == MenuNo) {
			
		}
		if (TITLE_MENU::END == MenuNo) {

		}
	}

	

	return this;
}

//-----------------------------------
// 描画
//-----------------------------------
void Title::Draw()const
{
	DrawGraph(0, 0, background_image, FALSE);
	DrawStringToHandle(GetDrawCenterX("踏め踏めダンジョン君!！", title_font), 100, "踏め踏めダンジョン君!！", 0x56F590, title_font, 0xFFFFFF);
	DrawStringToHandle(GetDrawCenterX("PLAY", text_font), 380, "PLAY", 0xFFFFFF, text_font, 0xFF0000);
	DrawStringToHandle(GetDrawCenterX("PLAY", text_font), 460, "RANKING", 0xFFFFFF, text_font, 0xFF0000);
	DrawStringToHandle(GetDrawCenterX("PLAY", text_font), 540, "END", 0xFFFFFF, text_font, 0xFF0000);
	DrawGraph(GetDrawCenterX("PLAY", text_font) - 80, 380 + select * 80, select_image, FALSE);
	DrawFormatString(0, 0, 0xFFFFFFF, "%d",select);
}

//-----------------------------------
// 画面の中心をとる
//-----------------------------------
int Title::GetDrawCenterX(const char* string, int font_handle, int margin)const
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