//
//  gkFilePath_osx.h
//  gkENGINE_CoreModule
//
//  Created by Eugene Stewart on 7/28/15.
//
//

#ifndef gkENGINE_CoreModule_gkFilePath_osx_h
#define gkENGINE_CoreModule_gkFilePath_osx_h

#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>

std::string macBundlePath(void)
{
    char path[PATH_MAX];
    
    CFBundleRef mainBundle = CFBundleGetMainBundle();
    assert(mainBundle);
    
    CFURLRef mainBundleURL = CFBundleCopyBundleURL(mainBundle);
    assert(mainBundleURL);
    
    CFStringRef cfStringRef = CFURLCopyFileSystemPath( mainBundleURL, kCFURLPOSIXPathStyle);
    assert(cfStringRef);
    
    CFStringGetCString(cfStringRef, path, PATH_MAX, kCFStringEncodingASCII);
    
    CFRelease(mainBundleURL);
    CFRelease(cfStringRef);
    
    char* lastpath = strrchr(path, '/');
    if (lastpath) {
        *lastpath = 0;
    }
    lastpath = strrchr(path, '/');
    if (lastpath) {
        *lastpath = 0;
    }
    //    lastpath = strrchr(path, '/');
    //    if (lastpath) {
    //        *lastpath = 0;
    //    }
    
    return std::string(path);
}

std::string iOSDocumentsDirectory(void)
{
    return macBundlePath();
}

std::string macCachePath()
{
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES);
    NSString *cachesDirectory = [paths objectAtIndex:0];
    
    return [[cachesDirectory stringByAppendingString:@"/"] cStringUsingEncoding:NSASCIIStringEncoding];
}

#endif
