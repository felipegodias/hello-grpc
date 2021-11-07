project(HelloGrpc.Server CXX)

set(HELLO_GRPC_SERVER_SRC)

add_subdirectory("Src")

list(SORT HELLO_GRPC_SERVER_SRC)
message("\n::::: Hello GRPC Server Source Files Start :::::")
foreach(SRC_FILE IN LISTS HELLO_GRPC_SERVER_SRC)
    message(${SRC_FILE})
endforeach()


add_executable(HelloGrpc.Server ${HELLO_GRPC_SERVER_SRC})

target_link_libraries(HelloGrpc.Server PRIVATE HelloGrpc.Protos)