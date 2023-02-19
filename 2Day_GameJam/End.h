#pragma once
#include"AbstractScene.h"
#include"DxLib.h"

class End :
	public AbstractScene {
private:
	//�G���h�p�t�H���g�n���h��
	int end_font;

	//�G���h��ʂ��I�����܂ł̎���
	int end_time;

public:
	End();
	~End();

	//�`��ȊO�̍X�V�����s
	AbstractScene* Update() override;

	//�`��Ɋւ��邱�Ƃ�����
	void Draw() const override;

	int GetDrawCenterX(const char* string, int font_handle = 0, int margin = 0) const;
};