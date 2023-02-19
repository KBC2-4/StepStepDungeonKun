#pragma once
#include"AbstractScene.h"
#include"DxLib.h"


class Result:
	public AbstractScene
{
private:
	//���U���g���j���[
	enum class RESULT_MENU
	{
		TITLE,
		END
	};

	//�w�i�p�O���t�B�b�N�n���h��
	int background_image;

	//����Ԋu����
	int input_margin;
	int result_font;
	int text_font;
	int flash_number;

	//�I��p�ϐ�
	int select;

	//�I��SE�p�T�E���h�n���h��
	int select_se;

	//�I��p�n���h��
	int select_image;

	RESULT_MENU MenuNo;

public:
	Result();
	~Result();

	AbstractScene* Update() override;
	void Draw() const override;
	int GetDrawCenterX(const char* string, int font_handle = 0, int margin = 0) const;
};

