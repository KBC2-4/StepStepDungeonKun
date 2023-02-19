#pragma once
class Stage
{
private:
	int tile_image[5];

	short stage[2][7];

	//���̃^�C��[0:��, 1:��, 2:��O, 3:����]
	short next_tile;

	//���̃^�C���̐F[0:��, 1:��, 2:��, 3:��]
	short next_color;

public:
	Stage();
	~Stage();
	void Update();
	void Draw();
	//�X�e�[�W��������
	void InitStage();
	//��ԉE�[�̃^�C�����쐬
	void CreateStage();

	struct NEXT_TILE
	{
		short up;
		short down;
	};

	NEXT_TILE next_tiles;

	//���̃^�C����Getter
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