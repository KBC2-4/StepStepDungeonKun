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

	struct NEXT_TILE
	{
		short up;
		short down;
	};

	NEXT_TILE next_tiles;

	//次のタイルのGetter
	NEXT_TILE GetNextTile() {
		if (stage[0][0] == 0 && stage[1][0] == 0) {
			next_tiles.up = stage[0][1];
			next_tiles.down = stage[1][1];
		}
		else if (stage[0][0] != 0 || stage[1][0] != 0) {
			next_tiles.up = stage[0][0];
			next_tiles.down = stage[1][0];
		}

		return next_tiles;
	}
};