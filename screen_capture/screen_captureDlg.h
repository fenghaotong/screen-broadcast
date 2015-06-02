
// screen_captureDlg.h : ͷ�ļ�
//

#pragma once
#include <string>
#include "afxwin.h"

// Cscreen_captureDlg �Ի���
class Cscreen_captureDlg : public CDialog
{
// ����
public:
	Cscreen_captureDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SCREEN_CAPTURE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

public:
	CWinThread *pThreadffmpeg;

	int charlist_size;
	char** charlist;
// ʵ��
protected:
	HICON m_hIcon;



	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonChooseRegion();
	afx_msg void OnBnClickedButtonStartTransfer();
	afx_msg void OnBnClickedButtonStopTransfer();

	//���ý��ȵ���Ϣ��Ӧ����
	//Callback of Set Progress Message
	LRESULT OnSetErrorMsg(WPARAM wParam, LPARAM lParam );

private:
	void init_audio_device_vector();
	void init_edit_and_member();
	void get_member_from_edit();
	void disable_edit_and_button();
	void enable_edit_and_button();

private:
	//����Ƶ�����װ�������
	int crop_x;
	int crop_y;
	int crop_width;
	int crop_height;
	std::string video_codec;
	std::string video_profile;
	int    video_fps;
	std::string video_rate;
	int    video_quality;

	std::string audio_device_name;
	std::string audio_codec;
	int    audio_chan;
	int	   audio_kbps;
	int	   audio_sample;

	std::string mux_type;
	std::string rtmp_url;

private:
	CComboBox combobox_video_codec;
	CComboBox combobox_video_profile;
	CComboBox combobox_video_rate;
	CEdit edit_video_quality;
	CEdit edit_video_fps;
	CComboBox combobox_audio_device;
	CComboBox combobox_audio_codec;
	CEdit edit_audio_chan;
	CEdit edit_audio_kbps;
	CEdit edit_audio_sample;
	CComboBox combobox_mux;
	CEdit edit_rtmp_url;
public:
	afx_msg void OnBnClickedButtonSavefile();
};
