#pragma once
#include "AbstractScene.h"
#include "Player.h"
#include "Stage.h"

enum class TILES {
	NONE,
	RED,
	GREEN,
	BLUE,
	YELLOW
};


class GameMain : public AbstractScene
{
public:
	GameMain();
	~GameMain();
	AbstractScene* Update() override;
	void Draw() const override;

private:

	//�X�^�[�g���̃J�E���g�_�E���p�t�H���g�n���h��
	int start_count_font;

	//1�^�C��������̐������ԗp�t�H���g�n���h��
	int answer_count_font;

	int guid_font;

	//�J�n�܂ł̎���
	int start_time;

	//1�^�C��������̐�������
	int answer_time;

	//�i�񂾋���(1��1m)
	int distance;

	enum class Answer {
		unanswered, //����
		wrong,		//�s����
		correct,	//����
	};

	Answer answer;

	//���\�[�X
	int background_image;

	//�T�E���h�n���h��
	int correct_se;
	int wrong_se;
	int background_music;
	int tile_se[4];
	
	//�e�N���X�I�u�W�F�N�g
	Player* player;
	Stage* stage;

};