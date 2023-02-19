#include "GameMain.h"
#include "DxLib.h"
#include "Result.h"

#define ANSWER_TIME		180

GameMain::GameMain()
{
	wrong_se = LoadSoundMem("Resource/Sounds/wrong.mp3");
	correct_se = LoadSoundMem("Resource/Sounds/correct.mp3");
	background_music = LoadSoundMem("Resource/Sounds/bgm.mp3");

	background_image = LoadGraph("Resource/Images/Stage/background.jpg");

	answer_count_font = CreateFontToHandle("メイリオ", 100, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	start_count_font = CreateFontToHandle("メイリオ", 300, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);

	player = new Player();
	stage = new Stage();

	start_time = 240;
	distance = 0;

	answer_time = ANSWER_TIME;

	answer = Answer::unanswered;

	PlaySoundMem(background_music, DX_PLAYTYPE_LOOP, TRUE);
}

GameMain::~GameMain()
{
	delete player;
	delete stage;

	DeleteFontToHandle(start_count_font);
	DeleteFontToHandle(answer_count_font);

	DeleteSoundMem(wrong_se);
	DeleteSoundMem(correct_se);
	StopSoundMem(background_music);
	DeleteSoundMem(background_music);
}

AbstractScene* GameMain::Update()
{
	if (start_time > 60) {
		start_time--;
	}
	else if (start_time <= 60) {

		//1タイル当たりの制限時間を減算
		if (answer_time > 0) {
			answer_time--;
		}

		//開始した後の処理
	player->Update();
	stage->Update();


	short up_tile = stage->GetNextTile().up;
	short down_tile = stage->GetNextTile().down;

	short tile_count = 0;
	for (int i = 0; i < 2; i++) {
		if (up_tile == 0 || down_tile == 0) { tile_count++; }
	}

	if (player->Getnum() == tile_count)
	{
		if ((up_tile + down_tile) == player->GetButton())
		{
			player->Reset();
			player->SetImagesNum(1);
			stage->CreateStage();

			answer = Answer::correct;
			PlaySoundMem(correct_se, DX_PLAYTYPE_BACK, TRUE);
		}
		else
		{
			player->SetMistake(true);
			player->Reset();

			answer = Answer::wrong;
			PlaySoundMem(wrong_se, DX_PLAYTYPE_BACK, TRUE);
		}

	}


	if (answer != Answer::unanswered) {
		answer_time = ANSWER_TIME;

		answer = Answer::unanswered;
	}

		/*	short is_a_button = player->GetButton(1);
			short is_b_button = player->GetButton(2);
			short is_y_button = player->GetButton(3);
			short is_x_button = player->GetButton(4);*/

		//for (int i = 1; i < 5; i++) {

		//	short is_button = 0;
		//	short is_buttonw = FALSE;
		//	printfDx("%d", is_button);

		//	if (is_buttonw == TRUE) {
		//		is_button = i;
		//	}


		//	if (up_tile == is_button || down_tile == is_button) {

		//		stage->CreateStage();
		//		answer_time = 0;
		//	}
		//	else {
		//		player->SetMistake(true);

		//		answer_time = 0;
		//	}
		//}


	}



	//プレイヤーのライフがなくなった時
	if (player->GetLife() <= 0) { return new Result(); }

	return this;
}

void GameMain::Draw() const
{
	DrawGraph(0, 0, background_image, FALSE);

	stage->Draw();
	player->Draw();


	//HUD

	//開始時のカウントダウン	描画
	if (start_time > 60) {
		DrawFormatString2ToHandle(GetDrawCenterX("0", start_count_font), 200, 0x000000, 0xFFFFFF, start_count_font, "%d", start_time / 60);
	}

	//1タイル当たりの制限時間	描画
	if (answer_time > 60) { DrawFormatString2ToHandle(50, 80, 0x000000, 0xFFFFFF, answer_count_font, "%d", (answer_time / 60)); }
	DrawFormatString2ToHandle(1050, 80, 0x000000, 0xFFFFFF, answer_count_font, "%2dm", distance);

	//ライフ		描画
	int life = player->GetLife();
	for (int i = 0; i < life; i++) {
		DrawCircle(50 + i * 50, 30, 10, 0xFFFFF, TRUE);
	}
}

