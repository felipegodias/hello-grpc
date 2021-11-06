cmake -S . -B "out" -G "Ninja" -DCMAKE_BUILD_TYPE:STRING="Release"
cmake --build "out"
ctest --test-dir "out" -VV