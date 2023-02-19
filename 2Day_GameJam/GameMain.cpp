#include "GameMain.h"
#include "DxLib.h"

GameMain::GameMain()
{
	bgm = 0;
	background_image = LoadGraph("Resource/Images/Stage/background.jpg");

	count_font = CreateFontToHandle("メイリオ", 300, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);

	player = new Player();
	stage = new Stage();
	
	start_time = 240;

	answer = 0;
}

GameMain::~GameMain()
{
	delete player;
	delete stage;

	DeleteFontToHandle(count_font);
}

AbstractScene* GameMain::Update()
{
	if (start_time > 60) {
		start_time--;
	}
	else if (start_time <= 60) {

		//開始した後の処理
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

	//if (start_time > 60) {
	//	DrawFormatStringToHandle(GetDrawCenterX("0", count_font), 200, 0x000000, 0xFFFFFF, count_font, "%d", start_time / 60);
	//}
}

