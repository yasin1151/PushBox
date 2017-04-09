#ifndef _SHOW_WITH_RATE_OBJ_H_
#define _SHOW_WITH_RATE_OBJ_H_

/*
	@brief : ��д��Ѫ����ͽ�������������Ļ���
	@auther: PengYao
	@time  : 2017/2/9
	@ver   : 1.0
*/
#include "cocos2d.h"
USING_NS_CC;

namespace yUtils
{
	typedef std::function<void(void)> NoParamCallBack;


	class CShowWithRateObj : public Node
	{
	protected:
		Sprite* m_spBg;				//����
		Sprite* m_spRateStripe;		//��Ҫ����һ��������ʾ����
		Size m_sStripe;				//���ĳ�ʼ��С

		std::vector<NoParamCallBack> m_arrNoParamFun;		//�޲λص�����������

		/*
			@brief : �������еĻص�����
		*/
		void CallBack();

	public:
		/*
			@brief : ��ʼ�����е��������飬����������Ϊ��ǰ�ڵ���ӽڵ㣬��������Ϊ�����ڵ���ӽڵ�
			@param bgTexture : ��������
			@param stripeTexture : ������
			@param offset : �������ڱ��������ϵ�ƫ��ֵ��Ĭ��Ϊ(0, 0)
		*/
		bool init(Texture2D* bgTexture, Texture2D* stripeTexture, const Vec2& offset = Vec2(0, 0));

		/*
			@brief : ����޲λص�����
			@param callBack : �ص�����
		*/
		void AddCallBack(NoParamCallBack& callBack);


		/*
			Getter
		*/
		Size GetStripeSize() const
		{
			return m_sStripe;
		}

		Sprite* GetBgSprite() const
		{
			return m_spBg;
		}

		Sprite* GetStripeSprite() const
		{
			return m_spRateStripe;
		}
	};
}

#endif