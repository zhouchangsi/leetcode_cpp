# run
```powershell
cmake -B build -DCMAKE_TOOLCHAIN_FILE=C:/Users/kong/scoop/apps/vcpkg/current/scripts/buildsystems/vcpkg.cmake -G "Ninja" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

nodemon -e cpp,h --exec "cmake --build build --config Release --target leetcode && build/leetcode.exe --gtest_filter=leetcode461.*"
```