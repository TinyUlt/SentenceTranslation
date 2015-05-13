//
//  XMLManager.cpp
//  Fishing3D
//
//  Created by TinyUlt on 15/1/28.
//
//

#include "XMLManager.h"

XMLManager::XMLManager()
{
    
}
XMLManager::~XMLManager()
{
//    for(auto &child:fishAttribute)
//    {
//        delete child;
//    }
//    fishAttribute.clear();
    
//    for(auto &child:bulletAttribute)
//    {
//        delete child;
//    }
//    bulletAttribute.clear();
}
XMLManager* XMLManager::m_instance = NULL;
void XMLManager::preLoad()
{
    if (m_instance == NULL)
    {
        m_instance = new XMLManager();
        m_instance->initXMLFile();
    }

}
XMLManager* XMLManager::getManager()
{
    if (m_instance == NULL)
    {
        m_instance = new XMLManager();
        m_instance->initXMLFile();
    }
    
    return m_instance;
}
void XMLManager::initXMLFile()
{
    initSentence("sentence.xml");
}

void XMLManager::initSentence(std::string fileName)
{
    auto _name = CCFileUtils::sharedFileUtils()->fullPathForFilename(fileName.c_str());
    TiXmlDocument* _document = new TiXmlDocument(_name.c_str());
    _document->LoadFile();
    TiXmlElement* _dataElement = _document->RootElement();
    TiXmlElement* element = _dataElement->FirstChildElement();
    while (element)
    {
        m_sentence.addSentence(element);
        
        element = element->NextSiblingElement();
    }
    
    delete _document;
}

