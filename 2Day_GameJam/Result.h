#pragma once
#include"AbstractScene.h"
#include"DxLib.h"


class Result:
	public AbstractScene
{
private:
	//リザルトメニュー
	enum class RESULT_MENU
	{
		TITLE,
		END
	};

	//背景用グラフィックハンドル
	int background_image;

	//操作間隔時間
	int input_margin;
	int result_font;
	int text_font;
	int flash_number;

	//選択用変数
	int select;

	//選択SE用サウンドハンドル
	int select_se;

	//選択用ハンドル
	int select_image;

	RESULT_MENU MenuNo;

public:
	Result();
	~Result();

	AbstractScene* Update() override;
	void Draw() const override;
	int GetDrawCenterX(const char* string, int font_handle = 0, int margin = 0) const;
};

