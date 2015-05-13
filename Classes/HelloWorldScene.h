#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "vector"
USING_NS_CC;
using namespace ui;
using namespace cocostudio::timeline;
using namespace cocostudio;
using namespace std;
class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    void checkBox_chinese_selectedEvent(Ref* pSender,CheckBox::EventType type);
    void checkBox_english_selectedEvent(Ref* pSender,CheckBox::EventType type);
    void checkBox_tip_selectedEvent(Ref* pSender,CheckBox::EventType type);
    
    void button_back_touchEvent(Ref *pSender, Widget::TouchEventType type);
    void button_restart_touchEvent(Ref *pSender, Widget::TouchEventType type);
    void button_next_touchEvent(Ref *pSender, Widget::TouchEventType type);
    
    void reInitText();
    
    Text* Text_chinese;
    Text* Text_tip;
    Text* Text_english;
    
    CheckBox* CheckBox_chinese;
    CheckBox* CheckBox_english;
    CheckBox* CheckBox_tip;
    
    Button* Button_back;
    Button* Button_restart;
    Button* Button_next;
    
    int sentenceCurrentIndex;
    vector<int> oderArray;
    int oderIndex;
};

#endif // __HELLOWORLD_SCENE_H__
