#pragma once

class Player
{
private:
	float player_x; //�v���C���[���W
	float player_y; //�v���C���[���W
	int hp; //�g�����킩��񂯂�
	bool player_mistake; //�v���C���[���~�X��������true
public:

	Player(); //�R���X�g���N�^
	~Player(); //�f�X�g���N�^ //����

	
	void Update(); //�`��ȊO�̏���
	void Draw()const; //�`��̂�
	bool CheckHp();
};

