/****************************************************************************
Copyright (c) 2013-2014 Chukong Technologies Inc.

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#ifndef __TRIGGERFACTORY_H__
#define __TRIGGERFACTORY_H__

#include "cocos2d.h"
#include <string>
#include <unordered_map>

namespace cocos2d
{
    namespace ui
    {
        class Widget;
    }
}
namespace cocostudio
{
    class WidgetReaderProtocol;
}

namespace cocostudio {

class ObjectFactory
{
public:
    typedef cocos2d::Ref* (*Instance)(void);
    struct TInfo
    {
        TInfo(void);
        TInfo(const std::string& type, Instance ins = NULL);
        TInfo(const TInfo &t);
        ~TInfo(void);
        TInfo& operator= (const TInfo &t);
        std::string _class;
        Instance _fun;
    };
    typedef std::unordered_map<std::string, TInfo>  FactoryMap;

    static ObjectFactory* getInstance();
    static void destroyInstance();
    cocos2d::Ref* createObject(const std::string &name);
    cocos2d::Component* createComponent(const std::string &name);
    cocos2d::ui::Widget* createGUI(std::string name);
    WidgetReaderProtocol* createWidgetReaderProtocol(std::string name);
    void registerType(const TInfo &t);
    void removeAll();

protected:
    ObjectFactory(void);
    virtual ~ObjectFactory(void);
private:
    static ObjectFactory *_sharedFactory;
    FactoryMap _typeMap;
};

}

#endif
