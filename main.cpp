#include <iostream>
#include <boost/any.hpp>
#include <string>
#include <vector>

using namespace std;
using namespace boost;

int main()
{
    any w;
    any x { 2.0 };
    vector<any> y { 42, "life" };
    any z = string("test");

    if (!x.empty())
        cout << x.type().name() << endl;

    auto a = any_cast<int>(y[0]);
    cout << "The value is " << a << endl;

    getchar();
    return 0;
}