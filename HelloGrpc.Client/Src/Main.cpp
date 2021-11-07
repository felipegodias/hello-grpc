#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>

#include "Protos/helloworld.grpc.pb.h"

class GreeterClient
{
public:
    GreeterClient(std::shared_ptr<grpc::Channel> channel)
        : stub_(helloworld::Greeter::NewStub(std::move(channel)))
    {
    }

    // Assembles the client's payload, sends it and presents the response back
    // from the server.
    std::string SayHello(const std::string& user) const
    {
        // Data we are sending to the server.
        helloworld::HelloRequest request;
        request.set_name(user);

        // Container for the data we expect from the server.
        helloworld::HelloReply reply;

        // Context for the client. It could be used to convey extra information to
        // the server and/or tweak certain RPC behaviors.
        grpc::ClientContext context;

        // The actual RPC.
        grpc::Status status = stub_->SayHello(&context, request, &reply);

        // Act upon its status.
        if (status.ok())
        {
            return reply.message();
        }
        std::cout << status.error_code() << ": " << status.error_message()
            << std::endl;
        return "RPC failed";
    }

private:
    std::unique_ptr<helloworld::Greeter::Stub> stub_;
};

int main(const int argc, char* argv[])
{
    // Instantiate the client. It requires a channel, out of which the actual RPCs
    // are created. This channel models a connection to an endpoint specified by
    // the argument "--target=" which is the only expected argument.
    // We indicate that the channel isn't authenticated (use of
    // InsecureChannelCredentials()).

    const std::string target_str = "localhost:50051";
    auto channel = CreateChannel(target_str, grpc::InsecureChannelCredentials());
    GreeterClient greeter(std::move(channel));
    const std::string user("world");
    const std::string reply = greeter.SayHello(user);
    std::cout << "Greeter received: " << reply << std::endl;
    return 0;
}
