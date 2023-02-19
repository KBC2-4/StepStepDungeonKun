#include "Title.h"
#include "DxLib.h"
#include "PadInput.h"
#include"GameMain.h"
#include"End.h"

//-----------------------------------
// �R���X�g���N�^
//-----------------------------------
Title::Title()
{
	background_image = LoadGraph("Resource/images/Title&Result/background_images2.png");
	select_image = LoadGraph("Resource/images/Title&Result/select_images.png");
	background_music = LoadSoundMem("Resource/Sounds/BGM/�^�C�g��.mp3");
	title_font = CreateFontToHandle("UD �f�W�^�� ���ȏ��� N-B", 90, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8, -1, 8);
	text_font = CreateFontToHandle("UD �f�W�^�� ���ȏ��� N-B", 60, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8, -1, 8);
	
	select_se = 0;

	select = 0;

	bgm = 0;
	select_se = 0;
	decision_se = 0;

	input_margin = 0;

	MenuNo = TITLE_MENU::PLAY;

	PlaySoundMem(background_music, DX_PLAYTYPE_LOOP, TRUE);
}

//-----------------------------------
// �f�X�g���N�^
//-----------------------------------
Title::~Title()
{
	DeleteFontToHandle(title_font);
	DeleteFontToHandle(text_font);
	DeleteGraph(background_image);
	StopSoundMem(background_music);
	DeleteSoundMem(background_music);
}

//-----------------------------------
// �X�V
//-----------------------------------
AbstractScene* Title::Update()
{
	//�V�[���؂�ւ��e�X�g		�f�o�b�N
	/*if (PAD_INPUT::GetNowKey(XINPUT_BUTTON_DPAD_RIGHT) && input_margin >= 30)
	{
		input_margin = 0;
		return new GameMain();
	}*/
	

	if (input_margin < 30)
	{
		input_margin++;

		
	}
	//���j���[�J�[�\���ړ�����
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_DPAD_DOWN && PAD_INPUT::GetPadState() == PAD_STATE::ON) {
		if (++select > 1)select = 0;
	}
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_DPAD_UP && PAD_INPUT::GetPadState() == PAD_STATE::ON) {
		if (--select < 0)select = 1;
	}
	if (select == 0)MenuNo = TITLE_MENU::PLAY;
	if (select == 1)MenuNo = TITLE_MENU::END;
	

	//�J�[�\������{�^��
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_A && PAD_INPUT::GetPadState() == PAD_STATE::ON && input_margin >= 30) {
		PlaySoundMem(select_se, DX_PLAYTYPE_BACK, TRUE);
		if (TITLE_MENU::PLAY == MenuNo) {
			return new GameMain();
		}
		if (TITLE_MENU::END == MenuNo) {
			return new End();
		}
	}

	

	return this;
}

//-----------------------------------
// �`��
//-----------------------------------
void Title::Draw()const
{
	DrawGraph(0, 0, background_image, FALSE);
	DrawStringToHandle(GetDrawCenterX("���ߓ��߃_���W�����N!�I", title_font), 100, "���ߓ��߃_���W�����N!�I", 0x56F590, title_font, 0xFFFFFF);
	DrawStringToHandle(GetDrawCenterX("PLAY", text_font), 380, "PLAY", 0xFFFFFF, text_font, 0xFF0000);
	DrawStringToHandle(GetDrawCenterX("PLAY", text_font), 460, "END", 0xFFFFFF, text_font, 0xFF0000);
	DrawGraph(GetDrawCenterX("PLAY", text_font) - 80, 380 + select * 80, select_image, TRUE);
}

//-----------------------------------
// ��ʂ̒��S���Ƃ�
//-----------------------------------
int Title::GetDrawCenterX(const char* string, int font_handle, int margin)const
{

	//��ʕ�
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