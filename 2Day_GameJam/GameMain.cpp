#include "GameMain.h"

GameMain::GameMain()
{
	bgm = 0;
	background_image = 0;

	player = new Player();
	stage = new Stage();
	
	start_time = 180;

	answer = 0;
}

GameMain::~GameMain()
{
	delete player;
	delete stage;
}

AbstractScene* GameMain::Update()
{
	if (start_time > 0) {
		start_time--;
	}
	else if (start_time <= 0) {

		//ŠJŽn‚µ‚½Œã‚Ìˆ—

	}

	

	player->Update();
	stage->Update();

	return this;

}

void GameMain::Draw() const
{
	player->Draw();
	stage->Draw();
}

