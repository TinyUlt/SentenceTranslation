//
//  XMLManager.h
//  Fishing3D
//
//  Created by TinyUlt on 15/1/28.
//
//

#ifndef __Fishing3D__XMLManager__
#define __Fishing3D__XMLManager__
#include "cocos2d.h"
#include "XMLextern/tinyxml.h"
#include <vector>
#include <string>
using namespace std;
USING_NS_CC;

class Sentence
{
public:
    Sentence(string chinese, string english, string tip):chinese(chinese),english(english),tip(tip)
    {
    }
    std::string chinese;
    std::string english;
    std::string tip;
};
class S_sentence
{
public:
    vector<Sentence> sentence;
    void addSentence(TiXmlElement* element)
    {
        auto _chinese = element->Attribute("chinese");
        auto _english = element->Attribute("english");
        auto _tip = element->Attribute("tip")==0 ? "0" : element->Attribute("tip");
        
        Sentence _sentence(_chinese, _english, _tip );
        sentence.push_back(_sentence);
    }
    
};
class XMLManager
{
public:
    static void preLoad();
    static XMLManager* getManager();
    void initSentence(std::string fileName);
        ~XMLManager();
    
    S_sentence m_sentence;
private:
    XMLManager();
    static XMLManager* m_instance;
    void initXMLFile();
};

#endif /* defined(__Fishing3D__XMLManager__) */
