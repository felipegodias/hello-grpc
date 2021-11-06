project(HelloWorld.Launcher CXX)

set(HELLO_WORLD_LAUNCHER_SRC)

add_subdirectory("Src")

list(SORT HELLO_WORLD_LAUNCHER_SRC)
message("\n::::: Hello World Launcher Source Files Start :::::")
foreach(SRC_FILE IN LISTS HELLO_WORLD_LAUNCHER_SRC)
    message(${SRC_FILE})
endforeach()

add_executable(HelloWorld.Launcher ${HELLO_WORLD_LAUNCHER_SRC})