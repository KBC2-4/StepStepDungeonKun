#include "Title.h"
#include "DxLib.h"
#include "PadInput.h"

//-----------------------------------
// �R���X�g���N�^
//-----------------------------------
Title::Title()
{
	title_font = CreateFontToHandle("UD �f�W�^�� ���ȏ��� N-B", 120, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8, -1, 8);

	background_image = 0;

	bgm = 0;
	select_se = 0;
	decision_se = 0;

	input_margin = 0;
}

//-----------------------------------
// �f�X�g���N�^
//-----------------------------------
Title::~Title()
{
	DeleteFontToHandle(title_font);
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

	return this;
}

//-----------------------------------
// �`��
//-----------------------------------
void Title::Draw()const
{
	DrawStringToHandle(GetDrawCenterX("�^�C�g��", title_font), 100, "�^�C�g��", 0x56F590, title_font, 0xFFFFFF);
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