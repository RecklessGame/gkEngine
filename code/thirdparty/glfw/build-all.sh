
cd _build

echo "...building debug universal library..."
for BUILD_ARCH in "i386" "x86_64"; do
	xcodebuild -sdk macosx10.10 -arch "$BUILD_ARCH" -configuration Debug -scheme glfw
	cp ../lib/Debug/libglfw3.a ../lib/libglfw3-"$BUILD_ARCH"-debug.a
done

lipo ../lib/libglfw3-i386-debug.a ../lib/libglfw3-x86_64-debug.a -create -output ../lib/libglfw3-universal-debug.a
rm -f ../lib/libglfw3-i386-debug.a
rm -f ../lib/libglfw3-x86_64-debug.a

echo "...done building debug universal library..."


echo "...building release universal library..."

echo "...done building release universal library..."

