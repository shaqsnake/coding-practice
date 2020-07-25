#include <iostream>
#include <exception>
#include <cpprest/http_client.h>

using namespace utility;
using namespace web::http;
using namespace web::http::client;
using std::cerr;
using std::cout;
using std::endl;

auto get_headers(http_response resp)
{
    auto headers = resp.to_string();
    auto end = headers.find(U("\r\n\r\n"));
    if (end != string_t::npos) {
        headers.resize(end + 4);
    }
    return headers;
}

auto get_request(string_t uri)
{
    http_client client{uri};
    auto request = client.request(methods::GET)
                         .then([](http_response resp) {
                             if (resp.status_code() != status_codes::OK) {
                                 auto headers = get_headers(resp);
                                 cout << headers;
                             }
                             return resp.extract_string();
                         })
                         .then([](string_t str) {
                             cout << str;
                         });
    return request;
}

int main(int argc, const char* argv[]) {
    if (argc != 2) {
        cerr << "A URL is needed\n";
        return 1;
    }

    try {
        auto request = get_request(argv[1]);
        request.wait();
    } catch (const std::exception& e) {
        cerr << "Error exception: " << e.what() << endl;
        return 1;
    }

    return 0;
}