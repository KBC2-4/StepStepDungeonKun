#include "Stage.h"
#include"DxLib.h"
#include "PadInput.h"

#define	BOX_ANGLE		20

Stage::Stage()
{
	LoadDivGraph("Resource/Images/Stage/color_tile.png", 4, 2, 2, 25, 25, tile_image + 1);
	trans_tile_image = LoadGraph("Resource/Images/Stage/trans_tile.png");
	**stage = 0;
	next_color = 0;



	/*for (int i = 0; i < 2; i++)
	{*/
		for (int j = 0; j < 7; j++)
		{
			next_tile = GetRand(1);
			stage[next_tile][j] = GetRand(3);


			//奥側のタイルが空白だった場合、空白以外を再度取得する
			//if (i == 2) {
			//	if (stage[0][j] == 0) {
			//		--j;
			//	}
			//}

			while (stage[0][j] == stage[1][j])
			{
				j--;
			}
		}
	//}
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

	//Aボタンを押した時
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_A && (PAD_INPUT::GetPadState() == PAD_STATE::ON)) {


		//タイルを入れ替える
		int w = 0;
		int j = 0;

		for (int i = 0; i < 2; i++)
		{
			w = stage[i][0];
			for (j = 0; j < 7; j++)
			{
				stage[i][j] = stage[i][j + 1];
			
			}
			stage[i][j - 1] = w;
		}

		for (int i = 0; i < 2; i++) {
			next_tile = GetRand(1);
			stage[i][6] = GetRand(3);
		}

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

			if (stage[i][j] != 0) {
				//[0:空, 1:奥, 2:手前, 3:両方]
				tile_color = tile_image[stage[i][j]];
			}
			else {
				//透明
				tile_color = trans_tile_image;
			}


			DrawModiGraph(left_x, up_y, right_x, up_y, right_x - BOX_ANGLE, down_y, left_x - BOX_ANGLE, down_y, tile_color, TRUE);
		}
	}


}
