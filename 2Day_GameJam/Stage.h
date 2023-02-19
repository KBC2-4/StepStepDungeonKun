#pragma once
class Stage
{
private:
	int tile_image[5];

	short stage[2][7];

	//次のタイル[0:空, 1:奥, 2:手前, 3:両方]
	short next_tile;

	//次のタイルの色[0:赤, 1:緑, 2:青, 3:黄]
	short next_color;

public:
	Stage();
	~Stage();
	void Update();
	void Draw();
	//ステージを初期化
	void InitStage();
	//一番右端のタイルを作成
	void CreateStage();
};