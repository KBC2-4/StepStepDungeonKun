#pragma once
#include "AbstractScene.h"



class Title :
    public AbstractScene
{
private:

    //�^�C�g�����j���[
    enum class TITLE_MENU
    {
        PLAY,
        END
    };

    //�w�i�p�O���t�B�b�N�n���h��
    int background_image;

    //�^�C�g�����p�t�H���g�n���h��
    int title_font;

    //BGM�p�T�E���h�n���h��
    int bgm;

    //�I��SE�p�T�E���h�n���h��
    int select_se;
    //����SE�p�T�E���h�n���h��
    int decision_se;

    //����Ԋu����
    int input_margin;

    //�e�L�X�g�p�t�H���g�n���h��
    int text_font;

    //�I��p�ϐ�
    int select;

    //�I��p�n���h��
    int select_image;

    TITLE_MENU MenuNo;

public:

    //�R���X�g���N�^
    Title();

    //�f�X�g���N�^
    ~Title();

    //�`��ȊO�̍X�V�����s
    AbstractScene* Update() override;

    //�`��Ɋւ��邱�Ƃ�����
    void Draw() const override;

    /// <summary>
    /// �����̕`�悷��X���W�����S�ɂȂ�X���W���擾����B
    /// </summary>
    /// <param name="string">�`�悷�镶����</param>
    /// <param name="font_handle">�`��Ɏg�p����t�H���g�n���h��(�����͖���0�̏ꍇ�̓f�t�H���g�t�H���g�n���h�����g�p</param>
    /// <param name="margin">������X���W�ɊԊu���󂯂�l</param>
    int GetDrawCenterX(const char* string, int font_handle = 0, int margin = 0) const;
};