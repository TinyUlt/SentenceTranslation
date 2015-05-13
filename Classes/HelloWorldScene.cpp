#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Manager/XMLManager.h"
USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    XMLManager::preLoad();
    auto rootNode = CSLoader::createNode("MainScene.csb");

    
    addChild(rootNode);
    
    
    sentenceCurrentIndex = random(0, (int)XMLManager::getManager()->m_sentence.sentence.size()-1);
    oderArray.push_back(sentenceCurrentIndex);
    oderIndex=0;
    
    
    
    auto Panel_show = static_cast<Layout*>(rootNode->getChildByName("Panel_show"));
    Text_chinese = static_cast<Text*>(Helper::seekWidgetByName(Panel_show, "Text_chinese"));
    Text_tip = static_cast<Text*>(Helper::seekWidgetByName(Panel_show, "Text_tip"));
    Text_english = static_cast<Text*>(Helper::seekWidgetByName(Panel_show, "Text_english"));
    
    
    
    reInitText();
    
    auto Panel_conttrol = static_cast<Layout*>(rootNode->getChildByName("Panel_conttrol"));
    CheckBox_chinese = static_cast<CheckBox*>(Helper::seekWidgetByName(Panel_conttrol, "CheckBox_chinese"));
    CheckBox_english = static_cast<CheckBox*>(Helper::seekWidgetByName(Panel_conttrol, "CheckBox_english"));
    CheckBox_tip = static_cast<CheckBox*>(Helper::seekWidgetByName(Panel_conttrol, "CheckBox_tip"));
    
    CheckBox_chinese->addEventListener(CC_CALLBACK_2(HelloWorld::checkBox_chinese_selectedEvent, this));
    CheckBox_english->addEventListener(CC_CALLBACK_2(HelloWorld::checkBox_english_selectedEvent, this));
    CheckBox_tip->addEventListener(CC_CALLBACK_2(HelloWorld::checkBox_tip_selectedEvent, this));
    
    
    Button_back = static_cast<Button*>(Helper::seekWidgetByName(Panel_conttrol, "Button_back"));
    Button_restart = static_cast<Button*>(Helper::seekWidgetByName(Panel_conttrol, "Button_restart"));
    Button_next = static_cast<Button*>(Helper::seekWidgetByName(Panel_conttrol, "Button_next"));
    
    Button_back->addTouchEventListener(CC_CALLBACK_2(HelloWorld::button_back_touchEvent, this));
    Button_restart->addTouchEventListener(CC_CALLBACK_2(HelloWorld::button_restart_touchEvent, this));
    Button_next->addTouchEventListener(CC_CALLBACK_2(HelloWorld::button_next_touchEvent, this));
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

    return true;
}
void HelloWorld::reInitText()
{
    Text_chinese->setString(XMLManager::getManager()->m_sentence.sentence[sentenceCurrentIndex].chinese);
    Text_english->setString(XMLManager::getManager()->m_sentence.sentence[sentenceCurrentIndex].english);
    Text_tip->setString(XMLManager::getManager()->m_sentence.sentence[sentenceCurrentIndex].tip);
}
void HelloWorld::button_back_touchEvent(Ref *pSender, Widget::TouchEventType type)
{
    if (type == Widget::TouchEventType::ENDED) {
        
//        sentenceCurrentIndex--;
//        if (sentenceCurrentIndex < 0)
//        {
//            sentenceCurrentIndex = (int) XMLManager::getManager()->m_sentence.sentence.size() - 1;
//        }
        --oderIndex;
        if (oderIndex <=0) {
            oderIndex =0;
        }
        
        if (oderIndex >= 0) {
            sentenceCurrentIndex = oderArray[oderIndex];
        }
        

        reInitText();
    }
}
void HelloWorld::button_restart_touchEvent(Ref *pSender, Widget::TouchEventType type)
{
    if (type == Widget::TouchEventType::ENDED) {
        oderArray.clear();
        sentenceCurrentIndex = random(0, (int)XMLManager::getManager()->m_sentence.sentence.size()-1);
        oderArray.push_back(sentenceCurrentIndex);
        oderIndex = 0;
        reInitText();
    }
}
void HelloWorld::button_next_touchEvent(Ref *pSender, Widget::TouchEventType type)
{
    if (type == Widget::TouchEventType::ENDED) {
//        sentenceCurrentIndex++;
//        if (sentenceCurrentIndex >= XMLManager::getManager()->m_sentence.sentence.size()) {
//            sentenceCurrentIndex = 0;
//        }
        if (++oderIndex < ((int)oderArray.size())) {
            sentenceCurrentIndex = oderArray[oderIndex];
        }
        else
        {
            sentenceCurrentIndex = random(0, (int)XMLManager::getManager()->m_sentence.sentence.size()-1);
            oderArray.push_back(sentenceCurrentIndex);
        }
        
        
        
        reInitText();
    }
}


void HelloWorld::checkBox_chinese_selectedEvent(Ref* pSender,CheckBox::EventType type)
{
    switch (type)
    {
        case CheckBox::EventType::SELECTED:
            Text_chinese->setVisible(true);
            break;
            
        case CheckBox::EventType::UNSELECTED:
            Text_chinese->setVisible(false);
            break;
            
        default:
            break;
    }
    
}
void HelloWorld::checkBox_english_selectedEvent(Ref* pSender,CheckBox::EventType type)
{
    switch (type)
    {
        case CheckBox::EventType::SELECTED:
            Text_english->setVisible(true);
            break;
            
        case CheckBox::EventType::UNSELECTED:
            Text_english->setVisible(false);
            break;
            
        default:
            break;
    }
    
}
void HelloWorld::checkBox_tip_selectedEvent(Ref* pSender,CheckBox::EventType type)
{
    switch (type)
    {
        case CheckBox::EventType::SELECTED:
            Text_tip->setVisible(true);
            break;
            
        case CheckBox::EventType::UNSELECTED:
            Text_tip->setVisible(false);
            break;
            
        default:
            break;
    }
    
}