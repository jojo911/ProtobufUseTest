@echo off

for /f "usebackq tokens=*" %%f in (`dir /s /b %~dp0\*.proto`) do (
	protoc -I=%~dp0  --cpp_out=%~dp0 %~dp0/im.hello.proto
)
pause