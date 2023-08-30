# run test on file change
```powershell
# replace gtest_filter with your test case
nodemon -e cpp,h --exec "cmake --build build --config Release --target leetcode && build\Release\leetcode.exe --gtest_filter=leetcode461*"
```