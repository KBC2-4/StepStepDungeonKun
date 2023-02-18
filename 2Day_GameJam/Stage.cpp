#include "Stage.h"
#include"DxLib.h"

Stage::Stage()
{
	LoadDivGraph("Resource/Images/Stage/color_tile.png", 4, 2, 2, 1, 1, tile_image);
	**stage = 0;
	next_tile = 0;
	next_color = 0;
}

Stage::~Stage()
{

}

void Stage::Update()
{
	next_tile = GetRand(1);
	next_color = GetRand(3);
	//DrawModiGraph(40,500,120,500,100,540,20,540,)
}

void Stage::Draw()
{

}
