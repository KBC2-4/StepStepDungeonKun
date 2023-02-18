#include "Stage.h"
#include"DxLib.h"
#include "PadInput.h"

#define	BOX_ANGLE		20

Stage::Stage()
{
	LoadDivGraph("Resource/Images/Stage/color_tile.png", 4, 2, 2, 25, 25, tile_image);
	trans_tile_image = LoadGraph("Resource/Images/Stage/trans_tile.png");
	**stage = 0;
	next_tile = GetRand(1);
	next_color = 0;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			stage[i][j] = GetRand(3);
			if (i == 1) //”z—ñ‚Ì[1][?]‚¾‚Á‚½‚ç 
			{
				if (stage[i - 1][j] == stage[i][j])//”z—ñ‚Ì‚O—ñA‚P—ñ‚ð”äŠrA“¯‚¶‚¾‚Á‚½‚ç
				{
					do
					{
						stage[i][j] = GetRand(3);
					} while (stage[i - 1][j] == stage[i][j]); //“¯‚¶F‚É‚È‚ç‚È‚¢‚æ‚¤‚É

				}
			}
		}
	}
}

Stage::~Stage()
{
	for (int i = 0; i < 4; i++) {
		DeleteGraph(tile_image[i]);
	}


	DeleteGraph(trans_tile_image);
}

void Stage::Update()
{
	
	//ƒ^ƒCƒ‹‚ð“ü‚ê‘Ö‚¦‚é
	int w = 0;
	int j = 0;

	for (int i = 0; i < 2; i++)
	{
		w = stage[i][0];
		for (j = 0; j < 6; j++)
		{
			stage[i][j] = stage[i][j + 1];

		}
		stage[i][j - 1] = w;
	}


	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			//next_tile = GetRand(1);
			//stage[next_tile][j] = GetRand(3);
		}
	}


}

void Stage::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawBox(0, 450, 1280, 590, 0x000000, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawFormatString(200, 300, GetColor(255, 0, 0), "%d", stage[1][1]);
	DrawFormatString(200, 400, GetColor(255, 0, 0), "%d", stage[0][0]);

	DrawFormatString(500, 350, GetColor(255, 0, 0), "%d", stage[0][1]+ stage[1][1]);
	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 7; j++)
		{

			int left_x = 0 + j * 200 + (i * -20);
			int right_x = 200 + j * 200 + (i * -20);
			int up_y = 450 + i * 140;
			int down_y = 590 + i * 140;

			//•`‰æ‚·‚éF‚Ì‰æ‘œ
			int tile_color;

			if (j != 0) {
				tile_color = tile_image[stage[i][j]];
			}
			else {
				tile_color = trans_tile_image;
			}


			DrawModiGraph(left_x, up_y, right_x, up_y, right_x - BOX_ANGLE, down_y, left_x - BOX_ANGLE, down_y, tile_color, TRUE);
		}
	}


}

short Stage::Getstage(int a, int b)
{
	return stage[a][b];
}