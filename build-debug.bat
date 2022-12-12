@echo off
pushd debug
ninja
copy compile_commands.json .. >nul
popd
