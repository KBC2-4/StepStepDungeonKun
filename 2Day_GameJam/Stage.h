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
};