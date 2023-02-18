#include "GameMain.h"
#include "DxLib.h"

GameMain::GameMain()
{
	bgm = 0;
	background_image = LoadGraph("Resource/Images/Stage/background.jpg");
	stage = new Stage();
	player = new Player();
	
}

GameMain::~GameMain()
{
	delete player;
	delete stage;
}

AbstractScene* GameMain::Update()
{
	
	if ((stage->Getstage(0, 1) + stage->Getstage(1, 1)) == player->GetButton())
	{
		stage->Update();
		player->Reset();
	}
	player->Update();
	return this;

}

void GameMain::Draw() const
{
	DrawGraph(0, 0, background_image, FALSE);

	stage->Draw();
	player->Draw();
}

