#ifndef _SCROLL_BG_H_
#define _SCROLL_BG_H_

/*
	@brief : �ҵĹ��ᱳ����
	@auther: PengYao
	@time  : 2017/1/19
	@ver   : 1.0
*/

#include "cocos2d.h"
#include <deque>

USING_NS_CC;

namespace yUtils
{
	class CScrollBg : public Node
	{
	protected:
		Vec2 m_vSpeed;		//�������ٶȣ�����

		Size m_sBlankSize;	//����ͼ�ļ����С

		std::deque<Sprite*> m_queueOfSprite;

		bool m_bIsStart;

		/*
			@brief : ���õ�ǰ���нڵ��λ��
					 ����Ҫ��������������
			@param initPos : ��һ���ڵ�ĳ�ʼλ��
							����0,0ΪĬ����Ļ��������
		*/
		void ResetPosition(const Vec2& initPos = Vec2::ZERO);


	public:
		CScrollBg():m_bIsStart(false){}

		static CScrollBg* create(const Vec2& vSpeed);

		bool init(const Vec2& vSpeed);


		/*
			@brief : �����еĳ������뱾��󣬵��ø÷�����ʼ����
			@param initPos : ��һ�������ĳ�ʼλ��

		*/
		bool Start(const Vec2& initPos = Vec2::ZERO);

		/*
			@brief : Ĭ�ϵ���������
		*/
		void update(float dt) override;
		
		/*
			@brief : ֧�ֶ�̬������ͼƬ
			@param spBg �µ�ͼƬ
		*/
		void AddNewBg(Sprite* spBg);

		/*
			@brief : ֧�ֶ�̬ɾ��ͼƬ
			@param spBg ��Ҫɾ����ͼƬ�ڵ�
		*/
		void RemoveBg(Sprite* spBg);


		/*
			@brief : ��ȡ��ǰ���ڵ�һλ�Ľڵ�
		*/
		Sprite* GetFrontNode() const;

		/*
			@brief : ��ȡ����ı���ͼƬ�ĸ���
		*/
		int GetBgSize() const;

		/*
			@brief : ��ͣ��������
		*/
		void Pause();


		/*
			@brief : �ָ���������
		*/
		void Resume();



		/*
			Getter and Setter
		*/
		void SetSpeed(const Vec2& speed)
		{
			m_vSpeed = speed;
		}

		Vec2 GetSpeed() const
		{
			return m_vSpeed;
		}

		/*
		@brief : ��ȡ����ͼƬ֮��ļ����С��Ĭ��Ϊ(0,0)
		*/
		Size GetBlankSize() const
		{
			return m_sBlankSize;
		}

		/*
		@brief : ��������ͼƬ֮��ļ����С
		@param blankSize : �����С
		*/
		void SetBlankSize(const Size& blankSize)
		{
			m_sBlankSize = blankSize;
		}
	};
}

#endif