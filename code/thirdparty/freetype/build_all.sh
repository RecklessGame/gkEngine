#bin bash

echo "...Build debug universal library...."
for BUILD_ARCH in "i386" "x86_64"; do
	xcodebuild -sdk macosx10.10 -arch "$BUILD_ARCH" -configuration Debug-OSX
	cp ./lib/osx/Debug/Debug-OSX/libfreetype2.a ./lib/osx/libfreetype2-"$BUILD_ARCH"-debug.a
done
lipo ./lib/osx/libfreetype2-i386-debug.a ./lib/osx/libfreetype2-x86_64-debug.a -create -output ./lib/osx/libfreetype2-universal-debug.a
rm -f ./lib/osx/libfreetype2-i386-debug.a
rm -f ./lib/osx/libfreetype2-x86_64-debug.a
echo "...Done! debug universal library..."



echo "Build release universal library...."
for BUILD_ARCH in "i386" "x86_64"; do
	xcodebuild -sdk macosx10.10 -arch "$BUILD_ARCH" -configuration Release-OSX
	cp ./lib/osx/Release/Release-OSX/libfreetype2.a ./lib/osx/libfreetype2-"$BUILD_ARCH"-release.a
done
lipo ./lib/osx/libfreetype2-i386-release.a ./lib/osx/libfreetype2-x86_64-release.a -create -output ./lib/osx/libfreetype2-universal-release.a
rm -f ./lib/osx/libfreetype2-i386-release.a
rm -f ./lib/osx/libfreetype2-x86_64-release.a
echo "...Done! release universal library..."


# xcodebuild -sdk macosx10.10 -arch "$BUILD_ARCH" -configuration Release-OSX

# xcodebuild -sdk iphoneos8.4 -configuration Debug
# xcodebuild -sdk iphoneos8.4 -configuration Release
# xcodebuild -sdk iphonesimulator8.4 -configuration Debug
# xcodebuild -sdk iphonesimulator8.4 -configuration Release
