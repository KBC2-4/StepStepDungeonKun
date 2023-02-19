#pragma once

class Player
{
private:
	float player_x; //�v���C���[���W
	float player_y; //�v���C���[���W
	int hp; //�g�����킩��񂯂�
	int time;
	int button; //�����ŊǗ����܂��A
	int num;
	int player_images[4];
	int images_num;
	bool player_mistake; //�v���C���[���~�X��������true
	bool button_flg; 
	bool a_button; //a�{�^���̃t���O
	bool b_button; //b�{�^���̃t���O
	bool y_button; //y�{�^���̃t���O
	bool x_button; //x�{�^���̃t���O
	
public:

	Player(); //�R���X�g���N�^
	~Player(); //�f�X�g���N�^ //����

	void Update(); //�`��ȊO�̏���
	void Draw()const; //�`��̂�ko
	int Getnum();
	bool CheckHp(); //HP���`�F�b�N����
	void Reset();
	int  GetButton(); // 1,A�{�^�� 2,B�{�^��  3,Y�{�^�� 4,X�{�^��
	void SetMistake(bool a); //�t���O��ݒ肷��
	void SetImagesNum(int a);

};

