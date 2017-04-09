#ifndef _LOADING_BAR_H_
#define _LOADING_BAR_H_


/*
	@brief : �������ؼ���, ��������Ϊ�������ӽڵ�
	@auther: PengYao
	@time  : 2017/1/18
	@ver   : 1.0
*/
#include "cocos2d.h"
#include "../Helper/yUtils.h"
#include <functional>

USING_NS_CC;



namespace yUtils
{
	typedef std::function<void(void)> LoadingBarCallBack;

	class CLoadingBar : public Node
	{
	protected:
		Sprite* m_spBg;				//����
		Sprite* m_spLoading;		//������
		Rect m_LoadingRect;			//���������������
		float m_fCurLoadingRate;	//��ǰ���صĽ���


		float m_fFinalDelayTime;	//��������������󣬼����������ûص�������Ĭ��Ϊ0.1f
									//Ϊ��ʹ�������ȼ����꣬�ڵ��ûص�����

		bool m_bIsChange;			//�Ƿ�ı�����ֵ
		bool m_bIsFinal;			//�Ƿ�ʼ�ص�

		std::vector<LoadingBarCallBack> m_arrCallBack;

		void RunCallBackFun();

	public:
		static CLoadingBar* create(const std::string& bgFileName, const std::string& loadFileName, const Vec2& offset = Vec2(0, 0));

		bool init(const std::string& bgFileName, const std::string& loadFileName, const Vec2& offset);

		/*
			@brief : ��������init�г�ʼ���ı������ڳ�ʼ���б��н��г�ʼ��
		*/
		CLoadingBar();

		/*
			@brief : ����һ���ص�����������������ȡ���ʱ���ã�
					 ֻ�����һ��
		*/
		void AddCallBack(LoadingBarCallBack callBack);


		/*
			@brief : ��ȡ�����ӳ�ʱ��

		*/
		float GetFinalDelayTime() const
		{
			return m_fFinalDelayTime;
		}

		void SetFinalDelayTime(float dt)
		{
			m_fFinalDelayTime = dt;
		}


		/*
			@brief : ���õ�ǰ���صĽ��ȱ���
			@rate  : ������0 �� 1
		*/
		void SetRate(float rate);

		float GetRate() const
		{
			return m_fCurLoadingRate;
		}

		void update(float dt) override;

		void FinalUpdate(float dt);
	};
}

#endif