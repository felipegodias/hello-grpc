project(HelloGrpc.Client CXX)

set(HELLO_GRPC_CLIENT_SRC)

add_subdirectory("Src")

list(SORT HELLO_GRPC_CLIENT_SRC)
message("\n::::: Hello GRPC Server Client Files Start :::::")
foreach(SRC_FILE IN LISTS HELLO_GRPC_CLIENT_SRC)
    message(${SRC_FILE})
endforeach()


add_executable(HelloGrpc.Client ${HELLO_GRPC_CLIENT_SRC})

target_link_libraries(HelloGrpc.Client PRIVATE HelloGrpc.Protos)