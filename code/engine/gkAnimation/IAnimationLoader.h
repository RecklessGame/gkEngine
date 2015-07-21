//
//  IAnimationLoader.h
//  gkENGINE_CoreModule
//
//  Created by Eugene Stewart on 7/21/15.
//
//

#ifndef gkENGINE_CoreModule_IAnimationLoader_h
#define gkENGINE_CoreModule_IAnimationLoader_h

#include "IAnimation.h"

class IAnimationLoader
{
public:
    IAnimationLoader() = 0;
    ~IAnimationLoader() = 0;
    
    virtual IAnimation* load(const TCHAR* file_name) = 0;
};

#endif
