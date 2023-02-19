#include "GameMain.h"
#include "DxLib.h"

GameMain::GameMain()
{
	bgm = 0;
	background_image = LoadGraph("Resource/Images/Stage/background.jpg");

	answer_count_font = CreateFontToHandle("���C���I", 100, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	start_count_font = CreateFontToHandle("���C���I", 300, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);

	player = new Player();
	stage = new Stage();
	
	start_time = 240;

	answer_time = 180;
}

GameMain::~GameMain()
{
	delete player;
	delete stage;

	DeleteFontToHandle(start_count_font);
	DeleteFontToHandle(answer_count_font);
}

AbstractScene* GameMain::Update()
{
	if (start_time > 60) {
		start_time--;
	}
	else if (start_time <= 60) {

		//1�^�C��������̐������Ԃ����Z
		if (answer_time > 0) {
			answer_time--;
		}

		//�J�n������̏���
		player->Update();
		stage->Update();
	}

	return this;

}

void GameMain::Draw() const
{
	DrawGraph(0, 0, background_image, FALSE);

	player->Draw();
	stage->Draw();


	//HUD

	////�J�n���̃J�E���g�_�E��	�`��
	//if (start_time > 60) {
	//	DrawFormatStringToHandle(GetDrawCenterX("0", start_count_font), 200, 0x000000, 0xFFFFFF, start_count_font, "%d", start_time / 60);
	//}

	

	//���C�t		�`��
	int life = player->GetLife();
	for (int i = 0; i < life; i++) {
		DrawCircle(50 + i * 50, 30, 10, 0xFFFFF, TRUE);
	}
}

