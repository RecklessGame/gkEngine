//
//  main.m
//  gkLauncherMac
//
//  Created by gameKnife on 13-7-14.
//  Copyright (c) 2013年 kkstudio. All rights reserved.
//

#include "gkPlatform.h"
#include "IGameFramework.h"
#include "IRenderer.h"
#include "gkPlatform_impl.h"

#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>
#import <AppKit/NSApplication.h>
#import <AppKit/NSWindow.h>

IGameFramework* gkLoadStaticModule_gkGameFramework();
void gkFreeStaticModule_gkGameFramework();

IGameFramework* g_pGame;

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

// implement of macPathUtil
std::string macBundlePath()
{
    char path[PATH_MAX];
    
//    NSString* appBundlePath = [NSBundle mainBundle].bundlePath;
//    
//    NSString* appRunningPath = [appBundlePath substringToIndex: [appBundlePath rangeOfString: [appBundlePath lastPathComponent]].location];
//    
//    if ([appRunningPath hasSuffix: @"/"]) {
//        appRunningPath  = [appRunningPath substringToIndex: [appRunningPath rangeOfString:@"/" options: NSBackwardsSearch].location];
//    }
//    
//    strncpy(path, appRunningPath.UTF8String, PATH_MAX);
    
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

std::string iOSDocumentsDirectory()
{
    return macBundlePath();
}

std::string macCachePath()
{
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES);
    NSString *cachesDirectory = [paths objectAtIndex:0];
    
    return [[cachesDirectory stringByAppendingString:@"/"] cStringUsingEncoding:NSASCIIStringEncoding];
}

void enum_all_files_in_folder( const TCHAR* root_path,std::vector<gkStdString>& result,bool inc_sub_folders/*=false*/ )
{
    
}

int main(int argc, char *argv[])
{
    g_pGame = gkLoadStaticModule_gkGameFramework();
    
    ISystemInitInfo sii;
    sii.fWidth = 1280;
    sii.fHeight = 720;
    
    g_pGame->Init(sii);
    g_pGame->PostInit(0, sii);
    
    g_pGame->InitGame(NULL);
    
    while (1) {
        if( !g_pGame->Update() )
        {
            break;
        }
    }
    
    g_pGame->Destroy();
    
    return 0;
}
