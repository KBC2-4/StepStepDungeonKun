#pragma once
#include"AbstractScene.h"
#include"DxLib.h"

class End :
	public AbstractScene {
private:
	//エンド用フォントハンドル
	int end_font;

	//エンド画面が終了すまでの時間
	int end_time;

public:
	End();
	~End();

	//描画以外の更新を実行
	AbstractScene* Update() override;

	//描画に関することを実装
	void Draw() const override;

	int GetDrawCenterX(const char* string, int font_handle = 0, int margin = 0) const;
};