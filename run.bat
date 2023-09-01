@ECHO OFF

cd bin
call make
call zstring "Hello World!"
cd ..