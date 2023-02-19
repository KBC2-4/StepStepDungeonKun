#include "Stage.h"
#include"DxLib.h"
#include "PadInput.h"

#define	BOX_ANGLE		20
#define TILE_NUM		4

Stage::Stage()
{
	LoadDivGraph("Resource/Images/Stage/color_tile.png", 4, 2, 2, 25, 25, tile_image + 1);
	tile_image[0] = LoadGraph("Resource/Images/Stage/trans_tile.png");
	**stage = 0;
	next_color = 0;

	InitStage();

}

Stage::~Stage()
{
	for (int i = 0; i < 5; i++) {
		DeleteGraph(tile_image[i]);
	}
}

void Stage::Update()
{

	//Aボタンを押した時
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_A && (PAD_INPUT::GetPadState() == PAD_STATE::ON)) {

		/*CreateStage();*/
	}

}

void Stage::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawBox(0, 450, 1280, 720, 0x000000, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 7; j++)
		{

			int left_x = 0 + j * 200 + (i * -20);
			int right_x = 200 + j * 200 + (i * -20);
			int up_y = 450 + i * 140;
			int down_y = 590 + i * 140;

			//描画する色の画像
			int tile_color;

			tile_color = tile_image[stage[i][j]];
			

			DrawModiGraph(left_x, up_y, right_x, up_y, right_x - BOX_ANGLE, down_y, left_x - BOX_ANGLE, down_y, tile_color, TRUE);
		}
	}


}

void Stage::InitStage()
{
	// ステージをランダムに生成する
	for (int i = 0; i < 2; i++)
	{
		for (int j = 1; j < 7; j++)
		{
			next_tile = GetRand(1);
			stage[next_tile][j] = GetRand(TILE_NUM);

			int reverse = i == 0 ? 0 : 1;
			if (stage[i][j] != 0) {
				stage[reverse][j] = 0;
			}
		}

		//プレイヤーの待機タイルを作成
		stage[i][0] = 0;
		stage[i][0] = 0;
	}

	// 上下のタイルが同じにならないように調整する
	for (int j = 1; j < 7; j++)
	{
		while (stage[0][j] == stage[1][j])
		{
			stage[1][j] = GetRand(TILE_NUM);
		}
	}


}

void Stage::CreateStage()
{
	//タイルを入れ替える
	int w = 0;
	int j = 0;

	DrawFormatString(500, 350, GetColor(255, 0, 0), "%d", stage[0][1]+ stage[1][1]);
	
	for (int i = 0; i < 2; i++)
	{
		w = stage[i][0];
		for (j = 0; j < 7; j++)
		{
			stage[i][j] = stage[i][j + 1];

		}
		stage[i][j - 1] = w;
	}

	//新しい右端のタイルを作成
	for (int i = 0; i < 2; i++) {
		next_tile = GetRand(1);
		stage[next_tile][6] = GetRand(TILE_NUM);

		int reverse = i == 0 ? 0 : 1;
		if (stage[i][6] != 0) {
			stage[reverse][6] = 0;
		}
	}


	// 上下のタイルが同じにならないように調整する
	while (stage[0][6] == stage[1][6])
	{
		stage[1][6] = GetRand(TILE_NUM);
	}

}
