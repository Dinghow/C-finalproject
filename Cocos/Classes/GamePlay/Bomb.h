#ifndef _BOMB_H_
#define _BOMB_H_


#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include <string>
USING_NS_CC;

class cBomb:public cocos2d::Layer
{
private:
	int m_IdleTime;
	int m_BombRange;
	float m_CurrentTime;
	bool m_Dropped;
	CCPoint m_BombPosition;
	CCPoint m_TBombPosition;
	cocos2d::CCTMXTiledMap* m_Map;
	cocos2d::CCSprite* m_Role1;
	enum dire {
		UP = 0,
		RIGHT,
		DOWN,
		LEFT,
	};
	CCPoint points[4] = { ccp(0,-1),ccp(1,0),ccp(0,1),ccp(-1,0) };
	Vector<Sprite*> m_AllSprites;
public:
	cBomb(int bombRange = 1, int idleTime = 3) :m_IdleTime(idleTime),
		m_BombRange(bombRange), m_CurrentTime(0.0), m_Dropped(false),m_Map(nullptr),m_Role1(nullptr)
	{
		cocos2d::Layer::onEnter();
	}
	void getMap(cocos2d::CCTMXTiledMap* map)
	{
		m_Map = map;
	}
	void getRole(cocos2d::CCSprite* role)
	{
		m_Role1 = role;
	}
	bool droppedOrNot()
	{
		return m_Dropped;
	}

	//����ը���ı�ը��Χ
	void addBombRange() { ++m_BombRange; }
	//��ȡը�����õ������
	CCPoint getBombPosition();
	//��ȡը��������Ƭ������
	CCPoint getGrid();
	//���ը����ըǰ�Ķ���
	Animation* creatBombAnimation();
	//����ը��
	void dropBomb();
	//��ñ�ը����ˮ���Ķ���
	//dire: ˮ������
	Animation* creatExplodeAnimation(dire drection);
	//��ñ�ը���ĵĶ���
	Animation* creatCenterAnimation();
	//ը����dire��ָ���ķ���ը
	void explosion(dire direction);
	//ը����������
	void explode();
	//��ը��ʱ��
	void idleUpdate(float dt);
	void explodeUpdate(float dt);
	//ɾȥ��ը����Ƭ
	void removeTile(dire direction);
};

#endif;