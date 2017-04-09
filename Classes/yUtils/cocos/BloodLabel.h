#ifndef _BLOOD_LABEL_H_
#define _BLOOD_LABEL_H_

/*
	@brief : Ѫ�����ƿ�
	@auther: PengYao
	@time  : 2017/2/3
	@ver   : 1.0

*/

#include "cocos2d.h"
USING_NS_CC;



/*
	@brief : 
*/
namespace yUtils
{
	class CBloodLabel : public Node
	{
	protected:
		float m_iHp;				//��Ѫ��
		float m_iCurHp;			//��ǰѪ��
		bool m_bIsChangeHp;		//Ѫ���Ƿ񱻸ı�
		Sprite* m_spBg;
		Sprite* m_spBlood;
		Rect m_BloodRect;

	public:

		//ͨ��Ѫ���ĳ��ȣ�Ѫ������ͼƬ��Ѫ��ǰ��ͼƬ��λ�ã���ʼѪ��������һ���µ�Ѫ��
		static CBloodLabel* create(Texture2D* bgTexture, Texture2D* bloodTexture, int initHp, const Vec2& offsetPos = Vec2(0,0));

		static CBloodLabel* create(const std::string& bgFileName, const std::string& bloodFileName, int initHp, const Vec2& offsetPos = Vec2(0, 0));

		bool init(Texture2D* bgTexture, Texture2D* bloodTexture, int initHp, const Vec2& offsetPos);

		void UpdateHp();

		void SetHp(float iHp);

		float GetHp() const
		{
			return m_iHp;
		}

		virtual void update(float dt) override;
	};

}

#endif