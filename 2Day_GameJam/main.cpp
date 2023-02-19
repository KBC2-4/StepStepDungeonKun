#include "main.h"
#include "PadInput.h"
#include "SceneManager.h"
#include "Title.h"
#include "GameMain.h"
#include"Result.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	double dNextTime = GetNowCount();

	SetMainWindowText("2Day_GameJam");
	ChangeWindowMode(TRUE);

	SetGraphMode(1280, 720, 32);

	SetAlwaysRunFlag(true);		//常にアクティブにする

	SetOutApplicationLogValidFlag(FALSE);   //ログ出力を無効にする

	ChangeFontType(DX_FONTTYPE_ANTIALIASING_4X4);

	if (DxLib_Init() == -1)return -1;

	SetDrawScreen(DX_SCREEN_BACK);

	//デフォルトの背景色を変更
	SetBackgroundColor(255, 0, 255);

	SceneManager* sceneMng;
	try
	{
		sceneMng = new SceneManager((AbstractScene*)new Result());

	}
	catch (const char* err)
	{
		FILE* fp = NULL;

		DATEDATA data;

		GetDateTime(&data);
		//ファイルオープン
		fopen_s(&fp, "data/ErrLog/ErrLog.txt", "	a");
		//エラーデータの書き込み
		fprintf_s(fp, "%02d年 %02d月 %02d日 %02d時 %02d分 %02d秒 : %sがありません。\n", data.Year, data.Mon, data.Day, data.Hour, data.Min, data.Sec, err);

		return 0;
	}

	// ゲームループ
	while ((ProcessMessage() == 0) && (sceneMng->Update() != nullptr)) {

		//強制終了
		if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_BACK)
		{
			break;
		}

		ClearDrawScreen();		// 画面の初期化
		PAD_INPUT::UpdateKey();	//パッドの入力状態の更新
		sceneMng->Draw();

		ScreenFlip();			// 裏画面の内容を表画面に反映
		SetWindowVisibleFlag(TRUE);// ウィンドウを表示させる

		//フレームレートの設定
		dNextTime += static_cast<double>(1.0 / 60.0 * 1000.0);
		if (dNextTime > GetNowCount()) {
			WaitTimer(static_cast<int>(dNextTime) - GetNowCount());
		}
		else { dNextTime = GetNowCount(); }		//補正


	}

	InitFontToHandle();	//全てのフォントデータを削除
	InitGraph();		//読み込んだ全てのグラフィックデータを削除
	InitSoundMem();		//読み込んだ全てのサウンドデータを削除
	DxLib_End();
	return 0;
}