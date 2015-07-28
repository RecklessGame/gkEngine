//
//  gkFilePath_iOS.h
//  gkENGINE_CoreModule
//
//  Created by Eugene Stewart on 7/28/15.
//
//

#ifndef gkENGINE_CoreModule_gkFilePath_iOS_h
#define gkENGINE_CoreModule_gkFilePath_iOS_h

#if defined OS_IOS

#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>

// implement of macPathUtil
std::string macBundlePath()
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
    
    return std::string(path);
}

std::string iOSDocumentsDirectory()
{
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = [paths objectAtIndex:0];
    
    return std::string([documentsDirectory cStringUsingEncoding:NSASCIIStringEncoding]);
}

std::string macCachePath()
{
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES);
    NSString *cachesDirectory = [paths objectAtIndex:0];
    
    return [[cachesDirectory stringByAppendingString:@"/"] cStringUsingEncoding:NSASCIIStringEncoding];
}

#endif  /// OS_IOS

#endif  /// gkENGINE_CoreModule_gkFilePath_iOS_h
