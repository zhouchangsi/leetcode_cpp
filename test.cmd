# get test filter argurment from command line
set arg=%1 # e.g. leetcode241.*
# if no argurment, run all tests
if "%arg%"=="" (
    set arg=leetcode
)
# run test
nodemon -e h,cpp --exec "cmake --build build -t leetcode_solutions && .\bin\leetcode_solutions.exe --gtest_filter=%arg%"