/*
    🔷 What is an enum in C++?
    An enum (short for enumeration) is a user-defined data type that assigns names to a set of integer constants — making code more readable and manageable.

    ✅ Syntax:
    enum EnumName {
        value1,
        value2,
        value3,
        ...
    };

    🔹 So yes:
    ✅ "Enum is a user-defined data type that stores names of integers." — this is correct in simple terms.

    But more precisely:
    - It associates meaningful names (like MONDAY, RED, ERROR_404) to underlying integer values (like 0, 1, 404).

    - You can use those names in place of raw numbers, which makes your logic clearer.
*/


#include<iostream>
using namespace std;

enum TrafficLight {
    red,     // 0
    YELLOW,  // 1
    Green    // 2
};

enum StatusCodes{
    ok = 200,
    not_found = 404,
    server_error = 500
};

int main() {
    cout << red << " " << YELLOW << " " << Green << endl;

    cout << ok << " " << not_found << " " << server_error << endl;
    return 0;
}
