#include <iostream>        // std::cout/cerr/endl/wcout
#include <string>          // std::string
#include <utility>         // std::move
#include <assert.h>        // assert
#ifdef _WIN32
#include <fcntl.h>         // _O_WTEXT
#include <io.h>            // _setmode
#include <stdio.h>         // _fileno/stdout
#endif
#include <cpprest/json.h>  // web::json

using namespace std;
using namespace utility;
using namespace web;

#ifdef _WIN32
#define tcout std::wcout
#else
#define tcout std::cout
#endif

int main()
{
#ifdef _WIN32
    _setmode(_fileno(stdout), _O_WTEXT);
#endif

    string_t json_str = U(R"(
    {
        "s": "你好，世界",
        "t": true,
        "f": false,
        "n": null,
        "i": 123,
        "d": 3.1416,
        "a": [1, 2, 3]
    })");
    tcout << "Original JSON: " << json_str << endl;

    json::keep_object_element_order(true);
    auto document = json::value::parse(json_str);

    static const char* type_names[] = {
        "Number", "Boolean", "String", "Object", "Array", "Null",
    };

    for (auto&& value: document.as_object()) {
        tcout << "Type of member " << value.first << " is " << type_names[value.second.type()] << endl;
    }

}