#include "GameMain.h"

GameMain::GameMain()
{
	bgm = 0;
	background_image = 0;

	player = new Player();
	stage = new Stage();
	
}

GameMain::~GameMain()
{
	delete player;
	delete stage;
}

AbstractScene* GameMain::Update()
{
	player->Update();
	stage->Update();

	return this;

}

void GameMain::Draw() const
{
	player->Draw();
	stage->Draw();
}

