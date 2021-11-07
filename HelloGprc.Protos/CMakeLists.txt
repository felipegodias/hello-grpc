project(HelloGrpc.Protos CXX)

set(HELLO_GRPC_PROTOS_SRC)

add_subdirectory("Protos")

list(SORT HELLO_GRPC_PROTOS_SRC)
message("\n::::: Hello GRPC Protos Source Files Start :::::")
foreach(SRC_FILE IN LISTS HELLO_GRPC_PROTOS_SRC)
    message(${SRC_FILE})
endforeach()

add_library(HelloGrpc.Protos STATIC ${HELLO_GRPC_PROTOS_SRC})

find_package(gRPC CONFIG REQUIRED)
target_link_libraries(HelloGrpc.Protos PUBLIC
    protobuf::libprotobuf
    gRPC::grpc
    gRPC::grpc++
)

target_include_directories(HelloGrpc.Protos PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

get_target_property(grpc_cpp_plugin_location gRPC::grpc_cpp_plugin LOCATION)

protobuf_generate(TARGET HelloGrpc.Protos LANGUAGE cpp)
protobuf_generate(TARGET HelloGrpc.Protos LANGUAGE grpc
    GENERATE_EXTENSIONS
        .grpc.pb.h
        .grpc.pb.cc
    PLUGIN
        "protoc-gen-grpc=${grpc_cpp_plugin_location}"
)